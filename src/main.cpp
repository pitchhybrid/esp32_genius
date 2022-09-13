#include <Arduino.h>

#define BTNVR 14 // VERMELHO
#define LEDVR 27 // VERMELHO

#define BTNAZ 26 // AZUL
#define LEDAZ 25 // AZUL

#define BTNVD 33 // VERDE
#define LEDVD 32 // VERDE

#define BTNAM 12 // AMARELO
#define LEDAM 13 // AMARELO

void acender(int btn, int led);

void setup() {
    Serial.begin(115200);
    pinMode(BTNVR,INPUT_PULLUP);
    pinMode(LEDVR,OUTPUT);
    pinMode(BTNAZ,INPUT_PULLUP);
    pinMode(LEDAZ,OUTPUT);
    pinMode(BTNVD,INPUT_PULLUP);
    pinMode(LEDVD,OUTPUT);
    pinMode(BTNAM,INPUT_PULLUP);
    pinMode(LEDAM,OUTPUT);
}

void loop() {
  acender(BTNVR,LEDVR);
  acender(BTNAZ,LEDAZ);
  acender(BTNVD,LEDVD);
  acender(BTNAM,LEDAM);
}

void acender(int btn,int led){
  if(digitalRead(btn) == 1){
    digitalWrite(led,HIGH);
    // Serial.println( String(digitalRead(btn)));
  }
  if(digitalRead(btn) == 0){
    digitalWrite(led,LOW);
    Serial.println( String(digitalRead(btn)));
  }
}