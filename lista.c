#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"
#define BUF_SIZE 1024
#define max_tab 8

/*
int main() {
	LISTA L = criar_lista();
	char linha[BUF_SIZE];
	printf("Insira várias linhas, acabando com CTRL-D:\n");	
	// control-D é a tecla CTRL e a tecla D ao mesmo tempo
	// Em windows é capaz de ser CTRL-Z
	while(fgets(linha, BUF_SIZE, stdin) != 0) {
		// A função strdup cria uma cópia da string que foi lida
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

int lista_esta_vazia (LISTA L) {
   // if (L == NULL) return 1;
    return !L;
    // OU (?)
    // return L;
}
LISTA criar_lista ()
{ 
  LISTA L;
  L = NULL;
  return L;
}

LISTA remove_cabeca(LISTA L)
{
    if (L == NULL) return NULL;
    LISTA tmp = L;
    L = L -> prox;
  	//Talvez apagar
	void *cA;
	cA = (tmp -> valor);
	free (cA);
	//Acabei
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


LISTA criaLista (ESTADO *e) {
	LISTA l = criar_lista ();

	COORDENADA atual = get_ultima_jogada(e);

	int ilinha = 1;
    while (ilinha >= -1) {
        int icoluna = 1;
        while (icoluna >= -1) {
            if (icoluna == 0 && ilinha == 0) icoluna = -1;
            COORDENADA a = {atual.coluna + icoluna, atual.linha + ilinha};
			adicionarCoordenada (e, &a, &l);
            icoluna --;
        }
        ilinha --;
	}
	return l;
}

void adicionarCoordenada (ESTADO *e, COORDENADA *c, LISTA *l) {
	if ((!jogadaValida (e, *c)) || (! CoordenadaValida (*c))) return;
	COORDENADA *s = malloc (sizeof (COORDENADA));
	(*s) = *c;
	(*l) = insere_cabeca (l, s);
}
	

int dist_jog1 (COORDENADA c, int jogAtual)
{
    int col = c.coluna;
    int lin = c.linha;
    if (jogAtual == 1)
        {
        if (col <= lin) return col--;
        else return lin--;
        }
    else 
        {
        lin = max_tab - lin;
        col = max_tab - col;
        if (lin <= col) return lin++;
        else return col++;
        }
}
	



