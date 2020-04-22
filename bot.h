/**
@file bot.h
Definição das funções relacionadas com o bot.
*/

#ifndef ___BOT_H___
#define ___BOT_H___

typedef struct minmax {
   COORDENADA jogada;
   struct minmax *jogadas[3][3]; // Outros nodos com outras tipos de jogadas
} *MinMax;


/**
brief Cria uma lista com os valores úteis para a heurística do Min_Max
@param e Apontador para o Estado
@param l LISTA com os valores
@min_max Valor min_max
*/
LISTA min_max_Lista (ESTADO *e, LISTA l, int min_max) ;
/**
brief Atribui um valor(usado na criação da lista para a heurística Min_Max)
@param e Apontador para o Estado
@param c Apontador para a COORDENADA
@returns Atribui 10(provisoriamente) à Coordenada
*/
int valorC (ESTADO *e, COORDENADA *c);

void CriaNivel (ESTADO *e, MinMax jogada, int comp);
MinMax adicionarCoordenadaMinMax (ESTADO *e, COORDENADA *c, MinMax l, int linha, int coluna, int comp);
#endif
