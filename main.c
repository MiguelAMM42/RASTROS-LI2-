#include "interface.c"

int main () {
    ESTADO *e = inicializar_estado();
    desenhaTabuleiro (e);
    mostra_jogadas (e);
    return 0;    
}