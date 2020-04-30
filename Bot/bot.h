/**
@file bot.h
Definição das funções relacionadas com o bot.
*/

#ifndef ___BOT_H___
#define ___BOT_H___

void inicializaMapa (MAPA m, ESTADO *e);
void flood_fill (int distAtual, MAPA m, COORDENADA cA);
int min_max_Estado (ESTADO *e, int min_max);
int test_min (MAPA m1, MAPA m2, int res, COORDENADA cA);
int test_max (MAPA m1, MAPA m2, int res, COORDENADA cA);
void mostrar_mapa (MAPA m);

COORDENADA jogadaOTIMA (ESTADO e, int comp, int alpha, int beta, int jogador);
int minimax(ESTADO e, int comp, int alpha, int beta, int Maximizar);

/**
brief Cria uma lista com os valores úteis para a heurística do Min_Max
@param e Apontador para o Estado
@param l lista de jogadas
@min_max Valor min_max
*/




#endif
