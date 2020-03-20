#ifndef ___LOGICA_H___
#define ___LOGICA_H___

/**
\brief Verifica se a casa destino está vazia
@param estado Apontador para o estado
@param c A coordenada
@returns Se a casa está livre ou não
*/
int casaVazia (ESTADO *estado, COORDENADA c);
/**
\brief Verifica se a jogada é possível, e  altera o estado
@param estado Apontador para o estado
@param c A coordenada
@returns Se a jogada é válida ou não
*/
int jogar (ESTADO *estado, COORDENADA c);
/**
\brief Verifica se a jogada é Válida
@param estado Apontador para o estado
@param c Coordenada da jogada
@returns Se a jogada é válida ou não
*/
int jogadaValida (ESTADO *estado, COORDENADA c);
/**
\brief Verifica se o jogo acaba
@param estado Apontador para o estado
@returns Retorna o fim ou não do jogo
*/
int fimDoJogo (ESTADO *estado);
/**
\brief Verifica se alguma das casas possíveis é vazia ou não
@param estado Apontador para o estado
@param c Apontador para a coordenada
@returns Retorna TRUE or FALSE 
*/
int anyVazio (ESTADO *e, COORDENADA c);
/**
\brief Verifica se na última jogada do estado existe alguma casa livre
@param estado Apontador para o estado
@returns Retorna se é possível ou não
*/
int JogadasPossiveis (ESTADO *estado);
 /**
\brief Verifica se Coordenada é válida
@param a Coordenada 
@returns Retorna se é possível ou não
*/
int CoordenadaValida (COORDENADA a);
/**
\brief Guarda um ficheiro com o Tabuleiro e as jogadas 
@param e Apontador para o estado
@param fp Apontador para o ficheiro
*/
void guarda_ficheiro (ESTADO *e, FILE *fp);
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
*/
void guardaLinha (ESTADO *e, char linha[], int nlinha);
/**
\brief Lê um ficheiro com as Jogadas e altera o Estado
@param e Apontador para o estado
@param linha Linha do tabuleiro
@param num_jogada Número da jogada
@param n Número de jogadas
*/
void guardaJogadas (ESTADO *e, char linha[],int num_jogada ,int n);

#endif
