/*****************************************************************/
/*                      Pilha de contentores                     */
/*****************************************************************/

#ifndef PILHA_H

#include "contentor.h"

/**
* \brief registo para armazenar elementos da pilha
*   este registo cont�m um apontador para um contentor
*   e um apontador para o pr�ximo elemento da pilha
*/
typedef struct item_p
{
	/** \brief contentor armazenado */
	contentor* elemento;
  struct item_p *proximo;
} pilhaItem;

typedef struct
{
	pilhaItem *raiz;
	int tamanho;
} pilha;

/**
 *  \brief cria uma nova pilha vazia
 *  \return apontador para a pilha
 */
pilha* pilha_nova();

/**
 *  \brief elimina uma pilha, libertando toda a mem�ria ocupada
 *  \param l apontador para a pilha
 *  \remark se pilha = NULL retorna sem fazer nada
 */
void pilha_apaga(pilha *p);

/**
 *  \brief indica o comprimento da pilha
 *  \param l apontador para a pilha
 *  \return numero de elementos da pilha ou -1 se pilha = NULL
 */
int pilha_tamanho(pilha *p);

/**
 *  \brief retorna o contentor armazenado no topo da pilha - proximo elemento a sair/ultimo elemento que entrou
 *  \param l apontador para a pilha
 *  \return apontador para o contentor no topo da pilha
 */
contentor* pilha_top(pilha *p);

/**
 *  \brief insere um novo elemento no topo da pilha
 *  \param l apontador para a pilha
 *  \param contr elemento pretendido
 */
void pilha_push(pilha *p, contentor* contr);

/**
 *  \brief retira o elemento no topo da pilha
 *  \param l apontador para a pilha
 */
void pilha_pop(pilha *p);

#define PILHA_H
#endif
