#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.h"

int casaVazia(ESTADO *estado, COORDENADA c) {
	// Primeiro ve se a casa de destino está vazia
    // 1 para vazia; 0 n vazia    
    int n, m;
    n = c.coluna;   // COLUNA DA JOGADA
    m = c.linha;   // LINHA DA JOGADA
    if (estado -> tab [m] [n] == VAZIO) return TRUE;
    else return FALSE;
}


int jogadaValida(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    int b, n, m, y , z;
    b = estado -> jogador_atual;
    y = (estado -> ultima_jogada).coluna;
    z = (estado -> ultima_jogada).linha;
    n = c.coluna;
    m = c.linha;
    if (((n > 1) && (n < 8)) && ((m > 1) && (m < 8)) && ((n == y) || (n == y+1) || (n == y-1)) && ((m == z) || (m == z+1) || (m == z-1)) && casaVazia(estado, c)) return TRUE;
    else return FALSE;
}

int jogar(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    // 1 - Devolve o Estado com a jogada efetuada; 0 - Devolve o estado inicial (a jogada não é válida)    
    int b, n, m, y , z, j, p;
    j = jogadaValida(estado, c);
    p = casaVazia(estado, c);
    if (!(p && j)) return 0; // Caso em que a jogada pretendida não é válida.
    b = estado -> jogador_atual ;   // JOGADOR ATUAL
    y = (estado -> ultima_jogada).coluna;   // COLUNA ULTIMA JOGADA
    z = (estado -> ultima_jogada).linha;   // LINHA ULTIMA JOGADA
    n = c.coluna;   // COLUNA DA JOGADA
    m = c.linha;   // LINHA DA JOGADA
    estado -> tab [z] [y] = PRETA; // ALTERA A CASA PARA PRETA, VERIFICAR SE É Y / Z OU Z / Y
    estado -> tab [m] [n] = BRANCA; // IGUAL A CIMA
    // Alterar no array de jogadas, acrescentar a atual
    if (b == 1) {
        estado -> num_jogadas ++;
        ((estado -> jogadas[estado -> num_jogadas - 1].jogador2).coluna) = y;
        ((estado -> jogadas[estado -> num_jogadas - 1].jogador2).linha) = z;
        (estado -> ultima_jogada) = c;
        estado -> jogador_atual = 2;
    } else {
        ((estado -> jogadas[estado -> num_jogadas].jogador1).coluna) = y;
        ((estado -> jogadas[estado -> num_jogadas].jogador1).linha) = z;
        (estado -> ultima_jogada) = c;
        estado -> jogador_atual = 1;
    }
    return 1;
}
