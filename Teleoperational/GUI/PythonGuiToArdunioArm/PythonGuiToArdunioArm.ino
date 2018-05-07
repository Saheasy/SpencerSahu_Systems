#include <AccelStepper.h>

int dirPin_BaseStepper = 12;
int pulPin_BaseStepper = 10;
int pwmPin_CenterLinear = 13; //Center Linear Actuator
int pwm_CenterLinear = 0;

int pwmPin_ForwardLinear = 11;
int pwm_ForwardLinear = 0;

int pwmPin_DrillMotor = 9;
int pwm_DrillMotor = 0;

int input[4];
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
    input = Serial.read();
    pwm_CenterLinear = input[0]
    pwm_ForardLinear = input[1]
    pwm_Drill = input[2]
    
  }
}


