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
	arvore -> comprimento = comp;
	arvore -> jogador = 3 - (e -> jogador_atual);
	CriaNivel (e, arvore, comp);
}

void CriaNivel (ESTADO *e, MinMax jogada, int comp) {
	COORDENADA atual = get_ultima_jogada(e);

	int ilinha = 1;
    while (ilinha >= -1) {
        int icoluna = -1;
        while (icoluna <= 1) {
            if (icoluna == 0 && ilinha == 0) icoluna = 1;
            COORDENADA a = {atual.coluna + icoluna, atual.linha + ilinha};
			adicionarCoordenadaMinMax (e, &a, jogada, icoluna + 1, ilinha + 1, comp);
            icoluna --;
        }
        ilinha --;
	}
}

void adicionarCoordenadaMinMax (ESTADO *e, COORDENADA *c, MinMax l, int linha, int coluna, int comp) {
	if (!comp) { // Adicionar NULL a todos os apontadores
		int i = 2;
		int j = 2;
		while (i) {
			while (j) l -> jogadas[i][j --] = NULL;
			i --;
		}
		return;
	} else if ((!jogadaValida (e, c)) || (! CoordenadaValida (c))) { // Avaliar se a jogada é válida
		l -> jogadas[linha][coluna] = NULL;
		return;
	}
	l -> jogadas[linha][coluna] = malloc (sizeof (struct minmax));
	(l -> jogadas[linha][coluna]) -> jogada = *c;
	(l -> jogadas[linha][coluna]) -> comprimento = -- comp;
	(l -> jogadas[linha][coluna]) -> jogador = e -> jogador_atual;
}
