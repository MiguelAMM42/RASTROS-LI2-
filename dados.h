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
/**
\brief Altera a CASA numa dada coordenada
@param e Apontador para o Estado
@param s Apontador para o Coordenada
@param V Apontador para o tipo de CASA Novo
*/
void set_casa (ESTADO *e, COORDENADA c, CASA V);
/**
\brief Lê o tipo de casa de uma dada coordenada
@param e Apontador para o Estado
@param c Coordenada para procurar no Estado
@returns CASA da coordenada
*/
CASA get_casa (ESTADO *e, COORDENADA c);
/**
\brief Lê a última jogada a partir do Estado
@param e Apontador para o Estado
@param c Coordenada para procurar no Estado
*/
void set_ultima_jogada (ESTADO *e, COORDENADA c);
/**
\brief Lê a Coordenada da última jogada
@param e Apontador para o Estado
@returns COORDENADA da última jogada
*/
COORDENADA get_ultima_jogada (ESTADO *e);
/**
\brief Altera o número de jogadas
@param e Apontador para o Estado
@param n Número para alterar
*/
void set_num_jogadas (ESTADO *e, int n);
/**
\brief Descobre o número de jogadas
@param e Apontador para o Estado
@returns Número de jogadas
*/
int get_num_jogadas (ESTADO *e);
/**
\brief Altera o jogador atual
@param e Apontador para o Estado
@param n Número do novo jogador atual
*/
void set_jogador_atual (ESTADO *e, int n);
/**
\brief Altera o jogador atual
@param e Apontador para o Estado
@returns Número do jogador atual
*/
int get_jogador_atual (ESTADO *e);
/**
\brief Altera a lista de jogadas, numa posição e de um jogador 
@param e Apontador para o Estado
@param num_jogada Número da posição que será alterada, no array JOGADAS
@param jogador Jogador que será alterado
@param c Coordenada para acrescentar na lista
*/
void set_jogadas_coordenada (ESTADO *e, int num_jogada, int jogador, COORDENADA c);
/**
\brief Compara duas coordenadas 
@param a Coordenada
@param b Coordenada
@returns TRUE (1) ou FALSE (0), se as coordenadas são iguais ou não
*/
int coordenadaIgual (COORDENADA a, COORDENADA b);
/**
\brief Define o nº.de comandos
@param e Apontador para o Estado
@param n Número de comandos
*/
void set_num_comandos (ESTADO *e, int n);
/**
\brief Devolve o nº.de comandos
@param e Apontador para o Estado
*/
int get_num_comandos (ESTADO *e)

#endif


