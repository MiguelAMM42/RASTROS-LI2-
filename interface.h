#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

#define BUF_SIZE 1024
void mostra_jogadas (ESTADO *s);
void mostrar_tabuleiro (ESTADO s);
ESTADO *inicializar_estado();
int interpretador(ESTADO *e);

#endif
