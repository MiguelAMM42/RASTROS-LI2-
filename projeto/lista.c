/**
@file lista.c
Definição das funções relacionadas com as listas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"

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
	if ((!jogadaValida (e, c)) || (! CoordenadaValida (c))) return;
	COORDENADA *s = malloc (sizeof (COORDENADA));
	(*s) = *c;
	(*l) = insere_cabeca (*l, s);
}
	
     


int length (LISTA l){
    int count=0;
    while (l != NULL){
         count ++;
         l = l -> prox;
    }
    return count;
}
