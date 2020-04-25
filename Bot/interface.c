#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"
#include "interface.h"
#define COMANDO_INVALIDO(jogo) jogo == 0

void mostrar_tabuleiro (ESTADO s, FILE *fp) {
    int i = 0;
    int linha;
    for (linha = 7; linha > (-1); linha--) {
        for (i = 0; i < 9; i++) {
            COORDENADA c = {i, linha};
            if (i == 8) fputc('\n', fp);
            else if (get_casa (&s, c) == DOIS) fputc('2', fp);
            else if (get_casa (&s, c) == UM) fputc('1', fp);
            else if (get_casa (&s, c) == BRANCA) fputc('*', fp);
            else if (get_casa (&s, c) == VAZIO) fputc('.', fp);
            else fputc('#', fp); 
        }
    }
}

void mostra_jogadas (ESTADO *s, FILE *fp) {  // Imprime a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum < (s -> num_jogadas)) {
        fprintf (fp, "%02d: ", jogadaNum + 1);
        fprintf (fp, "%c%d ", 'a' + (((s -> jogadas[jogadaNum]).jogador1).coluna) , (((s -> jogadas[jogadaNum]).jogador1).linha) + 1); 
        fprintf (fp, "%c%d\n", 'a' + (((s -> jogadas[jogadaNum]).jogador2).coluna) , (((s -> jogadas[jogadaNum]).jogador2).linha) + 1);
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 2) {
        fprintf (fp, "%02d: ", jogadaNum + 1);
        fprintf (fp, "%c%d \n", 'a' + (((s -> jogadas[s -> num_jogadas]).jogador1) .coluna), (((s -> jogadas[s -> num_jogadas]).jogador1) .linha) + 1); 
    }        
}

void guarda_ficheiro (ESTADO *e, FILE *fp) {
    mostrar_tabuleiro (*e, fp);
    fputc ('\n', fp);
    mostra_jogadas (e, fp);
}


