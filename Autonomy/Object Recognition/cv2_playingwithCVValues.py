import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while(1):
    fgbg = cv2.createBackgroundSubtractorMOG2()
    # Take each frame
    _, frame = cap.read()
    fgmask = fgbg.apply(frame)
    # Convert BGR to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV_FULL)

    cv2.imshow('',hsv)
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
