/*****************************************************************/
/*                Fila | PROG2 | MIEEC | 2013/14                 */      
/*****************************************************************/

#ifndef FILA_H

#define FILA_ILIMITADA	0

#define FILA_OK		0
#define FILA_CHEIA		(-1)
#define FILA_ERRO		(-2)
#define FILA_INVALIDA	(-3)

/** 
* \brief registo para suportar os itens de uma fila de strings
* este registo contém uma string e um ponteiro para o proximo item
*/
struct fitem
{
	char *string;
	struct fitem *proximo;
};

typedef struct fitem filaItem;

/** 
* \brief registo para suportar uma fila de strings com base em lista
* este registo contém um ponteiro para a cabeca da lista de strings, 
* outro para a cauda e um inteiro que indica o numero maximo de 
* strings armazenadas
*/
typedef struct
{
	int capacidade;
	filaItem *cabeca;
	filaItem *cauda;
} fila;

/** 
 *  \brief cria uma nova fila com capacidade especificada
 *  \param capacidade numero maximo de strings armazenadas (0 corresponde a capacidade ilimitada)
 *  \return apontador para a fila criada
 *  \remark se a fila nao for criada, retorna NULL
 */
fila* fila_nova(int capacidade);

/**
 *  \brief testa se a fila esta' vazia
 *  \param f apontador para a fila em causa
 *	\return 1, se estiver vazia. 0, caso contrario
 */
int	fila_vazia(fila *f);

/**
 *  \brief testa se a fila esta' cheia (tendo em conta a capacidade da fila)
 *  \param f apontador para a fila em causa
 *	\return 1, se estiver cheia. 0, caso contrario
 *	\remark se capacidade for FILA_ILIMITADA, deve obviamente retornar 0
 */
int	fila_cheia(fila *f);

/**
 *  \brief insere string na cauda da fila
 *  \param f apontador para a fila em causa
 *  \param string string a inserir
 *  \return se inserir com sucesso, retorna FILA_OK
 *  \return se nao inserir por exceder a capacidade, retorna FILA_CHEIA
 *  \return noutras situacoes, retorna FILA_ERRO
 *	\remark se capacidade for FILA_ILIMITADA, nunca ha excesso de capacidade
 */
int fila_push(fila *f, const char*string);

/**
 *  \brief retira e retorna a string 'a cabeca da fila
 *  \param f apontador para a fila em causa
 *  \remark se a fila estiver vazia, retorna NULL
 */
void fila_pop(fila *f);

/**
 *  \brief retorna o comprimento actual da fila
 *  \param f apontador para a fila em causa
 *  \return numero de strings actualmente na fila (comprimento da lista)
 */
int fila_comprimento(fila *f);

/**
 *  \brief devolve string 'a cabeca da fila, sem a retirar
 *  \param f apontador para a fila em causa
 *  \return string 'a cabeca da fila
 *  \remark se a fila estiver vazia, retorna NULL
 */
char* fila_front(fila *f);

/**
 *  \brief esvazia a fila e liberta-a da memoria
 *  \param f_ref endereco do apontador para a fila em causa
 *	\remark o apontador para a fila em causa deve ficar a apontar para NULL
 */
void fila_apaga(fila **f_ref);

#define FILA_H
#endif
