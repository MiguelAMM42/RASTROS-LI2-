#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "bot.h"
#include "logica.h"

LISTA min_max_Lista (ESTADO *e, LISTA l, int min_max) { // min -> 0 || max -> 1
	int v = valorC (e, &(((MinMax)(l -> valor)) -> jogada)); // Valor mínimo/máximo, inicializado com o valor do primeiro elemento.
	LISTA ls = l; // Apontador para o Nodo com menor/maior valor, inicializado com o apontador para o primeiro Nodo.
	l = l -> prox;
	if (min_max = 0) { // Queremos o mínimo da lista
		while (!l -> prox) {
			COORDENADA *c = &(((MinMax)(l -> valor)) -> jogada);
			int valor = valorC (e, c);
			if (valor < v) {
				v = valor;
				ls = l;
			}
		}
	} else { // Queremos o máximo da lista
		while (!l -> prox) {
			COORDENADA *c = &(((MinMax)(l -> valor)) -> jogada);
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

void Cria_ListaMinMax (ESTADO *e, LISTA *l, int comp) { // comprimento
	(*l) = malloc ((sizeof (NODO)));
	(*l) -> prox = NULL;
	// Alocação da memória inicial para o árvore de jogadas
	MinMax arvore = malloc (sizeof (MinMax)); 
	(*l) -> valor = arvore;
	arvore -> jogada = e -> ultima_jogada;
	// Criação de um nível de jogadas
	CriaNivel (e, arvore, comp);
}

void CriaNiveis (ESTADO *e, MinMax jogada, int comp) {
	int i = 2;
	int j = 2;
	while (i) { 
		while (j) jogada -> jogadas[i][j --] = NULL;
		i --;
	}
	
}


void CriaNivel (ESTADO *e, MinMax jogada, int comp) {
	COORDENADA atual = get_ultima_jogada(e);

	int ilinha = 1;
    while (ilinha >= -1) {
        int icoluna = -1;
        while (icoluna <= 1) {
            COORDENADA a = {atual.coluna + icoluna, atual.linha + ilinha};
			adicionarCoordenadaMinMax (e, &a, jogada, icoluna + 1, ilinha + 1, comp);
            icoluna --;
        }
        ilinha --;
	}
}

MinMax adicionarCoordenadaMinMax (ESTADO *e, COORDENADA *c, MinMax l, int linha, int coluna, int comp) {
	if (!comp) { // Comprimento chegou ao fim
		int i = 2;
		int j = 2;
		while (i) { // Adicionar NULL a todos os apontadores
			while (j) l -> jogadas[i][j --] = NULL;
			i --;
		}
		return NULL;
	} else if (linha == 1 && coluna == 1 || (!jogadaValida (e, c)) || (! CoordenadaValida (c))) { // Avaliar se a jogada é válida
		l -> jogadas[linha][coluna] = NULL;
		return NULL;
	}
	// A jogada é válida logo é adicionada.
	l -> jogadas[linha][coluna] = malloc (sizeof (struct minmax));
	(l -> jogadas[linha][coluna]) -> jogada = *c;
	return l -> jogadas[linha][coluna];
}
