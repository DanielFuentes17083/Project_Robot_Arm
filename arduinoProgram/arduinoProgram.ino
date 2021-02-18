#include <Stepper.h>
#include <Servo.h>
#define STEPS 2048

Stepper stepper(STEPS, 13, 12, 8, 7);
Servo ServoMotor1;
Servo ServoMotor2;
Servo ServoMotor3;
const int DCMotorPinL = 3;
const int DCMotorPinR = 2;
const int ServoPin1 = 11;
const int ServoPin2 = 10;
const int ServoPin3 = 9;
byte control = 0;
int action = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  stepper.setSpeed(10);
  ServoMotor1.attach(ServoPin1);
  ServoMotor2.attach(ServoPin2);
  ServoMotor3.attach(ServoPin3);
  ServoMotor1.write(0);
  ServoMotor2.write(0);
  ServoMotor3.write(0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  control = Serial.read();
  while (control == 1){
    if (Serial.available() > 0){
      action = Serial.read();
      ServoMotor1.write(action);
      break;
    }
  }
  while (control == 2){
    if (Serial.available() > 0){
      action = Serial.read();
      ServoMotor2.write(action);
      break;
    }
  }
  while (control == 3){
    if (Serial.available() > 0){
      action = Serial.read();
      ServoMotor3.write(action);
      break;
    }
  }
  while (control == 4){
//    if (Serial.available() > 0){
//      action = Serial.read();
//      ServoMotor1.write(action);
      break;
//    }
  }
}
