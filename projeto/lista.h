/**
@file lista.h
Definição das funções relacionadas com as listas.
*/

#ifndef ___LISTA_H___
#define ___LISTA_H___

/**
 *brief Para calcular as distâncias usamos uma matriz de inteiros, que indicam distâncias ou a casa, conformo o Estado.
 * A essa matriz chamamos MAPA.
 */
typedef int MAPA[8][8];


/**
 *brief Estrutura de dados para listas
 */
typedef struct nodo {
   /*@{*/
   void *valor; /**< valor */
   /*@}*/
  /**
  * @name Nodo prox
  */
  /*@{*/
   struct nodo *prox; /**< struct prox  */
} NODO, *LISTA; /**< struct Nodo  */
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
\brief Caso a coordenada seja uma jogada válida, adiciona à lista
@param Apontador para o Estado
@param Apontador para a Coordenada
@param Apontador para a Lista
*/
void adicionarCoordenada (ESTADO *e, COORDENADA *c, LISTA *l);
/**
\brief Calcula o tamanho de uma lista
@param l Lista a que se vai calcular o comprimento
@returns Comprimento da lista.
*/
int length (LISTA l);




#endif



