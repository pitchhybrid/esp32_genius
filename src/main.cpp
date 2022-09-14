#include <Arduino.h>

#define BTNVR 14 // VERMELHO
#define LEDVR 27 // VERMELHO

#define BTNAZ 26 // AZUL
#define LEDAZ 25 // AZUL

#define BTNVD 33 // VERDE
#define LEDVD 32 // VERDE

#define BTNAM 12 // AMARELO
#define LEDAM 13 // AMARELO

#define T_RODADAS 5

int rodada = 2;

int *old;

enum CORES {
  VERMELHO = LEDVR,
  AZUL = LEDAZ,
  VERDE = LEDVD,
  AMARELO = LEDAM
};

void acender(int btn, int led);
int *copiarVetor(int *v, int len);
int *gerarRodadas();
int getCores();
void verRodadas(int* ant, int* atu);
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
    if(rodada < T_RODADAS){
      int *arr = gerarRodadas();
      for(int i=0; i < rodada; i++){
        digitalWrite(arr[i],HIGH);
        delay(1000);
        digitalWrite(arr[i],LOW);
      }
      free(old);
      old = copiarVetor(arr,rodada);
      rodada++;
      verRodadas(old,arr);
      free(arr);
    }
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

int *gerarRodadas(){
    int *arr = (int*) malloc(1024*rodada);
    
    for(int i=0;i < rodada;i++){
      // if(old != NULL){
      //   arr[i] = old[i];
      // }
      arr[i] = getCores();
    }
    return arr;
}

int getCores(){
  int r = random(0,4);
  if(r == 0)
    return VERMELHO;
  if(r == 1)
    return AZUL;
  if(r == 2)
    return VERDE;
  if(r == 3)
    return AMARELO;
  return 0;
}

int *copiarVetor(int *v, int len){
  int *t = (int*) malloc(1024 * len);
  for(int i = 0; i < len; i++ ){
    t[i] = v[i];
  }
  return t;
}

void verRodadas(int* ant, int* atu){
  Serial.println("\nant");
  for(int i = 0; i < (sizeof(ant) / sizeof(ant[0])); i++ ){
    Serial.print(ant[i]);
    Serial.print(" ");
  }
  Serial.println("\natu");
  for(int i = 0; i < (sizeof(atu) / sizeof(atu[0])); i++ ){
    Serial.print(atu[i]);
    Serial.print(" ");
  }
}