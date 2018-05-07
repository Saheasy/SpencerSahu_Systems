#include <Servo.h>

Servo roll_Servo;
Servo azimuth_Servo; 

int pressed;
int pos = 0;

int roll_input = 45;
int azimuth_input;
int x = 0;
String str;
void setup() 
{
  // put your setup code here, to run once:
  roll_Servo.attach(2);
  //azimuth.attach(3);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  input();
  roll_Servo.write(x);
  //Serial.println(roll_input);

}

void input()
{
   if (Serial.available())
   {
    pressed = Serial.read();
    roll_input = pressed;
   }
}

