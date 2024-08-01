import cv2
import numpy as np
import matplotlib.pyplot as plt

img=cv2.imread("arjun.jpg")
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

blurred=cv2.GaussianBlur(gray,(5,5),0)

thresh=cv2.adaptiveThreshold(blurred,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV,15,4)

contours,hierarchy=cv2.findContours(thresh,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(img,contours,-1,(0,255,0),2)
imgrgb=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

plt.imshow(imgrgb)
plt.title("Contour Detection")
plt.axis("off")
plt.show()