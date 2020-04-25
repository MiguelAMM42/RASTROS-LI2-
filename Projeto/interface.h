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
/**
\brief Usado no Interpretador para executar o comando "pos"
@param e Apontador para o Estado
@param jog Número do conjunto de jogadas para as quais se quer retornar
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int comandoPos(ESTADO *e, int jog);
/**
\brief Usado no Interpretador para executar uma jogada(ex.:"e4")
@param e Apontador para o Estado
@param col Apontador para a coluna onde se vai jogar
@param lin Apontador para a linha onde se vai jogar
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int comandoJogar(ESTADO *e, char *col, char *lin);
/**
\brief Usado no Interpretador para executar o comando "gr"
@param e Apontador para o Estado
@param endereco Apontador para o endero do ficheiro onde se guarda o Estado
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int comandoGravar(ESTADO *e, const char *endereco );
/**
\brief Usado no Interpretador para executar o comando "jog"
@param e Apontador para o Estado
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int comandoJog (ESTADO *e);
/**
\brief Usado no Interpretador para executar o comando "ler"
@param e Apontador para o Estado
@param endereco Apontador para o endereço do ficheiro a ler
@returns Valor que corresponde ao tipo de comportamento que deve ter o Jogo.
*/
int comandoLer(ESTADO *e, const char *endereco );

#endif
