#ifndef Main_h


#define _BTNVR 14 // VERMELHO
#define _LEDVR 27 // VERMELHO

#define _BTNAZ 26 // AZUL
#define _LEDAZ 25 // AZUL

#define _BTNVD 33 // VERDE
#define _LEDVD 32 // VERDE

#define _BTNAM 12 // AMARELO
#define _LEDAM 13 // AMARELO

#define T_RODADAS 5

typedef enum CORES
{
  VERMELHO = _LEDVR,
  AZUL = _LEDAZ,
  VERDE = _LEDVD,
  AMARELO = _LEDAM,
  NENHUM
} COR;

int *gerarRodadas();
int getCores();
void verRodadas(int ant[], int atu[]);
void copiar(int v[]);
COR buttonWait();
void atraso(int ms);
bool game(int arr[]);

#endif