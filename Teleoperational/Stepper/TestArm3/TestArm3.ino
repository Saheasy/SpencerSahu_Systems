int dirPin_LeftStepper = 4;
int pulPin_LeftStepper = 2;
int dir_LeftStepper = 0;

int dirPin_RightStepper = 8;
int pulPin_RightStepper = 6;
int delay_LeftRightStepper = 1000;
int dir_RightStepper = 0;

 
int dirPin_BaseStepper = 12;
int pulPin_BaseStepper = 10;
int delay_BaseStepper = 1000;
int dir_BaseStepper = 0;

int pwmPin_CenterLinear = 13; //Center Linear Actuator
int pwm_CenterLinear = 127;
int pwmPin_ForwardLinear = 11;
int pwm_ForwardLinear = 127;

int dir = 0;
int delay_step;
int toggle_step = 2;
int key_pressed;
unsigned long StartTime = micros();
void setup() {
  // put your setup code here, to run once:
  pinMode(dirPin_LeftStepper, OUTPUT);  //dir
  pinMode(pulPin_LeftStepper, OUTPUT); //step pin (pul)
  pinMode(dirPin_RightStepper, OUTPUT);  //dir
  pinMode(pulPin_RightStepper, OUTPUT); //step pin (pul)
  pinMode(dirPin_BaseStepper, OUTPUT);  //dir
  pinMode(pulPin_BaseStepper, OUTPUT); //step pin (pul)
  pinMode(pwmPin_CenterLinear, OUTPUT); //pwm input
  Serial.begin(9600);
  unsigned long StartTime = micros();
}

void loop() {
  unsigned long CurrentTime = micros();
  unsigned long ElapsedTime = CurrentTime - StartTime;
  // put your main code here, to run repeatedly:
  keyInput();
  StepFirer(dirPin_LeftStepper, dir_LeftStepper, pulPin_LeftStepper, ElapsedTime, delay_LeftRightStepper);
  StepFirer(dirPin_RightStepper, dir_RightStepper, pulPin_RightStepper, ElapsedTime, delay_LeftRightStepper);
  StepFirer(dirPin_BaseStepper, dir_BaseStepper, pulPin_BaseStepper, ElapsedTime, delay_BaseStepper);
  analogWrite(13, pwm_CenterLinear);
  analogWrite(pwmPin_ForwardLinear, pwm_ForwardLinear);
  Serial.print(ElapsedTime);
  
}

void keyInput()
{
  if (Serial.available())
  {
    key_pressed = Serial.read();
    if (key_pressed == 'a')
    {
      dir = -1;
      if (toggle_step == 1) //Base
      {
        dir_BaseStepper = dir;
      }
      if (toggle_step == 2) //Claw
      {
        dir_LeftStepper = dir;
        dir_RightStepper = -1 * dir;
      }  
    }
    if (key_pressed == 'd')
    {
      dir = 1;
      if (toggle_step == 1) //Base
      {
        dir_BaseStepper = dir;
      }
      if (toggle_step == 2) //Claw
      {
        dir_LeftStepper = dir;
        dir_RightStepper = -1 * dir;
      }
    }
    if (key_pressed == 's')
    {
      dir = 0;
      if (toggle_step == 1) //Base
      {
        dir_BaseStepper = dir;
      }
      else if (toggle_step == 2) //Claw
      {
        dir_LeftStepper = dir;
        dir_RightStepper = dir;
      }
    }
    if (key_pressed == 'q')
    {
      toggle_step ++;
      if (toggle_step > 2)
      {
        toggle_step = 1;
      }
    }
    if (key_pressed == '1')
    {
      delay_step = 400;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '2')
    {
      delay_step = 600;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '3')
    {
      delay_step = 800;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '4')
    {
      delay_step = 1000;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '5')
    {
      delay_step = 1500;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '6')
    {
      delay_step = 2500;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '7')
    {
      delay_step = 5000;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '8')
    {
      delay_step = 7500;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '9')
    {
      delay_step = 10000;
      if (toggle_step == 1)
      {
        delay_LeftRightStepper = delay_step;
      }
      if (toggle_step == 2)
      {
        delay_BaseStepper = delay_step;
      }
    }
    if (key_pressed == '0')
    {
      pwm_CenterLinear = 127;
      pwm_ForwardLinear = 127;
      dir_LeftStepper = 0;
      dir_RightStepper = 0;
      dir_BaseStepper = 0;
    }
    if (key_pressed == 'n')
    {
      pwm_CenterLinear = 0;
    }
    if (key_pressed == 'm')
    {
      pwm_CenterLinear = 64;
    }
    if (key_pressed == ',')
    {
      pwm_CenterLinear = 127;
    }
    if (key_pressed == '.')
    {
      pwm_CenterLinear = 191;
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
      pwm_ForwardLinear = 64;
    }
    if (key_pressed == 'k')
    {
      pwm_ForwardLinear = 127;
    }
    if (key_pressed == 'l')
    {
      pwm_ForwardLinear = 191;
    }
    if (key_pressed == ';')
    {
      pwm_ForwardLinear = 255;
    }
    
    
  }
}

void StepFirer(int dirPin, int dir, int pulPin, unsigned long ElaspedTime, int TimeDelay)
{
  if (dir > 0)
    {
      digitalWrite(dirPin, HIGH);
    }
  else if (dir < 0)
    {
      digitalWrite(dirPin, LOW);
    }
  if (ElaspedTime%TimeDelay > 100 and ElaspedTime%TimeDelay < -100)
  {
    if (dir != 0)
    {
      digitalWrite(pulPin, LOW);
      digitalWrite(pulPin, HIGH);
    }
  }
  
}

