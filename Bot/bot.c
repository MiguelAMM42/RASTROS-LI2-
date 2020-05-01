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
    COORDENADA jogada = jogadaOTIMA (*e, 6, -500, +500, 2 - get_jogador_atual(e));
    // printf ("\n%d\n", minimax(*e, 4, -500, 500, 1));
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


COORDENADA jogadaOTIMA (ESTADO e, int comp, int alpha, int beta, int jogador) {
    COORDENADA jogadaotima;
    // Queremos o MAXIMO
    if (jogador) {
        int max = -500;
        COORDENADA ultimajogada = get_ultima_jogada(&e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(&e, &jogada)) {
                    ESTADO a = e;
                    jogar (&a, jogada);

                    int valor = minimax(e, comp - 1, alpha, beta, 0);
                    if (valor > max) {
                        max = valor;
                        jogadaotima = jogada;
                    } 
                    if (alpha < valor) alpha = valor;
                    if (beta <= alpha) return jogadaotima; // Alpha Beta Pruning
                }
                icoluna --; 
		    }
		ilinha --;
	    }
    return jogadaotima;

    } else { // Queremos o MINIMO
        int min = +500;
        COORDENADA ultimajogada = get_ultima_jogada(&e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = -1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(&e, &jogada)) {
                    ESTADO a = e;
                    jogar (&a, jogada);

                    int valor = minimax(e, comp - 1, alpha, beta, 1);
                    if (valor < min) {
                        min = valor;
                        jogadaotima = jogada;
                    }
                    if (beta > valor) beta = valor;
                    if (beta <= alpha) return jogadaotima; // Alpha Beta Pruning
                }
                icoluna --; 
		    }
		ilinha --;
	    }
    return jogadaotima;
    }
}














/////////////////////////////////

/// Função valorativa
/// j2 -200_______________0_______________200 j1
/// Chamada inicial minimax (e, 3, -500, +500, 2 - jogador)


int minimax(ESTADO e, int comp, int alpha, int beta, int Maximizar) { 

    // Chegamos a uma folha/jogada vencedora 
    int vencedor = Vencedor (&e);
    if (vencedor == 1) return 201; // Jogada vencedora
    else if (vencedor == 2) return -201; // Jogada perdedora
    else if (!comp) return min_max_Estado(&e, Maximizar);

    // Queremos o MAXIMO
    if (Maximizar) {
        int max = -500;
        COORDENADA ultimajogada = get_ultima_jogada(&e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(&e, &jogada)) {
                    ESTADO a = e;
                    jogar (&a, jogada);

                    int valor = minimax(e, comp - 1, alpha, beta, 0);
                    if (valor > max) max = valor; 
                    if (alpha < valor) alpha = valor;
                    if (beta <= alpha) return max; // Alpha Beta Pruning
                }
                icoluna --; 
		    }
		ilinha --;
	    }
    return max;

    } else { // Queremos o MINIMO
        int min = +500;
        COORDENADA ultimajogada = get_ultima_jogada(&e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(&e, &jogada)) {
                    ESTADO a = e;
                    jogar (&a, jogada);

                    int valor = minimax(e, comp - 1, alpha, beta, 1);
                    if (valor < min) min = valor; 
                    if (beta > valor) beta = valor;
                    if (beta <= alpha) return min; // Alpha Beta Pruning
                }
                icoluna --;
		    }
		ilinha --;
	    }
    return min;
    }
}




//////////////////////

 










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


void mostrar_mapa (MAPA m) {
    printf ("\n  cheguei  \n");
    int i = 0;
    int linha;
    for (linha = 7; linha > (-1); linha--) {
        for (i = 0; i < 9; i++) {
            COORDENADA c = {i, linha}; {
            if (i == 8) printf ("\n");
            else printf ("%03d_", (m[linha][i])); }  }
    }
}


int test_max (MAPA m1, MAPA m2, int res, COORDENADA cA)
{
        if (CoordenadaValida (&cA)) {
                                   int valTab1, valTab2, temp;
                                    valTab1 = m1[cA.linha][cA.coluna];
                                    valTab2 = m2[cA.linha][cA.coluna];
                                    temp = valTab2 - valTab1;
                                    if (valTab1 >= 0 && valTab1 <= 40 && valTab2 >= 0 && valTab2 <= 40 && temp > res ) res = temp;
                                    }

        return res;
}
int test_min (MAPA m1, MAPA m2, int res, COORDENADA cA)
{
   if (CoordenadaValida (&cA)) {
                                 int valTab1, valTab2, temp;
                                 valTab1 = m1[cA.linha][cA.coluna];
                                 valTab2 = m2[cA.linha][cA.coluna];
                                 temp = valTab2 - valTab1;
                                 if (temp < res ) res = temp;
                                }
        return res;
}
// O inteiro do min_max diz se é suposto maximizar ou minimar o valor
int min_max_Estado (ESTADO *e, int min_max)
{
 //   if (vencedor (e) == 1 );
    int jogA = get_jogador_atual (e);
    COORDENADA coorJ = get_ultima_jogada (e);
    //Inicializar mapas
    // m1 = mapa cuja contagem parte da casa (0,0) - J1
    //m2 = ...
    MAPA m1, m2;
    inicializaMapa (m1,  e);
    inicializaMapa (m2,  e);
    COORDENADA cA;
     //maximizar
    cA.coluna = 0;
    cA.linha = 0;
    flood_fill (0, m1, cA);  //

  //  mostrar_mapa (m1);
    printf ("\n");
    cA.coluna = maximino;
    cA.linha = maximino;  //Depois copiar mapa, em vez de inicializar
    // Gastas memória desnecessária
    flood_fill (0, m2, cA);  //
    int valTab1, valTab2, res;
    int coorVal;

mostrar_mapa ( m1) ; //   
mostrar_mapa ( m2) ;
    //inicializa mapas feitos
    if (min_max == 1) {  //Para maximizar
        (coorJ.coluna)++;
        valTab1 = m1[coorJ.linha][coorJ.coluna];
        valTab2 = m2[coorJ.linha][coorJ.coluna];
                                        
        if (coorJ.coluna <= maximino && valTab1 != -1 && valTab2 != -1) res = valTab2  -  valTab1 ;
        else res = 100;
                                        //Inicializar valor de resposta
        
        
        (coorJ.linha)++;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.coluna)--;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.coluna)--;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.linha)--;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.linha)--;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.coluna)++;
        res = test_max (m1, m2, res, coorJ);
        (coorJ.coluna)++;
        res = test_max (m1, m2, res, coorJ);
    }
        else 
        {
         (coorJ.coluna)++;  
//Inicializar valor de resposta
        valTab1 = m1[coorJ.linha][coorJ.coluna];
        valTab2 = m2[coorJ.linha][coorJ.coluna];
        
        if (coorJ.coluna <= maximino && valTab1 != -1 && valTab2 != -1) res = valTab2  -  valTab1 ;
        else res = 100;
        (coorJ.linha)++;

        res = test_min (m1, m2, res, coorJ);
        (coorJ.coluna)--;
        res = test_min (m1, m2, res, coorJ);
        (coorJ.coluna)--;
        res = test_min (m1, m2, res, coorJ);
        (coorJ.linha)--;
        res = test_min (m1, m2, res, coorJ);
        (coorJ.linha)--;
        res = test_min (m1, m2, res, coorJ);
        (coorJ.coluna)++;
        res = test_min (m1, m2, res, coorJ);
        (coorJ.coluna)++;
        res = test_min (m1, m2, res, coorJ);
        }
        int i, ii;
        for (i = 0; i <= maximino; i++)
            {
                for (ii = 0; ii<= maximino; ii++)
                {
                    int v2 = getCasaBOT (i, ii, m2);
                    int v1 = getCasaBOT (i, ii, m1);
                   if (v1 == -1 || v2 == -1) v2 = -69;
                   else v2 = v2-v1;
                setCasaBOT (i, ii, m2, v2) ;
                }
            }
        printf("\n Mapa final \n ");
        mostrar_mapa (m2);    
        printf ("\n %d \n", res);

        return res;
    }
    // Queremos o mínimo da lista
