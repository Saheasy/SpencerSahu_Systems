import numpy as np
import cv2
from matplotlib import pyplot as plt

#Messed up the file names
imgL = cv2.imread('right6.jpg',0)
imgR = cv2.imread('left6.jpg',0) 

stereo = cv2.StereoBM_create(numDisparities=16, blockSize=19)
disparity1 = stereo.compute(imgL, imgR)
plt.imshow(disparity1,'gray')
plt.show()


