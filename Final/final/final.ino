#include <DHT.h>// including temp sensor
#include <LiquidCrystal.h>//including lcd
#include <IRremote.h>  //including infrared remote header file     

//Color Data Object
class ColorData {
  private:
    String color;
    boolean r, g, b;
  public:
    ColorData(String colorIn, boolean rIn, boolean gIn, boolean bIn) {
      color = colorIn;
      r = rIn;
      g = gIn;
      b = bIn;
    }
    String getColor() {
      return color;
    }

    boolean getRed() {
      return r;
    }
    boolean getGreen() {
      return g;
    }
    boolean getBlue() {
      return b;
    }
};
//Color Wheel
ColorData red = ColorData("Red", true, false, false);
ColorData green = ColorData("Green", false, true, false);
ColorData blue = ColorData("Blue", false, false, true);
ColorData purple = ColorData("Purple", true, false, true);
ColorData yellow = ColorData("Yellow", false, true, true);
ColorData brown = ColorData("Brown", true, true, false);
ColorData white = ColorData("White", true, true, true);
ColorData black = ColorData("Black", false, false, false);
ColorData rainbow[]  = {purple, blue, green, yellow, red, brown};
ColorData fullSpectrum[] = {white, yellow, brown, red, purple, blue, green};
//Used to change Modes
enum State {off, solid, strobe, cycle, heat, humidity, sporadic, sRed, sGreen, sBlue, sYellow, sPurple, sWhite};
State currentState;

//Ir Reciver
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

//Rgb Pins
int pinR = 3;
int pinG = 4;
int pinB = 5;

//Setup LCD
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

// Set Temp pin:
#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11  Temp Sensor
DHT dht = DHT(DHTPIN, DHTTYPE); // Initialize DHT sensor :

void setup() {
  pinMode(pinR, OUTPUT);    // sets the digital pin R as output
  pinMode(pinG, OUTPUT);    // sets the digital pin G as output
  pinMode(pinB, OUTPUT);    // sets the digital pin B as output
  lcd.begin(16, 2);
  dht.begin(); //Turn Temp/Humidity Sensor On
  Serial.begin(9600);
  irrecv.enableIRIn();
  attachInterrupt(digitalPinToInterrupt(2), recieveIRData , RISING);
  printTitleCard();
  currentState = off;
}


void loop() {
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
  switch (currentState) {
    case off:
      clearLights();
      return;
    case solid:
      changeLights(green, 500);
      return;
    case strobe:
      policeLights(150, 3);
      return;
    case cycle:
      cycleLights(500);
      return;
    case heat:
      displayTemp(f, t);
      changeLights(colorOnTemp(f), 800);
      return;
    case humidity:
      displayHumidity(h);
      changeLights(colorOnHumid(h), 800);
      return;
    case sporadic:
      randomLight(200, 20);
      return;
    case sRed:
      setColor(red);
      break;
    case sGreen:
      setColor(green);
      break;
    case sBlue:
      setColor(blue);
      break;
    case sYellow:
      setColor(yellow);
      break;
    case sPurple:
      setColor(purple);
      break;
    case sWhite:
      setColor(white);
      break;
  }
}
void recieveIRData() {

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

  if (irrecv.decode(&results)) {
    int readResults = results.value;
    Serial.print("Code: ");
    Serial.println(results.value);
    irrecv.resume();
    switch (results.value) {
      case 16753245:
        currentState = off;
        break;
      case 16724175:
        currentState = solid;
        break;
      case 16718055:
        currentState = strobe;
        break;
      case 16743045:
        currentState = cycle;
        break;
      case 16716015:
        currentState = heat;
        break;
      case 16726215:
        currentState = humidity;
        break;
      case 16734885:
        currentState = sporadic;
      case 16720605:
        currentState = sRed;
        break;
      case 16712445:
        currentState = sBlue;
        break;
      case 16761405:
        currentState = sGreen;
        break;
      case 16769055:
        currentState = sYellow;
        break;
      case 16754775:
        currentState = sPurple;
        break;
      case 16748655:
        currentState = sWhite;
        break;
      default:
        break;
    }


  }
}


void printTitleCard() {
  lcd.setCursor(0, 0);
  lcd.print("COMPSCI 412 VSC");
  lcd.setCursor(0, 1);
  lcd.print("LCD Lights Ctrlr");
  delay(1000);
  lcd.clear();
}

void displayTemp(float f, float c) {
  //String Builder for F Temp
  String buff;
  buff += "Temp F: ";
  buff += f;
  //String Builder for C Temp
  String bufc;
  bufc += "Temp C: ";
  bufc += c;
  lcd.setCursor(0, 0);
  lcd.print(buff);
  lcd.setCursor(0, 1);
  lcd.print(bufc);
  delay(1000);
  lcd.clear();
}
void displayHumidity(float h) {
  //String Builder for Humidity
  String bufh;
  bufh += "Humidity: ";
  bufh += h;
  lcd.setCursor(0, 0);
  lcd.print(bufh);
  delay(1000);
  lcd.clear();
}

void setColor(ColorData data) {
  lcd.setCursor(0, 0);
  lcd.print(data.getColor() + " Lights");
  if (data.getRed()) {
    digitalWrite(pinR, LOW);
  } else {
    digitalWrite(pinR, HIGH);
  }
  if (data.getGreen()) {
    digitalWrite(pinG, LOW);
  } else {
    digitalWrite(pinG, HIGH);
  }
  if (data.getBlue()) {
    digitalWrite(pinB, LOW);
  } else {
    digitalWrite(pinB, HIGH);
  }
}


void cycleLights(int pulseTime) {
  changeLights(red, pulseTime);
  changeLights(green, pulseTime);
  changeLights(blue, pulseTime);
  changeLights(purple, pulseTime);
  changeLights(yellow, pulseTime);
  changeLights(brown, pulseTime);
  changeLights(black, pulseTime);
  changeLights(white, pulseTime);
}


void policeLights(int pulseTime, int flashAmount) {
  for (int i = 0; i < flashAmount; i++) {
    changeLights(red, pulseTime);
    delay(pulseTime);
    changeLights(blue, pulseTime);
    delay(pulseTime);
  }
}
void alarmLights(int pulseTime, int flashAmount) {
  for (int i = 0; i < flashAmount; i++) {
    changeLights(red, pulseTime);
    delay(pulseTime);
    changeLights(black, pulseTime);
    delay(pulseTime);
  }
}
void strobeLights(int pulseTime, int flashAmount) {
  for (int i = 0; i < flashAmount; i++) {
    changeLights(white, pulseTime);
    delay(pulseTime);
    changeLights(black, pulseTime);
    delay(pulseTime);
  }
}

void rainbowLights(int pulseTime, int flashAmount) {
  for (int i = 0; i < flashAmount; i++) {
    for (int i = 0; i < (sizeof(rainbow) / sizeof(*rainbow)); i++) {
      changeLights(rainbow[i], pulseTime);
    }
  }
}
void randomLight(int pulseTime, int flashAmount) {
  for (int i = 0; i < flashAmount; i++) {
    for (int i = 0; i < (sizeof(fullSpectrum) / sizeof(*fullSpectrum)); i++) {
      changeLights(fullSpectrum[i], pulseTime);
    }
  }
}


void changeLights(ColorData data, int pulseTime) {
  lcd.setCursor(0, 0);
  lcd.print(data.getColor() + " Lights");
  if (data.getRed()) {
    digitalWrite(pinR, LOW);
  } else {
    digitalWrite(pinR, HIGH);
  }
  if (data.getGreen()) {
    digitalWrite(pinG, LOW);
  } else {
    digitalWrite(pinG, HIGH);
  }
  if (data.getBlue()) {
    digitalWrite(pinB, LOW);
  } else {
    digitalWrite(pinB, HIGH);
  }
  delay(pulseTime);
  clearLights();

}


ColorData colorOnTemp(float temp) {
  if (temp > 95) {
    return red;
  } else if (temp <= 95 && temp > 90) {
    return yellow;
  } else if (temp <= 90 && temp > 85) {
    return brown;
  } else if (temp <= 85 && temp > 80) {
    return purple;
  } else if (temp <= 80 && temp > 75) {
    return green;
  } else if (temp <= 75 && temp > 70) {
    return blue;
  } else {
    return white;
  }
}
ColorData colorOnHumid(float humid) {
  if (humid > 50) {
    return purple;
  } else if (humid <= 50 && humid > 40) {
    return green;
  } else if (humid <= 40 && humid > 30) {
    return blue;
  } else if (humid <= 30 && humid > 20) {
    return yellow;
  } else if (humid <= 20 && humid > 10) {
    return red;
  } else {
    return white;
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
