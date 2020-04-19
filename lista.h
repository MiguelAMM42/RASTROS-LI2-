/**
@file lista.h
Definição das funções relacionadas com as listas.
*/

#ifndef ___LISTA_H___
#define ___LISTA_H___

#define BUF_SIZE 1024

#define MAX_TAB 8

typedef struct minmax {
   COORDENADA jogada;
   int comprimento; // (?) (Não sei até que ponto é útil meter na estrutura de dados se calhar é melhor meter como contador numa função).
   int jogador; // Jogador a efetuar esta jogada. Importante para ver se é utilizado o max ou min neste conjunto de nodos.
   struct minMax *jogadas11; // Outros nodos com outras tipos de jogadas
   struct minMax *jogadas12;
   struct minMax *jogadas13;
   struct minMax *jogadas21;
   struct minMax *jogadas23;
   struct minMax *jogadas31;
   struct minMax *jogadas32;
   struct minMax *jogadas33;
} MinMax;

typedef int MAPA[8][8];

typedef struct nodo {
   void *valor;
   struct nodo *prox;
} NODO, *LISTA;
<<<<<<< HEAD


//COMENTAR FUNÇÕES TODAS-------------///

=======
/**
\brief Inicializa a lista, com NULL
@param e Apontador para o Estado
@param c Apontador para o Coordenada
@param l Apontador para uma lista
*/
>>>>>>> 1ca75f6ad4ec0af002a711c3a86e2034238931f6
LISTA criar_lista();
/**
\brief Acrescenta um valor ao início da lista
@param L Lista à qual serão acrescentados valores
@param valor Endereço do valor para acrescentar 
*/
LISTA insere_cabeca(LISTA L, void *valor);

void *devolve_cabeca(LISTA L);

LISTA proximo(LISTA L);

LISTA remove_cabeca(LISTA L);

int lista_esta_vazia(LISTA L);

LISTA criaLista (ESTADO *e);
<<<<<<< HEAD
LISTA adicionarCoordenada (ESTADO *e, COORDENADA c, LISTA l);
/**
\brief Calcula rapidamente a distância da coordenada à peça do jogador Atual
@param c Coordenada onde se encontra a peça branca
@param JOgador Atual (1 ou 2)
*/
int dist_jog1 (COORDENADA c, int jogAtual);
=======

void adicionarCoordenada (ESTADO *e, COORDENADA *c, LISTA *l);
>>>>>>> 1ca75f6ad4ec0af002a711c3a86e2034238931f6



#endif



