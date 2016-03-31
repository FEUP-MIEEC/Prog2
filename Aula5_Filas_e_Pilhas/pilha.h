/*****************************************************************/
/*                Pilha | PROG2 | MIEEC | 2015/16                */      
/*****************************************************************/

#ifndef PILHA_H

/** 
* \brief registo para armazenar elementos da pilha
*   este registo contem um apontador para uma string 
*   e um apontador para o proximo elemento da pilha
*/
typedef struct item_p
{
	char* elemento;
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
 *  \brief elimina uma pilha, libertando toda a memória ocupada
 *  \param l apontador para a pilha
 *  \remark se pilha = NULL retorna sem fazer nada
 */
void pilha_apaga(pilha *p);

/**
 *  \brief testa se a pilha esta' vazia
 *  \param p apontador para a pilha em causa
 *	\return 1, se estiver vazia. 0, caso contrario
 */
int	pilha_vazia(pilha *p);

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
char* pilha_top(pilha *p);

/** 
 *  \brief insere um novo elemento no topo da pilha
 *  \param l apontador para a pilha
 *  \param strung elemento pretendido
 */
void pilha_push(pilha *p, char* string);

/**
 *  \brief retira o elemento no topo da pilha
 *  \param l apontador para a pilha
 */
void pilha_pop(pilha *p);

#define PILHA_H
#endif
