int sig = 127;
int key_pressed;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(13, sig);
  input();
}
void input()
{
    if (Serial.available())
  {
    
    key_pressed = Serial.read();
    if (key_pressed == '1')
    {
      sig = 0;
    }
    if (key_pressed == '0')
    {
      sig = 127;
    }
    if (key_pressed == '9')
    {
      sig = 255;
    }
    if (key_pressed == '2')
    {
      sig = 64;
    }
    if (key_pressed == '8')
    {
      sig = 191;
    }
  }
}
