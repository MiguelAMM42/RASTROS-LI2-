#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logica.h"
#include "dados.h"




ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    for (int i = 0; i < 8; i++) {
        for (int ii = 0; ii < 8; ii ++) {
            if (i == 3 && ii == 4) (e -> tab [i][ii]) = PRETA;
            else (e -> tab [i][ii]) = VAZIO;                                                    
        }
    }
    return e;
}


void desenhaTabuleiro (ESTADO *s) {
    int i = 0;
    int linha = 0;
    for (linha = 0; linha < 8; linha++) {
        for (i = 0; i < 9; i++) {
            if (i == 8) putchar('\n');
            else {
                if (i == 7 && linha == 0) putchar ('2');
                else {
                    if (i == 0 && linha == 7) putchar ('1');
                    else {
                        if ((s -> tab [linha] [i]) == PRETA) putchar ('#');    // &(s -> registos[(s -> jogadas)
                        else {
                            if ((s -> tab [linha] [i]) == VAZIO) putchar ('.');
                            else putchar ('*'); 
                        }
                    }
                }
            }
        }
    }
}

void mostra_jogadas (ESTADO *s)  // Imprime a lista de jogadas
{ // Falta inicializar a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum != (s -> num_jogadas)) {
        printf ("%d : ", jogadaNum);
        printf ("%c%d", (((s -> jogadas) -> jogador1) .coluna) + 96, (((s -> jogadas) -> jogador1) .linha)); 
        printf ("%c%d ; \n", (((s -> jogadas) -> jogador2) .coluna) + 96, (((s -> jogadas) -> jogador2) .linha));
        jogadaNum ++;
    }
}

