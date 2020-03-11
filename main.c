#include "interface.c"
#include "logica.c"
#include "dados.h"

int main () {
    ESTADO *e = inicializar_estado();
    desenhaTabuleiro (e);
    mostra_jogadas (e);
    COORDENADA c1 = {4, 4};
    jogar (e, c1);
    printf ("\n");
    desenhaTabuleiro (e);
    return 0;    
}
