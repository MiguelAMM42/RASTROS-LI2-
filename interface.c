#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "logica.h"


ESTADO *inicializar_estado() {
    ESTADO *teste1 = (ESTADO *) malloc(sizeof(ESTADO));
    teste1 -> jogador_atual = 1;
    teste1 -> num_jogadas = 0;
    teste1 -> ultima_jogada.coluna = 4;
    teste1 -> ultima_jogada.linha = 3;
    for (int i = 0; i < 8; i++) {
        for (int ii = 0; ii < 8; ii ++) {
            if (i == 3 && ii == 4) (teste1 -> tab [i] [ii]) = BRANCA;
            else (teste1 -> tab [i] [ii]) = VAZIO;                                          
        }
    }
    return teste1;
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
                        if ((s -> tab [linha] [i]) == BRANCA) putchar ('*');
                        else {
                            if ((s -> tab [linha] [i]) == VAZIO) putchar ('.');
                            else putchar ('#'); 
                        }
                    }
                }
            }
        }
    }
}

void mostra_jogadas (ESTADO *s) {  // Imprime a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum < (s -> num_jogadas)) 
    {
        if ( jogadaNum < 10)   printf ("0%d : ", jogadaNum + 1);
        else printf ("%d : ", jogadaNum + 1);
        printf ("%c %d / ", 'a' + (((s -> jogadas[jogadaNum]).jogador1).coluna) , (((s -> jogadas[jogadaNum]).jogador1).linha)); 
        printf ("%c %d ;\n", 'a' + (((s -> jogadas[jogadaNum]).jogador2).coluna) , (((s -> jogadas[jogadaNum]).jogador2).linha));
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 1) printf ("\nÉ a vez do jogador 1! \n");
    else {
        if ( jogadaNum < 10)   printf ("0%d : ", jogadaNum + 1);
        else printf ("%d : ", jogadaNum + 1);
        printf ("%c %d / \n", 'a' + (((s -> jogadas[s -> num_jogadas]).jogador1) .coluna), (((s -> jogadas[s -> num_jogadas]).jogador1) .linha)); 
        printf ("È a vez do jogador 2!\n");
    }        
}
