#include <AccelStepper>

int dirPin_BaseStepper = 12;
int pulPin_BaseStepper = 10;
int pwmPin_CenterLinear = 13; //Center Linear Actuator
int pwm_CenterLinear = 0;

int pwmPin_ForwardLinear = 11;
int pwm_ForwardLinear = 0;

int pwmPin_DrillMotor = 9;
int pwm_DrillMotor = 0;

int key_pressed;
AccelStepper Base(1,pulPin_BaseStepper,dirPin_BaseStepper);

int StepPos = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pwmPin_CenterLinear, OUTPUT); //pwm input
  pinMode(pwmPin_ForwardLinear, OUTPUT); //pwm input
  pinMode(pwmPin_DrillMotor, OUTPUT); //pwm input
  Base.setMaxSpeed(2000);
  Base.setSpeed(80);
  Base.setAcceleration(800);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  keyInput(); 
  analogWrite(pwmPin_CenterLinear, pwm_CenterLinear);
  analogWrite(pwmPin_ForwardLinear, pwm_ForwardLinear);
  analogWrite(pwmPin_DrillMotor, pwm_DrillMotor);
  Base.runSpeedToPosition();
  
}

void keyInput()
{
  if (Serial.available())
  {
    key_pressed = Serial.read();
    if (key_pressed == 's')
    {
      StepPos = 0;
      Base.moveTo(StepPos);
    }
    if (key_pressed == 'a')
    {
      StepPos+= 150;
      Base.moveTo(StepPos);
    }
    if (key_pressed == 'd')
    {
      StepPos-= 150;
      Base.moveTo(StepPos);
    }
    if (key_pressed == '0')
    {
      pwm_CenterLinear = 127;
      pwm_ForwardLinear = 127;
    }
    if (key_pressed == 'n')
    {
      pwm_CenterLinear == 0;
    }
    if (key_pressed == 'm')
    {
      pwm_CenterLinear = 63.5;
    }
    if (key_pressed == ',')
    {
      pwm_CenterLinear = 127;
    }
    if (key_pressed == '.')
    {
      pwm_CenterLinear =190.5;
    }
    if (key_pressed == '/')
    {
      pwm_CenterLinear = 255;
    }
    if (key_pressed == 'h')
    {
      pwm_ForwardLinear = 0;
    }
    if (key_pressed == 'j')
    {
      pwm_ForwardLinear = 63.5;
    }
    if (key_pressed == 'k')
    {
      pwm_ForwardLinear = 127;
    }
    if (key_pressed == 'l')
    {
      pwm_ForwardLinear = 190.5;
    }
    if (key_pressed == ';')
    {
      pwm_ForwardLinear = 255;
    }
    if (key_pressed == 'u')
    {
     pwm_DrillMotor = 0;
    }
    if (key_pressed == 'i')
    {
      pwm_DrillMotor = 63.5;
    }
    if (key_pressed == 'o')
    {
      pwm_DrillMotor = 127;
    }
    if (key_pressed == 'p')
    {
      pwm_DrillMotor = 190.5;
    }
    if (key_pressed == '[')
    {
      pwm_DrillMotor = 255;
    }
    
  }
}



