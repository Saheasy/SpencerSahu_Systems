import pygame
import serial

pygame.init()
ser = serial.Serial('/dev/ttyACM0', 9600)
li_data = [0,0,0] #li_data[0] = Auto/Teleop li_data[1] = Lattitude/LeftYJoystick li_data[2] = Longitude/RightYJoystick
GPS_coor = [(0,0),(0,0),(0,0),(0,0)] #Right, Left, Up, Down


def strConversion(li):
    str_data = ""
    for x in range(0,3):
		if x != 2:
			str_data += str(x) + ","
        else:
            str_data += str(x)
    return(str_data)

def pwmConversion(input_pwm):
    return(input_pwm * -255)

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
        #print ("Detected joystick '",joysticks[-1].get_name(),"'")
    while keepPlaying:
        clock.tick(60)
        for event in pygame.event.get():
			if event.type == pygame.QUIT:
                #print("Received event 'Quit', exiting.")
				keepPlaying = False
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                #print("Escape key pressed, exiting.")
                keepPlaying = False
            elif event.type == pygame.KEYDOWN:
                #print("Keydown,", event.key)
            elif event.type == pygame.KEYUP:
                #print("Keyup,", event.key)
            elif event.type == pygame.MOUSEBUTTONDOWN:
                #print("Mouse button",event.button,"down at",pygame.mouse.get_pos())
            elif event.type == pygame.MOUSEBUTTONUP:
                #print ("Mouse button",event.button,"up at",pygame.mouse.get_pos())
            elif event.type == pygame.JOYAXISMOTION:
                #print("Joystick '",joysticks[event.joy].get_name(),"' axis",event.axis,"motion.", pwmConversion(round( 10 * joysticks[event.joy].get_axis(event.axis) )/10 ) )
            elif event.type == pygame.JOYBUTTONDOWN:
                #print("Joystick '",joysticks[event.joy].get_name(),"' button",event.button,"down.")
                if event.button == 0:
                    li_data[0] = 0 #Pressing Button 1 enables FULL TELEOPERATIONAL mode
                elif event.button == 1:
                    li_data[0] = 1 #Pressing Button2 enables SEMI AUTONOMOUS mode 
            elif event.type == pygame.JOYBUTTONUP:
                #print("Joystick '",joysticks[event.joy].get_name(),"' button",event.button,"up.")
                if event.button == 0:
                    pass
                elif event.button == 1:
                    pass
					
            elif event.type == pygame.JOYHATMOTION:
                #print("Joystick '",joysticks[event.joy].get_name(),"' hat",event.hat," moved.",joysticks[event.joy].get_hat(event.hat))
                    if li_data[0] == 1: # When the SEMI AUTONOMOUS mode is active, the robot shall go to the coordinates
                        if joysticks[event.joy].get_hat(event.hat)[1] == 1: #Right Dpad
							li_data[1],li_data[2] = GPS_coor[0]
                        if joysticks[event.joy].get_hat(event.hat)[1] == -1: #Left Dpad
                            li_data[1],li_data[2] = GPS_coor[1]
						if joysticks[event.joy].get_hat(event.hat)[2] == 1: #Up Dpad
							li_data[1],li_data[2] = GPS_coor[2]
                        if joysticks[event.joy].get_hat(event.hat)[2] == -1: #Down Dpad
                            li_data[1],li_data[2] = GPS_coor[3]
        
		#ser.write((bytes(strConversion(li_data)), "utf-8"))
 
main()
pygame.quit()
