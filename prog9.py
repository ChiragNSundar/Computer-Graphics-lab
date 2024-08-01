import cv2
import numpy as np
import matplotlib.pyplot as plt

img=cv2.imread("arjun.jpg")
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

edges=cv2.Canny(gray,100,200)

kernel=np.ones((5,5),np.float32)/25
texture=cv2.filter2D(gray,-1,kernel)

plt.figure(figsize=(25,10))

plt.subplot(1,3,1)
plt.imshow(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
plt.title("Original Image")
plt.axis("off")

plt.subplot(1,3,2)
plt.imshow(edges,cmap="gray")
plt.title("Edge Detection")
plt.axis("off")

plt.subplot(1,3,3)
plt.imshow(texture,cmap="gray")
plt.title("Texture Detection")
plt.axis("off") 

plt.show()