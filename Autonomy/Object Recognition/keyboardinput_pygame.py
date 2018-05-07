import  pygame, sys
from pygame.locals import*
print("esc key to exit the game window must be focused for this to work")
while True:
    DISPLAYSURF = pygame.display.set_mode((50,10)) 
    while True:                          
        for event in pygame.event.get():
            if event.type == QUIT:       
                pygame.quit()            
                sys.exit()               
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    pygame.quit()        
                    sys.exit()           
                print(event.key, end=" ")
#               print(event.key)         
