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
    while (repetir == 1)
    {
    mostrar_tabuleiro (*e);
    repetir = interpretador (e);
    return 0;
    }
}
