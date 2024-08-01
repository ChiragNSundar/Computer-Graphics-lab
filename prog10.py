import cv2
import numpy as np
import matplotlib.pyplot as plt

img=cv2.imread("arjun.jpg")

gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

gaussianblur=cv2.GaussianBlur(gray,(5,5),0)

bilateralfilter=cv2.bilateralFilter(gray,9,75,75)

plt.figure(figsize=(25,10))
plt.subplot(1,3,1)
plt.imshow(gray,cmap="gray")
plt.title("Gray Image original")
plt.axis("off")

plt.subplot(1,3,2)
plt.imshow(gaussianblur,cmap="gray")
plt.title("Gaussian Blur")
plt.axis("off")

plt.subplot(1,3,3)
plt.imshow(bilateralfilter,cmap="gray")
plt.title("Bilateral Filter Smoothing")
plt.axis("off")

plt.show()