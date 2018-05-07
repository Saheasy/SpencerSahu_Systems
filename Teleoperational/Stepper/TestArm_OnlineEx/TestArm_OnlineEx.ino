void setup(){
pinMode(4, OUTPUT);  //dir
pinMode(2, OUTPUT); //step pin (pul)
pinMode(8, OUTPUT);  //dir
pinMode(6, OUTPUT); //step pin (pul)
pinMode(12, OUTPUT);  //dir
pinMode(10, OUTPUT); //step pin (pul)
pinMode(12, OUTPUT);
pinMode(13,OUTPUT);

digitalWrite(4, HIGH);
digitalWrite(2, LOW);
digitalWrite(8, HIGH);
digitalWrite(6, LOW);
digitalWrite(12, HIGH);
digitalWrite(10, LOW);
analogWrite(13, 0);
}

void loop(){
digitalWrite(2, HIGH);
digitalWrite(6, HIGH);
digitalWrite(10, HIGH);
delayMicroseconds(800);
analogWrite(13, 80);
digitalWrite(2, LOW);
digitalWrite(6, LOW);
digitalWrite(10, LOW);

}
