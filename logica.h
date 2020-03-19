#ifndef ___LOGICA_H___
#define ___LOGICA_H___



int casaVazia (ESTADO *estado, COORDENADA c);
int jogar (ESTADO *estado, COORDENADA c);
int jogadaValida (ESTADO *estado, COORDENADA c);
int fimDoJogo (ESTADO *estado);
int anyBRANCA (CASA a[], int N);
int JogadasPossiveis (ESTADO *estado);
int CoordenadaValida (COORDENADA a);
void guarda_ficheiro (ESTADO *e, FILE *fp);
ESTADO le_ficheiro (ESTADO *e, FILE *fp);
void guardalinha (ESTADO *e, char linha[], int nlinha);

#endif
