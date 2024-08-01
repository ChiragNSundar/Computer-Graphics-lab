import cv2
import numpy as np
import matplotlib.pyplot as plt

def translate_image(image,dx,dy):
    rows,cols=image.shape[:2]
    translationmatrix=np.float32([[1,0,dx],[0,1,dy]])
    translatedimage=cv2.warpAffine(image,translationmatrix,(cols,rows))
    return translatedimage

img=cv2.imread("arjun.jpg")
imgrgb=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
height,width=img.shape[:2]
center=(width//2,height//2)
rotationvalue=100 
scalingvalue=1.5

rotated=cv2.getRotationMatrix2D(center=center,angle=rotationvalue,scale=1)
rotatedimage=cv2.warpAffine(src=img,M=rotated,dsize=(width,height))

scaled=cv2.getRotationMatrix2D(center=center,angle=0,scale=scalingvalue)
scaledimage=cv2.warpAffine(src=rotatedimage,M=scaled,dsize=(width,height))    

h=5
v=5 

translatedimage=translate_image(scaledimage,dx=h,dy=v)
translatedimgrgb=cv2.cvtColor(translatedimage,cv2.COLOR_BGR2RGB)
cv2.imwrite('FinalImage.jpg',translatedimage)

plt.figure(figsize=(25,10))
plt.subplot(1,3,1)
plt.imshow(imgrgb)
plt.title("Original Image")
plt.axis("off")

plt.subplot(1,3,2)
plt.imshow(translatedimgrgb)
plt.title("Transformed Image")
plt.axis("off")

plt.show()


