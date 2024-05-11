

#### 赛道图片

![image-20240511161540327](C:\Users\HONOR\AppData\Roaming\Typora\typora-user-images\image-20240511161540327.png)



#### 赛道要求

1.起跑线（15cm×1.8cm）以黑胶带的形式垂直于赛道粘贴，赛前不公布，具体位

置比赛时揭晓；

2.横断路障为 15cm×5cm×15cm 的红色纸盒；

3.每组有且仅有 10 分钟比赛时间，用于调试和正式发车，期间不可烧录程序；

4.比赛期间最多记录 3 次有效成绩，小车出发离开起跑线开始计时，运行一周后

经过起跑线后自行停止为一次有效成绩，当拥有 3 次有效成绩或比赛时间超过

10 分钟后结束发车，选手离场，取最好成绩为最终成绩；

5.比赛前一天选手将小车与竞赛设计报告一同提交到 NA206（具体时间另行通

知）。

评分标准：

1.从小车出发离开起跑线开始计时，运行一周后经过起跑线后停止，以这段时间作为基础成绩；

2.横断路障位置超出安全区，即为避障失败，成绩有效，但罚时 15 秒，安全区为

横断路障前后 5cm 左右 3cm 的胶布内；

3.小车在距离横断路障前 40cm 的范围内方可驶出赛道，绕过横断路障后在距离

其 40cm 内返回赛道，否则此次发车成绩无效；

4.小车行驶期间，参赛选手不得人为干预其行驶，否则此次发车成绩无效；

5.小车行驶大幅偏离赛道，此次发车成绩无效。





#### 软件算法

位置式PID算法用于控制小车的运动，使其能够循迹，避障则使用红外传感器。

#### 系统工作流程

灰度传感器和红外传感器采集地面颜色和障碍物信息。主控制器接收传感器数据，根据PID算法计算出对应的参数赋值给PWM波占空比，并通过TB6122电机驱动模块控制电机的速度和方向。小车根据PID算法计算的参数进行运动，实现循迹。

#### 主控芯片和主要器件

stm32f103c8t6主控、电机、灰度传感器、红外传感器、tb6612电机驱动模块、小车底盘。



#### 循迹原理

循迹采用了8路灰度传感器检测巡线轨迹，传感器识别到白色区域，传感器返回高电平，如果识别到黑线，该传感器会返回低电平，将传感器放到合适的位置，通过传感器的状态来判断小车是直走还是偏左、偏右。以下分别是小车直走、偏右和偏左的情况。

<img src="C:\Users\HONOR\AppData\Roaming\Typora\typora-user-images\image-20240511155814745.png" alt="image-20240511155814745" style="zoom: 67%;" />

​                                                                                                        灰度传感器

##### 位置式PID原理

小车巡线时的目标位置是循迹黑线正好在传感器中间，当小车左偏或右偏时会产生偏差，利用PID算法可以减少偏差，PID的负反馈控制系统中的反馈回路将输出信号与期望值进行比较，并将比较结果作为输入信号的一部分，用于调节控制器的输出信号，从而使得输出信号能够逼近期望值。负反馈的作用是通过不断修正控制器输出信号，使系统的实际输出与期望值之间的差异趋近于零。在这里控制器具体指stm32单片机，

在这里利用的是位置式PID算法，具体的期望值是黑线在传感器中间。当小车偏离循迹时，对小车左偏或右偏产生的偏差(error)进行量化，例如，小车在中间时,error=0；小车左偏一个传感器距离时，error=-2；小车左偏两个传感器距离，error=-5等，将尽可能多的情况考虑到并且量化。

##### PID算法具体公式

$$
u\left(t\right)=k_p\cdot e\left(t\right)+k_i\cdot\int_{0}^{t}e\left(t\right)dt+k_d\cdot\ \ \frac{de\left(t\right)}{dt}
$$

​                            

在实际进行计算时，对以上公式进行离散化得到


$$
u\left(k\right)=K_p\cdot e\left(k\right)+k_i\cdot\sum e\left(k\right)+K_d\cdot[e(k)-e(k-1)]
$$

$e(k)$ 是产生的偏差 ，$k_p$是比例系数，$k_i$是积分系数，$k_d$是微分系数,$pid$算法得到的负反馈结果,将这个值赋给控制电机占空比的函数,从而控制车左右轮子的速度，让小车回到中间位置，实现循迹




```c

int Position_PID (int Encoder,int Target)   //PID的目标值是error=0
{   
     float Position_KP=300,Position_KI=0.40,Position_KD=460;
     static float Bias,Pwm,Integral_bias,Last_Bias;
     Bias=Encoder-Target;                         //当前的误差
     Integral_bias+=Bias;                         //对误差进行累加
     Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);           //将PID计算结果赋给Pwm
     Last_Bias=Bias;   //保存当下误差，在下次计算差值 
     return Pwm;      //返回PWMֵ
}

```

  PID函数在定时器定时中断中执行 ，定时器每10ms定时中断一次。





#### 避障原理

避障用到是红外传感器，传感器out端口起始时刻为高电平，当传感器前方距离障碍物一定距离检测到障碍物时，传感器端口输出低电平，在程序中，配置stm32外部触发中断用来接收红外传感器的下降信号。同时，在外部中断服务函数中，执行拐弯程序让小车避过障碍。以下是外部中断服务函数

<img src="C:\Users\HONOR\AppData\Roaming\Typora\typora-user-images\image-20240511160129201.png" alt="image-20240511160129201" style="zoom: 50%;" />

​                                                                                                        红外传感器

#### 系统运行流程框图



<img src="C:\Users\HONOR\AppData\Roaming\Typora\typora-user-images\image-20240511155611354.png" alt="image-20240511155611354" style="zoom:80%;" />







<img src="C:\Users\HONOR\Documents\WeChat Files\wxid_94k80re6ur1912\FileStorage\Temp\080edc8385bf5562c4005e680e10f04.jpg" alt="080edc8385bf5562c4005e680e10f04" style="zoom: 50%;" />





![a50e3163d2e841d8917714d83767dc0](C:\Users\HONOR\Documents\WeChat Files\wxid_94k80re6ur1912\FileStorage\Temp\a50e3163d2e841d8917714d83767dc0.jpg)



