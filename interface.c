#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "logica.h"
#include "interface.h"


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
        fprintf (fp, "%02d : ", jogadaNum + 1);
        fprintf (fp, "%c%d ", 'a' + (((s -> jogadas[jogadaNum]).jogador1).coluna) , (((s -> jogadas[jogadaNum]).jogador1).linha) + 1); 
        fprintf (fp, "%c%d\n", 'a' + (((s -> jogadas[jogadaNum]).jogador2).coluna) , (((s -> jogadas[jogadaNum]).jogador2).linha) + 1);
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 1) printf ("\n");
    else 
    {
        fprintf (fp, "%02d : ", jogadaNum + 1);
        fprintf (fp, "%c%d \n\n", 'a' + (((s -> jogadas[s -> num_jogadas]).jogador1) .coluna), (((s -> jogadas[s -> num_jogadas]).jogador1) .linha) + 1); 
    }        
}



void mostra_prompt (ESTADO *s) {  // Imprime o prompt
    int jogadaNum = 0;
    while (jogadaNum < (s -> num_jogadas)) {
        jogadaNum ++;
    }
    if ((s -> jogador_atual) == 1) printf ("\nPL1");
    else {
        printf ("\nPL2");
    }        
}

//IGNORA: -1 ; ACABA: 0; CONTINUA: +1 
//INFO JOGAR) VÁLIDA: 1 ; INVÁLIDA: 0; ACABA: 2 

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    printf (">>");
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return -1;
    // Quando é feita a jogada normal
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        int jogo = jogar(e, coord);
        if (jogo == 2) return 0;
        if (jogo == 0) return -1;
        printf("\n");
        mostrar_tabuleiro(*e, stdout);
        return 1;
    } else { //Se premires qualquer carater, termina
        if((strcmp(linha, ("Q\n")) == 0) || (strcmp(linha, ("q\n")) == 0)) {      
            printf ("Fim\n");
            return 0;
        } else {     
            char endereco[BUF_SIZE]; 
            if (sscanf(linha, "gr%s", endereco) == 1) { // para gravar, se meteres gr QUALQUER_COISA vai para esta parte
                FILE *fp;
                fp = fopen(endereco, "w");
                if (fp == NULL) {  // Caso em que não abre
                    printf("Could not create file. Maybe locked or being used by another application?\n");
                    return (-1);
                } else { // SE o caminho está certo
                    printf ("guarda_ficheiro %s", endereco);
                    guarda_ficheiro (e, fp);
                    fclose(fp);
                    return 1;
                } 
            } else { 
                if (strcmp(linha, ("movs\n")) == 0)
                                 {
                                 mostra_jogadas (e, stdout);
                                 return 1;
                                 }
                 else {
                if (sscanf(linha, "ler%s", endereco) == 1) { // para gravar, se meteres gr QUALQUER_COISA vai para esta parte
                    FILE *fp;
                    fp = fopen(endereco, "r");
                    if (fp == NULL) {  // Se não abre
                        printf("Could not create file. Maybe locked or being used by another application?\n");
                        return (-1);
                    } else { // SE o caminho está certo
                        printf ("\nEstamos a ler! %s\n", endereco);
                        le_ficheiro (e, fp);
                        fclose(fp);
                        mostrar_tabuleiro (*e, stdout);
                        mostra_jogadas(e, stdout);
                        return 1;
                    }
                }
                }           
            }
        }
    } return -1;
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
                                   void guardaLinha (ESTADO *e, char linha[], int nlinha) {
    int i = 0;	    int i = 0;
    while (i != 8) {	    while (i != 8) {
        if (linha [i] == '#') e -> tab [nlinha] [i] = PRETA;	        if (linha [i] == '#') e -> tab [nlinha] [i] = PRETA;
        else if (linha [i] == '*') e -> tab [nlinha] [i] = BRANCA;	        else if (linha [i] == '*') e -> tab [nlinha] [i] = BRANCA;
        else e -> tab [nlinha][i] = VAZIO;	        else if (linha [i] == '.') e -> tab [nlinha] [i] = VAZIO;
        else if (linha [i] == '1') e -> tab [nlinha] [i] = UM;
        else e -> tab [nlinha] [i] = DOIS;         
        i ++;	        i ++;
    }	    }


}	} int linha = 0;
                        
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

