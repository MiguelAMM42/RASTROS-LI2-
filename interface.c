#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"


ESTADO *inicializar_estado() {
    ESTADO *teste1 = (ESTADO *) malloc(sizeof(ESTADO));
    teste1 -> jogador_atual = 1;
    teste1 -> num_jogadas = 0;
    teste1 -> ultima_jogada.coluna = 4;
    teste1 -> ultima_jogada.linha = 4;
    for (int i = 7; i > (-1); i--) {
        for (int ii = 0; ii < 8; ii ++) {
            if (i == 4 && ii == 4) (teste1 -> tab [i] [ii]) = BRANCA;
            else (teste1 -> tab [i] [ii]) = VAZIO;                                          
        }
    }
    return teste1;
}


void mostrar_tabuleiro (ESTADO s, FILE *fp) {
    int i = 0;
    int linha;
    for (linha = 7; linha > (-1); linha--) {
        for (i = 0; i < 9; i++) {
            if (i == 8) fputc('\n', fp);
            else {
                if (i == 7 && linha == 7) fputc('2', fp);
                else {
                    if (i == 0 && linha == 0) fputc('1', fp);
                    else {
                        if ((s.tab [linha] [i]) == BRANCA) fputc('*', fp);
                        else {
                            if ((s.tab [linha] [i]) == VAZIO) fputc('.', fp);
                            else fputc('#', fp); 
                        }
                    }
                }
            }
        }
    }
}

void mostra_jogadas (ESTADO *s, FILE *fp) {  // Imprime a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum < (s -> num_jogadas)) {
        fprintf (fp, "%02d : ", jogadaNum + 1);
        fprintf (fp, "%c%d / ", 'a' + (((s -> jogadas[jogadaNum]).jogador1).coluna) , (((s -> jogadas[jogadaNum]).jogador1).linha) + 1); 
        fprintf (fp, "%c%d\n", 'a' + (((s -> jogadas[jogadaNum]).jogador2).coluna) , (((s -> jogadas[jogadaNum]).jogador2).linha) + 1);
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 1) printf ("\nÉ a vez do jogador 1! \n");
    else {
        fprintf (fp, "%02d : ", jogadaNum + 1);
        fprintf (fp, "%c%d / \n", 'a' + (((s -> jogadas[s -> num_jogadas]).jogador1) .coluna), (((s -> jogadas[s -> num_jogadas]).jogador1) .linha) + 1); 
        printf ("È a vez do jogador 2!\n");
    }        
}


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    printf ("Comando:");
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    // Quando é feita a jogada normal
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) 
    {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(*e, stdout);
        return 1;
    }
    else {
        //Se premires qualquer carater, termina
        if((strcmp(linha, ("Q\n")) == 0) || (strcmp(linha, ("q\n")) == 0)) {      
            printf ("Fim\n");
            return -1;
        } else {      
            char endereco[BUF_SIZE]; 
            if (sscanf(linha, "gr%s", endereco) == 1) 
            {  // para gravar, se meteres gr QUALQUER_COISA vai para esta parte
                FILE *fp;
                fp = fopen(endereco, "w");
                if(fp == NULL) {  // Se não abre
                    printf("Could not create file. Maybe locked or being used by another application?\n");
                    return (-1);
                } else {// SE o caminho está certo
                    printf ("guarda_ficheiro %s", endereco);
                    guarda_ficheiro (e, fp);
                    fclose(fp);
                    }
            } 
            else {
                    if (sscanf(linha, "ler%s", endereco) == 1) { // para gravar, se meteres gr QUALQUER_COISA vai para esta parte
                            FILE *fp;
                            fp = fopen(endereco, "r");
                            if(fp == NULL) {  // Se não abre
                                printf("Could not create file. Maybe locked or being used by another application?\n");
                                return (-1);
                            } 
                            else { // SE o caminho está certo
                                printf ("\n ler ficheiro %s", endereco);
                                printf ("\nEstamos a ler! %s\n", endereco);
                                le_ficheiro (e, fp);
                                fclose(fp);
                                mostrar_tabuleiro (*e, stdout);
                                    }
                               return 1;
                         }           
                        else return 1;
                    }
    }
    return 1;
}
}

/*
int interpretador(ESTADO *e) 
{
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char endereco[50];
    FILE *fp;

    printf ("Comando: ");   
    
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    else {      
        if(sscanf(linha, "Q")) {      
                                           printf ("Fim");
                                           return -1;
                                           }           
                   
        else {
            if(strlen(linha) >= 4 && sscanf (linha, "ler %s", endereco) == 1) {  // eu acho que o strlen começa no 0, por isso é 0 = ler e 1 = endereço
                    FILE *fp;   
                    fp = fopen(endereco, "a+");
                       //if (fp == NULL) return 0;
                       printf("Ficheiro aberto\n");
                       mostrar_tabuleiro(*e);
                   }
            else   {
                   if( strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) 
                        {
                        COORDENADA coord = {*col - 'a', *lin - '1'};
                        jogar(e, coord);
                        mostrar_tabuleiro(*e);
                        }
        else {
                        if(sscanf(linha, "gr %s", endereco) == 1) 
                        {  // eu acho que o strlen começa no 0, por isso é 0 = ler e 1 = endereço
                               FILE *fp;
                               fp=fopen(endereco, "w");
                                    if(fp == NULL) {
                            printf("Could not create file. Maybe locked or being used by another application?\n");
                            exit(-1);
                                                    }
                                    else 
                                    {
                                    int i = 0;
                                    int linha = 0;
                        
                                    for (linha = 0; linha < 8; linha++) {
                                            for (i = 0; i < 9; i++) {
                                                    if (i == 8) fputc('\n', fp);
                                                    else {
                                                         if (i == 7 && linha == 0) fputc('2', fp);
                                                         else {
                                                                    if (i == 0 && linha == 7) fputc('1', fp);
                                                                    else {
                                                                        if ((e->tab [linha] [i]) == BRANCA) fputc('*', fp);
                                                                        else {
                                                                             if ((e->tab [linha] [i]) == VAZIO) fputc('.', fp);
                                                                               else fputc('#', fp); 
                                                                          }
                                                                            }
                                      }
                                }
                            }
                        }  
                                }
                            }
                            else return 0;
                        }}}}
              
return 1;
}
*/

// Links giros para ver exemplos de guardar ficheiros:
// https://www.quora.com/How-do-I-write-a-program-in-C-to-create-a-new-file-with-a-name-taken-from-the-user

