#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interface.h"
#include "logica.h"
#include "dados.h"

void mostra_jogadas (ESTADO *s)  // Imprime a lista de jogadas
{ // Falta inicializar a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum < (s -> num_jogadas) -2) {
        printf ("%d : ", jogadaNum);
        printf ("%c %d / ", (((s -> jogadas[0]) -> jogador1) .coluna) + 96, (((s -> jogadas) -> jogador1) .linha)); 
        printf ("%c %d ;\n", (((s -> jogadas[0]) -> jogador2) .coluna) + 96, (((s -> jogadas) -> jogador2) .linha));
        jogadaNum++;
    }
    if (jogadaNum == (s -> num_jogadas) -2)
        {
            if ((s -> jogador_atual) == 1) printf ("é a vez do jogador 1!");
            else {
                    printf ("%d : ", jogadaNum);
                    printf ("%c %d / ", (((s -> jogadas) -> jogador1) .coluna) + 96, (((s -> jogadas) -> jogador1) .linha)); 
                    printf ("È a vez do jogador 2!\n");
                 }
        
        }
        
}
