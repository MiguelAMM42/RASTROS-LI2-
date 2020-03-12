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
    if (!(p && j)) return 0;
    b = teste1 -> jogador_atual ;   //JOGADOR ATUAL
    y = (teste1 -> ultima_jogada).coluna;   // COLUNA ULTIMA JOGADA
    z = (teste1 -> ultima_jogada).linha;   // LINHA ULTIMA JOGADA
    n = c.coluna;   // COLUNA DA JOGADA
    m = c.linha;   // LINHA DA JOGADA
    teste1 -> tab [z] [y] = PRETA; // ALTERA A CASA PARA PRETA, VERIFICAR SE É Y / Z OU Z / Y
    teste1 -> tab [m] [n] = BRANCA; // IGUAL A CIMA
    // Alterar no array de jogadas, acrescentar a atual
    if (b == 1) {
        teste1 -> num_jogadas ++;
        ((teste1 -> jogadas[teste1 -> num_jogadas - 1].jogador2).coluna) = y;
        ((teste1 -> jogadas[teste1 -> num_jogadas - 1].jogador2).linha) = z;
        (teste1 -> ultima_jogada) = c;
        teste1 -> jogador_atual = 2;
    }
    else {
        ((teste1 -> jogadas[teste1 -> num_jogadas].jogador1).coluna) = y;
        ((teste1 -> jogadas[teste1 -> num_jogadas].jogador1).linha) = z;
        (teste1 -> ultima_jogada) = c;
        teste1 -> jogador_atual = 1;
    }
    return 1;
}
