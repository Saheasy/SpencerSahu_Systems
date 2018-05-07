int pulPin1 = 2;
int dirPin1 = 4;
int step1 = 0;
int initstep1 = 0;

void setup() {
  // put your setup code here, to run once:
 // put your setup code here, to run once:
  pinMode(pulPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin1, HIGH);
  digitalWrite(pulPin1, HIGH);
  delay(10);
  digitalWrite(pulPin1, LOW);
}
