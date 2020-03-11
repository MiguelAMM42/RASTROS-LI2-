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
        COORDENADA ultima_jogada;
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
/* int acrescenta (Estado *s, coordenada *jogada);
int jogadaValida (Estado *s, coordenada *jogada);
int distancia (Estado *s, coordenada *jogada);
int pertence (Estado *s, coordenada *jogada);
void geraArray (Estado *s, int *arr, int linhaD);
int CoorIgual (coordenada *a, coordenada *b);
*/
int main () {
    // Defenir o estado inicial, preenche as casas com Branco
    ESTADO teste1; 
    for (int i = 0; i < 8; i++) {for (int ii = 0; ii < 8; ii ++) 
                                                {   if (i == 3 && ii == 4) teste1.tab [i] [ii] = PRETA;
                                                    else teste1.tab [i] [ii] = BRANCA;
                                                        
                                                }
                                         }
    teste1.ultima_jogada.jogador1.coluna = 4;
    teste1.ultima_jogada.jogador1.linha = 4;
    teste1.num_jogadas = 1;
    teste1.jogador_atual = 2;

                                                        
    /*
    coordenada v = {'a',5};
    teste1.registos[0] = v;
    coordenada v1 = {'b', 5};
    teste1.registos[1] = v1; */
    desenhaTabuleiro (&teste1);
    /*
    while (1) {
         printf ("Qual A jogada?");

        } */
    return 0;
    
}


void desenhaTabuleiro (ESTADO *s) {
    int i = 0;
    int linha = 0;
    for (linha = 0; linha < 8; linha++)
    {
     for (i = 0; i < 9; i++){
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
   



int jogadaValida(ESTADO *teste1, COORDENADA c){
    //primeiro ve se ajogada é valida
    //depois modifica o estado se for válida
    // 1 para válida; 0 n valida    
    int b, n, m, y , z;
    teste1 -> jogador_atual = b;
    y = ((teste1 -> ultima_jogada).jogador1).coluna;
    z = (teste1 -> ultima_jogada).jogador1.linha;
    n = c.coluna;
    m = c.linha;
    if (((n > 1) && (n < 8)) &&
        ((m > 1) && (m < 8)) &&
        ((n == y) || (n == y+1) || (n == y-1)) && 
        ((m == z) || (m == z+1) || (m == z-1)) ) return TRUE;
    else return FALSE;
}

int jogar(ESTADO *teste1, COORDENADA c){
    //primeiro ve se a jogada é valida
    //depois modifica o estado se for válida
    // 1 para válida; 0 n valida    
    int b, n, m, y , z, j;
    j = jogadaValida(teste1, c);
    if (!j) return 0;
    teste1 -> jogador_atual = b;
    y = ((teste1 -> ultima_jogada).jogador1).coluna;
    z = (teste1 -> ultima_jogada).jogador1.linha;
    n = c.coluna;
    m = c.linha;
    teste1 -> tab [z] [y] = PRETA; // ALTERA A CASA PARA PRETA, VERIFICAR SE É Y / Z OU Z / Y
    teste1 -> tab [m] [n] = BRANCA; // IGUAL A CIMA
    // Alterar no array de jogadas, acrescentar a atual
    int jogadaAtual;
    jogadaAtual = (teste1->num_jogadas);
    ((((&teste1) -> jogadas[jogadaAtual]).jogador2).coluna) = n;
    ((((&teste1) -> jogadas[jogadaAtual]).jogador2).linha) = m;

    (teste1 -> num_jogadas) ++;
    if ( b == 2) teste1 -> jogador_atual = 1;
    else teste1 -> jogador_atual = 2;
    return 1;
}

