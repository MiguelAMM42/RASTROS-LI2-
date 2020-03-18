#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.h"
#include "interface.h"


int jogar (ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    // 1 - Devolve o Estado com a jogada efetuada; 0 - Devolve o estado inicial (a jogada não é válida)
    if (! jogadaValida(estado, c)) return 0; // Caso em que a jogada pretendida não é válida.
    estado -> tab [(estado -> ultima_jogada).linha] [(estado -> ultima_jogada).coluna] = PRETA; // Altera a casa BRANCA da jogada anterior para PRETA 
    estado -> tab [c.linha] [c.coluna] = BRANCA; //  Altera a casa VAZIO da jogada atual para BRANCA 
    // Alterar no array de jogadas, acrescentar a atual
    // Coloca a última jogada no array de Jogadas #1
    // Altera a última jogada para a jogada que o jogador pretende efetuar #2
    // Muda o jogador atual para o seguinte #3
    if (estado -> jogador_atual == 1) {
        ((estado -> jogadas[estado -> num_jogadas].jogador1).coluna) = c.coluna; // #1
        ((estado -> jogadas[estado -> num_jogadas].jogador1).linha) = c.linha; // #1
        (estado -> ultima_jogada) = c; // #2
        estado -> jogador_atual = 2; // #3
    } else {
        ((estado -> jogadas[estado -> num_jogadas].jogador2).coluna) = c.coluna; // #1
        ((estado -> jogadas[estado -> num_jogadas].jogador2).linha) = c.linha; // #1
        (estado -> ultima_jogada) = c; // #2
        estado -> jogador_atual = 1; // #3
        estado -> num_jogadas ++;
    }
    // Casos em que o jogo se dá como terminado
    if (! JogadasPossiveis (estado)) { // Não há jogadas possíveis
        printf ("O vencedor é o jogador %d.", 3 - estado -> jogador_atual);
        return 2;
    } else if (c.linha == 1 && c.coluna == 1) { // A casa 'a1' é alcançada
        printf ("O vencedor é o jogador %d.", 1);
        return 2;
    } else if (c.linha == 8 && c.coluna == 8) { // A casa 'h8' é alcançada
        printf ("O vencedor é o jogador %d.", 2);
        return 2;
    }

    return 1;
}


int casaVazia(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a casa de destino está vazia
    // 1 para vazia; 0 n vazia    
    int n, m;
    n = c.coluna;   // COLUNA DA JOGADA           VER SE TEMOS DE TROCAR O M POR N; NÃO TENHO A CERTEZA...
    m = c.linha;   // LINHA DA JOGADA
    if (estado -> tab [m] [n] == VAZIO) return TRUE;
    else return FALSE;
}


int jogadaValida(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    int b, n, m, y, z;
    b = estado -> jogador_atual;
    y = (estado -> ultima_jogada).coluna;
    z = (estado -> ultima_jogada).linha;
    n = c.coluna;
    m = c.linha;
    if (((n > 1) && (n < 8)) && ((m > 1) && (m < 8)) && ((n == y) || (n == y + 1) || (n == y - 1)) && ((m == z) || (m == z + 1) || (m == z - 1)) && casaVazia(estado, c) && CoordenadaValida (c)) return TRUE;
    else return FALSE;
}

int JogadasPossiveis (ESTADO *estado) {
    COORDENADA c = estado -> ultima_jogada;
    CASA tabuleiro [8][8] = estado -> tab;
    CASA p [] = {tabuleiro[c.linha + 1][c.coluna + 1], tabuleiro[c.linha - 1][c.coluna - 1], tabuleiro[c.linha + 1][c.coluna - 1], tabuleiro[c.linha - 1][c.coluna + 1], tabuleiro[c.linha + 1][c.coluna], tabuleiro[c.linha - 1][c.coluna], tabuleiro[c.linha][c.coluna + 1], tabuleiro[c.linha][c.coluna - 1]};
    if (anyBRANCA(p, 8)) return TRUE;

}

int anyBRANCA (CASA a[], int N) {
    int i = 0;
    while (i != N) {
        if (a[i] == BRANCA) return TRUE;
        i ++;
    }
    return FALSE;
}

int CoordenadaValida (COORDENADA a) {
    if (a.linha <= 8 && a.linha >= 1 && a.coluna >= 'a' && a.coluna <= 'h') return TRUE;
    return FALSE;
}

