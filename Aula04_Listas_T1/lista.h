/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#ifndef LISTA_H

/** 
* registo para armazenar elementos da lista duplamente ligada
* este registo contem uma string e apontadores para o proximo e 
* anterior elementos da lista
*/
typedef struct _elemento {
    /* string armazenada */
    char *str;
    /* apontadores para elementos vizinhos */
    struct _elemento *proximo;
    struct _elemento *anterior;
} elemento;

typedef struct {
    elemento *inicio;
    elemento *fim;
    int tamanho;
} lista;

#define INICIO 0
#define FIM 1

/**
 *  cria uma nova lista ligada vazia
 *  retorno: apontador para a lista
 *  observacao: se a lista não foi criada retorna NULL 
 */
lista *lista_nova();

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
 *  devolve o apontador para o primeiro elemento da lista
 *  parametro: lst apontador para a lista
 *  retorno: apontador para o primeiro elemento da lista ou NULL se lista = NULL
 */
elemento *lista_inicio(lista *lst);

/**
 *  devolve o apontador para o ultimo elemento da lista
 *  parametro: lst apontador para a lista
 *  retorno: apontador para o ultimo elemento da lista ou NULL se lista = NULL
 */
elemento *lista_fim(lista *lst);

/**
 *  insere um elemento na posicao especificada
 *  parametro: lst apontador para a lista
 *  parametro: valor string a inserir
 *  parametro: pos posicao da lista onde se pretende inserir o novo elemento, 
 *             se pos=NULL insere no fim da lista
 *  retorno: apontador para novo elemento inserido na lista ou NULL se ocorrer um erro
 */
elemento *lista_insere(lista *lst, const char *valor, elemento *pos);

/**
 *  remove o elemento especificado
 *  parametro: lst apontador para a lista
 *  parametro: pos elemento que se pretende remover
 *  retorno: apontador para proximo elemento ao que foi removido ou NULL se ocorrer um erro
 */
elemento *lista_remove(lista *lst, elemento *pos);

/**
 *  devolve a posicao do primeiro elemento da lista com a string especificada
 *  parametro: lst apontador para a lista
 *  parametro: str string a pesquisar
 *  parametro: origem origem da pesquisa: a partir do início (INICIO) ou a partir do fim (FIM)
 *  retorno: elemento ou NULL se nao encontrar elemento ou ocorrer um erro
 */
elemento *lista_pesquisa(lista *lst, const char *str, int origem);

/**
 *  ordena uma lista por ordem alfabetica
 *  parametro: lst apontador para a lista
 *  retorno: -1 se ocorrer um erro ou 0 se for bem sucedido
 */
int lista_ordena(lista *lst);

/**
 *  inverte a ordem dos elementos de uma lista
 *  parametro: lst apontador para a lista
 *  retorno: -1 se ocorrer um erro ou 0 se for bem sucedido
 */
int lista_inverte(lista *lst);


#define LISTA_H
#endif
