const int LED=9; //The LED is connected to pin 9
const int BUTTON=2; //The Button is connected to pin 2
void setup(){
pinMode (LED, OUTPUT);
pinMode (BUTTON, INPUT);
}
void loop() {
if (digitalRead(BUTTON) == LOW) {
digitalWrite(LED, LOW);
}
else {  digitalWrite(LED, HIGH);} 
}
