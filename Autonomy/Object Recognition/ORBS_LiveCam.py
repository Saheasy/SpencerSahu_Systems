import cv2
import numpy as np

cam= cv2.VideoCapture(0)

while 1:
       ret, img=cam.read()
       gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
       orb = cv2.ORB_create(nfeatures=1500)
       keypoints, descriptors = orb.detectAndCompute(img, None)
 
       img = cv2.drawKeypoints(img, keypoints, None)
 
       cv2.imshow("Image", img)
       cv2.imshow("Image1", gray)
       cv2.waitKey(10)
cv2.destroyAllWindows()
