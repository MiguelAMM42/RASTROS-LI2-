/**
@file lista.h
Definição das funções relacionadas com as listas.
*/

#ifndef ___LISTA_H___
#define ___LISTA_H___

#define BUF_SIZE 1024

typedef struct
{
	COORDENADA c;
	int valor;
} COOR;

typedef struct slist
{
	COOR c;
	struct slist *prox;
} Nodo;

typedef Nodo *LISTA;

// LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
// void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);
// LISTA remove_cabeca(LISTA L);
int lista_esta_vazia(LISTA L);



#endif



