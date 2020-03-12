#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.c"
#include "logica.c"

int main () {
// Defenir o estado inicial, preenche as casas com Branco
    ESTADO *teste1 = inicializar_estado();
   /* ESTADO teste1; 
    for (int i = 0; i < 8; i++) {
                                 for (int ii = 0; ii < 8; ii ++) 
                                                {   if (i == 3 && ii == 4) teste1.tab [i] [ii] = PRETA;
                                                    else teste1.tab [i] [ii] = VAZIO;
                                                        
                                                }
                                }
   
    teste1.jogador_atual = 2;
    teste1.num_jogadas = 5;
    teste1.ultima_jogada.coluna = 5;
    teste1.ultima_jogada.linha = 4;
    ((((&teste1) -> jogadas[0]).jogador1) .coluna) = 3;
    ((((&teste1) -> jogadas[0]).jogador1) .linha) = 4;
    ((((&teste1) -> jogadas[0]).jogador2) .coluna) = 5;
    ((((&teste1) -> jogadas[0]).jogador2) .linha) = 4;
    ((((&teste1) -> jogadas[2]).jogador1) .coluna) = 6;
    ((((&teste1) -> jogadas[2]).jogador1) .linha) = 6;

    ((((&teste1) -> jogadas[2]).jogador2).coluna) = 7;
    ((((&teste1) -> jogadas[2]).jogador2).linha) = 7 ;

    ((((&teste1) -> jogadas[3]).jogador1).linha) = 1 ;

    ((((&teste1) -> jogadas[3]).jogador1).coluna) = 1 ;
*/
    /*
    coordenada v = {'a',5};
    teste1.registos[0] = v;
    coordenada v1 = {'b', 5};
    teste1.registos[1] = v1; */
    printf ("\n \n");
    desenhaTabuleiro (teste1);
    printf ("\n \n");
    mostra_jogadas (teste1);
    COORDENADA c1 = {4, 4};
    if ((jogadaValida(teste1, c1) && casaVazia(teste1,c1))) printf ("1");
    else printf("0");
    jogar (teste1, c1);
    desenhaTabuleiro (teste1);
    printf ("\n \n");
    mostra_jogadas (teste1);
    COORDENADA c2 = {5, 4};
    if ((jogadaValida (teste1, c2) && casaVazia(teste1,c2))) printf ("1");
    else printf("0");
    jogar (teste1, c2);
    desenhaTabuleiro (teste1);
    printf ("\n \n");
    mostra_jogadas (teste1);
    COORDENADA c3 = {4, 4};
    if ((jogadaValida (teste1, c3) && casaVazia(teste1,c3))) printf ("1");
    else printf("0\n");
    jogar (teste1, c3);
    desenhaTabuleiro (teste1);
    printf ("\n \n");
    mostra_jogadas (teste1);
    COORDENADA c4 = {1, 1};
    if ((jogadaValida (teste1, c4) && casaVazia(teste1,c4))) printf ("1");
    else printf("0\n");
    jogar (teste1, c4);
    desenhaTabuleiro (teste1);
    printf ("\n \n");
    mostra_jogadas (teste1);
    
    
    /*
    while (1) {
         printf ("Qual A jogada?");

        } */
    return 0;
    
// (s -> registos [++ (s -> jogadas)]) = *jogada;
    

}
