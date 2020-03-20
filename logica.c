#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dados.c"


int jogar (ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    // 1 - Devolve o Estado com a jogada efetuada; 0 - Devolve o estado inicial (a jogada não é válida)
    if (! jogadaValida(estado, c)) return 0; // Caso em que a jogada pretendida não é válida.
    set_casa (estado, get_ultima_jogada (estado), PRETA); // Altera a casa BRANCA da jogada anterior para PRETA 
    set_casa (estado, c, BRANCA); //  Altera a casa VAZIO da jogada atual para BRANCA 
    // Alterar no array de jogadas, acrescentar a atual
    // Coloca a última jogada no array de Jogadas #1
    // Altera a última jogada para a jogada que o jogador pretende efetuar #2
    // Muda o jogador atual para o seguinte #3
    if (get_jogador_atual (estado) == 1) {
        set_jogadas_coordenada (estado, get_num_jogadas(estado), 1, c); // #1
        set_ultima_jogada (estado, c); // #2
        set_jogador_atual (estado, 2); // #3
    } else {
        set_jogadas_coordenada (estado, get_num_jogadas(estado), 2, c); // #1
        set_ultima_jogada (estado, c); // #2
        set_jogador_atual (estado, 1); // #3
        set_num_jogadas (estado, get_num_jogadas(estado) + 1);
    }
    // Casos em que o jogo se dá como terminado
    COORDENADA a1 = {0, 0};
    COORDENADA h8 = {7, 7};
    if (coordenadaIgual (a1, c)) { // A casa 'a1' é alcançada
        printf ("O vencedor é o jogador %d.\n", 1);
        return 2;
    } else if (coordenadaIgual (h8, c)) { // A casa 'h8' é alcançada
        printf ("O vencedor é o jogador %d.\n", 2);
        return 2;
    }
    /*else if (! JogadasPossiveis (estado)) { // Não há jogadas possíveis
        printf ("O vencedor é o jogador %d.\n", 3 - estado -> jogador_atual);
        return 2;
    }
    */
    return 1;
}


int casaVazia(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a casa de destino está vazia
    // 1 para vazia; 0 n vazia    
    int n, m;
    if (get_casa (estado, c) != PRETA || get_casa (estado, c) != BRANCA) return TRUE;
    else return FALSE;
}


int jogadaValida(ESTADO *estado, COORDENADA c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    int n, m, y, z;
    y = (estado -> ultima_jogada).coluna;
    z = (estado -> ultima_jogada).linha;
    n = c.coluna;
    m = c.linha;
    if (((n == y) || (n == y + 1) || (n == y - 1)) && ((m == z) || (m == z + 1) || (m == z - 1)) && casaVazia(estado, c)) return TRUE;
    else return FALSE;
}

//Something is wrong in Jogadas_Possiveis

int JogadasPossiveis (ESTADO *estado) {
    COORDENADA c = estado -> ultima_jogada;
    CASA p [] = {estado -> tab[c.linha + 1][c.coluna + 1], estado -> tab[c.linha - 1][c.coluna - 1], estado -> tab[c.linha + 1][c.coluna - 1], estado -> tab[c.linha - 1][c.coluna + 1], estado -> tab[c.linha + 1][c.coluna], estado -> tab[c.linha - 1][c.coluna], estado -> tab[c.linha][c.coluna + 1], estado -> tab[c.linha][c.coluna - 1]};
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


void guarda_ficheiro (ESTADO *e, FILE *fp) {
    mostrar_tabuleiro (*e, fp);
    fputc ('\n', fp);
    mostra_jogadas (e, fp);
}

void le_ficheiro (ESTADO *e, FILE *fp) {
    char linha[100];
    int nlinha = 7;
    int num_jogadas = 0;
    // Ler tabuleiro
    while (nlinha >= 0 && fscanf (fp, "%s", linha) == 1) guardaLinha (e, linha, nlinha --);
    // Ler jogadas
    while (fscanf (fp, "%*s %*s %s %*s %s", linha, &linha[2]) == 2) guardaJogadas (e, linha, num_jogadas ++, 2);
    while (fscanf (fp, "%*s %*s %s", linha) == 1) guardaJogadas (e, linha, num_jogadas, 1);
    e -> num_jogadas = num_jogadas;
}

void guardaLinha (ESTADO *e, char linha[], int nlinha) { // Guarda as linhas do tabuleiro do ficheiro no estado.
    int i = 0;
    while (i != 8) {
        if (linha [i] == '#') e -> tab [nlinha] [i] = PRETA;
        else if (linha [i] == '*') e -> tab [nlinha] [i] = BRANCA;
        else if (linha [i] == '.') e -> tab [nlinha] [i] = VAZIO;
        else if (linha [i] == '1') e -> tab [nlinha] [i] = UM;
	    else e -> tab [nlinha] [i] = DOIS;    
        i ++;
    }
}


void guardaJogadas (ESTADO *e, char linha[],int num_jogada ,int n) {
    COORDENADA jogada1 = {linha[0] - 'a', atoi (&linha[1]) - 1};
    (e -> jogadas[num_jogada]).jogador1 = jogada1;
    e -> ultima_jogada = jogada1;
    e -> jogador_atual = 2;
    if (n == 2) { // Caso sejam dois jogadores.
        COORDENADA jogada2 = {linha[2] - 'a', atoi (&linha[3]) - 1};
        (e -> jogadas[num_jogada]).jogador2 = jogada2;
        e -> ultima_jogada = jogada2;
        e -> jogador_atual = 1;
    }
}

