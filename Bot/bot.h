/**
@file bot.h
Definição das funções relacionadas com o bot.
*/

#ifndef ___BOT_H___
#define ___BOT_H___
/**
 * Para calcular as distâncias usamos uma matriz de inteiros, que indicam distâncias ou a casa, conformo o Estado.
 * A essa matriz chamamos MAPA.
 */

/**
\brief Função que transcreve para um mapa as casas já ocupadas, atribuindo-lhes o valor -1.
@param e Apontador para o Estado.
@param m Mapa pronto para ser inicializado, no início não tem valores corretos.
*/
void inicializaMapa (MAPA m, ESTADO *e);
/**
\brief Através da heutísitica do flood_fill, preenche as posições do mapa
@param distAtual Quando a função é chamada pela primeira vez, o valor é 0. 
@param e Apontador para o Estado
@param c Referência das distâncias, a partir deste ponto começa a contagem
*/
void flood_fill (int distAtual, MAPA m, COORDENADA cA);
/**
\brief Dá valores à coordenada atual, última jogada, a partir das distâncias.
@param e Apontador para o Estado.
@param jogAtual Jogador atual.
*/
int min_max_Estado (ESTADO *e, int jogAtual);
/**
\brief Calcula um valor a partir de 2 mapas e compara com o valor atual da coordenada, 
\brief analisando se é uma casa melhor do que a atual hipótese.
@param m1 Mapa cujo referencial é a coordenada (0,0).
@param m2 Mapa cujo referencial é a coordenada (7,7).
@param res Melhor hipótese até agora da coordenada atual.
@param cA Coordenada para ver nos 2 mapas.
*/
int test_min (MAPA m1, MAPA m2, int res, COORDENADA cA);
/**
\brief Função similar à função anterior.
@param m1 Mapa cujo referencial é a coordenada (0,0).
@param m2 Mapa cujo referencial é a coordenada (7,7).
@param res Melhor hipótese até agora da coordenada atual.
@param cA Coordenada para ver nos 2 mapas.
*/
int test_max (MAPA m1, MAPA m2, int res, COORDENADA cA);
/**
\brief Função utilizada para imprimir um tabuleiro, para visualizar melhor o mapa.
@param m1 Mapa cujo referencial é a coordenada (0,0).
*/
void mostrar_mapa (MAPA m);

COORDENADA jogadaOTIMA (ESTADO e, int comp, int alpha, int beta, int jogador);
int minimax(ESTADO e, int comp, int alpha, int beta, int Maximizar);
/**
\brief Função que vai buscar um valor ao mapa.
@param col Coluna para procurar no MAPA.
@param lin Linha para procurar no MAPA.
@param m Mapa para procurar.
*/
int getCasaBOT (int col, int lin, MAPA m);
/**
\brief Função que altera um valor ao mapa.
@param col Coluna para procurar no MAPA.
@param lin Linha para procurar no MAPA.
@param m Mapa para procurar.
@param subst Valor para inserir no mapa (m).
*/
void setCasaBOT (int col, int lin, MAPA m, int subst);
int valor(ESTADO *e, int jogador);

/**
brief Cria uma lista com os valores úteis para a heurística do Min_Max
@param e Apontador para o Estado
@param l lista de jogadas
@min_max Valor min_max
*/




#endif
