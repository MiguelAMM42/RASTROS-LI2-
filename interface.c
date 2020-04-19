#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dados.h"
#include "lista.h"
#include "interface.h"
#include "logica.h"
#define Jogador_1_ganhou 2
#define Jogador_2_ganhou 3
#define ALGUEM_GANHOU(jogo) jogo >= 2
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
    if ((s -> jogador_atual) == 1) printf ("\n");
    else 
    {
        fprintf (fp, "%02d: ", jogadaNum + 1);
        fprintf (fp, "%c%d \n\n", 'a' + (((s -> jogadas[s -> num_jogadas]).jogador1) .coluna), (((s -> jogadas[s -> num_jogadas]).jogador1) .linha) + 1); 
    }        
}



void mostra_prompt (ESTADO *s) {  // Imprime o prompt
    int jogadaNum = 0;
    int conta_comandos = (s -> num_comando);
    while (jogadaNum < (s -> num_jogadas)) {
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 1) printf ("\nPL1(%d)", conta_comandos);
    else {
        printf ("\nPL2(%d)", conta_comandos);
    }        
}


// IGNORA: -1 ; ACABA: 0; CONTINUA: +1;
// INFO JOGAR: VÁLIDA: 1 ; INVÁLIDA: 0; ACABA: 2; 


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char endereco[BUF_SIZE]; 
    int jog = 0;
    printf (">>");
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return -1;

    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { // Quando é feita a jogada normal.
        COORDENADA coord = {*col - 'a', *lin - '1'};
        int jogo = jogar(e, coord);
        if (ALGUEM_GANHOU (jogo)) {
            mostrar_tabuleiro(*e, stdout);
            return 0;
        } 
        if (COMANDO_INVALIDO(jogo)) return -1;
        printf("\n");
        mostrar_tabuleiro(*e, stdout);
        e -> num_comando ++;
        return 1;

    } else if ((strcmp(linha, ("Q\n")) == 0) || (strcmp(linha, ("q\n")) == 0)) { // Se premires qualquer carater, termina.
        printf ("Fim\n");
        return 0;

    } else if (sscanf(linha, "gr%s", endereco) == 1) { // Para gravar, se meteres gr QUALQUER_COISA vai para esta parte.
        FILE *fp;
        fp = fopen(endereco, "w");
        if (fp == NULL) {  // Caso em que não abre
            printf("Could not create file. Maybe locked or being used by another application?\n");
            return (-1);
        } else { // Se o caminho está certo.
            printf ("guarda_ficheiro %s", endereco);
            guarda_ficheiro (e, fp);
            fclose(fp);
            e -> num_comando ++;
            return 1;
        }

    } else if (sscanf(linha, "pos%d", &jog) == 1) {
            int jogadas;
            jogadas =  get_num_jogadas (e);
            if (jog > jogadas) {
                printf ("Jogada inválida, mete-me outro");
                return -1;
            } else jogadaAnterior (e, jog);
            mostrar_tabuleiro (*e, stdout);
            e -> num_comando ++;
            return 1;

    } else if (strcmp(linha, ("jog\n")) == 0) {
            LISTA vV = criaLista (e);
            COORDENADA* jogada = comando_jog(vV, e);
            int jogo = jogar(e, *jogada);
            if (ALGUEM_GANHOU(jogo)) {
                mostrar_tabuleiro(*e, stdout);
                return 0;
            } 
            else if (COMANDO_INVALIDO(jogo)) return -1;
            printf("\n");
            mostrar_tabuleiro(*e, stdout);
            while (!lista_esta_vazia(vV)) vV = remove_cabeca(vV);
            e -> num_comando ++;
            return 1;

    } else if (strcmp(linha, ("movs\n")) == 0) {
            mostra_jogadas (e, stdout);
            e -> num_comando ++;
            return 1;

    } else if (sscanf(linha, "ler%s", endereco) == 1) { // Para gravar, se meteres gr QUALQUER_COISA vai para esta parte.
            FILE *fp;
            fp = fopen(endereco, "r");
            if (fp == NULL) {  // Se não abre.
                printf("Could not create file. Maybe locked or being used by another application?\n");
                return (-1);
            } else { // Se o caminho está certo.
                printf ("\nEstamos a ler! %s\n", endereco);
                le_ficheiro (e, fp);
                fclose(fp);
                mostrar_tabuleiro (*e, stdout);
                mostra_jogadas(e, stdout);
                e -> num_comando ++;
                return 1;
            }
    }
    return -1;
} 


