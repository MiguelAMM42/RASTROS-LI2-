#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.h"

int casaVazia(ESTADO *teste1, COORDENADA c) {
	//primeiro ve se a casa de destino está vazia
    // 1 para vazia; 0 n vazia    
    int n, m;
    n = c.coluna;   // COLUNA DA JOGADA
    m = c.linha;   // LINHA DA JOGADA
    if (teste1 -> tab [m] [n] == VAZIO) return TRUE;
    else return FALSE;
}




int jogadaValida(ESTADO *teste1, COORDENADA c) {
    //primeiro ve se ajogada é valida
    //depois modifica o estado se for válida
    // 1 para válida; 0 n valida    
    int b, n, m, y , z;
    b = teste1 -> jogador_atual;
    y = (teste1 -> ultima_jogada).coluna;
    z = (teste1 -> ultima_jogada).linha;
    n = c.coluna;
    m = c.linha;
    if (((n > 1) && (n < 8)) && ((m > 1) && (m < 8)) && ((n == y) || (n == y+1) || (n == y-1)) && ((m == z) || (m == z+1) || (m == z-1)) ) return TRUE;
    else return FALSE;
}

int jogar(ESTADO *teste1, COORDENADA c) {
    //primeiro ve se a jogada é valida
    //depois modifica o estado se for válida
    // 1 para válida; 0 n valida    
    int b, n, m, y , z, j, p;
    j = jogadaValida(teste1, c);
    p = casaVazia(teste1, c);
    if (!p)return 0;
    if (!j)return 0;
    b = teste1 -> jogador_atual ;   //JOGADOR ATUAL
    y = (teste1 -> ultima_jogada).coluna;   // COLUNA ULTIMA JOGADA
    z = (teste1 -> ultima_jogada).linha;   // LINHA ULTIMA JOGADA
    n = c.coluna;   // COLUNA DA JOGADA
    m = c.linha;   // LINHA DA JOGADA
    teste1 -> tab [z] [y] = BRANCA; // ALTERA A CASA PARA PRETA, VERIFICAR SE É Y / Z OU Z / Y
    teste1 -> tab [m] [n] = PRETA; // IGUAL A CIMA
    // Alterar no array de jogadas, acrescentar a atual
    int jogadaAtual;
    jogadaAtual = (teste1->num_jogadas);
    if (b == 1) {
    ((teste1 -> jogadas[jogadaAtual].jogador1).coluna) = n;
    ((teste1 -> jogadas[jogadaAtual].jogador1).linha) = m;
                }
    else        {
    ((teste1 -> jogadas[jogadaAtual].jogador2).coluna) = n;
    ((teste1 -> jogadas[jogadaAtual].jogador2).linha) = m; 
                }

    (teste1->ultima_jogada).coluna = n;
        (teste1->ultima_jogada).linha = m;  
    (teste1 -> num_jogadas) = jogadaAtual + 1;
    if ( b == 2) teste1 -> jogador_atual = 1;
    else teste1 -> jogador_atual = 2;
    printf ("\n jogador atual %d", (teste1 -> jogador_atual));
    printf ("\n num jogadas %d \n", jogadaAtual);
    
    return 1;
}
