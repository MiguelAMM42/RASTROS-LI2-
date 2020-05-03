#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"
#include "bot.h"

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

	// Jogada do Bot
	putchar ('\n');
    int comp = 4;
    comp += (get_num_jogadas(e)/3);
    COORDENADA jogada = jogadaOTIMA (e, comp, -500, +500, 2 - get_jogador_atual(e));
    // printf ("\n%d\n", minimax(e, 4, -500, 500, 2 - get_jogador_atual(e)));
    jogar(e, jogada); // Tirar verificaçao da jogada valida
    putchar('\n');
    mostrar_tabuleiro(*e, stdout);

	// Gravação da jogada no ficheiro
	FILE *fileGravacao;
    fileGravacao = fopen(argv[2], "w");
    if (fileGravacao == NULL) return -1; // Caso em que não abre
    guarda_ficheiro (e, fileGravacao);
    fclose(fileGravacao);
    putchar('\n');
    return 0;
}


COORDENADA jogadaOTIMA (ESTADO *e, int comp, int alpha, int beta, int jogador) {
    COORDENADA jogadaotima;
    // Queremos o MAXIMO
    if (jogador) {
        int max = -500;
        COORDENADA ultimajogada = get_ultima_jogada(e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(e, &jogada)) {
                    ESTADO eNovo = *e;
                    jogar (&eNovo, jogada);

                    int valor = minimax(&eNovo, comp - 1, alpha, beta, 0);
                    if (valor > max) {
                        max = valor;
                        jogadaotima = jogada;
                    } 
                    if (valor > alpha) alpha = valor;
                    if (beta <= alpha) return jogadaotima; // Pruning
                }
                icoluna --; 
		    }
		ilinha --;
	    }
    return jogadaotima;

    } else { // Queremos o MINIMO
        int min = +500;
        COORDENADA ultimajogada = get_ultima_jogada(e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(e, &jogada)) {
                    ESTADO eNovo = *e;
                    jogar (&eNovo, jogada);

                    int valor = minimax(&eNovo, comp - 1, alpha, beta, 1);
                    if (valor < min) {
                        min = valor;
                        jogadaotima = jogada;
                    }
                    if (valor < beta) beta = valor;
                    if (beta <= alpha) return jogadaotima; // Pruning
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


int minimax(ESTADO *e, int comp, int alpha, int beta, int Maximizar) { 

    // Chegamos a uma folha/jogada vencedora 
    int vencedor = Vencedor (e);
    if (vencedor == 1) return 200; // Jogada vencedora para o jogador 1
    else if (vencedor == 2) return -200; // Jogada vencedora para o jogador 2
    else if (!comp) return valor(e); // min_max_Estado(&e, Maximizar);

    // Queremos o MAXIMO
    if (Maximizar) {
        int max = -500;
        COORDENADA ultimajogada = get_ultima_jogada(e);
        int ilinha = 1;
        while (ilinha >= -1) {
		    int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(e, &jogada)) {
                    ESTADO eNovo = *e;
                    jogar (&eNovo, jogada);

                    int valor = minimax(&eNovo, comp - 1, alpha, beta, 0);
                    if (valor > max) max = valor;
                    if (valor > alpha) alpha = valor;
                    if (beta <= alpha) return max; // Pruning
                }
                icoluna --; 
		    }
		ilinha --;
	    }
    return max;

    } else { // Queremos o MINIMO
        int min = +500;
        COORDENADA ultimajogada = get_ultima_jogada(e);
        int ilinha = 1;
        while (ilinha >= -1) {
		int icoluna = 1;
		    while (icoluna >= -1) {
                COORDENADA jogada = {ultimajogada.coluna + icoluna, ultimajogada.linha + ilinha};
                if (!ilinha && !icoluna);
                else if (CoordenadaValida(&jogada) && jogadaValida(e, &jogada)) {
                    ESTADO eNovo = *e;
                    jogar (&eNovo, jogada);

                    int valor = minimax(&eNovo, comp - 1, alpha, beta, 1);
                    if (valor < min) min = valor;
                    if (valor < beta) beta = valor;
                    if (beta <= alpha) return min; // Pruning
                }
                icoluna --;
		    }
		ilinha --;
	    }
    return min;
    }
}




//////////////////////

int valor(ESTADO *e) {
    int valor = 0;
    MAPA m;
    inicializaMapa (m, e);
    flood_fill (0, m, get_ultima_jogada(e));
    int d1 = getCasaBOT (0, 0, m);
    int d2 = getCasaBOT (maximino, maximino, m);
    if (d1 + d2 == 200) paridade (e); // Caso não seja possível chegar a nenhuma das casas, a pariedade entra em questão
    if (d1 == 100) valor -= 100;      // Impossível chegar à casa do jogador 1
    else if (d2 == 100) valor += 100; // Impossível chegar à casa do jogador 2
    else if (d2 == 1 && get_jogador_atual(e) == 2) valor = -200; // Jogador 2 ganha
    else if (d1 == 1 && get_jogador_atual(e) == 1) valor = 200;  // Jogador 1 ganha
    else if (d1 > d2) {
        if (d1 > 5) valor -= 50 + d1 - d2; // Jogador 2 a ganhar
        else valor += 50 + d1 - d2; // Jogador 1 a ganhar
    } else {
        if (d2 > 5) valor -= 50 + d1 - d2; // Jogador 2 a ganhar
        else valor += 50 + d1 - d2; // Jogador 1 a ganhar
    }
    return valor;
}










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
            if (atual == DOIS) setCasaBOT (coluna, linha, m, 100); // O flood-fill preenche o mapa todo, e para
            else if (atual == UM)  setCasaBOT (coluna, linha, m, 100); // termos acesso à distância à casa X vemos o valor na casa X
            else if (atual == BRANCA)  setCasaBOT (coluna, linha, m, 0); // Assim vamos à casa (0,0) e temos a distância do Jog 1;
            else if (atual == VAZIO)  setCasaBOT (coluna, linha, m, 100);
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
            // COORDENADA c = {i, linha};
            if (i == 8) printf ("\n");
            else printf ("%03d_", (m[linha][i]));  
            }
    }
}


int contaVazias(MAPA m){
    int vazias=0;
    int linha, coluna;
    for(linha = maximino; linha >= 0; linha --){

        for(coluna = 0; coluna <= maximino; coluna ++){

            if( (m[linha][coluna] > 0) && (m[linha][coluna] < 100) ) vazias++;

        }
    
    }
    
    return vazias;
}


int paridade(ESTADO *e){
    MAPA m;
    inicializaMapa (m, e);
    flood_fill (0, m, get_ultima_jogada(e));
    int jogador = get_jogador_atual(e);
    int casasVazias = contaVazias(m);
    if ((jogador + casasVazias)%2) return -200; 
    return 200;
}
