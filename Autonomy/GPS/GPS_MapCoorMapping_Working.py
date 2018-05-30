import cv2
import numpy as np

map_img_o = cv2.imread("Map_IC_Chem2.png")
sat_img_o = cv2.imread("Sat_IC_Chem2.png")

li = [ [], [((11,9),(47,37)),((48,9),(103,37))] ] #Dots (coordinates) #rectangles (Gui and Robot)

# mouse callback function
def map_coor(event,x,y,flags,param):
    if event == cv2.EVENT_LBUTTONDBLCLK:
        li[0].append( (x,y) )
        
def draw_li(li):
       for a in range( 0, len(li[0])):
              cv2.circle(map_img_o,(li[0][a][0],li[0][a][1]),5,(255,0,0),-1)
              cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)

       for a in range( 0, len(li[1])):
              cv2.rectangle(map_img_o,(li[1][a][0][0],li[1][a][0][1]),(li[1][a][1][0],li[1][a][1][1]),(510,128),(0,255,0),3)
        
cv2.imshow("Map",map_img_o)
cv2.imshow("Sat",sat_img_o)

map_img = map_img_o
sat_img = sat_img_o

cv2.namedWindow('Map')
cv2.setMouseCallback('Map',map_coor)

while(1):
       draw_li(li)
       cv2.imshow("Map",map_img_o)
       cv2.imshow("Sat",sat_img_o)

       map_img = map_img_o
       sat_img = sat_img_o

       if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    


cap.release()
cv2.destroyAllWindows()
