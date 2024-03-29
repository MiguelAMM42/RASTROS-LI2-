#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dados.h"
#include "logica.h"



int jogar (ESTADO *e, COORDENADA c) {
    // 1 - Devolve o Estado com a jogada efetuada; 0 - Devolve o estado inicial (a jogada não é válida)
    //if (! jogadaValida(estado, &c)) return 0; // Caso em que a jogada pretendida não é válida.
    set_casa (e, get_ultima_jogada (e), PRETA); // Altera a casa BRANCA da jogada anterior para PRETA 
    set_casa (e, c, BRANCA); //  Altera a casa VAZIO da jogada atual para BRANCA 
    // Alterar no array de jogadas, acrescentar a atual
    // Coloca a última jogada no array de Jogadas #1
    // Altera a última jogada para a jogada que o jogador pretende efetuar #2
    // Muda o jogador atual para o seguinte #3
    if (get_jogador_atual (e) == 1) {
        set_jogadas_coordenada (e, get_num_jogadas(e), 1, c); // #1
        set_ultima_jogada (e, c); // #2
        set_jogador_atual (e, 2); // #3
    } else {
        set_jogadas_coordenada (e, get_num_jogadas(e), 2, c); // #1
        set_ultima_jogada (e, c); // #2
        set_jogador_atual (e, 1); // #3
        set_num_jogadas (e, get_num_jogadas(e) + 1);
    }
    return 1;
}

int Vencedor (ESTADO *e) {
    // Casos em que o jogo se dá como terminado
    COORDENADA a1 = {0, 0};
    COORDENADA h8 = {7, 7};
    COORDENADA c = get_ultima_jogada(e);
    // A casa 'a1' é alcançada
    if (coordenadaIgual (a1, c)) return 1;
    // A casa 'h8' é alcançada
    else if (coordenadaIgual (h8, c)) return 2;
    // Não há jogadas possíveis
    else if (! JogadasPossiveis (e)) return (3 - get_jogador_atual (e));
    return 0; // Não há vencedor
}

int casaVazia(ESTADO *e, COORDENADA *c) {
    // Primeiro ve se a casa de destino está vazia
    // 1 para vazia; 0 n vazia    
    CASA casa = get_casa (e, *c);
    if (casa != PRETA && casa != BRANCA) return TRUE;
    else return FALSE;
}

int jogadaValida(ESTADO *e, COORDENADA *c) {
    // Primeiro ve se a jogada é valida
    // Depois modifica o estado se for válida
    int colA, linA, colB, linB;
    linA = (e -> ultima_jogada).linha; 
    colA = (e -> ultima_jogada).coluna; 
    linB = c -> linha; 
    colB = c -> coluna; 
    if
    (( ((colA == colB) && ((linA == linB-1) || (linA == linB+1)))
    || ((colA == colB +1) && ((linA == linB-1) || (linA == linB)|| (linA == linB+1))) 
    || ((colA == colB -1) && ((linA == linB-1) || (linA == linB)|| (linA == linB+1))))
    && casaVazia(e, c)) return TRUE;
    else return FALSE;
}


//Something is wrong in Jogadas_Possiveis

int JogadasPossiveis (ESTADO *e) {
    COORDENADA c = e -> ultima_jogada;
    if (anyVazio (e, &c)) return TRUE;
    return FALSE;
}

int anyVazio (ESTADO *e, COORDENADA *c) {
    int ilinha = 1;
    while (ilinha >= -1) {
        int icoluna = 1;
        while (icoluna >= -1) {
            if (icoluna == 0 && ilinha == 0) icoluna = -1;
            COORDENADA a = {c -> coluna + icoluna, c -> linha + ilinha};
            CASA casa = get_casa (e, a);
            if (CoordenadaValida (&a) && (casa == VAZIO || casa == UM || casa == DOIS)) return TRUE;
            icoluna --;
        }
        ilinha --;
    }
    return FALSE;
}


int CoordenadaValida (COORDENADA *c) {	
    if (c -> linha <= 7 && c -> linha >= 0 && c -> coluna >= 0 && c -> coluna <= 7) return TRUE;	
    return FALSE;	
}


void le_ficheiro (ESTADO *e, FILE *fp) {
    char linha[100];
    int nlinha = 7;
    int num_jogadas = 0;
    int contador = 0;
    // Ler tabuleiro
    while (nlinha >= 0 && fscanf (fp, "%s", linha) == 1) guardaLinha (e, linha, nlinha --, &contador);
    set_num_jogadas (e, contador / 2);
    // Ler jogadas
    COORDENADA c = {4, 4};
    set_ultima_jogada (e, c);
    while (num_jogadas != get_num_jogadas(e) && fscanf (fp, "%*s %s %s", linha, &linha[2]) == 2) guardaJogadas (e, linha, num_jogadas ++, 2);
    if (fscanf (fp, "%*s %s", linha) == 1) guardaJogadas (e, linha, num_jogadas, 1);
}

void guardaLinha (ESTADO *e, char linha[], int nlinha, int *contador) { // Guarda as linhas do tabuleiro do ficheiro no estado.
    int i = 0;
    while (i != 8) {
        COORDENADA c = {i, nlinha};
        switch (linha [i]) {
        case '#':
            set_casa (e, c, PRETA);
            (*contador) ++;
            break;
        case '*':
            set_casa (e, c, BRANCA);
            break;
        case '.':
            set_casa (e, c, VAZIO);
            break;
        case '1':
            set_casa (e, c, UM);
            break;
        case '2':
            set_casa (e, c, DOIS);
            break;
        }  
        i ++;
    }
}


void guardaJogadas (ESTADO *e, char linha[],int num_jogada ,int n) {
    COORDENADA jogada1 = {linha[0] - 'a', atoi (&linha[1]) - 1};
    set_jogadas_coordenada (e, num_jogada, 1, jogada1);
    set_ultima_jogada (e, jogada1);
    set_jogador_atual (e, 2);
    if (n == 2) { // Caso sejam dois jogadores.
        COORDENADA jogada2 = {linha[2] - 'a', atoi (&linha[3]) - 1};
        set_jogadas_coordenada (e, num_jogada, 2, jogada2);
        set_ultima_jogada (e, jogada2);
        set_jogador_atual (e, 1);
    }
}









