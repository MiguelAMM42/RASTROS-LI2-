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
    mostrar_tabuleiro (*e, stdout);
    while (repetir != 0)
    {
    mostra_prompt (e);
    repetir = interpretador (e);
    if (repetir == 0) return 0;
    }
    return 0;
}


