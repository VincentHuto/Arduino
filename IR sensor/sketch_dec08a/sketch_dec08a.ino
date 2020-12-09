#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#include <IRremote.h>  //including infrared remote header file     

int pinR = 2;
int pinG = 3;
int pinB = 4;
int pinButton = 8;
int buttonState = 0;
LiquidCrystal lcd(5, 6, 7, 11, 9, 10);
// Set Temp pin:
#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11  Temp Sensor
DHT dht = DHT(DHTPIN, DHTTYPE); // Initialize DHT sensor :

//int RECV_PIN = 13;
//IRrecv irrecv(RECV_PIN);
//decode_results results;


void setup() {
  pinMode(pinR, OUTPUT);    // sets the digital pin R as output
  pinMode(pinG, OUTPUT);    // sets the digital pin G as output
  pinMode(pinB, OUTPUT);    // sets the digital pin B as output
  pinMode(pinButton, INPUT); // Button Input to override Loop
  lcd.begin(16, 2);
  dht.begin(); //Turn Temp/Humidity Sensor On
  Serial.begin(9600);
  // irrecv.enableIRIn();
   printTitleCard();
}



void loop() {
  //  {
  //    if (irrecv.decode(&results)) {
  //      int readResults = results.value;
  //      Serial.print("Code: ");
  //      Serial.println(results.value, HEX);
  //      irrecv.resume();
  //    }
  //  }
  //}

  //Codes
  //FFA25D = Power
  //FF6897 = 0
  //FF30CF = 1
  //FF18E7 = 2
  //FF7A85 = 3
  //FF10EF = 4
  //FF38C7 = 5
  //FF5AA5 = 6
  //FF42BD = 7
  //FF4AB5 = 8
  //FF52AD = 9


 
  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from Temp sensor!");
    return;
  }

  //String Builder for F Temp
  String buff;
  buff += "Temp F: ";
  buff += f;
  //String Builder for C Temp
  String bufc;
  bufc += "Temp C: ";
  bufc += t;
  lcd.setCursor(0, 0);
  lcd.print(buff);
  lcd.setCursor(0, 1);
  lcd.print(bufc);
  delay(1000);
  lcd.clear();
  //String Builder for Humidity
  String bufh;
  bufh += "Humidity: ";
  bufh += h;
  lcd.setCursor(0, 0);
  lcd.print(bufh);
  lcd.setCursor(0, 1);
  lcd.print("u r my friend Oo");
  delay(1000);
  lcd.clear();


  //  //If Buttons Are not being overriden

  lcd.setCursor(0, 0);
    changeLights(true,false,false);
  lcd.print("Red Lights");
  delay(500);
  clearLights();

  //Turn Green Lighs On
  changeLights(false,true,false);
  lcd.setCursor(0, 0);
  lcd.print("Green Lights");
  delay(500);
  clearLights();

  //Turn Blue Lighs Off
  changeLights(false,false,true);
  lcd.setCursor(0, 0);
  lcd.print("Blue Lights");
  delay(500);
  clearLights();

}

void printTitleCard(){
  lcd.setCursor(0, 0);
  lcd.print("COMPSCI 412 VSC");
  lcd.setCursor(0, 1);
  lcd.print("LCD Lights Ctrlr");
  delay(1000);
  lcd.clear();
}

void changeLights(boolean r, boolean g, boolean b) {
  if (r) {
    digitalWrite(pinR, LOW);
  } else {
    digitalWrite(pinR, HIGH);
  }
  if (g) {
    digitalWrite(pinG, LOW);
  } else {
    digitalWrite(pinG, HIGH);
  }
  if (b) {
    digitalWrite(pinB, LOW);
  } else {
    digitalWrite(pinB, HIGH);
  }

}


void clearLights() {
  digitalWrite(pinR, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinB, HIGH);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("No Lights");
  delay(500);
  lcd.clear();
}

int colorOnTemp(float temp) {
  if (temp > 90) {
    return 2;
  } else if (temp <= 90 && temp > 80) {
    return 3;
  } else {
    return 4;
  }
}
