int pulPin1 = 13;
int dirPin1 = 12;
int step1 = 0;

int pulPin2 = 11;
int dirPin2 = 10;
int step2 = 0;

int pulPin3 = 9;
int dirPin3 = 8;
int step3 = 0;

int pulPin4 = 6;
int dirPin4 = 5;
int step4 = 0;

int dir_Signal = 0;
long delay_Millis = 1275; // Set value

long currentMillis = 0; 
long previousMillis = 0;

int numofloops = 2080;
int num = 0;
int SM_speed = 200;

int caseinput = 0;
int key_pressed;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(pulPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

  pinMode(pulPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  pinMode(pulPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);

  pinMode(pulPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  input_key();
  for(int i = 0; i<numofloops; i++)
  {
    switch(caseinput)
    {
      case 0:
        case0();
        break;
      case 1:
        drive(true,true,false,false);
        break;
      case 2:
        drive(true,true,true,true);
        break;
      case 3:
        drive(false,false,true,false);
        break;  
    }
  }
  
}
void drive(bool motor1, bool motor2, bool motor3, bool motor4){ //motor_pos will not be further elaborated until I see the how the wheel turns
  
  //everything in an endless while loop
  //use interupts to break out of the function when the case changes
  
  //take in data here

  //then determine cw or ccw
  //ccw is always gonna make the robot go left

  //determine which set of motors need to be turned

  //if statements to turn all motors that are set to true

  //

      
      if(dir_Signal > 0)
      {
        //sets all directions to cw
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, HIGH);
        digitalWrite(dirPin3, HIGH);
        digitalWrite(dirPin4, HIGH);
        if(motor1 == true){
          digitalWrite(pulPin1, HIGH);
          step1++;
          
        }
        if(motor2 == true){
          digitalWrite(pulPin2, HIGH);
          step2++;
          
        }
        if(motor3 == true){
          digitalWrite(pulPin3, HIGH);
          step3++;
          
        }
        if(motor4 == true){
          digitalWrite(pulPin4, HIGH);
          step4++;
          
        }
        delayMicroseconds(SM_speed);
        digitalWrite(pulPin1, LOW);
        digitalWrite(pulPin2, LOW);
        digitalWrite(pulPin3, LOW);
        digitalWrite(pulPin4, LOW);
      }


      if(dir_Signal < 0)
      {
        //sets all directions to ccw
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
        digitalWrite(dirPin3, LOW);
        digitalWrite(dirPin4, LOW);
        if(motor1 == true){
          digitalWrite(pulPin1, HIGH);
          step1--;
          
        }
        if(motor2 == true){
          digitalWrite(pulPin2, HIGH);
          step2--;
          
        }
        if(motor3 == true){
          digitalWrite(pulPin3, HIGH);
          step3--;
          
        }
        if(motor4 == true){
          digitalWrite(pulPin4, HIGH);
          step4--;
          
        }
        delayMicroseconds(SM_speed);
        digitalWrite(pulPin1, LOW);
        digitalWrite(pulPin2, LOW);
        digitalWrite(pulPin3, LOW);
        digitalWrite(pulPin4, LOW);
      }   
}

void case0()
{
  while(step1 != 0)
  {
    if (step1 > 0)
    {
       digitalWrite(dirPin1, LOW);
       step1--;
    }
    else if (step1 < 0)
    {
      digitalWrite(dirPin1, HIGH);
      step1++;
    }
    digitalWrite(pulPin1, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);
  }
  while(step2 != 0)
  {
    if (step2 > 0)
    {
       digitalWrite(dirPin2, LOW);
       step2--;
    }
    else if (step2 < 0)
    {
      digitalWrite(dirPin2, HIGH);
      step2++;
    }
    digitalWrite(pulPin2, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin2, LOW);
  }
  while(step3 != 0)
  {
    if (step3 > 0)
    {
       digitalWrite(dirPin3, LOW);
       step3--;
    }
    else if (step3 < 0)
    {
      digitalWrite(dirPin3, HIGH);
      step3++;
    }
    digitalWrite(pulPin3, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin3, LOW);
  }
  while(step4 != 0)
  {
    if (step4 > 0)
    {
       digitalWrite(dirPin4, LOW);
       step4--;
    }
    else if (step4 < 0)
    {
      digitalWrite(dirPin4, HIGH);
      step4++;
    }
    digitalWrite(pulPin4, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin4, LOW);
  }
}
void input_key()
{
  
  if (Serial.available())
  {
    key_pressed = Serial.read();
    if (key_pressed == '1')
    {
      SM_speed = 100;
    }
    if (key_pressed == '2')
    {
      SM_speed = 200;
    }
    if (key_pressed == '3')
    {
      SM_speed = 400;
    }
    if (key_pressed == '4')
    {
      SM_speed = 800;
    }
    if (key_pressed == '5')
    {
      SM_speed = 1000;
    }
    if (key_pressed == '6')
    {
      SM_speed = 2500;
    }
    if (key_pressed == '7')
    {
      SM_speed = 5000;
    }
    if (key_pressed == '8')
    {
      SM_speed = 7500;
    }
    if (key_pressed == '9')
    {
      SM_speed = 10000;
    }
    if (key_pressed == '0')
    {
      dir_Signal = 0;
    }
    if (key_pressed == 'y')
    {
      caseinput = 0;
    }
    if (key_pressed == 'u')
    {
      caseinput = 1;
    }
    if (key_pressed == 'i')
    {
      caseinput = 2;
    }
    if (key_pressed == 'o')
    {
      caseinput = 3;
    }
    if (key_pressed == 'p')
    {
      caseinput = 4;
    }
    if (key_pressed == 'a')
    {
      dir_Signal = -1;
    }
    if (key_pressed == 'd')
    {
      dir_Signal = 1;
    }
    
  }
}

