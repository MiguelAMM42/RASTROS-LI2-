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
int jogadaValida (ESTADO *estado, COORDENADA c);
int fimDoJogo (ESTADO *estado);
int anyBRANCA (CASA a[], int N);
int JogadasPossiveis (ESTADO *estado);
int CoordenadaValida (COORDENADA a);
void guarda_ficheiro (ESTADO *e, FILE *fp);
void le_ficheiro (ESTADO *e, FILE *fp);
void guardaLinha (ESTADO *e, char linha[], int nlinha);
void guardaJogadas (ESTADO *e, char linha[],int num_jogada ,int n);

#endif
