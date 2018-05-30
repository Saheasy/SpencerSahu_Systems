import pygame, sys
from pygame.locals import *

GREEN = (0, 255, 0)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

pygame.init()

windowSurface = pygame.display.set_mode((800, 600), 0, 32)

### Tells the number of joysticks/error detection
joystick_count = pygame.joystick.get_count()
print ("There is ", joystick_count, "joystick/s")
if joystick_count == 0:
    print ("Error, I did not find any joysticks")
else:
    my_joystick = pygame.joystick.Joystick(0)
    my_joystick.init()

crosshairs = pygame.image.load("crosshairs.png")

x = 300
y = 300
### Creates rectangle
Rectangle = pygame.Rect( x, y, 10, 10)
Back = pygame.Rect(0, 0, 3264, 2448)


while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    h_axis_pos = round(my_joystick.get_axis(0)*10)/10
    v_axis_pos = round(my_joystick.get_axis(1)*10)/10
    print(h_axis_pos,v_axis_pos,x,y)
    if x < 0:
        x = 1
    elif x > 700:
        x = 700
    else:    
        x = int(x + h_axis_pos * 5)

    if y < 0:
        y = 0
    elif y > 500:
        y = 500
    else: 
        y = int(y + v_axis_pos * 5)

    Rectangle.left = x
    Rectangle.top = y
    
    windowSurface.fill(WHITE)
    
    #windowSurface.blit(background, Back)
    
    windowSurface.blit(crosshairs, Rectangle)
        
    pygame.display.update()
 
