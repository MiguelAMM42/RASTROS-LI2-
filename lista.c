#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#define BUF_SIZE 1024

int main() {
	LISTA L = criar_lista();
	char linha[BUF_SIZE];
	printf("Insira várias linhas, acabando com CTRL-D:\n");	
	// control-D é a tecla CTRL e a tecla D ao mesmo tempo
	// Em windows é capaz de ser CTRL-Z
	while(fgets(linha, BUF_SIZE, stdin) != 0) {
		// A função strdup cria uma cópia da string que foi lida
	    L = insere_cabeca(L, strdup(linha));
	}

	printf("\n==============================\n");
	printf(  "=          PERCURSO          =\n");
	printf(  "==============================\n\n");
	
	// percorre sem remover os elementos da lista
	for (LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
		char *str = (char *) devolve_cabeca(T);
	  	printf("%s", str);
	}
	
	printf("\n==============================\n");
	printf(  "=           REMOCAO          =\n");
	printf(  "==============================\n\n");
	// percorre e vai removendo a cabeça
	while(!lista_esta_vazia(L)) {
	    char *str = (char *) devolve_cabeca(L);
	    L = remove_cabeca(L);
	    printf("%s", str);
	    free(str);
	}
	return 0;
}

int lista_esta_vazia (LISTA L) {
	if (L == NULL) return 1;
	return 0;
	// OU (?)
	// return L;
}
LISTA criar_lista ()
{ 
  LISTA L;
  L = malloc (sizeof (LISTA));
  //COOR Inicializada
  COORDENADA cI = {4, 4};
  COOR ini;
  ini.c = cI;
  ini.valor = 1;
  //LISTA iniciada
  L->c = ini;
  L->prox = NULL;
  return L;
}

LISTA remove_cabeca(LISTA L)
{
	if (L == NULL) return NULL;
	LISTA tmp = L;
	L = L -> prox;
	free (tmp);
	return L;
}


LISTA proximo(LISTA L){
	LISTA proximo = L -> prox;
	return proximo;
}


LISTA insere_cabeca(LISTA L, void *valor){
    LISTA R = malloc(sizeof(LISTA));
    R -> valor = *valor;
    R -> prox = L;
	return R;
}

