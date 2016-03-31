/*****************************************************************/
/*                  Fila de pilhas de contentores                */
/*****************************************************************/

#ifndef FILA_H

#include "pilha_contentores.h"

/** 
* \brief registo para armazenar elementos da fila
*   este registo contém um apontador para uma pilha de contentores
*   e um apontador para o próximo elemento da fila
*/
typedef struct item_f
{
	/** \brief pilha de contentores armazenada */
	pilha* elemento;
  struct item_f *proximo;
} filaItem;

typedef struct
{
	filaItem *raiz;
	int tamanho;
} fila;

/**
 *  \brief cria uma nova fila vazia
 *  \return apontador para a fila
 */
fila* fila_nova();

/** 
 *  \brief elimina uma fila, libertando toda a memória ocupada
 *  \param l apontador para a fila
 *  \remark se fila = NULL retorna sem fazer nada
 */
void fila_apaga(fila *f);

/**
 *  \brief indica o comprimento da fila
 *  \param f apontador para a fila
 *  \return numero de elementos da fila ou -1 se fila = NULL
 */
int fila_tamanho(fila *f);

/** 
 *  \brief retorna a pilha armazenada no inicio da fila - proximo elemento a sair
 *  \param f apontador para a fila
 *  \return apontador para a pilha no inicio da fila
 */
pilha* fila_front(fila *f);

/** 
 *  \brief retorna a pilha armazenada no fim da fila - ultimo elemento que entrou
 *  \param f apontador para a fila
 *  \return apontador para a pilha no fim da fila
 */
pilha* fila_back(fila *f);

/** 
 *  \brief insere uma nova pilha no fim da fila
 *  \param f apontador para a fila
 *  \param valor pilha pretendida
 */
void fila_push(fila *f, pilha* valor);

/**
 *  \brief retira a pilha no inicio da fila
 *  \param f apontador para a fila
 */
void fila_pop(fila *f);

#define FILA_H
#endif
