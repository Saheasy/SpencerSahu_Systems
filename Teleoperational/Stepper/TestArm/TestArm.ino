
int pulPin1 = 15;
int dirPin1 = 13;
int dir_Signal;
int SM_speed = 10000;
int key_pressed;


int numofloops = 100; //2080 full rotation

void setup() 
{
  // put your setup code here, to run once:
  pinMode(pulPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);


  
  Serial.begin(9600);
}

void loop() {
  input_key();
  for(int i = 0; i<numofloops; i++)
  {
      if(dir_Signal > 0)
      {
        //sets all directions to cw
        digitalWrite(dirPin1, HIGH);
   
        
      }


      if(dir_Signal < 0)
      {
        //sets all directions to ccw
        digitalWrite(dirPin1, LOW);
 

      }
      
    digitalWrite(pulPin1, HIGH);
    delayMicroseconds(SM_speed);
    digitalWrite(pulPin1, LOW);

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


