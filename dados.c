#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

ESTADO *inicializar_estado() {
    ESTADO *teste1 = (ESTADO *) malloc(sizeof(ESTADO));
    set_jogador_atual (teste1, 1);
    set_num_jogadas (teste1, 0);
    set_num_comandos (teste1, 0);
    COORDENADA c = {4, 4};
    set_ultima_jogada(teste1, c);
    for (int i = 7; i > (-1); i--) {
        for (int ii = 0; ii < 8; ii ++) {
            COORDENADA a = {ii, i};
            if (i == 4 && ii == 4) set_casa (teste1, a, BRANCA);
            else if (i == 7 && ii == 7) set_casa (teste1, a, DOIS);
            else if (i == 0 && ii == 0) set_casa (teste1, a, UM);
            else set_casa (teste1, a, VAZIO);                                         
        }
    }
    return teste1;
}

void set_casa (ESTADO *e, COORDENADA c, CASA V) {
    (e -> tab [c.linha][c.coluna]) = V;
}

CASA get_casa (ESTADO *e, COORDENADA c) {
    return e -> tab [c.linha][c.coluna];
}

void set_ultima_jogada (ESTADO *e, COORDENADA c) {
    e -> ultima_jogada = c;
}

COORDENADA get_ultima_jogada (ESTADO *e) {
    return e -> ultima_jogada;
}

void set_num_jogadas (ESTADO *e, int n) {
    e -> num_jogadas = n;
}

int get_num_jogadas (ESTADO *e) {
    return e -> num_jogadas;
}

void set_jogador_atual (ESTADO *e, int n) {
    e -> jogador_atual = n;
}

int get_jogador_atual (ESTADO *e) {
    return e -> jogador_atual;
}

void set_jogadas_coordenada (ESTADO *e, int num_jogada, int jogador, COORDENADA c) {
    if (jogador == 1) e -> jogadas[num_jogada].jogador1 = c;
    else e -> jogadas[num_jogada].jogador2 = c;
}

int coordenadaIgual (COORDENADA a, COORDENADA b) {
    if (a.coluna == b.coluna && a.linha == b.linha) return TRUE;
    return FALSE;
}

void set_num_comandos (ESTADO *e, int n) {
    e -> num_comando = n;
}

int get_num_comandos (ESTADO *e){
    return e -> num_comando;
}


