/**
@file logica.h
Definição das funções relacionadas com o lógica do jogo.
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

/**
\brief Verifica se a casa destino está vazia
@param estado Apontador para o estado
@param c A coordenada
@returns Se a casa está livre ou não
*/
int casaVazia (ESTADO *e, COORDENADA *c);
/**
\brief Verifica se a jogada é possível, e  altera o estado
@param estado Apontador para o estado
@param c A coordenada
@returns Se a jogada é válida ou não
*/
int jogar (ESTADO *e, COORDENADA c);
/**
\brief Verifica se há um vencedor
@param estado Apontador para o estado
@returns Retorna o número do vencedor caso haja
*/
int Vencedor (ESTADO *e);
/**
\brief Verifica se a jogada é Válida
@param estado Apontador para o estado
@param c Coordenada da jogada
@returns Se a jogada é válida ou não
*/
int jogadaValida (ESTADO *e, COORDENADA *c);

/**
\brief Verifica se alguma das casas possíveis é vazia ou não
@param estado Apontador para o estado
@param c Apontador para a coordenada
@returns Retorna TRUE or FALSE 
*/
int anyVazio (ESTADO *e, COORDENADA *c);
/**
\brief Verifica se na última jogada do estado existe alguma casa livre
@param estado Apontador para o estado
@returns Retorna se é possível ou não
*/
int JogadasPossiveis (ESTADO *e);
 /**
\brief Verifica se Coordenada é válida
@param a Coordenada 
@returns Retorna se é possível ou não
*/
int CoordenadaValida (COORDENADA *c);
/**
\brief Lê um ficheiro com o Tabuleiro e as jogadas 
@param e Apontador para o estado
@param fp Apontador para o ficheiro
*/
void le_ficheiro (ESTADO *e, FILE *fp);
/**
\brief Lê um ficheiro com o Tabuleiro e altera o Estado
@param e Apontador para o estado
@param linha Linha do tabuleiro
@param nlinha Linha atual
@param contador Apontador para um contador que posteriormente irá calcular o número de jogadas
*/
void guardaLinha (ESTADO *e, char linha[], int nlinha, int *contador);
/**
\brief Lê um ficheiro com as Jogadas e altera o Estado
@param e Apontador para o estado
@param linha Linha do tabuleiro
@param num_jogada Número da jogada
@param n Número de jogadas
*/
void guardaJogadas (ESTADO *e, char linha[],int num_jogada ,int n);

#endif
