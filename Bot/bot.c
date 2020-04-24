#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"
#include "interface.h"
#include "bot.h"

int main (int argc, char *argv[]) {
	if (argc != 3) return -1;

	// Leitura do estado através do ficheiro
	ESTADO *e;
	FILE *fileLeitura;
    fileLeitura = fopen(argv[1], "r");
    if (fileLeitura == NULL) return -1; // Se não abre.
    le_ficheiro (e, fileLeitura);
    fclose(fileLeitura);
    mostrar_tabuleiro (*e, stdout);
    mostra_jogadas(e, stdout);
    e -> num_comando ++;

	// Jogada do Bot
	MinMax arvore = malloc (sizeof (MinMax));
    Cria_ListaMinMax (e, &arvore, 2);
    COORDENADA jogada = ((arvore -> jogadas[0][0]) -> jogadas[0][0]) -> jogada;
    jogar(e, jogada);
    mostrar_tabuleiro(*e, stdout);
	// Gravação da jogada no ficheiro

	FILE *fileGravacao;
    fileGravacao = fopen(argv[2], "w");
    if (fileGravacao == NULL) return -1; // Caso em que não abre
    guarda_ficheiro (e, fileGravacao);
    fclose(fileGravacao);
    e -> num_comando ++;
    return 0;
}

// void imprime_minmax(m) {}

/*
MinMax min_max_Lista (ESTADO *e, MinMax l, int min_max) { // min -> 0 || max -> 1
	int v = valorC (e, &(((MinMax)(l -> valor)) -> jogada)); // Valor mínimo/máximo, inicializado com o valor do primeiro elemento.
	MinMax ls = l; // Apontador para o Nodo com menor/maior valor, inicializado com o apontador para o primeiro Nodo.
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
*/

int valorC (ESTADO *e, COORDENADA *c) {
	return 10;
}

void Cria_ListaMinMax (ESTADO *e, MinMax *m, int comp) {
	// Alocação da memória inicial para o árvore de jogadas
	(*m) -> jogada = e -> ultima_jogada;
	// Criação de um nível de jogadas
	CriaNivel (e, *m, comp);
}

void CriaNiveis (ESTADO *e, MinMax jogada, int comp) { // Aplica a CriaNível várias vezes 
	int i = 2;
	int j = 2;
	CriaNivel (e, jogada, comp);
	while (i) { // Adicionar NULL a todos os apontadores
		while (j) CriaNiveis(e, jogada -> jogadas[i][j --], --comp);
		i --;
	}
	
}


void CriaNivel (ESTADO *e, MinMax jogada, int comp) {
	if (!comp) jogada = NULL;
	COORDENADA atual = get_ultima_jogada(e);

	int ilinha = 1;
    while (ilinha >= -1) {
        int icoluna = -1;
        while (icoluna <= 1) {
            COORDENADA a = {atual.coluna + icoluna, atual.linha + ilinha};
			MinMax nodo = adicionarCoordenadaMinMax (e, &a, jogada, ilinha + 1, icoluna + 1, comp);
			CriaNivel (e, nodo, comp - 1);
            icoluna ++;
        }
        ilinha --;
	}
}

MinMax adicionarCoordenadaMinMax (ESTADO *e, COORDENADA *c, MinMax m, int linha, int coluna, int comp) {
	if (!comp) { // Comprimento chegou ao fim
		int i = 2;
		while (i) { // Adicionar NULL a todos os apontadores
			int j = 2;
			while (j) m -> jogadas[i][j --] = NULL;
			i --;
		}
		return NULL;
	} else if (linha == 1 && coluna == 1 || (!jogadaValida (e, c)) || (! CoordenadaValida (c))) { // Avaliar se a jogada é válida
		m -> jogadas[linha][coluna] = NULL;
		return NULL;
	}
	// A jogada é válida logo é adicionada.
	m -> jogadas[linha][coluna] = malloc (sizeof (struct minmax));
	(m -> jogadas[linha][coluna]) -> jogada = *c;
	return m -> jogadas[linha][coluna];
}
