#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 64

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int coluna;
    int linha; } COORDENADA;


typedef struct 
        {
        COORDENADA jogador1;
        COORDENADA jogador2;
        } JOGADA;

typedef JOGADA JOGADAS[32];
typedef struct {
        CASA tab[8][8];
        JOGADA ultima_jogada;
        JOGADAS jogadas;
        int num_jogadas;
        int jogador_atual;
                } ESTADO;

/*
typedef struct coordenada {
    char coluna ;
    int linha;
} coordenada;

typedef struct Estado {
    int jogadas;
    coordenada registos[MAX];
    } Estado;
*/

void desenhaTabuleiro (ESTADO *s);

ESTADO *inicializar_estado();
void mostra_jogadas (ESTADO *s);

void converte_string (JOGADA *lista, int num, int jog_atual, char *jog);

/* int acrescenta (Estado *s, coordenada *jogada);
int jogadaValida (Estado *s, coordenada *jogada);
int distancia (Estado *s, coordenada *jogada);
int pertence (Estado *s, coordenada *jogada);
void geraArray (Estado *s, int *arr, int linhaD);
int CoorIgual (coordenada *a, coordenada *b);
*/
int main () {
    // Defenir o estado inicial, preenche as casas com Branco
    //ESTADO *e = inicializar_estado();
    ESTADO teste1; 
    for (int i = 0; i < 8; i++) {for (int ii = 0; ii < 8; ii ++) 
                                                {   if (i == 3 && ii == 4) teste1.tab [i] [ii] = PRETA;
                                                    else teste1.tab [i] [ii] = BRANCA;
                                                        
                                                }
                                         }
   
    teste1.jogador_atual = 2;
    teste1.num_jogadas = 2;
    teste1.ultima_jogada.jogador1.coluna = 3;
    teste1.ultima_jogada.jogador1.linha = 4;


    /*
    coordenada v = {'a',5};
    teste1.registos[0] = v;
    coordenada v1 = {'b', 5};
    teste1.registos[1] = v1; */
    desenhaTabuleiro (&teste1);
    mostra_jogadas (&teste1);
    /*
    while (1) {
         printf ("Qual A jogada?");

        } */
    return 0;
    
// (s -> registos [++ (s -> jogadas)]) = *jogada;
    

}

ESTADO *inicializar_estado() {
    ESTADO *teste1;
    teste1->jogador_atual = 1;
    teste1->num_jogadas = 0;
    // Falta defenir as primeiras jogadas, são precisas informações dos dois jogadores
    for (int i = 0; i < 8; i++) {for (int ii = 0; ii < 8; ii ++) 
                                                {   if (i == 3 && ii == 4) (teste1-> tab [i] [ii]) = PRETA;
                                                    else (teste1->tab [i] [ii]) = BRANCA;
                                                        
                                                }
                                         }
    return teste1;
}


void desenhaTabuleiro (ESTADO *s) {
    int i = 0;
    int linha = 0;
    for (linha = 0; linha < 8; linha++)
    {
     for (i = 0; i < 9; i++)
     {
        if (i == 8) putchar('\n');
        else{
         if (i == 7 && linha == 0) putchar ('2');
         else {
            if (i == 0 && linha == 7) putchar ('1');
                else {
                        if ((s -> tab [linha] [i]) == VAZIO) putchar ('#');    // &(s -> registos[(s -> jogadas)
                        else {
                            if ((s -> tab [linha] [i]) == BRANCA) putchar ('.');
                            else putchar ('*'); 
                            }
                     }

              }
            }
    }
}
}

void mostra_jogadas (ESTADO *s)  // Imprime a lista de jogadas
{ // Falta inicializar a lista de jogadas
    int atual = 0;
    char *jog[500] = {}; 
    converte_string ((*s).jogadas, (*s).num_jogadas, (*s).jogador_atual, *jog);   // Converte as coordenadas das jogadas para uma string, tudo junto tipo : a1a2b1b2
    while ((*jog[atual]) != '\0')
        {printf ("%d : ", atual);
        printf ("%c",*jog[atual]); 
        printf ("%c ; \n", *jog[atual+1]);
        atual = atual + 2;
       // putchar ('\n');
        }
}
void converte_string (JOGADA *lista, int num, int jog_atual, char *jog)
{
    int jogada = 0, string = 0;
    while (jogada+1 < num)
        {
            int c1, l1, c2, l2;
            c1 = (((lista[jogada]).jogador1).coluna);  // VAi buscar a coluna do jogador 1
            jog[string] = (c1 + '0');  // Insere na string a coordenada, nenhum tem 2 carateres
            string++;
            l1 = ((lista[jogada].jogador1).linha); // o mesmo para as linhas
            jog[string] = l1;
            string++;
            c2 = ((lista[jogada].jogador2).coluna);
            jog[string] = (c2 + '0');
            string++;
            l2 = ((lista[jogada].jogador2).linha);
            jog[string] = l2;
            string++;
            jogada++;
        }
    if (jog_atual == 1) jog[string] = '\0';     
                                           
    else {
        int c1, l1;
            c1 = (((lista[jogada]).jogador1).coluna);
            jog[string] = c1 + '0';
            string++;
            l1 = (((lista[jogada]).jogador1).linha);
            jog[string] = l1;
            jog[string+1] = '\0';
        }

}


    // printf (" 12345678 \n");
    /*while (linha != 8) {
        printf ("%c ", linha + 97);
        int arr[8];
        geraArray (s, arr, linha + 1);
        while (i != 8) {
            if (linha == 0 && i == 7)  printf ("1 ");
                                       
            else if (linha == 7 && i == 0) putchar ('2');
            else if (arr[i] == 2) putchar ('*');
            else if (arr[i] == 1) putchar ('#');
            else putchar ('.');
            i ++;
       }
        i = 0;
        printf ("\n");
        linha ++;
    }*/
/*
void geraArray (Estado *s, int *arr, int linhaD) {
    int i = 0;
    char coluna = 'a';
    while (i != 8) {
        coordenada v; 
        (v).coluna = coluna;
        (v).linha = linhaD;

        if (CoorIgual (&(s -> registos[(s -> jogadas) - 1]), &v)) {
            arr[i] = 2;
        }
        else if (pertence (s, &v)) {
            arr[i] = 1;  
        } else arr[i] = 0;
        i ++;
        coluna ++;
    }
}



int acrescenta (Estado *s, coordenada *jogada) {
    if (! jogadaValida (s, jogada)) {printf ("Jogada Inválida"); return 0;}
    (s -> registos [++ (s -> jogadas)]) = *jogada;
    return 1;
}


int jogadaValida (Estado *s, coordenada *jogada) {
    if (distancia (s, jogada) || (! pertence (s, jogada))) return TRUE;
    return FALSE;
}


int distancia (Estado *s, coordenada *jogada) { // Verifica se a casa atual do asterisco esta a um de distancia de uma certa casa
    coordenada *ast = &(s -> registos[(s -> jogadas) - 1]); // Casa atual do asterisco
    if ((abs (((ast -> coluna) - 95) - ((jogada -> coluna) - 95)) == 1) || (abs ((ast -> linha) - (jogada -> linha))) == 1) return TRUE;
    return FALSE;
}


int pertence (Estado *s, coordenada *jogada) {
    int i = 0;
    while (i != s -> jogadas) {
        if (CoorIgual (&(s -> registos[i]), jogada)) return TRUE;
        i ++;
    }
    return FALSE;
}

int CoorIgual (Coordenada *a, Coordenada *b) {
    if (((a -> coluna) == (b -> coluna)) && ((a -> linha) == (b -> linha))) return TRUE;
    return FALSE;
}

*/