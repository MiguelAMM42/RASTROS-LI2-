#include "dados.h"


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    // Falta a resto da inicialização.
    for (int i = 0; i < 8; i++) {
        for (int ii = 0; ii < 8; ii ++) {
            if (i == 3 && ii == 4) (e -> tab [i][ii]) = PRETA;
            else (e -> tab [i][ii]) = VAZIO;                                                    
        }
    }
    return e;
}


void desenhaTabuleiro (ESTADO *s) {
    int i = 0;
    int linha = 0;
    for (linha = 0; linha < 8; linha++) {
        for (i = 0; i < 9; i++) {
            if (i == 8) putchar('\n');
            else {
                if (i == 7 && linha == 0) putchar ('2');
                else {
                    if (i == 0 && linha == 7) putchar ('1');
                    else {
                        if ((s -> tab [linha] [i]) == PRETA) putchar ('#');    // &(s -> registos[(s -> jogadas)
                        else {
                            if ((s -> tab [linha] [i]) == VAZIO) putchar ('.');
                            else putchar ('*'); 
                        }
                    }
                }
            }
        }
    }
}

void mostra_jogadas (ESTADO *s)  // Imprime a lista de jogadas
{ // Falta inicializar a lista de jogadas
    int jogadaNum = 0;
    while (jogadaNum != (s -> num_jogadas)) {
        printf ("%d : ", jogadaNum);
        printf ("%c%d", (((s -> jogadas) -> jogador1) .coluna) + 96, (((s -> jogadas) -> jogador1) .linha)); 
        printf ("%c%d ; \n", (((s -> jogadas) -> jogador2) .coluna) + 96, (((s -> jogadas) -> jogador2) .linha));
        jogadaNum ++;
    }
}



    // printf (" 12345678 \n");
    /*while (linha != 8) {
        printf ("%c ", linha + 97);
        int arr[8];
        geraArray (s, arr, linha + 1);
        while (i != 8) {
            if (linha == 0 && i == 7)  printf ("1 ");
                                       
            else if (linha == 7 && i == 0) putchar ('2');
            else if (arr[i] == 2) putchar ('*');
            else if (arr[i] == 1) putchar ('#');
            else putchar ('.');
            i ++;
       }
        i = 0;
        printf ("\n");
        linha ++;
    }*/
/*




int acrescenta (Estado *s, coordenada *jogada) {
    if (! jogadaValida (s, jogada)) {printf ("Jogada Inválida"); return 0;}
    (s -> registos [++ (s -> jogadas)]) = *jogada;
    return 1;
}


int jogadaValida (Estado *s, coordenada *jogada) {
    if (distancia (s, jogada) || (! pertence (s, jogada))) return TRUE;
    return FALSE;
}


int distancia (Estado *s, coordenada *jogada) { // Verifica se a casa atual do asterisco esta a um de distancia de uma certa casa
    coordenada *ast = &(s -> registos[(s -> jogadas) - 1]); // Casa atual do asterisco
    if ((abs (((ast -> coluna) - 95) - ((jogada -> coluna) - 95)) == 1) || (abs ((ast -> linha) - (jogada -> linha))) == 1) return TRUE;
    return FALSE;
}


int pertence (Estado *s, coordenada *jogada) {
    int i = 0;
    while (i != s -> jogadas) {
        if (CoorIgual (&(s -> registos[i]), jogada)) return TRUE;
        i ++;
    }
    return FALSE;
}

int CoorIgual (Coordenada *a, Coordenada *b) {
    if (((a -> coluna) == (b -> coluna)) && ((a -> linha) == (b -> linha))) return TRUE;
    return FALSE;
}

*/