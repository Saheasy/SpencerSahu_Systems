int pulPin1 = 9;
int dirPin1 = 8;
int step1 = 0;
int initstep1 = 0;

int pulPin2 = 7;
int dirPin2 = 6;
int step2 = 0;
int initstep2 = 0;

int pulPin3 = 5;
int dirPin3 = 4;
int step3 = 0;
int initstep3 = 0;

int pulPin4 = 3;
int dirPin4 = 2;
int step4 = 0;
int initstep4 = 0;

int dir_Signal = 0;
long delay_Millis = 1275; // Set value

long currentMillis = 0; 
long previousMillis = 0;

int casecheck = 0;
int numofloops = 100; //2080 full rotation
int num = 0;
int SM_speed = 200;

int caseinput;
int key_pressed;
bool case4run = false;
int case4pos = (6040/8);

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
  Serial.println(SM_speed);
  Serial.println(step1);
  
  Serial.println(step2);
  
  Serial.println(step3);
  
  Serial.println(step4);
  input_key();
  for(int i = 0; i<numofloops; i++)
  {
    switch(caseinput)
    {
      case 0:
        case0();
        break;
      case 1:
        case1();
        break;
      case 2:
        case2();
        break;
      case 3:
        case3();
        break;
      case 4:
        case4();
        break;
      }
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

    if (step1 != 0)
    {
      if (step1 > 0)
      {
        digitalWrite(dirPin1, LOW);
        step1--;
      }
      if (step1 < 0)
      {
        digitalWrite(dirPin1, HIGH);
        step1++;
      }
      digitalWrite(pulPin1, HIGH);
    }
    if (step2 != 0)
    {
     
      if (step2 > 0)
      {
        digitalWrite(dirPin2, LOW);
        step2--;
      }
      if (step2 < 0)
      {
        digitalWrite(dirPin2, HIGH);
        step2++;
      }
      digitalWrite(pulPin2, HIGH);
    }
    if (step3 != 0)
    {
      if (step3 > 0)
      {
        digitalWrite(dirPin3, LOW);
        step3--;
      }
      if (step3 < 0)
      {
        digitalWrite(dirPin3, HIGH);
        step3++;
      }
      digitalWrite(pulPin3, HIGH);
    }
    if (step4 != 0)
    {
      if (step4 > 0)
      {
        digitalWrite(dirPin4, LOW);
        step4--;
      }
      if (step4 < 0)
      {
        digitalWrite(dirPin4, HIGH);
        step4++;
      }
      digitalWrite(pulPin4, HIGH);
    }
    
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);
    digitalWrite(pulPin2, LOW);
    digitalWrite(pulPin3, LOW);
    digitalWrite(pulPin4, LOW);
    casecheck = 0;


}
void case1()
{
  if (casecheck != 0)
    {
      case0();
    }
  else
 {
      if(dir_Signal > 0)
      {
        //sets all directions to cw
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, HIGH);
      }


      if(dir_Signal < 0)
      {
        //sets all directions to ccw
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);

      }
      
    digitalWrite(pulPin1, HIGH);
    digitalWrite(pulPin2, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);
    digitalWrite(pulPin2, LOW);
    digitalWrite(pulPin3, LOW);
    digitalWrite(pulPin4, LOW);
 }
}
void case2()
{
  if (casecheck != 0)
    {
      case0();
    }
  else
  {
    if(dir_Signal > 0)
      {
        //sets all directions to cw
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, HIGH);
        digitalWrite(dirPin3, HIGH);
        digitalWrite(dirPin4, HIGH);
        
      }


      if(dir_Signal < 0)
      {
        //sets all directions to ccw
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
        digitalWrite(dirPin3, LOW);
        digitalWrite(dirPin4, LOW);

      }
      
    digitalWrite(pulPin1, HIGH);
    digitalWrite(pulPin2, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);
    digitalWrite(pulPin2, LOW);
    digitalWrite(pulPin3, LOW);
    digitalWrite(pulPin4, LOW);
  }
  
}
void case3()
{
  if (casecheck != 0)
    {
      case0();
    }
  else
 {
      if(dir_Signal > 0)
      {
        //sets all directions to cw
        digitalWrite(dirPin2, HIGH);
        digitalWrite(dirPin4, HIGH);
      }


      if(dir_Signal < 0)
      {
        //sets all directions to ccw
        digitalWrite(dirPin2, LOW);
        digitalWrite(dirPin4, LOW);

      }
      
    digitalWrite(pulPin2, HIGH);
    digitalWrite(pulPin4, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin2, LOW);
    digitalWrite(pulPin4, LOW);
 }
}
void case4()
{

    if (step1 != case4pos)
    {
      if (step1 > case4pos)
      {
        digitalWrite(dirPin1, LOW);
        step1--;
      }
      if (step1 < case4pos)
      {
        digitalWrite(dirPin1, HIGH);
        step1++;
      }
      digitalWrite(pulPin1, HIGH);
    }
    
    if (step2 != case4pos)
    {
     
      if (step2 > -case4pos)
      {
        digitalWrite(dirPin2, LOW);
        step2--;
      }
      if (step2 < -case4pos)
      {
        digitalWrite(dirPin2, HIGH);
        step2++;
      }
      digitalWrite(pulPin2, HIGH);
    }
    if (step3 != -case4pos)
    {
      if (step3 > -case4pos)
      {
        digitalWrite(dirPin3, LOW);
        step3--;
      }
      if (step3 < -case4pos)
      {
        digitalWrite(dirPin3, HIGH);
        step3++;
      }
      digitalWrite(pulPin3, HIGH);
    }
    if (step4 != case4pos)
    {
      if (step4 > case4pos)
      {
        digitalWrite(dirPin4, LOW);
        step4--;
      }
      if (step4 < case4pos)
      {
        digitalWrite(dirPin4, HIGH);
        step4++;
      }
      digitalWrite(pulPin4, HIGH);
    }
    
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);
    digitalWrite(pulPin2, LOW);
    digitalWrite(pulPin3, LOW);
    digitalWrite(pulPin4, LOW);
    


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
      SM_speed = 600;
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
      casecheck = 1;
    }
    if (key_pressed == 'i')
    {
      caseinput = 2;
      casecheck = 2;
    }
    if (key_pressed == 'o')
    {
      caseinput = 3;
      casecheck = 3;
    }
    if (key_pressed == 'p')
    {
      caseinput = 4;
      casecheck = 4;
      
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


