#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.c"
#include "logica.c"

int main () {
// Define o estado inicial
    int repetir = 1, contComandos = 0; 
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro (*e, stdout);
    while (repetir != 0)
    {
    mostra_jogadas (e, stdout);
    printf("(%d)\n", contComandos);
    repetir = interpretador (e);
    if (repetir == 0) return 0;
    if (repetir == 1) contComandos++;
    }
    return 0;
}

