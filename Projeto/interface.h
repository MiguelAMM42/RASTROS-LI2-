/**
@file interface.h
Definição das funções relacionadas com o interface.
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

#define BUF_SIZE 1024
/**
\brief Mostra as jogadas
@param s Apontador para o estado
@param fp Apontador para o ficheiro
*/
void mostra_jogadas (ESTADO *s, FILE *fp);
/**
\brief Imprime o tabuleiro
@param s Estado
@param fp Apontador para o ficheiro 
*/
void mostrar_tabuleiro (ESTADO s, FILE *fp);
/**
\brief Interpreta as jogadas feitas pelo jogador
@param s Apontador para o Estado
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int interpretador(ESTADO *e);
/**
\brief Imprime o prompt
@param s Apontador para o estado
*/
void mostra_prompt (ESTADO *s);
/**
\brief Interpreta as jogadas feitas pelo jogador
@param e Apontador para o Estado
@param fp Apontador para o ficheiro onde se guarda o Estado
*/
void guarda_ficheiro (ESTADO *e, FILE *fp);

#endif
