/**
@file lista.h
Definição das funções relacionadas com as listas.
*/

#ifndef ___LISTA_H___
#define ___LISTA_H___

#define BUF_SIZE 1024

typedef struct
{
	COORDENADA jogada;
} COOR;

typedef struct nodo {
   void *valor;
   struct nodo *prox;
} NODO, *LISTA;

LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);
LISTA remove_cabeca(LISTA L);
int lista_esta_vazia(LISTA L);
LISTA min_max_Lista (ESTADO *e, LISTA l, int min_max);
int valorC (ESTADO *e, COORDENADA *c);
LISTA criaLista (ESTADO *e);
LISTA adicionarCoordenada (ESTADO *e, COORDENADA c, LISTA l);



#endif



