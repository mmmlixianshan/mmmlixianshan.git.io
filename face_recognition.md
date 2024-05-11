第一，stm32初始化

第二，视觉部分对来访者进行识别 

第三，将识别情况发送给stm32 

第四，stm32控制舵机和oled显示 



#### 

####  stm32主控和用到的外设资源

<img src="face_recognition.assets/image-20240511145103730.png" alt="image-20240511145103730" style="zoom:80%;" />



#### stm32主程序流程图

<img src="face_recognition.assets/image-20240511145409030-1715444232836-8.png" alt="image-20240511145409030" style="zoom:80%;" />





#### python视觉部分程序流程图



<img src="face_recognition.assets/image-20240511145514746-1715444300661-12.png" alt="image-20240511145514746" style="zoom: 67%;" />

#### 



#### 使用opencv-python dlib库检测识别



##### 使用dlib库检测到人脸

![image-20240511145942035](face_recognition.assets/image-20240511145942035.png)

##### 采集保存用户人脸图片

![image-20240511145957365](face_recognition.assets/image-20240511145957365.png)

##### 提取人脸特征

![image-20240511150006604](face_recognition.assets/image-20240511150006604.png)



##### 人脸实时识别

![image-20240511150056805](face_recognition.assets/image-20240511150056805.png)



##### 来访者信息录入，人脸识别成功效果



![image-20240511150214454](face_recognition.assets/image-20240511150214454.png)



##### 来访者信息未录入，无法识别效果



![](face_recognition.assets/image-20240511150248655.png)
