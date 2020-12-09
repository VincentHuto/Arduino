

int greenPin = 7;
int yellowPin = 8;
int redPin = 9;
const int BUTTON = 2; //The Button is connected to pin 2
void setup()
{
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(BUTTON, INPUT); //Remove the register
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (digitalRead(BUTTON) == HIGH)
  {
    digitalWrite(greenPin, HIGH); // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellowPin, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(redPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                  // wait for a second
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    delay(1000);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(1000);
    digitalWrite(greenPin, LOW);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellowPin, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(redPin, LOW);
  }
  else
  {
    digitalWrite(greenPin, LOW);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellowPin, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(redPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                  // wait for a second
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    delay(1000);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    delay(1000);
    digitalWrite(greenPin, LOW);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellowPin, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(redPin, LOW);
  }
}
