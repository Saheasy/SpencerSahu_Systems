int pulPin1 = 9;
int dirPin1 = 8;

int pulPin2 = 7;
int dirPin2 = 6;

int pulPin3 = 5;
int dirPin3 = 4;

int pulPin4 = 3;
int dirPin4 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(pulPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

  pinMode(pulPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  pinMode(pulPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);

  pinMode(pulPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
    int testinput = 2;

    switch(testinput){
      case 0:
        drive(false,false,false,false);
        break;
      case 1:
        drive(true,true,false,false);
        break;
      case 2:
        drive(true,true,true,true);
        break;
      case 3:
        drive(false,true,false,true);
        break;  
    }

}

void drive(bool motor1, bool motor2, bool motor3, bool motor4){
  
  //everything in an endless while loop
  //use interupts to break out of the function when the case changes
  
  //take in data here

  //then determine cw or ccw
  //ccw is always gonna make the robot go left

  //determine which set of motors need to be turned

  //if statements to turn all motors that are set to true

  //
   int testSignal;

    while(true ){//change to while the signal does not change
      testSignal = -1;

      if(testSignal > 0){
        //sets all directions to cw
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, HIGH);
        digitalWrite(dirPin3, HIGH);
        digitalWrite(dirPin4, HIGH);
        if(motor1 == true){
          digitalWrite(pulPin1, HIGH);
        }
        if(motor2 == true){
          digitalWrite(pulPin2, HIGH);
        }
        if(motor3 == true){
          digitalWrite(pulPin3, HIGH);
        }
        if(motor4 == true){
          digitalWrite(pulPin4, HIGH);
        }
        delay(1);
        digitalWrite(pulPin1, LOW);
        digitalWrite(pulPin2, LOW);
        digitalWrite(pulPin3, LOW);
        digitalWrite(pulPin4, LOW);
      }


      if(testSignal < 0){
        //sets all directions to ccw
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
        digitalWrite(dirPin3, LOW);
        digitalWrite(dirPin4, LOW);
        if(motor1 == true){
          digitalWrite(pulPin1, HIGH);
        }
        if(motor2 == true){
          digitalWrite(pulPin2, HIGH);
        }
        if(motor3 == true){
          digitalWrite(pulPin3, HIGH);
        }
        if(motor4 == true){
          digitalWrite(pulPin4, HIGH);
        }
        delay(1);
        digitalWrite(pulPin1, LOW);
        digitalWrite(pulPin2, LOW);
        digitalWrite(pulPin3, LOW);
        digitalWrite(pulPin4, LOW);
      }
      
    }
   
}









