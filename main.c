#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.c"
#include "logica.c"


int main () {
// Define o estado inicial
    int repetir = 1;
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro (*e);
    while (repetir == 1)
    {
    interpretador (e);
    mostrajogadas (e);          
    }
    return 0;
}
