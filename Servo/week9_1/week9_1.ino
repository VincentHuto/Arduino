int enablePin=3;
int in1Pin =4;
int in2Pin =5;
int switchPin=2;
int potPin = 0;


void setup() {
  pinMode(in1Pin,OUTPUT);
  pinMode(in2Pin,OUTPUT);
  pinMode(enablePin,OUTPUT);
  pinMode(switchPin,INPUT_PULLUP);

  
}

void loop() {
  int speed = analogRead(potPin)/4;
  boolean reverse = digitalRead(switchPin);
  setMotor(speed,reverse);  

}
void setMotor(int speed,boolean reverse){
  analogWrite(enablePin,speed);
  digitalWrite(in1Pin,!reverse);
  digitalWrite(in2Pin,reverse);
  
}
