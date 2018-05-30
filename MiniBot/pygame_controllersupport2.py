import pygame
pygame.init()

def pwmConversion(input_pwm):
       return((input_pwm * -127.5) + 127.5)

def main(): 
    screen = pygame.display.set_mode((100,100))
    pygame.display.set_caption("Joystick Testing / XBOX360 Controller")
 

 
    joysticks = []
    clock = pygame.time.Clock()
    keepPlaying = True
 
    # for all the connected joysticks
    for i in range(0, pygame.joystick.get_count()):
        # create an Joystick object in our list
        joysticks.append(pygame.joystick.Joystick(i))
        # initialize them all (-1 means loop forever)
        joysticks[-1].init()
        # print a statement telling what the name of the controller is
        print ("Detected joystick '",joysticks[-1].get_name(),"'")
    while keepPlaying:
        clock.tick(60)
        for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    print("Received event 'Quit', exiting.")
                    keepPlaying = False
                elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                    print("Escape key pressed, exiting.")
                    keepPlaying = False
                elif event.type == pygame.KEYDOWN:
                    print("Keydown,", event.key)
                elif event.type == pygame.KEYUP:
                    print("Keyup,", event.key)
                #elif event.type == pygame.MOUSEMOTION:
                 #   print("Mouse movement detected."
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    print("Mouse button",event.button,"down at",pygame.mouse.get_pos())
                elif event.type == pygame.MOUSEBUTTONUP:
                    print ("Mouse button",event.button,"up at",pygame.mouse.get_pos())
                elif event.type == pygame.JOYAXISMOTION:
                    print("Joystick '",joysticks[event.joy].get_name(),"' axis",event.axis,"motion.", pwmConversion(round( 10 * joysticks[event.joy].get_axis(event.axis) )/10 ) )
                elif event.type == pygame.JOYBUTTONDOWN:
                    print("Joystick '",joysticks[event.joy].get_name(),"' button",event.button,"down.")
                    if event.button == 0:
                        pass
                    elif event.button == 1:
                        pass
                elif event.type == pygame.JOYBUTTONUP:
                    print("Joystick '",joysticks[event.joy].get_name(),"' button",event.button,"up.")
                    if event.button == 0:
                        pass
                    elif event.button == 1:
                        pass
                elif event.type == pygame.JOYHATMOTION:
                    print("Joystick '",joysticks[event.joy].get_name(),"' hat",event.hat," moved.",joysticks[event.joy].get_hat(event.hat))
                     
 
main()
pygame.quit()
