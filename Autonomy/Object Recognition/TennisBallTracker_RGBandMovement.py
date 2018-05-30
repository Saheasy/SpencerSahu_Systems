
import cv2
import numpy as np
yellow = [[30, 30, 30],[55,255,255]]
brown = [[0, 30, 20],[30,255,255]]
blue = [[100, 20, 20],[200,255,255]]

lowerBound=np.array(yellow[0])
upperBound=np.array(yellow[1])

cam= cv2.VideoCapture(0)
fgbg = cv2.createBackgroundSubtractorMOG2()

kernelOpen=np.ones((5,5))
kernelClose=np.ones((20,20))

font = cv2.FONT_HERSHEY_PLAIN
while 1:
    ret, img=cam.read()
    img=cv2.resize(img,(480,480))
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (21, 21), 0)
    fgmask = fgbg.apply(gray)
    #convert BGR to HSV
    imgHSV= cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    # create the Mask
    mask=cv2.inRange(imgHSV,lowerBound,upperBound)
    #morphology
    maskOpen=cv2.morphologyEx(mask,cv2.MORPH_OPEN,kernelOpen)
    maskClose=cv2.morphologyEx(maskOpen,cv2.MORPH_CLOSE,kernelClose)
    
    maskFinal=maskClose
    _,conts,h = cv2.findContours(maskFinal.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
    _,conts2,h2 = cv2.findContours(fgmask.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    
    cv2.drawContours(img,conts,-1,(255,255,0),3)
    for c in conts2:
        if (cv2.contourArea(c) > 10):
            
            
            x,y,w,h=cv2.boundingRect(c)
            
            
            cv2.putText(fgmask, 'Moving',(x,y+h),font,0.5,(255,255,255),1,cv2.LINE_AA)
            ballmoving1 = True
        else:
            ballmoving1 = False
            
    for c in conts:
        if (cv2.contourArea(c) > 400):
            
            x,y,w,h=cv2.boundingRect(c)
            cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255), 2)
            cv2.putText(img, 'Ball',(x,y+h),font,2,(255,0,0),2,cv2.LINE_AA)
            ballmoving2 = True
            if ballmoving1 and ballmoving2:
                cv2.putText(img, 'Moving',(x,(y+15)+h),font,1,(255,0,0),2,cv2.LINE_AA)
        else:
            ballmoving2 = False
            
    cv2.imshow("maskClose",maskClose)
    cv2.imshow("maskOpen",maskOpen)
    cv2.imshow("fgmask",fgmask)
    cv2.imshow("mask",mask)
    cv2.imshow("cam",img)
    cv2.waitKey(10)
