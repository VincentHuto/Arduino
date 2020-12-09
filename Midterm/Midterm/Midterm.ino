//Vince Comaroto Midterm H-Bridge With Button

int enablePin=3;//Enable
int in1Pin = 4; //Pin 5
int in2Pin =5; //Pin 4
int switchPin=2;
void setup()
{
  pinMode(enablePin,OUTPUT);
  pinMode(in1Pin,OUTPUT);
  pinMode(in2Pin,OUTPUT);
  pinMode(switchPin,INPUT_PULLUP);

}

void loop()
{
  boolean reverse = digitalRead(switchPin);
 setMotor(reverse); //OOP Code
  
}
void setMotor(boolean reverse){
  analogWrite(enablePin,200);
  digitalWrite(in1Pin,!reverse);
  digitalWrite(in2Pin,0);

}
