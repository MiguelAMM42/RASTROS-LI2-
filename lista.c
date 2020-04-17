#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"
#define BUF_SIZE 1024

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

LISTA min_max_Lista (ESTADO *e, LISTA l, int min_max) { // min -> 0 || max -> 1
	int v = valorC (e, &(((MinMax*)(l -> valor)) -> jogada)); // Valor mínimo/máximo, inicializado com o valor do primeiro elemento.
	LISTA ls = l; // Apontador para o Nodo com menor/maior valor, inicializado com o apontador para o primeiro Nodo.
	l = l -> prox;
	if (min_max = 0) { // Queremos o mínimo da lista
		while (!l -> prox) {
			COORDENADA *c = &(((MinMax*)(l -> valor)) -> jogada);
			int valor = valorC (e, c);
			if (valor < v) {
				v = valor;
				ls = l;
			}
		}
	} else { // Queremos o máximo da lista
		while (!l -> prox) {
			COORDENADA *c = &(((MinMax*)(l -> valor)) -> jogada);
			int valor = valorC (e, c);
			if (valor > v) {
				v = valor;
				ls = l;
			}
		}
	}
	return ls;
}

int valorC (ESTADO *e, COORDENADA *c) {
	return 10;
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
			l = adicionarCoordenada (e, a, l);
            icoluna --;
        }
        ilinha --;
	}


	return l;
}

LISTA adicionarCoordenada (ESTADO *e, COORDENADA c, LISTA l) {
	if ((!jogadaValida (e, c)) || (! CoordenadaValida (c))) return l;
	COORDENADA *s = malloc (sizeof (COORDENADA));
	(*s) = c;
	return insere_cabeca (l, s);
}
	
	






