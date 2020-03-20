/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___
#define  ___DADOS_H___
#define BUF_SIZE 1024

#define TRUE 1
#define FALSE 0
#define MAX 64
/**
\brief Tipo de dados para a casa
*/
typedef enum {
  UM = '1',
  DOIS = '2',
  VAZIO = '.',
  BRANCA = '*',
  PRETA = '#'
} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/

typedef struct {
  /** O tabuleiro */
    CASA tab[8][8];
  /** As jogadas */
    JOGADAS jogadas;
  /** O número das jogadas, usado no prompt */
    int num_jogadas;
  /** O jogador atual */
    int jogador_atual;
  /** O nº de comando, usado no prompt */
  int num_comando;
  /** A coordenada da última jogada */
  COORDENADA ultima_jogada;
} ESTADO;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

void set_casa (ESTADO *e, COORDENADA c, CASA V);

CASA get_casa (ESTADO *e, COORDENADA c);

void set_ultima_jogada (ESTADO *e, COORDENADA c);

COORDENADA get_ultima_jogada (ESTADO *e);

void set_num_jogadas (ESTADO *e, int n);

int get_num_jogadas (ESTADO *e);

void set_jogador_atual (ESTADO *e, int n);

int get_jogador_atual (ESTADO *e);

void set_jogadas_coordenada (ESTADO *e, int num_jogada, int jogador, COORDENADA c);

int coordenadaIgual (COORDENADA a, COORDENADA b);

#endif


