#include<Servo.h>
int servoPin = 9;
int switchPin =2;
Servo servo1;

void setup() {
  servo1.attach(servoPin);
  pinMode(switchPin,INPUT_PULLUP);

  
}

void loop() {
  setServoMotor(digitalRead(switchPin));
  

}
void setServoMotor(boolean reverse){
  if(reverse){
    servo1.write(90);
  }else{
    servo1.write(0);
  }
}
