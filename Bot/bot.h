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
\brief Através da heutísitica do flood_fill, preenche as posições do mapa.
@param distAtual Quando a função é chamada pela primeira vez, o valor é 0. 
@param e Apontador para o Estado.
@param c Referência das distâncias, a partir deste ponto começa a contagem.
*/
void flood_fill (int distAtual, MAPA m, COORDENADA cA);
/**
\brief Dá valores à coordenada atual, última jogada, a partir das distâncias.
@param e Apontador para o Estado.
@param jogAtual Jogador atual.
@returns Valor da casa(entre -200 e 200)
*/
int min_max_Estado (ESTADO *e, int jogAtual);
/**
\brief Calcula um valor a partir de 2 mapas e compara com o valor atual da coordenada, 
\brief analisando se é uma casa melhor do que a atual hipótese.
@param m1 Mapa cujo referencial é a coordenada (0,0).
@param m2 Mapa cujo referencial é a coordenada (7,7).
@param res Melhor hipótese até agora da coordenada atual.
@param cA Coordenada para ver nos 2 mapas.
@returns Menor valor pequeno à volta daquela casa.
*/
int test_min (MAPA m1, MAPA m2, int res, COORDENADA cA);
/**
\brief Função similar à função anterior.
@param m1 Mapa cujo referencial é a coordenada (0,0).
@param m2 Mapa cujo referencial é a coordenada (7,7).
@param res Melhor hipótese até agora da coordenada atual.
@param cA Coordenada para ver nos 2 mapas.
@returns Maior valor à volta daquela casa.
*/
int test_max (MAPA m1, MAPA m2, int res, COORDENADA cA);
/**
\brief Função utilizada para imprimir um tabuleiro, para visualizar melhor o mapa.
@param m1 Mapa cujo referencial é a coordenada (0,0).
*/
void mostrar_mapa (MAPA m);
/**
\brief Função que devolve a melhor coordenada para a qual se pode jogar.
@param e Estado do tabuleiro.
@param comp Comprimento até onde vai a MiniMax.
@param alpha Alpha é o melhor valor que a função maximixadora pode garantir naquele nível ou mais à frente.
@param beta Beta é o melhor valor que a função minimizadora pode garantir naquele nível ou mais à frente.
@param jogador Número do jogador(1 ou 2).
*/
COORDENADA jogadaOTIMA (ESTADO e, int comp, int alpha, int beta, int jogador);
/**
\brief Função que dexecuta a heurística MiniMax.
@param e Estado do tabuleiro.
@param comp Comprimento até onde vai a MiniMax.
@param alpha Alpha é o melhor valor que a função maximixadora pode garantir naquele nível ou mais à frente.
@param beta Beta é o melhor valor que a função minimizadora pode garantir naquele nível ou mais à frente.
@param jogador Maximizar 0 se fôr para maximizar. Outro número para minimizar.
@returns Devolve o valor máximo se maximizou. Devolve o valor mínimo se minimizou.
*/
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
/**
\brief Função que atribui um valor a cada casa do tabuleiro.
@param e Apontador para o estado.
@param jogador Número do jogador(1 ou 2).
@returns valor 
*/
int valor(ESTADO *e, int jogador);
/**
\brief Função que contam o número de casas alcançáveis vazias no tabuleiro.
@param m Mapa cujos valores fornecem a informação se certa peça é ou não alcançável.
@returns Número de casas vazias.
*/
int contaVazias(MAPA m);
/**
\brief Função que dá informação sobre a paridade.
@param e Apontador para o estado.
@returns 200 se a jogada é boa para o jogador 1; -200 se é boa para o jogador 2.
*/
 int paridade(ESTADO *e);




#endif
