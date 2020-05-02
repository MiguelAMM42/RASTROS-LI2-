/**
@file lista.h
Definição das funções relacionadas com as listas.
*/

#ifndef ___LISTA_H___
#define ___LISTA_H___

#define BUF_SIZE 1024
#define maximino 7
#define MAX_TAB 8

typedef int MAPA[8][8];

typedef struct nodo {
   void *valor;
   struct nodo *prox;
} NODO, *LISTA;



/**
\brief Inicializa a lista, com NULL
@param e Apontador para o Estado
@param c Apontador para o Coordenada
@param l Apontador para uma lista
*/
LISTA criar_lista();
/**
\brief Acrescenta um valor ao início da lista
@param L Lista à qual serão acrescentados valores
@param valor Endereço do valor para acrescentar 
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
brief Devolve a cabeça da lista
@param L Lista a ver
@param valor Apontador para a cabeça da Lista
*/
void *devolve_cabeca(LISTA L);
/**
brief Devolve a cauda da lista
@param L Lista à qual se vai remover a cabeça
*/
LISTA proximo(LISTA L);
/**
brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Lista na qual se vai retirar a cabeça e libertar espaço
*/
LISTA remove_cabeca(LISTA L);
/**
brief Diz se a Lista está vazia(devolvendo 1) ou não (devolvendo 0)
@param L Lista a verificar se está ou não vazia
*/
int lista_esta_vazia(LISTA L);
/**
\brief Cria uma lista com as coordenadas de possiveis jogadas, para posteriormente criar uma heurística
@param e Apontador para o Estado
*/
LISTA criaLista (ESTADO *e);
/**
\brief Calcula rapidamente a distância da coordenada à peça de vitória do jogador Atual
@param c Coordenada onde se encontra a peça branca
@param JOgador Atual (1 ou 2)
*/
int dist_jog1 (COORDENADA c, int jogAtual);
/**
\brief Caso a coordenada seja uma jogada válida, adiciona à lista
@param Apontador para o Estado
@param Apontador para a Coordenada
@param Apontador para a Lista
*/
void adicionarCoordenada (ESTADO *e, COORDENADA *c, LISTA *l);




#endif



