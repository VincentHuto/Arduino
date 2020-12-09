int pinR = 0;
int pinG = 1;
int pinB = 2;
int pinButton = 8;

void setup() {
  pinMode(pinR, OUTPUT);    // sets the digital pin 13 as output
  pinMode(pinG, OUTPUT);    // sets the digital pin 13 as output
  pinMode(pinB, OUTPUT);    // sets the digital pin 13 as output
  pinMode(pinButton, INPUT);

}

void loop() {
  if(digitalRead(pinButton)==LOW){
  digitalWrite(pinR, LOW); // sets the digital pin 13 on
  digitalWrite(pinG, HIGH); // sets the digital pin 13 on
  digitalWrite(pinB, HIGH); // sets the digital pin 13 on
  delay(1000);            // waits for a second
  digitalWrite(pinR, HIGH);  // sets the digital pin 13 off
  digitalWrite(pinG, HIGH);  // sets the digital pin 13 off
  digitalWrite(pinB, HIGH);  // sets the digital pin 13 off
  delay(1000);     

  digitalWrite(pinR, HIGH); // sets the digital pin 13 on
  digitalWrite(pinG, LOW); // sets the digital pin 13 on
 digitalWrite(pinB, HIGH); // sets the digital pin 13 on
  delay(1000);            // waits for a second
 digitalWrite(pinR, HIGH);  // sets the digital pin 13 off
    digitalWrite(pinG, HIGH);  // sets the digital pin 13 off
  digitalWrite(pinB, HIGH);  // sets the digital pin 13 off
  delay(1000);  

  digitalWrite(pinR, HIGH); // sets the digital pin 13 on
  digitalWrite(pinG, HIGH); // sets the digital pin 13 on
 digitalWrite(pinB, LOW); // sets the digital pin 13 on  
  delay(1000);  
   digitalWrite(pinR, HIGH);  // sets the digital pin 13 off
    digitalWrite(pinG, HIGH);  // sets the digital pin 13 off
  digitalWrite(pinB, HIGH);  // sets the digital pin 13 off// waits for a second
  delay(1000);  
  }else{
    digitalWrite(pinR, HIGH);  // sets the digital pin 13 off
    digitalWrite(pinG, HIGH);  // sets the digital pin 13 off
    digitalWrite(pinB, HIGH);  // sets the digital pin 13 off// waits for a second
  }
}
