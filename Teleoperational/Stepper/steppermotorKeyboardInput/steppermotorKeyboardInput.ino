#define Pulse 9

#define Dir 8

long delay_Millis = 1275; // Set value

long currentMillis = 0; long previousMillis = 0;

int numofloops = 2080;
int num = 0;\
int SM_speed = 200;
char x;
void setup() {
  // put your setup code here, to run once:

  pinMode(Pulse, OUTPUT);

  pinMode(Dir, OUTPUT);

  digitalWrite(Dir, LOW); //HIGH or LOW for direction
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  for(int i = 0; i<numofloops; i++){
    digitalWrite(Pulse, HIGH);
    delayMicroseconds(SM_speed);//change this | Norm: 200 | Fastest: 100 | Slowest: 10000  | 
    digitalWrite(Pulse, LOW);
  
  } 
  if(num == 0){
    digitalWrite(Dir, HIGH);
     num++;
  }
  else{
    digitalWrite(Dir, LOW);
    num--;
  }
  if (Serial.available())
  {
    x = Serial.read();
    if (x == '1')
    {
      SM_speed = 100;
      
    }
    if (x == '2')
    {
      SM_speed = 200;
      
    }
    if (x == '3')
    {
      SM_speed = 400;
      
    }
    if (x == '4')
    {
      SM_speed = 600;
      
    }
    if (x == '5')
    {
      SM_speed = 800;
      
    }
    if (x == '6')
    {
      SM_speed = 1000;
      
    }
    if (x == '7')
    {
      SM_speed = 2500;
      
    }
    if (x == '8')
    {
      SM_speed = 5000;
      
    }
    if (x == '9')
    {
      SM_speed = 75000;
      
    }
    if (x == '0')
    {
      SM_speed = 10000;
      
    }
    
  }

  delay(1000);




}
