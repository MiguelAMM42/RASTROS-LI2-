#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "bot.h"
#include "logica.h"

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

void Cria_ListaMinMax (ESTADO *e, LISTA *l) {
	
}
