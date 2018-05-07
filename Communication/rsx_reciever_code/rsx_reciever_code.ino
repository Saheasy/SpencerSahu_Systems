#include <FUTABA_SBUS.h>
#include <Servo.h> 
#include <SoftwareSerial.h>

SoftwareSerial mserial(10, 11); // RX, TX
FUTABA_SBUS sBus;
Servo myservo;

void setup(){
  mserial.begin(115200);
  sBus.begin();
  myservo.attach(14); 
}

void loop(){
  //mserial.println("Loop");
  delay(100);
  sBus.FeedLine();
  if (sBus.toChannels == 1){
    sBus.UpdateServos();
    sBus.UpdateChannels();
    sBus.toChannels = 0;
    mserial.print(sBus.channels[1]);
    mserial.print("\t");
    mserial.print(sBus.channels[2]);
    mserial.print("\t");
    mserial.print(sBus.channels[3]);
    mserial.print("\t");
    mserial.println(sBus.channels[4]);
    mserial.print(sBus.channels[5]);
    mserial.print("\t");
    mserial.print(sBus.channels[6]);
    mserial.print("\t");
    mserial.print(sBus.channels[7]);
    mserial.print("\t");
    mserial.println(sBus.channel8[4]);
    //myservo.writeMicroseconds(sBus.channels[6]+800);
  }
}
