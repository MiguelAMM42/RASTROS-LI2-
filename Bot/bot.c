#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista.h"
#include "logica.h"
#include "interface.h"
#include "bot.h"
#define maximino 7

int main (int argc, char *argv[]) {
	if (argc != 3) return -1;

	// Leitura do estado através do ficheiro
	ESTADO *e = inicializar_estado();
	FILE *fileLeitura;
    fileLeitura = fopen(argv[1], "r");
    if (fileLeitura == NULL) return -1; // Se não abre.
    le_ficheiro (e, fileLeitura);
    fclose(fileLeitura);
    mostrar_tabuleiro (*e, stdout);
    mostra_jogadas(e, stdout);

	// Jogada do Bot
	putchar ('\n');
	MinMax arvore = malloc (sizeof (struct minmax));
    Cria_ListaMinMax (e, &arvore, 4);
	MinMax ar1 = (arvore -> jogadas[0][0] -> jogadas[0][0]);
    COORDENADA jogada = ar1 -> jogada;
    jogar(e, jogada); // Tirar verificaçao da jogada valida
    mostrar_tabuleiro(*e, stdout);

	// Gravação da jogada no ficheiro
	FILE *fileGravacao;
    fileGravacao = fopen(argv[2], "w");
    if (fileGravacao == NULL) return -1; // Caso em que não abre
    guarda_ficheiro (e, fileGravacao);
    fclose(fileGravacao);
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
	CriaNivel (*e, *m, comp);
}



void CriaNivel (ESTADO e, MinMax jogada, int comp) {
	if (!jogada) return;
	else if (!comp) {
		jogada = NULL;
		return;
	}
	COORDENADA atual = get_ultima_jogada(&e);
	int ilinha = 1;
	while (ilinha >= -1) {
	    int icoluna = -1;
	    while (icoluna <= 1) {
	        COORDENADA coor = {atual.coluna + icoluna, atual.linha + ilinha};
			if (!ilinha && !icoluna) (jogada -> jogadas[1][1]) = NULL;
			else if (CoordenadaValida (&coor) && jogadaValida (&e, &coor)) {
				MinMax nodo = adicionarCoordenadaMinMax (&e, &coor, jogada, -ilinha + 1, icoluna + 1, comp);
				ESTADO a = e;
				jogar(&a, coor); // Tirar Verificação de jogada válida
				CriaNivel (a, nodo, comp - 1);
			} else jogada -> jogadas[-ilinha + 1][icoluna + 1] = NULL;
	        icoluna ++;
		}
		putchar('\n');
	ilinha --;
	}
}


MinMax adicionarCoordenadaMinMax (ESTADO *e, COORDENADA *c, MinMax m, int linha, int coluna, int comp) {
	if (!m) return NULL; // Nodo é NULL
	else if (!comp) { // Comprimento chegou ao fim
		int i = 2;
		while (i) { // Adicionar NULL a todos os apontadores
			int j = 2;
			while (j) {
				m -> jogadas[i][j] = NULL;
				j --;
			}
			i --;
		}
		return NULL;
	}
	// A jogada é válida logo é adicionada.
	m -> jogadas[linha][coluna] = malloc (sizeof (struct minmax));
	printf ("0%d:%c%c \n", comp,'a' + (c -> coluna), '1' + (c -> linha));
	(m -> jogadas[linha][coluna]) -> jogada = *c;
	return m -> jogadas[linha][coluna];
}


int test_coor_rec (ESTADO *e, COORDENADA cTeste, int jA)
{
    int res = jogar (e, cTeste);
    if (jA == 2)
    {
        if (res == 22) return 2; //2 ganhou
        if (res == 21) return -1; //1 ganhou
        if (res == 1) return 1; //possível
        else return 0; //Jogada impossível                
   }

    if (jA == 1)
    {
        if (res == 21) return 2; //1 ganhou
        if (res == 22) return -1; //2 ganhou
        if (res == 1) return 1; //possível
        else return 0; //Jogada impossível                
   }
} 


int distRap (ESTADO *e)
{
    printf ("&&&&&");
    int jA = get_jogador_atual (e);
    COORDENADA cA = get_ultima_jogada (e);
    int vLogico = 1;
    int dist = 0;

    if (jA == 1)
    {
        (cA.coluna)--;
        (cA.linha) --;
        vLogico = casaVazia(e, &cA);                                                 
        while (cA.coluna > 0 && cA.linha > 0 && vLogico)
        {
   //     printf (" meio1 ");           
         dist++;
         (cA.coluna)--;
         (cA.linha) --;
         vLogico = casaVazia(e, &cA);
        }
        while (cA.coluna > 0 && cA.linha == 0 && cA.coluna < maximino && cA.linha < maximino && vLogico) {

  //      printf (" linha1 == 0 ");
                                                        (cA.coluna) --;
                                                        vLogico = casaVazia(e, &cA);
                                                        if (vLogico) dist++;   
                                                    }   
        
        while (cA.coluna == 0 && cA.linha > 0 && cA.coluna < maximino && cA.linha < maximino && vLogico) {
                          
      //  printf (" coluna1 == 0 ");
                                                                (cA.linha) --;
                                                                vLogico = casaVazia(e, &cA);
                                                                if (vLogico) dist++;   
                                                            }

        if (cA.coluna < maximino && cA.linha < maximino && cA.coluna == 0 && cA.linha == 0) return ++dist;
        else return 0;
    }
    else
    {   

       // printf (" meio2 " );
        (cA.coluna)++;
        (cA.linha) ++;
        vLogico = casaVazia(e, &cA);
        
        while (cA.coluna < maximino && cA.linha < maximino && cA.coluna > 0 && cA.linha > 0 && vLogico)
        {

    //    printf (" meio2 ");
          dist++;           
         (cA.coluna)++;
         (cA .linha) ++;
         vLogico = casaVazia(e, &cA);
         //
        }
        while (cA.coluna < maximino && cA.linha  == maximino && cA.coluna > 0 && cA.linha > 0 && vLogico) 
                                                    {
                          
       // printf (" linha max 2 " );
                                                        (cA.coluna) ++;
                                                        vLogico = casaVazia(e, &cA);
                                                        if (vLogico) dist++;   
                                                    }   
        
        while (cA.coluna == maximino && cA.linha  < maximino && cA.coluna > 0 && cA.linha > 0 && vLogico) {
                          
     //   printf (" coluna max 2 ");
                                                                (cA.linha ) ++;
                                                                vLogico = casaVazia(e, &cA);
                                                                if (vLogico) dist++;   
                                                            }

        if (cA.coluna == maximino && cA.linha  == maximino && cA.coluna > 0 && cA.linha > 0) return ++dist;
        else return 0;
    }
}

//Calcula a distância independentemente de estar ou não ocupado
int dist_imdt (COORDENADA c, int jogA)
{
    int col = c.coluna;
    int lin = c.linha;
    if (jogA == 1)
        {
        if (col >= lin) return col--;
        else return lin--;
        }
    else 
        {
        lin = maximino - lin;
        col = maximino - col;
        if (lin >= col) return lin++;
        else return col++;
        }
}



//flood_fill testar com

//Altera um valor na matriz para um dado número (subst)
void setCasaBOT (int col, int lin, MAPA m, int subst)
{   
    //int * mi;
    (m[lin][col]) = subst;
}

int getCasaBOT (int col, int lin, MAPA m)
{   
    //int * mi;
    return ((m)[lin] [col]);
}
// iniciar com 0 da peça atual
void flood_fill (int distAtual, MAPA m, COORDENADA cA)
{
    int coluna = cA.coluna;
    int linha = cA.linha;
    if (coluna < 0 || linha < 0 || coluna > maximino || linha > maximino) return;  //limite do mapa
    int posMapa = getCasaBOT (coluna, linha, m);    //  o posMapa está errado, e no gdb não faz sentido
    if (posMapa < 0 ) return ;  // Bate na parede
    if (posMapa <= distAtual && distAtual != 0) return;
    
    
        setCasaBOT (coluna, linha, m, distAtual);
        distAtual++;
        COORDENADA volta = cA;
        (volta.coluna)++;
        flood_fill (distAtual, m, volta);
        (volta.linha)++;
        flood_fill (distAtual, m, volta);
        (volta.coluna)--;
        flood_fill (distAtual, m, volta);
        (volta.coluna)--;
        flood_fill (distAtual, m, volta);
        (volta.linha)--;
        flood_fill (distAtual, m, volta);
        (volta.linha)--;
        flood_fill (distAtual, m, volta);
        (volta.coluna)++;
        flood_fill (distAtual, m, volta);                    
        (volta.coluna)++;
        flood_fill (distAtual, m, volta);
   
}
//Inicializa a matriz/mapa
void inicializaMapa (MAPA m, ESTADO *e)
{
   //    printf (" ini! ");
    int coluna = maximino, linha = maximino;
    COORDENADA cA;
    while (linha >= 0)
    {
        while (coluna >= 0)
        {
            cA.coluna = coluna;
            cA.linha = linha;
            CASA atual;
            atual = get_casa (e, cA);
            if (get_casa (e, cA) == DOIS) setCasaBOT (coluna, linha, m, 100); // O flood-fill preenche o mapa todo, e para
            else if (get_casa (e, cA) == UM)  setCasaBOT (coluna, linha, m, 100); // termos acesso à distância à casa X vemos o valor na casa X
            else if (get_casa (e, cA) == BRANCA)  setCasaBOT (coluna, linha, m, 0); // Assim vamos à casa (0,0) e temos a distância do Jog 1;
            else if (get_casa (e, cA) == VAZIO)  setCasaBOT (coluna, linha, m, 100);
            else  setCasaBOT (coluna, linha, m, -1); 
            coluna--;
        }
        coluna = maximino;
        linha--;
   }
}

int dist (ESTADO *e)
{
    COORDENADA cA = get_ultima_jogada (e);
                            int jA = get_jogador_atual (e);
                                MAPA m;
      //                          int a = dist_imdt (cA, jA);
    
        //                        int b = distRap (e);
                                inicializaMapa (m,e);
    
                             flood_fill (0, m, cA);
                                //mostrar_mapa (m);
    //int lin = cA -> linha;
    //int col = cA -> coluna;
    int d1 = getCasaBOT (0, 0, m);
    int d2 = getCasaBOT (maximino, maximino, m);
    
    //int dist = distRap ();
    if (d1 == 0 || d2 == 0) return -1;
    if (jA == 1) return (d1- d2);
    else return (d2-d1);
}

/*
int main() {
    LISTA L = criar_lista();
    char linha[BUF_SIZE];
    printff("Insira várias linhas, acabando com CTRL-D:\n"); 
    // control-D é a tecla CTRL e a tecla D ao mesmo tempo
    // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma copia da string que foi lida
        L = insere_cabeca(L, strdup(linha));
    }

    printff("\n==============================\n");
    printff(  "=          PERCURSO          =\n");
    printff(  "==============================\n\n");
    
    // percorre sem remover os elementos da lista
    for (LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        char *str = (char *) devolve_cabeca(T);
        printff("%s", str);
    }
    
    printff("\n==============================\n");
    printff(  "=           REMOCAO          =\n");
    printff(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!lista_esta_vazia(L)) {
        char *str = (char *) devolve_cabeca(L);
        L = remove_cabeca(L);
        printff("%s", str);
        free(str);
    }
    return 0;
}

*/


