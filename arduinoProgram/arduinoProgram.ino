#include <Stepper.h>
#include <Servo.h>
#define STEPS 20

Stepper stepper(STEPS, 8, 13, 7, 12);
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
  stepper.setSpeed(30);
  ServoMotor1.attach(ServoPin1);
  ServoMotor2.attach(ServoPin2);
  ServoMotor3.attach(ServoPin3);
  ServoMotor1.write(0);
  ServoMotor2.write(0);
  ServoMotor3.write(0);
  stepper.step(1);
  pinMode(DCMotorPinL, OUTPUT);
  pinMode(DCMotorPinR, OUTPUT);
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
    digitalWrite(DCMotorPinR, LOW);
    digitalWrite(DCMotorPinL, HIGH);
    delay(100);
    digitalWrite(DCMotorPinR, HIGH);
    break;
  }
  while (control == 5){
    digitalWrite(DCMotorPinL, LOW);
    digitalWrite(DCMotorPinR, HIGH);
    delay(100);
    digitalWrite(DCMotorPinL, HIGH);
    break;
  }
  if (control == 6){
    stepper.step(1);
  }
  if (control == 7){
    stepper.step(-1);
  }
  
}
