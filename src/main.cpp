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

int rodada = 1;

int old[T_RODADAS] = {0};

enum CORES
{
  VERMELHO = LEDVR,
  AZUL = LEDAZ,
  VERDE = LEDVD,
  AMARELO = LEDAM,
  NENHUM
};

bool leastVR = HIGH;
bool leastVD = HIGH;
bool leastAZ = HIGH;
bool leastAM = HIGH;

int *gerarRodadas();
int getCores();
void verRodadas(int ant[], int atu[]);
void copiar(int v[]);
CORES buttonWait();
void apagar(int btn);
bool boucingButton(int least, int pin);
void setup()
{
  Serial.begin(115200);
  pinMode(BTNVR, INPUT_PULLUP);
  pinMode(LEDVR, OUTPUT);
  pinMode(BTNAZ, INPUT_PULLUP);
  pinMode(LEDAZ, OUTPUT);
  pinMode(BTNVD, INPUT_PULLUP);
  pinMode(LEDVD, OUTPUT);
  pinMode(BTNAM, INPUT_PULLUP);
  pinMode(LEDAM, OUTPUT);

  digitalWrite(VERMELHO, HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, HIGH);
  digitalWrite(AMARELO, HIGH);
  delay(500);
  digitalWrite(VERMELHO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(AMARELO, LOW);
  delay(500);
}

void loop()
{
 
  if (rodada < T_RODADAS)
  {

    int *arr = gerarRodadas();

    for (int i = 0; i < rodada; i++)
    {
      digitalWrite(arr[i], HIGH);
      delay(1000);
      digitalWrite(arr[i], LOW);
      delay(1000);
    }
    
    for(int i= 0;i < rodada; i++){
      CORES cor = buttonWait();
      if(arr[i] == cor){
        Serial.println("\ncerto");
      }else{
        Serial.println("\nerrado");
      }
    }

    

    rodada++;
    copiar(arr);
  }
}

CORES buttonWait()
{

  while (true)
  {
    if (!boucingButton(leastVR,BTNVR))
    {
      // leastVR = HIGH;
      // Serial.println("\nVERMELHO");
      return VERMELHO;
    }
    if (!boucingButton(leastVR,BTNVD))
    {
      // leastVD = HIGH;
      // Serial.println("\nVERDE");
      return VERDE;
    }
    if (!boucingButton(leastVR,BTNAZ))
    {
      // leastAZ = HIGH;
      // Serial.println("\nAZUL");
      return AZUL;
    }
    if (!boucingButton(leastVR,BTNAM))
    {
      // leastAM = HIGH;
      // Serial.println("\nAMARELO");
      return AMARELO;
    }
  }
  return NENHUM;
}

void copiar(int v[])
{
  for (int i = 0; i < T_RODADAS; i++)
  {
    old[i] = v[i];
  }
}

void apagar(int btn)
{
  switch (btn)
  {
  case BTNVR:
    digitalWrite(VERMELHO, LOW);
    break;
  case BTNVD:
    digitalWrite(VERDE, LOW);
    break;
  case BTNAZ:
    digitalWrite(AZUL, LOW);
    break;
  case BTNAM:
    digitalWrite(AMARELO, LOW);
    break;
  }
}

int *gerarRodadas()
{
  static int arr[T_RODADAS] = {0};
  for (int i = 0; i < T_RODADAS; i++)
  {
    if (old[i] != 0)
    {
      arr[i] = old[i];
    }
    if (i < rodada)
    {
      if (arr[i] == 0)
      {
        arr[i] = getCores();
      }
    }
  }
  return arr;
}

int getCores()
{
  int r = random(0, 4);
  if (r == 0)
    return LEDVR;
  if (r == 1)
    return LEDAZ;
  if (r == 2)
    return LEDVD;
  if (r == 3)
    return LEDAM;
  return 0;
}

bool boucingButton(int least, int pin){
  int current = digitalRead(pin);
  if(least == LOW && current == HIGH ){
    least = current;
    delay(50);
  }
  return current;
}