#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.c"
#include "logica.c"

int main () {
// Define o estado inicial
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro (*e);
    interpretador (e);
    return 0;
}
