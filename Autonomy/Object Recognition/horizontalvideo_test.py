import numpy as np
import cv2
 
cap = cv2.VideoCapture(0)
while(1):
    _, frame = cap.read()
    rgba = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    rgbaflip = cv2.flip( rgba, 1 )
    cv2.imshow( "Horizontal flip", rgbaflip )
    cv2.imshow( "noFlip", rgba )
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cv2.waitKey(0)
 
cv2.destroyAllWindows()
