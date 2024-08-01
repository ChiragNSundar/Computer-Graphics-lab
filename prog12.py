import cv2
import matplotlib.pyplot as plt

faces=cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_frontalface_default.xml")
eyes=cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_eye.xml")

img=cv2.imread("arjun.jpg")

gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

face=faces.detectMultiScale(gray,scaleFactor=1.3,minNeighbors=5)

for (x,y,w,h) in face:
    cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)

img_rgb=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

plt.imshow(img_rgb)
plt.title("Face Detection")
plt.axis("off")
plt.show()