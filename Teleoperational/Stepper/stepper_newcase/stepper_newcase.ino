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

int numofloops = 100; //2080 full rotation
int num = 0;
int SM_speed = 200;

int caseinput;
int key_pressed;
float returndata
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

  // put your main code here, to run repeatedly:
  String data = Serial.readString();
  String command;
  int value;
  
  //if (Serial.available()) {
    if (data[0] == 'I') {
      data = rmSemi(data); // removes Idevice: and similar I: things
    }
    data = rmSemi(data); // removes the destination
    while (data.length() > 0) {
      data = parseM(data, command, value);
      // put command and value switches here
      int pos;
      int pul_motor;
      int dir_motor;
      speed_input
      if (command == "motor1")
      {
        velocity(pulPin1, dirPin1, pos, value);
      }
      else if (command == "motor2")
      {
        velocity(pulPin2, dirPin2, pos, value);
      }
      else if (command == "motor3")
      {
        velocity(pulPin3, dirPin3, pos, value);
      }
      else if (command == "motor4")
      {
        velocity(pulPin4, dirPin4, pos, value);
      } 

      
    }
  //}


}

void velocity(int pul_motor, int dir_motor, int & pos, int speed_input)
{
  
   if (speed_input > 0)
   {
    digitalWrite(dir_motor, HIGH); 
    pos++;
   }
   if (speed_input < 0)
   {
    digitalWrite(dir_motor, LOW);
    pos--; 
   }

   digitalWrite(pul_motor, HIGH);
   delayMicroseconds(abs(speed_input));
   digitalWrite(pul_motor, LOW);
   
}
void angle(int pul_motor,int dir_motor, int & pos, int dir_input, int speed_input, float degree)
{
  float pos = 0;
  pos = 
  if (dir_imput > 0)
   {
    digitalWrite(dir_motor, HIGH); 
    pos++;
   }
   if (dir_input < 0)
   {
    digitalWrite(dir_motor, LOW);
    pos--; 
   }

   digitalWrite(pul_motor, HIGH);
   delayMicroseconds(speed_input);
   digitalWrite(pul_motor, LOW);
   
}
String parseM(String data, String &command, int &value) {
  command = "";
  value = 0;
  int i = 0;
  while (data[i] != '-') {
    command += data[i];
    i++;
  }
  String temp = "";
  i++;
  while (data[i] != ':' && data[i] != ';') {
    temp += data[i];
    value = temp.toInt();
    i++;
  }
  data.remove(0,i+1);
  return data;
}

String rmSemi(String inputString) {
  while ((inputString[0] != ':') && inputString.length() > 0) {
    inputString.remove(0,1);
  }
  inputString.remove(0,1);
  return inputString;
}


