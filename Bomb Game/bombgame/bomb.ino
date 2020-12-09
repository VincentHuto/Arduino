#define FND_A 2
#define FND_DP 9
int beepPin = 10;
int btn1 = 11, btn2 = 12;
long randNumber;

boolean digit[10][8] = {
  {1,1,1,1,1,1,0,0},//0
  {0,1,1,0,0,0,0,0},//1
  {1,1,0,1,1,0,1,0},//2
  {1,1,1,1,0,0,1,0},//3
  {0,1,1,0,0,1,1,0},//4
  {1,0,1,1,0,1,1,0},//5
  {1,0,1,1,1,1,1,0},//6
  {1,1,1,0,0,0,0,1},//7
  {1,1,1,1,1,1,1,1},//8
  {1,1,1,0,0,1,1,0,}//9
};

void setup() {
  for(int i=FND_A; i<=10;i++){
    pinMode(i,OUTPUT); //pin2~pin10 output
  }
  pinMode(btn1,INPUT_PULLUP);
  pinMode(btn2,INPUT_PULLUP);
  randomSeed(analogRead(0));
  randNumber = random(11,13); //Random 11 or 12
  Serial.begin(9600);
}




int j =9;
void loop() {
  for(j=9; j>=0;j--){
    for(int i = FND_A; i<=FND_DP;i++){
      digitalWrite(i,digit[j][i-2]); //Each pin low or high
      chk_btn();
    }
    if(j==0){
      analogWrite(beepPin,20);
    }else{
      analogWrite(beepPin,0);
    }
    delay(1000);
  }
}

void chk_btn(){
  while(true){
    if(digitalRead(btn1)==LOW&&digitalRead(btn2)==LOW){
      j=9;
      randNumber = random(11,13); //random 11 or 12
      Serial.println(randNumber);      
    }else if(digitalRead(btn1)==LOW){
      if(randNumber==btn1){
              Serial.println(randNumber);      
        analogWrite(beepPin,20);
        delay(100);
      }else{
        delay(100);
      }
    }else if(digitalRead(btn2)==LOW){
      if(randNumber==btn2){
        analogWrite(beepPin,20);
        delay(100);
      }else{
        delay(100);
      }
    }else{
      break;
    }
  }
}
