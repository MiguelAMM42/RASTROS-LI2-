#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 64

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int coluna;
    int linha; 
} COORDENADA;


typedef struct {
        COORDENADA jogador1;
        COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];
typedef struct {
        CASA tab[8][8];
        COORDENADA ultima_jogada;
        JOGADAS jogadas;
        int num_jogadas;
        int jogador_atual;
} ESTADO;

