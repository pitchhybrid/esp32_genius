#include <Arduino.h>
#include "button.hpp"
#include "led.hpp"

#define _BTNVR 14 // VERMELHO
#define _LEDVR 27 // VERMELHO

#define _BTNAZ 26 // AZUL
#define _LEDAZ 25 // AZUL

#define _BTNVD 33 // VERDE
#define _LEDVD 32 // VERDE

#define _BTNAM 12 // AMARELO
#define _LEDAM 13 // AMARELO

#define T_RODADAS 5

int rodada = 1;

int old[T_RODADAS] = {0};

typedef enum CORES
{
  VERMELHO = _LEDVR,
  AZUL = _LEDAZ,
  VERDE = _LEDVD,
  AMARELO = _LEDAM,
  NENHUM
} COR;

Button btnVR(_BTNVR);
Button btnAZ(_BTNAZ);
Button btnVD(_BTNVD);
Button btnAM(_BTNAM);

Led ledVR(_LEDVR);
Led ledAZ(_LEDAZ);
Led ledVD(_LEDVD);
Led ledAM(_LEDAM);

int *gerarRodadas();
int getCores();
void verRodadas(int ant[], int atu[]);
void copiar(int v[]);
COR buttonWait();
bool boucingButton(int least, int pin);
void atraso(int ms);

void setup()
{
  Serial.begin(115200);
  
  btnVR.iniciar();
  btnAZ.iniciar();
  btnVD.iniciar();
  btnAM.iniciar();

  ledVR.iniciar();
  ledAZ.iniciar();
  ledVD.iniciar();
  ledAM.iniciar();

  ledVR.acender();
  ledAZ.acender();
  ledVD.acender();
  ledAM.acender();
  
  atraso(500);

  ledVR.apagar();
  ledAZ.apagar();
  ledVD.apagar();
  ledAM.apagar();

  atraso(500);
}

void loop()
{
 
  CORES cor = buttonWait();
  Serial.println(cor);
  // if (rodada < T_RODADAS)
  // {

  //   int *arr = gerarRodadas();

  //   for (int i = 0; i < rodada; i++)
  //   {
  //     digitalWrite(arr[i], HIGH);
  //     delay(1000);
  //     digitalWrite(arr[i], LOW);
  //     delay(1000);
  //   }

  //   for (int i = 0; i < rodada; i++)
  //   {
  //     CORES cor = buttonWait();
  //     if (arr[i] == cor)
  //     {
  //       Serial.println("\ncerto");
  //     }
  //     else
  //     {
  //       Serial.println("\nerrado");
  //     }
  //   }

  //   rodada++;
  //   copiar(arr);
  // }
}

COR buttonWait()
{

  while (true)
  {
    if (btnVR.liberado())
    {
      // leastVR = HIGH;
      Serial.println("\nVERMELHO");
      return VERMELHO;
    }
    // if (!boucingButton(leastVD, _BTNVD))
    // {
    //   // leastVD = HIGH;
    //   Serial.println("\nVERDE");
    //   return VERDE;
    // }
    // if (!boucingButton(leastAZ, _BTNAZ))
    // {
    //   // leastAZ = HIGH;
    //   Serial.println("\nAZUL");
    //   return AZUL;
    // }
    // if (!boucingButton(leastAM, _BTNAM))
    // {
    //   // leastAM = HIGH;
    //   Serial.println("\nAMARELO");
    //   return AMARELO;
    // }
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
    return VERMELHO;
  if (r == 1)
    return AZUL;
  if (r == 2)
    return VERDE;
  if (r == 3)
    return AMARELO;
  return 0;
}

bool boucingButton(int least, int pin)
{
  int current = digitalRead(pin);
  if (least == LOW && current == HIGH)
  {
    least = current;
    delay(30);
  }
  return current;
}

void atraso(int ms){
  const long timeNow = millis();
  while (millis() < timeNow + ms);
};