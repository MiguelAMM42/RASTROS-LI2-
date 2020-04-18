#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"

//#include "dados.c"
// #include "lista.c"
//#include "logica.c"

#define BUF_SIZE 1024
#define max_tab 8

int lista_esta_vazia (LISTA L) {
   // if (L == NULL) return 1;
    return !L;
    // OU (?)
    // return L;
}

LISTA criar_lista ()
{ 
  LISTA L;
 // L = malloc (sizeof (LISTA));
  //COOR Inicializada
  //LISTA iniciada
  L= NULL;
  return L;
}

LISTA remove_cabeca(LISTA L)
{
    if (L == NULL) return NULL;
    LISTA tmp = L;
    L = L -> prox;
    free (tmp);
    return L;
}

LISTA proximo(LISTA L){
    return L -> prox;
}


LISTA insere_cabeca(LISTA L, void *x){
    LISTA R;
    R = malloc (sizeof (NODO)); 
    R -> prox = L;
    R -> valor = x;
    
    //free(R);
    return R;
    //incompleto?
}

void *devolve_cabeca(LISTA L) {
    return ((L -> valor));
}
// DEFINIR MAX DO TABULEIRO

// A partir daqui mexi eu, normal dar erros
int dist (ESTADO *e)
{
    int dist = distRap (e);
    if (dist != 0) return dist;    
}

int distRec (ESTADO *e)
{
    int jA = get_jogador_atual (e);
    COORDENADA cA = get_ultima_jogada (e);
    COORDENADA cTemp;
 //   int dist, dist_T1, dist_Bom;
    ESTADO expl = *e;
    if (jA == 2)
    {
       //Testa cima direita
       cTemp.coluna = (cA.coluna)+1;
       cTemp.linha = (cA.linha)+1; 
       if (test_coor_rec (e, cTemp, 2) == 2) return 1; // Ganhou, fim da procura
       jogar (&expl, cTemp);
       int prox = distRec (&expl);
       if (test_coor_rec (e, cTemp, 2) == 1 && prox > 1) return (1+ prox); // Proximas jogadas também são válidas
       else {  // A proxima dá derrota para nos ou a atual
            cTemp.coluna = (cA.coluna);
            cTemp.linha = (cA.linha)+1; 
            if (test_coor_rec (e, cTemp, 2) == 2) return 1; // Ganhou, fim da procura
            jogar (&expl, cTemp);
            int prox = distRec (&expl);
            if (test_coor_rec (e, cTemp, 2) == 1 && prox > 1) return (1+ prox); // Proximas jogadas também são válidas
            }
    }
}

int test_coor_rec (ESTADO *e, COORDENADA cTeste, int jA)
{
    int res = jogar (e, cTeste);
    if (jA == 2)
    {
        if (res == 22) return 2; //2 ganhou
        if (res == 21) return -1; //1 ganhou
        if (res == 1) return 1; //possível
        else return 0; //Jogada impossível                
   }

    if (jA == 1)
    {
        if (res == 21) return 2; //1 ganhou
        if (res == 22) return -1; //2 ganhou
        if (res == 1) return 1; //possível
        else return 0; //Jogada impossível                
   }
} 

int distRap (ESTADO *e)
{
    printf ("&&&&&");
    int jA = get_jogador_atual (e);
    COORDENADA cA = get_ultima_jogada (e);
    int vLogico = 1;
    int dist = 0;

    if (jA == 1)
    {
        (cA.coluna)--;
        (cA.linha) --;
        vLogico = casaVazia(e, cA);                                                 
        while (cA.coluna > 0 && cA.linha > 0 && vLogico)
        {           
         dist++;
         (cA.coluna)--;
         (cA.linha) --;
         vLogico = casaVazia(e, cA);
        }
        while (cA.coluna > 0 && cA.linha == 0 && cA.coluna < max_tab && cA.linha < max_tab && vLogico) {

                                                        (cA.coluna) --;
                                                        vLogico = casaVazia(e, cA);
                                                        if (vLogico) dist++;   
                                                    }   
        
        while (cA.coluna == 0 && cA.linha > 0 && cA.coluna < max_tab && cA.linha < max_tab && vLogico) {
                                                                (cA.linha) --;
                                                                vLogico = casaVazia(e, cA);
                                                                if (vLogico) dist++;   
                                                            }

        if (cA.coluna < max_tab && cA.linha < max_tab && cA.coluna == 0 && cA.linha == 0) return --dist;
        else return 0;
    }
    else
    {   
        (cA.coluna)++;
        (cA.linha) ++;
        vLogico = casaVazia(e, cA);
        
        while (cA.coluna < max_tab && cA.linha < max_tab && cA.coluna > 0 && cA.linha > 0 && vLogico)
        {

          dist++;           
         (cA.coluna)++;
         (cA .linha) ++;
         vLogico = casaVazia(e, cA);
         //
        }
        while (cA.coluna < max_tab && cA.linha  == max_tab && cA.coluna > 0 && cA.linha > 0 && vLogico) 
                                                    {
                                                        (cA.coluna) ++;
                                                        vLogico = casaVazia(e, cA);
                                                        if (vLogico) dist++;   
                                                    }   
        
        while (cA.coluna == max_tab && cA.linha  < max_tab && cA.coluna > 0 && cA.linha > 0 && vLogico) {
                                                                (cA.linha ) ++;
                                                                vLogico = casaVazia(e, cA);
                                                                if (vLogico) dist++;   
                                                            }

        if (cA.coluna == max_tab && cA.linha  == max_tab && cA.coluna > 0 && cA.linha > 0) return --dist;
        else return 0;
    }
}

//Calcula a distância independentemente de estar ou não ocupado
int dist_imdt (COORDENADA c, int jogA)
{
    int col = c.coluna;
    int lin = c.linha;
    if (jogA == 1)
        {
        if (col >= lin) return col--;
        else return lin--;
        }
    else 
        {
        lin = max_tab - lin;
        col = max_tab - col;
        if (lin >= col) return lin++;
        else return col++;
        }
}
/*
int main() {
    LISTA L = criar_lista();
    char linha[BUF_SIZE];
    printf("Insira várias linhas, acabando com CTRL-D:\n"); 
    // control-D é a tecla CTRL e a tecla D ao mesmo tempo
    // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma copia da string que foi lida
        L = insere_cabeca(L, strdup(linha));
    }

    printf("\n==============================\n");
    printf(  "=          PERCURSO          =\n");
    printf(  "==============================\n\n");
    
    // percorre sem remover os elementos da lista
    for (LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        char *str = (char *) devolve_cabeca(T);
        printf("%s", str);
    }
    
    printf("\n==============================\n");
    printf(  "=           REMOCAO          =\n");
    printf(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!lista_esta_vazia(L)) {
        char *str = (char *) devolve_cabeca(L);
        L = remove_cabeca(L);
        printf("%s", str);
        free(str);
    }
    return 0;
}

*/