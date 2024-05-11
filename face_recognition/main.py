# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


# def print_hi(name):
#     # Use a breakpoint in the code line below to debug your script.
#     print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.
#
#
# # Press the green button in the gutter to run the script.
# if __name__ == '__main__':
#     print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/


# 1显示图片
# import cv2
# # read the image
# img = cv2.imread(r"C:\Users\HONOR\Desktop\facedect.png")
# resized_img = cv2.resize(img, (0, 0), fx=0.3, fy=0.3)
# # show the image
# cv2.imshow(winname="Face", mat=resized_img)
# # Wait for a key press to exit
# cv2.waitKey(delay=0)
# # Close all windows
# cv2.destroyAllWindows()


# 2识别人脸并框出人脸范围
#
# import cv2
# import dlib
# # Load the detector
# detector = dlib.get_frontal_face_detector()
# # read the image
# img = cv2.imread(r"C:\Users\HONOR\Desktop\facedect.png")
# resized_img = cv2.resize(img, (0, 0), fx=0.3, fy=0.3)
# # Convert image into grayscale
#
# gray = cv2.cvtColor(src=resized_img, code=cv2.COLOR_BGR2GRAY)
# # Use detector to find landmarks
# faces = detector(gray)
# for face in faces:
#     x1 = face.left() # left point
#     y1 = face.top() # top point
#     x2 = face.right() # right point
#     y2 = face.bottom() # bottom point
#     # Draw a rectangle
#     cv2.rectangle(img=resized_img, pt1=(x1, y1), pt2=(x2, y2), color=(0, 255, 0), thickness=4)
# # show the image
# cv2.imshow(winname="Face", mat=resized_img)
# # Wait for a key press to exit
# cv2.waitKey(delay=0)
# # Close all windows
# cv2.destroyAllWindows()


# 3渲染一个点
# import cv2
# import dlib
# # Load the detector
# detector = dlib.get_frontal_face_detector()
# # Load the predictor
# predictor = dlib.shape_predictor(r"D:\Pycharm\project\protest3\shape_predictor_68_face_landmarks.dat\shape_predictor_68_face_landmarks.dat")
# # read the image
# img = cv2.imread(r"C:\Users\HONOR\Desktop\facedect.png")
# # Convert image into grayscale
# gray = cv2.cvtColor(src=img, code=cv2.COLOR_BGR2GRAY)
# # Use detector to find landmarks
# faces = detector(gray)
# for face in faces:
#     x1 = face.left() # left point
#     y1 = face.top() # top point
#     x2 = face.right() # right point
#     y2 = face.bottom() # bottom point
#     # Look for the landmarks
#     landmarks = predictor(image=gray, box=face)
#     x = landmarks.part(27).x
#     y = landmarks.part(27).y
#     # Draw a circle
#     cv2.circle(img=img, center=(x, y), radius=5, color=(0, 255, 0), thickness=-1)
# # show the image
# cv2.imshow(winname="Face", mat=img)
# # Wait for a key press to exit
# cv2.waitKey(delay=0)
# # Close all windows
# cv2.destroyAllWindows()


# 4提取68个特征点
#
# import cv2
# import numpy as np
# import dlib
# # Load the detector
# detector = dlib.get_frontal_face_detector()
# # Load the predictor
# predictor = dlib.shape_predictor(r"D:\Pycharm\project\protest3\shape_predictor_68_face_landmarks.dat\shape_predictor_68_face_landmarks.dat")
# # read the image
# img = cv2.imread(r"C:\Users\HONOR\Desktop\facedect.png")
# resized_img = cv2.resize(img, (0, 0), fx=0.3, fy=0.3)
# # Convert image into grayscale
# gray = cv2.cvtColor(src=resized_img, code=cv2.COLOR_BGR2GRAY)
# # Use detector to find landmarks
# faces = detector(gray)
# for face in faces:
#     x1 = face.left() # left point
#     y1 = face.top() # top point
#     x2 = face.right() # right point
#     y2 = face.bottom() # bottom point
#     # Create landmark object
#     landmarks = predictor(image=gray, box=face)
#     # Loop through all the points
#     for n in range(0, 68):
#         x = landmarks.part(n).x
#         y = landmarks.part(n).y
#         # Draw a circle
#         cv2.circle(img=resized_img, center=(x, y), radius=3, color=(0, 255, 0), thickness=-1)
# # show the image
# cv2.imshow(winname="Face", mat=resized_img)
# # Delay between every fram
# cv2.waitKey(delay=0)
# # Close all windows
# cv2.destroyAllWindows()


# 5读取视频中人脸
#
# import cv2
# import numpy as np
# import dlib
# video = cv2.VideoCapture(0)
# fps = video.get(cv2.CAP_PROP_FPS)
# print(fps)
# size = (int(video.get(cv2.CAP_PROP_FRAME_WIDTH)), int(video.get(cv2.CAP_PROP_FRAME_HEIGHT)))
# print(size)
# predictor = dlib.shape_predictor(r"D:\Pycharm\project\protest3\shape_predictor_68_face_landmarks.dat\shape_predictor_68_face_landmarks.dat")
# detector = dlib.get_frontal_face_detector()
# while True:
#     ret, frame = video.read()
#     # cv2.imshow("A video", frame)
#
#     # Load the predictor
#     resized_img = cv2.resize(frame, (0, 0), fx=0.7, fy=0.7)
#     # Convert image into grayscale
#     gray = cv2.cvtColor(src=resized_img, code=cv2.COLOR_BGR2GRAY)
#     # Use detector to find landmarks
#     faces = detector(gray)
#     for face in faces:
#         x1 = face.left() # left point
#         y1 = face.top() # top point
#         x2 = face.right() # right point
#         y2 = face.bottom() # bottom point
#         # Draw a rectangle
#         cv2.rectangle(img=resized_img, pt1=(x1, y1), pt2=(x2, y2), color=(255, 191, 135), thickness=4)
#
#     # Use detector to find landmarks
#
#         # Create landmark object
#         landmarks = predictor(image=gray, box=face)
#         # Loop through all the points
#         for n in range(0, 68):
#             x = landmarks.part(n).x
#             y = landmarks.part(n).y
#             # Draw a circle
#             cv2.circle(img=resized_img, center=(x, y), radius=3, color=(255, 191, 135), thickness=-1)
#     # show the image
#     cv2.imshow(winname="Face", mat=resized_img)
#
#     c = cv2.waitKey(10)
#     if c == 27:
#         break
#
# video.release()
# cv2.destroyAllWindows()


# 6读取摄像头内容
# import cv2
# video = cv2.VideoCapture(0)
# fps = video.get(cv2.CAP_PROP_FPS)
# print(fps)
# size = (int(video.get(cv2.CAP_PROP_FRAME_WIDTH)), int(video.get(cv2.CAP_PROP_FRAME_HEIGHT)))
# print(size)
# while True:
#     ret, frame = video.read()
#     cv2.imshow("A video", frame)
#     c = cv2.waitKey(50)
#     if c == 27:
#         break
# video.release()
# cv2.destroyAllWindows()


# 7 人脸识别
#
# import cv2
# import os
# import tkinter as tk
# from PIL import Image, ImageTk, ImageDraw
# import numpy as np
# import serial
#
# from PIL import ImageFont
#
# def cv2AddChineseText(img, text, position, textColor=(0, 255, 0), textSize=30):
#     if (isinstance(img, np.ndarray)):  # 判断是否OpenCV图片类型
#         img = Image.fromarray(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
#     # 创建一个可以在给定图像上绘图的对象
#     draw = ImageDraw.Draw(img)
#     # 字体的格式
#     fontStyle = ImageFont.truetype(
#         "simsun.ttc", textSize, encoding="utf-8")
#     # 绘制文本
#     draw.text(position, text, textColor, font=fontStyle)
#
#     # 转换回OpenCV格式
#     return cv2.cvtColor(np.asarray(img), cv2.COLOR_RGB2BGR)
#
#
# # 加载自定义字体
# # font = ImageFont.truetype(r"C:\Users\ge\Desktop\test1\Cuesor\msyh.ttc", size=30)
#
#
# # 加载Haar Cascade分类器
# face_cascade = cv2.CascadeClassifier(r"D:\Pycharm\project\protest3\haarcascade_frontalface_default.xml")
# # 创建GUI窗口
# root = tk.Tk()
# root.geometry('640x480')
# root.title('人脸识别')
#
# # 创建标签用于显示图像
# image_label = tk.Label(root)
# image_label.pack()
#
# # 打开摄像头并捕获实时图像
# cap = cv2.VideoCapture(0)
#
# # 创建 PhotoImage 对象
# photo = None
#
# # 读取person文件夹中的图像和姓名
# person_images = []
# person_names = []
# for filename in os.listdir(r"C:\Users\HONOR\Desktop\tu"):
#     if filename.endswith('.jpg') :
#         # if filename.endswith('.jpg') or filename.endswith('.png'):
#         # 使用utf-8编码打开文件
#         with open(os.path.join(r"C:\Users\HONOR\Desktop\tu", filename), 'rb') as f:
#             person_images.append(cv2.imdecode(np.frombuffer(f.read(), np.uint8), cv2.IMREAD_COLOR))
#         person_names.append(os.path.splitext(filename)[0])
#
# # 循环处理摄像头捕获的图像
# while True:
#     ret, frame = cap.read()
#     # if not ret:
#     #     break
#
#     # 转换图像格式以进行人脸检测
#     gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#
#     # 使用Haar Cascade分类器检测人脸
#     faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)
#
#     # 在图像中框出检测到的人脸
#     for (x, y, w, h) in faces:
#         # 检查人脸是否属于person文件夹中的某个人
#         found_person = False
#         for i in range(len(person_images)):
#             person_image = person_images[i]
#             person_name = person_names[i]
#             # 将person图像转换为灰度图像以进行比较
#             person_gray = cv2.cvtColor(person_image, cv2.COLOR_BGR2GRAY)
#             # 检查是否存在与person图像相匹配的人脸
#             match = cv2.matchTemplate(gray[y:y + h, x:x + w], person_gray, cv2.TM_CCOEFF_NORMED)
#             if match.max() > 0.8:
#                 print(person_name)
#                 found_person = True
#                 # # 在图像中框出人脸并显示姓名
#                 # cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
#                 # 在图像中框出人脸并显示姓名
#                 cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
#                 frame = cv2AddChineseText(frame, person_name, (x + (w / 2) - 10, y - 30), (0, 255, 255), 30)
#                 break
#
#         # 如果没有找到匹配的人脸，则在图像中框出人脸但不显示姓名
#         if not found_person:
#             cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
#
#     # 将图像转换为PIL Image格式以在GUI中显示
#
#     image = Image.fromarray(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
#     photo = ImageTk.PhotoImage(image)
#
#     # 更新标签以显示图像
#     image_label.configure(image=photo)
#     image_label.image = photo
#
#     # 处理GUI事件以避免程序挂起
#     root.update()
# # 关闭摄像头并销毁窗口
# cap.release()
# cv2.destroyAllWindows()


# 8录入人脸
# Enter
# 2022/2/17

# import cv2
#
# face_name = '123'  # 该人脸的名字
#
# # 加载OpenCV人脸检测分类器
# face_cascade = cv2.CascadeClassifier(r"D:\Pycharm\project\protest3\haarcascade_frontalface_default.xml")
# recognizer = cv2.face.LBPHFaceRecognizer_create()  # 准备好识别方法LBPH方法
#
# camera = cv2.VideoCapture(0 ,cv2.CAP_DSHOW)  # 0:开启摄像头
# success, img = camera.read()  # 从摄像头读取照片
# W_size = 0.1 * camera.get(3)  # 在视频流的帧的宽度
# H_size = 0.1 * camera.get(4)  # 在视频流的帧的高度
#
#
# def get_face():
#     print("正在从摄像头录入新人脸信息 \n")
#     picture_num = 0  # 设置录入照片的初始值
#     while True:  # 从摄像头读取图片
#         global success  # 设置全局变量
#         global img  # 设置全局变量
#         ret, frame = camera.read()  # 获得摄像头读取到的数据(ret为返回值,frame为视频中的每一帧)
#         if ret is True:
#             gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # 转为灰度图片
#             cv2.imshow("gray",gray)
#         else:
#             break
#
#         face_detector = face_cascade  # 记录摄像头记录的每一帧的数据，让Classifier判断人脸
#         faces = face_detector.detectMultiScale(gray, 1.3, 5)  # gray是要灰度图像，1.3为每次图像尺寸减小的比例，5为minNeighbors
#
#         for (x, y, w, h) in faces:  # 制造一个矩形框选人脸(xy为左上角的坐标,w为宽，h为高)
#             cv2.rectangle(frame, (x, y), (x + w, y + w), (255, 0, 0))
#             picture_num += 1  # 照片数加一
#             t = face_name
#             print(r"C:\Users\HONOR\Desktop\data\1" + str(t) + '.' + str(picture_num))
#             cv2.imwrite(r"C:\Users\HONOR\Desktop\data\1" + str(t) + '.' + str(picture_num) + '.jpg', gray[y:y + h, x:x + w])
#             # 保存图像，将脸部的特征转化为二维数组，保存在data文件夹内
#         maximums_picture = 13  # 设置摄像头拍摄照片的数量的上限
#         if picture_num > maximums_picture:
#             break
#         cv2.waitKey(100)
#
#
# get_face()


# 9训练
# Train
# 2022/2/17
#

#
# import os
# import cv2
# from PIL import Image
# import numpy as np
#
#
# def getlable(path):
#     facesamples = []  # 储存人脸数据(该数据为二位数组)
#     ids = []  # 储存星门数据
#     imagepaths = [os.path.join(path, f) for f in os.listdir(path)]  # 储存图片信息
#     face_detector = cv2.CascadeClassifier(r"D:\Pycharm\project\protest3\haarcascade_frontalface_default.xml")  # 加载分类器
#     print('数据排列：', imagepaths)  # 打印数组imagepaths
#     for imagePath in imagepaths:  # 遍历列表中的图片
#         pil_img = Image.open(imagePath).convert('L')
#         # 打开图片，灰度化，PIL的两种不同模式：
#         # (1)1(黑白，有像素的地方为1，无像素的地方为0)
#         # (2)L(灰度图像，把每个像素点变成0~255的数值，颜色越深值越大)
#         img_numpy = np.array(pil_img, 'uint8')  # 将图像转化为数组
#         faces = face_detector.detectMultiScale(img_numpy)  # 获取人脸特征
#         id = int(os.path.split(imagePath)[1].split('.')[0])  # 获取每张图片的id和姓名
#         for x, y, w, h in faces:  # 预防无面容照片
#             ids.append(id)
#             facesamples.append(img_numpy[y:y + h, x:x + w])
#         # 打印脸部特征和id
#         print('id:', id)
#     print('fs:', facesamples)
#     return facesamples, ids
#
#
# if __name__ == '__main__':
#       # 图片路径
#     faces, ids = getlable(r"C:\Users\HONOR\Desktop\data")  # 获取图像数组和id标签数组和姓名
#     recognizer = cv2.face.LBPHFaceRecognizer_create()  # 获取训练对象
#     recognizer.train(faces, np.array(ids))
#     recognizer.write(r"D:\Pycharm\project\protest3\trainer.yml")  # 保存生成的人脸特征数据文件


# 10识别人脸
# Recognition
# 2022/2/17
#
# import cv2
# import os
#
# # 加载训练数据集文件
# recogizer = cv2.face.LBPHFaceRecognizer_create()
# recogizer.read(r"D:\Pycharm\project\protest3\trainer.yml")  # 获取脸部特征数据文件
# names = []
# warningtime = 0
#
#
# def face_detect_demo(img):
#     gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # 转换为灰度图像
#     face_detector = cv2.CascadeClassifier(r"D:\Pycharm\project\protest3\haarcascade_frontalface_default.xml")  # 加载分类器
#     face = face_detector.detectMultiScale(gray, 1.3, 5, cv2.CASCADE_SCALE_IMAGE, (100, 100), (300, 300))
#     # 进行识别，把整张人脸部分框起来
#     for x, y, w, h in face:
#         cv2.rectangle(img, (x, y), (x + w, y + h), color=(0, 0, 255), thickness=2)  # 矩形
#         cv2.circle(img, center=(x + w // 2, y + h // 2), radius=w // 2, color=(255, 0, 0), thickness=1)  # 圆形
#         ids, confidence = recogizer.predict(gray[y:y + h, x:x + w])  # 进行预测、评分
#         if confidence <90:
#             # global warningtime
#             # warningtime += 1
#             # if warningtime > 10:  # 警报达到一定次数，说明不是这个人
#             #     warningtime = 0
#             cv2.putText(img, 'unkonw', (x + 10, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 255, 0), 1)
#         else:
#             cv2.putText(img, 'lishan', (x + 10, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 255, 0), 1)
#             # 把姓名打到人脸的框图上
#         # print('names:', names)
#         # print('ids:', ids)
#     cv2.imshow('result', img)
#     # print('bug:',ids)
#
#
# def name():
#     path = r"C:\Users\HONOR\Desktop\data"
#     imagepaths = [os.path.join(path, f) for f in os.listdir(path)]
#     for imagePath in imagepaths:
#         name1 = str(os.path.split(imagePath)[1].split('.', 2)[1])
#         names.append(name1)
#
#
# cap = cv2.VideoCapture(0,cv2.CAP_DSHOW)
# name()
#
# while True:
#     flag, frame = cap.read()  # 获得摄像头读取到的数据(flag为返回值,frame为视频中的每一帧)
#     if not flag:
#         break
#
#     face_detect_demo(frame)
#     if ord(' ') == cv2.waitKey(10):  # 按空格，退出
#         break
# cv2.destroyAllWindows()
# cap.release()
# # print(names)


# 11获取人脸图片
#
# import cv2
# import dlib
# import os
# import sys
# import random
#
#
# # 存储位置
# output_dir = r"C:\Users\HONOR\Desktop\facetrain\3li"  # 这里填编号+人名
# size = 256  # 图片边长
#
# if not os.path.exists(output_dir):
#     os.makedirs(output_dir)
#
# # 改变图片的亮度与对比度
# def relight(img, light=1 ,bias=0):
#     w = img.shape[1]
#     h = img.shape[0]
#     for i in range(0, w):
#         for j in range(0, h):
#             for c in range(3):
#                 tmp = int(img[j, i, c] * light + bias)
#                 if tmp > 255:
#                     tmp = 255
#                 elif tmp < 0:
#                     tmp = 0
#                 img[j, i, c] = tmp
#     return img
#
#
# # 使用dlib自带的frontal_face_detector作为我们的特征提取器
# detector = dlib.get_frontal_face_detector()
# # 打开摄像头 参数为输入流，可以为摄像头或视频文件
# camera = cv2.VideoCapture(0)
# # camera = cv2.VideoCapture('C:/Users/CUNGU/Videos/Captures/wang.mp4')
#
# index = 1
# while True:
#     if index <=20:  # 存储15张人脸特征图像
#         print('Being processed picture %s' % index)
#         # 从摄像头读取照片
#         success, img = camera.read()
#         # 转为灰度图片
#         gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#         # 使用detector进行人脸检测
#         dets = detector(gray_img, 1)
#
#         for i, d in enumerate(dets):
#             x1 = d.top() if d.top() > 0 else 0
#             y1 = d.bottom() if d.bottom() > 0 else 0
#             x2 = d.left() if d.left() > 0 else 0
#             y2 = d.right() if d.right()> 0 else 0
#
#             face = img[x1:y1, x2:y2]
#             # 调整图片的对比度与亮度， 对比度与亮度值都取随机数，这样能增加样本的多样性
#             face = relight(face, random.uniform(0.5, 1.5), random.randint(-50, 50))
#
#             face = cv2.resize(face, (size, size))
#
#             cv2.imshow('image',face)
#
#             cv2.imwrite(output_dir + '/3li' + str(index) + '.jpg', face)
#
#             index += 1
#         key = cv2.waitKey(30) & 0xff
#         if key == 27:
#             break
#     else:
#         print('Finished!')
#         # 释放摄像头 release camera
#         camera.release()
#         # 删除建立的窗口 delete all the windows
#         cv2.destroyAllWindows()
#         break


#
# import cv2
# import dlib
# import os
# import sys
# import random
#
# # 存储位置
# output_dir = r"C:\Users\HONOR\Desktop\facetrain\3li"
# size = 64
#
# if not os.path.exists(output_dir):
#     os.makedirs(output_dir)
#
#
# # 改变图片的亮度与对比度
#
# def relight(img, light=1, bias=0):
#     w = img.shape[1]
#     h = img.shape[0]
#     # image = []
#     for i in range(0, w):
#         for j in range(0, h):
#             for c in range(3):
#                 tmp = int(img[j, i, c] * light + bias)
#                 if tmp > 255:
#                     tmp = 255
#                 elif tmp < 0:
#                     tmp = 0
#                 img[j, i, c] = tmp
#     return img
#
#
# # 使用dlib自带的frontal_face_detector作为我们的特征提取器
# detector = dlib.get_frontal_face_detector()
# # 打开摄像头 参数为输入流，可以为摄像头或视频文件
# camera = cv2.VideoCapture(0)
# # camera = cv2.VideoCapture('C:/Users/CUNGU/Videos/Captures/wang.mp4')
#
# index = 1
# while True:
#     if (index <= 15):  # 存储15张人脸特征图像
#         print('Being processed picture %s' % index)
#         # 从摄像头读取照片
#         success, img = camera.read()
#         # 转为灰度图片
#         gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#         # 使用detector进行人脸检测
#         dets = detector(gray_img, 1)
#
#         for i, d in enumerate(dets):
#             x1 = d.top() if d.top() > 0 else 0
#             y1 = d.bottom() if d.bottom() > 0 else 0
#             x2 = d.left() if d.left() > 0 else 0
#             y2 = d.right() if d.right() > 0 else 0
#
#             face = img[x1:y1, x2:y2]
#             # 调整图片的对比度与亮度， 对比度与亮度值都取随机数，这样能增加样本的多样性
#             face = relight(face, random.uniform(0.5, 1.5), random.randint(-50, 50))
#
#             face = cv2.resize(face, (size, size))
#
#             cv2.imshow('image', face)
#
#             cv2.imwrite(output_dir + '/' + str(index) + '.jpg', face)
#
#             index += 1
#         key = cv2.waitKey(30) & 0xff
#         if key == 27:
#             break
#     else:
#         print('Finished!')
#         # 释放摄像头 release camera
#         camera.release()
#         # 删除建立的窗口 delete all the windows
#         cv2.destroyAllWindows()
#         break


# import cv2
#
# import os
# import dlib
# from skimage import io
# import csv
# import numpy as np
#
# # 要读取人脸图像文件的路径
# path_images_from_camera = r"C:\Users\HONOR\Desktop\facetrain"
#
# # Dlib 正向人脸检测器
# detector = dlib.get_frontal_face_detector()
#
# # Dlib 人脸预测器
# predictor = dlib.shape_predictor(r"D:\Pycharm\project\protest3\shape_predictor_68_face_landmarks.dat\shape_predictor_68_face_landmarks.dat")
#
# # Dlib 人脸识别模型
# # Face recognition model, the object maps human faces into 128D vectors
# face_rec = dlib.face_recognition_model_v1( r"D:\Pycharm\project\protest3\dlib_face_recognition_resnet_model_v1.dat\dlib_face_recognition_resnet_model_v1.dat")
#
#
# # 返回单张图像的 128D 特征
# def return_128d_features(path_img):
#     img_rd = io.imread(path_img)
#     img_gray = cv2.cvtColor(img_rd, cv2.COLOR_BGR2RGB)
#     faces = detector(img_gray, 1)
#
#     print("%-40s %-20s" % ("检测到人脸的图像 / image with faces detected:", path_img), '\n')
#
#     # 因为有可能截下来的人脸再去检测，检测不出来人脸了
#     # 所以要确保是 检测到人脸的人脸图像 拿去算特征
#     if len(faces) != 0:
#         shape = predictor(img_gray, faces[0])
#         face_descriptor = face_rec.compute_face_descriptor(img_gray, shape)
#     else:
#         face_descriptor = 0
#         print("no face")
#
#     return face_descriptor
#
#
# # 将文件夹中照片特征提取出来, 写入 CSV
# def return_features_mean_personX(path_faces_personX):
#     features_list_personX = []
#     photos_list = os.listdir(path_faces_personX)
#     if photos_list:
#         for i in range(len(photos_list)):
#             # 调用return_128d_features()得到128d特征
#             print("%-40s %-20s" % ("正在读的人脸图像 / image to read:", path_faces_personX + "/" + photos_list[i]))
#             features_128d = return_128d_features(path_faces_personX + "/" + photos_list[i])
#             #  print(features_128d)
#             # 遇到没有检测出人脸的图片跳过
#             if features_128d == 0:
#                 i += 1
#             else:
#                 features_list_personX.append(features_128d)
#     else:
#         print("文件夹内图像文件为空 / Warning: No images in " + path_faces_personX + '/', '\n')
#
#     # 计算 128D 特征的均值
#     # N x 128D -> 1 x 128D
#     if features_list_personX:
#         features_mean_personX = np.array(features_list_personX).mean(axis=0)
#     else:
#         features_mean_personX = '0'
#
#     return features_mean_personX
#
#
# # 读取某人所有的人脸图像的数据
# people = os.listdir(path_images_from_camera)
# people.sort()
#
# with open("C:/Users/HONOR/Desktop/feature/features2_all.csv", "w", newline="") as csvfile:
#     writer = csv.writer(csvfile)
#     for person in people:
#         print("##### " + person + " #####")
#         # Get the mean/average features of face/personX, it will be a list with a length of 128D
#         features_mean_personX = return_features_mean_personX(path_images_from_camera + '/' + person)
#         writer.writerow(features_mean_personX)
#         print("特征均值 / The mean of features:", list(features_mean_personX))
#         print('\n')
#     print("所有录入人脸数据存入 / Save all the features of faces registered into: C:/Users/HONOR/Desktop/feature/features2_all.csv")
# #


# 主程序
# 摄像头实时进行人脸识别
import os
import cv2
import winsound  # 系统音效
# from playsound import playsound  # 音频播放
import dlib  # 人脸处理的库 Dlib
import csv  # 存入表格
import time
import sys
import numpy as np  # 数据处理的库 numpy
# from cv2 import cv2 as cv2  # 图像处理的库 OpenCv
import pandas as pd  # 数据处理的库 Pandas
import serial.tools.list_ports

# 人脸识别模型，提取128D的特征矢量
# face recognition model, the object maps human faces into 128D vectors
# Refer this tutorial: http://dlib.net/python/index.html#dlib.face_recognition_model_v1
facerec = dlib.face_recognition_model_v1(
    r"D:\Pycharm\project\protest3\dlib_face_recognition_resnet_model_v1.dat\dlib_face_recognition_resnet_model_v1.dat")
ports_list = list(serial.tools.list_ports.comports())
port_num = ports_list[0][0]
ser = serial.Serial(port=port_num, baudrate=115200, bytesize=serial.EIGHTBITS, stopbits=serial.STOPBITS_ONE,
                    parity=serial.PARITY_NONE, timeout=0.5)
data1 = bytearray([0xaa, 0x06, 0xb1, 0x12, 0x0d, 0x0e])
data2 = bytearray([0xaa, 0x06, 0xa1, 0x02, 0x0d, 0x0e])


# 计算两个128D向量间的欧式距离
# compute the e-distance between two 128D features
def return_euclidean_distance(feature_1, feature_2):
    feature_1 = np.array(feature_1)
    feature_2 = np.array(feature_2)
    dist = np.sqrt(np.sum(np.square(feature_1 - feature_2)))
    return dist


# 处理存放所有人脸特征的 csv
path_features_known_csv = "C:/Users/HONOR/Desktop/feature/features2_all.csv"
csv_rd = pd.read_csv(path_features_known_csv, header=None)

# 用来存放所有录入人脸特征的数组
# the array to save the features of faces in the database
features_known_arr = []

# 读取已知人脸数据
# print known faces
for i in range(csv_rd.shape[0]):
    features_someone_arr = []
    for j in range(0, len(csv_rd.loc[i, :])):
        features_someone_arr.append(csv_rd.loc[i, :][j])
    features_known_arr.append(features_someone_arr)
print("Faces in Database：", len(features_known_arr))

# Dlib 检测器和预测器
# The detector and predictor will be used
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor(
    r"D:\Pycharm\project\protest3\shape_predictor_68_face_landmarks.dat\shape_predictor_68_face_landmarks.dat")

# 创建 cv2 摄像头对象
# cv2.VideoCapture(0) to use the default camera of PC,
# and you can use local video name by use cv2.VideoCapture(filename)
cap = cv2.VideoCapture(0)

# cap.set(propId, value)
# 设置视频参数，propId 设置的视频参数，value 设置的参数值
cap.set(3, 480)

# cap.isOpened() 返回 true/false 检查初始化是否成功
# when the camera is open
while cap.isOpened():

    flag, img_rd = cap.read()
    kk = cv2.waitKey(1)

    # 取灰度
    img_gray = cv2.cvtColor(img_rd, cv2.COLOR_RGB2GRAY)

    # 人脸数 faces
    faces = detector(img_gray, 0)

    # 待会要写的字体 font to write later
    font = cv2.FONT_HERSHEY_COMPLEX

    # 存储当前摄像头中捕获到的所有人脸的坐标/名字
    # the list to save the positions and names of current faces captured
    pos_namelist = []
    name_namelist = []
    # 按下 q 键退出
    # press 'q' to exit
    if kk == ord('q'):
        break
    else:
        # 检测到人脸 when face detected
        if len(faces) != 0:
            # 获取当前捕获到的图像的所有人脸的特征，存储到 features_cap_arr
            # get the features captured and save into features_cap_arr
            features_cap_arr = []
            for i in range(len(faces)):
                shape = predictor(img_rd, faces[i])
                features_cap_arr.append(facerec.compute_face_descriptor(img_rd, shape))

            # 遍历捕获到的图像中所有的人脸
            # traversal all the faces in the database
            for k in range(len(faces)):
                print("##### camera person", k + 1, "#####")
                # 让人名跟随在矩形框的下方
                # 确定人名的位置坐标
                # 先默认所有人不认识，是 unknown
                # set the default names of faces with "unknown"
                name_namelist.append("unknown")

                # 每个捕获人脸的名字坐标 the positions of faces captured
                pos_namelist.append(
                    tuple([faces[k].left(), int(faces[k].bottom() + (faces[k].bottom() - faces[k].top()) / 4)]))

                # 对于某张人脸，遍历所有存储的人脸特征
                # for every faces detected, compare the faces in the database
                e_distance_list = []
                for i in range(len(features_known_arr)):
                    # 如果 person_X 数据不为空
                    if str(features_known_arr[i][0]) != '0.0':
                        print("with person", str(i + 1), "the e distance: ", end='')
                        e_distance_tmp = return_euclidean_distance(features_cap_arr[k], features_known_arr[i])
                        print(e_distance_tmp)
                        e_distance_list.append(e_distance_tmp)
                    else:
                        # 空数据 person_X
                        e_distance_list.append(999999999)
                # 找出最接近的一个人脸数据是第几个
                # Find the one with minimum e distance
                similar_person_num = e_distance_list.index(min(e_distance_list))
                print("Minimum e distance with person", int(similar_person_num) + 1)

                # 计算人脸识别特征与数据集特征的欧氏距离
                # 距离小于0.4则标出为可识别人物
                if min(e_distance_list) < 0.4:
                    # 这里可以修改摄像头中标出的人名
                    # Here you can modify the names shown on the camera
                    # 1、遍历文件夹目录
                    folder_name = r"C:\Users\HONOR\Desktop\facetrain"
                    # 最接近的人脸
                    sum = similar_person_num + 1
                    key_id = 1  # 从第一个人脸数据文件夹进行对比
                    # 获取文件夹中的文件名:1wang、2zhou、3...
                    file_names = os.listdir(folder_name)
                    for name in file_names:
                        # print(name+'->'+str(key_id))
                        if sum == key_id:
                            # winsound.Beep(300,500)# 响铃：300频率，500持续时间
                            name_namelist[k] = name[1:]  # 人名删去第一个数字（用于视频输出标识）
                        key_id += 1
                    time.sleep(0.1)
                    write_len = ser.write(data1)
                    print("发送数据: %s" % data1)
                    time.sleep(0.1)
                    # -----------筛选出人脸并保存到visitor文件夹------------
                    for i, d in enumerate(faces):
                        x1 = d.top() if d.top() > 0 else 0
                        y1 = d.bottom() if d.bottom() > 0 else 0
                        x2 = d.left() if d.left() > 0 else 0
                        y2 = d.right() if d.right() > 0 else 0
                        face = img_rd[x1:y1, x2:y2]
                        size = 64
                        face = cv2.resize(face, (size, size))
                        # 要存储visitor人脸图像文件的路径
                        path_visitors_save_dir = "C:/Users/HONOR/Desktop/facetrain/visitor/known"
                        # 存储格式：2019-06-24-14-33-40wang.jpg
                        now_time = time.strftime("%Y-%m-%d-%H-%M-%S", time.localtime())
                        save_name = str(now_time) + str(name_namelist[k]) + '.jpg'
                        # print(save_name)
                        # 本次图片保存的完整url
                        save_path = path_visitors_save_dir + '/' + save_name
                        # 遍历visitor文件夹所有文件名
                        visitor_names = os.listdir(path_visitors_save_dir)
                        visitor_name = ''
                        for name in visitor_names:
                            # 名字切片到分钟数：2019-06-26-11-33-00wangyu.jpg
                            visitor_name = (name[0:16] + '-00' + name[19:])
                        # print(visitor_name)
                        visitor_save = (save_name[0:16] + '-00' + save_name[19:])
                        # print(visitor_save)
                        # 一分钟之内重复的人名不保存
                        if visitor_save != visitor_name:
                            cv2.imwrite(save_path, face)
                            print('新存储：' + path_visitors_save_dir + '/' + str(now_time) + str(
                                name_namelist[k]) + '.jpg')
                        else:
                            print('重复，未保存！')

                else:

                    time.sleep(0.1)
                    write_len = ser.write(data2)
                    print("发送数据: %s" % data2)
                    time.sleep(0.1)
                    print("Unknown person")
                    # -----保存图片-------
                    # -----------筛选出人脸并保存到visitor文件夹------------
                    for i, d in enumerate(faces):
                        x1 = d.top() if d.top() > 0 else 0
                        y1 = d.bottom() if d.bottom() > 0 else 0
                        x2 = d.left() if d.left() > 0 else 0
                        y2 = d.right() if d.right() > 0 else 0
                        face = img_rd[x1:y1, x2:y2]
                        size = 64
                        face = cv2.resize(face, (size, size))
                        # 要存储visitor-》unknown人脸图像文件的路径
                        path_visitors_save_dir = "C:/Users/HONOR/Desktop/facetrain/visitor/unknown"
                        # 存储格式：2019-06-24-14-33-40unknown.jpg
                        now_time = time.strftime("%Y-%m-%d-%H-%M-%S", time.localtime())
                        # print(save_name)
                        # 本次图片保存的完整url
                        save_path = path_visitors_save_dir + '/' + str(now_time) + 'unknown.jpg'
                        cv2.imwrite(save_path, face)
                        print('新存储：' + path_visitors_save_dir + '/' + str(now_time) + 'unknown.jpg')

                # 矩形框
                # draw rectangle
                for kk, d in enumerate(faces):
                    # 绘制矩形框
                    cv2.rectangle(img_rd, tuple([d.left(), d.top()]), tuple([d.right(), d.bottom()]), (0, 255, 255), 2)
                print('\n')

            # 在人脸框下面写人脸名字
            # write names under rectangle
            for i in range(len(faces)):
                cv2.putText(img_rd, name_namelist[i], pos_namelist[i], font, 0.8, (0, 255, 255), 1, cv2.LINE_AA)

    print("Faces in camera now:", name_namelist, "\n")

    # cv2.putText(img_rd, "Press 'q': Quit", (20, 450), font, 0.8, (84, 255, 159), 1, cv2.LINE_AA)
    cv2.putText(img_rd, "Face Recognition", (20, 40), font, 1, (0, 0, 255), 1, cv2.LINE_AA)
    cv2.putText(img_rd, "Visitors: " + str(len(faces)), (20, 100), font, 1, (0, 0, 255), 1, cv2.LINE_AA)

    # 窗口显示 show with opencv
    cv2.imshow("camera", img_rd)

# 释放摄像头 release camera
cap.release()

# 删除建立的窗口 delete all the windows
cv2.destroyAllWindows()
