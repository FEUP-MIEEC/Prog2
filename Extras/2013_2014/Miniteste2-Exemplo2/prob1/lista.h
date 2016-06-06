/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2013/14          */      
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#ifndef LISTA_H

/**
* definicao de constantes
*/
#define FIM -1
#define INICIO 0

/** 
* registo para armazenar elementos da lista
* este registo contem uma string e um apontador para o proximo elemento da lista
*/
typedef struct _elemento
{
	/** string armazenada */
	char* str;
    struct _elemento *proximo;
} elemento_lista;

typedef struct
{
	elemento_lista *raiz;
	int tamanho;
} lista;

/**
 *  cria uma nova lista vazia
 *  retorno: apontador para a lista
 *  observacao: se a lista não foi criada retorna NULL 
 */
lista* lista_nova();

/** 
 *  elimina uma lista, libertando toda a memoria ocupada
 *  parametro: lst apontador para a lista
 *  observacao: se lista = NULL retorna sem fazer nada
 */
void lista_apaga(lista *lst);

/**
 *  indica o comprimento da lista
 *  parametro: lst apontador para a lista
 *  retorno: numero de elementos da lista ou -1 se lista = NULL
 */
int lista_tamanho(lista *lst);

/** 
 *  retorna a string armazenada na posicao especificada
 *  parametro: lst apontador para a lista
 *  parametro: pos posicao do elemento na lista
 *  retorno: apontador para a string na posicao correspondente
 *  observacao: se pos < 0 ou pos >= tamanho da lista, retorna NULL
 *  observacao: considera-se que o primeiro elemento da lista esta' na posicao 0, o segundo na posicao 1, etc.
 */
const char* lista_elemento(lista *lst, int pos);

/** 
 *  atribui o valor especificado a uma posicao 
 *  parametro: lst apontador para a lista
 *  parametro: pos posicao do elemento da lista a modificar
 *  parametro: str string pretendida
 *  retorno: -1 se pos < 0 ou pos >= tamanho da lista, e pos se bem sucedido 
 *  observacao: considera-se que o primeiro elemento da lista esta' na posicao 0, o segundo na posicao 1, etc.
 */
int lista_atribui(lista *lst, int pos, const char* str);

/**
 *  insere um elemento na posicao especificada
 *  parametro: lst apontador para a lista
 *  parametro: valor string a inserir
 *  parametro: pos posicao da lista onde se pretende inserir o novo elemento, se pos=-1 insere no fim da lista
 *  retorno: -1 se pos < 0 ou pos >= tamanho da lista, e pos se bem sucedido
 *  observacao: considera-se que o primeiro elemento da lista esta' na posicao 0, o segundo na posicao 1, etc.
 */
int lista_insere(lista *lst, const char* valor, int pos);

/**
 *  remove o elemento da posicao especificada
 *  parametro:  lst apontador para a lista
 *  parametro: pos posicao da lista de onde se pretende remover um elemento
 *  retorno: -1 se pos < 0 ou pos >= tamanho da lista, e 0 se bem sucedido
 *  observacao: considera-se que o primeiro elemento da lista esta' na posicao 0, o segundo na posicao 1, etc.
 */
int lista_remove(lista *lst, int pos);

/**
 *  devolve a posicao do primeiro elemento da lista com a string especificada
 *  parametro: lst apontador para a lista
 *  parametro: str string a pesquisar
 *  parametro: origem origem da pesquisa: a partir do início (INICIO) ou a partir do fim (FIM)
 *  retorno: posicao ou -1 se nao encontrar elemento ou ocorrer um erro
 *  retorno: -1 se pos < 0 ou pos >= tamanho da lista, e pos se bem sucedido
 */
int lista_pesquisa(lista *lst, const char* str, int origem);

/**
 *  ordena uma lista por ordem alfabetica
 *  parametro: lst apontador para a lista
 *  retorno: -1 se ocorrer um erro ou 0 se for bem sucedido
 */
int lista_ordena(lista *lst);

/**
 *  compara duas listas
 *  parametro: lst1 apontador para a primeira lista
 *  parametro: lst2 apontador para a segunda lista
 *  retorno: -1 se ocorrer um erro, 0 se lst1 for igual a lst2 e 1 caso contrário
 */
int lista_compara(lista *lst1, lista *lst2);

/**
 *  cria uma nova lista com a ordem dos elementos inverte
 *  parametro: lst apontador para a lista
 *  retorno: apontador a nova lista invertida 
 *  observacao: se ocorrer um erro, retorna NULL 
 */
lista* lista_inverte(lista *lst);

#define LISTA_H
#endif
