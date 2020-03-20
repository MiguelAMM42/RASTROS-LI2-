#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

void set_casa (ESTADO *e, COORDENADA c, CASA V) {
    (e -> tab [c.linha][c.coluna]) = V;
}

CASA get_casa (ESTADO *e, COORDENADA c) {
    return e -> tab [c.linha][c.coluna];
}

void set_ultima_jogada (ESTADO *e, COORDENADA c) {
    e -> ultima_jogada = c;
}

void get_ultima_jogada (ESTADO *e) {
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


