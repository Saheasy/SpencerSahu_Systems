import cv2
import numpy as np

map_img_o = cv2.imread("C:\\Users\\Sahea\\Desktop\\UI_Robotics\\Spencer Sahu Systems\\Autonomy\\GPS\\Map_IC_Chem2")
sat_img_o = cv2.imread("C:\\Users\\Sahea\\Desktop\\UI_Robotics\\Spencer Sahu Systems\\Autonomy\\GPS\\Sat_IC_Chem2")


map_img = map_img_o
sat_img = sat_img_o

x = 0
while(1):
       x = x + 1
       cv2.circle(map_img,(x,0), 0, (0,0,255), -1)
       
       cv2.imshow("Map",map_img_o)
       cv2.imshow("Sat",sat_img_o)

       map_img = map_img_o
       sat_img = sat_img_o

       if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    


cap.release()
cv2.destroyAllWindows()
