/*****************************************************************/
/*   Arvore Binaria de Pesquisa (BST) | PROG2 | MIEEC | 2015/16  */
/*****************************************************************/

#ifndef _ARVOREBST_H
#define _ARVOREBST_H

/**
 * registo para armazenar cada no'
 */
typedef struct no_bst_
{
        char *str;
        struct no_bst_ *esquerda;
        struct no_bst_ *direita;
} no_bst;

/**
 * arvore_bst contem apenas um apontador para a raiz
 */
typedef struct
{
        no_bst *raiz;
} arvore_bst;

/**
 *  cria uma nova arvore BST vazia
 *  retorno: apontador para a arvore criada
 *  nota: se arvore nao foi criada retorna NULL
 */
arvore_bst* bst_nova();

/**
 *  elimina uma arvore, libertando toda a memoria ocupada
 *  parametro: bst apontador para arvore
 *  nota: se bst = NULL retorna sem fazer nada
 */
void bst_apaga(arvore_bst* bst);

/**
 *  devolve o no' que contem a string especificada
 *  parametro: bst apontador para arvore
 *  parametro: str string pretendida
 *  retorno: elemento pretendido ou NULL se ocorrer algum erro ou nao encontrar elemento
 */
no_bst* bst_pesquisa(arvore_bst* bst, const char *str);

/**
 *  insere um novo no' com a string especificada
 *  parametro: bst apontador para arvore
 *  parametro: str string a inserir
 *  retorno: -1 se ocorrer algum erro ou 0 se bem sucedido
 */
int bst_insere(arvore_bst* bst, const char *str);

/**
 *  remove o no' com a string especificada
 *  parametro: bst apontador para arvore
 *  parametro: str string a remover
 *  retorno: -1 se ocorrer algum erro ou 0 caso contrario
 */
int bst_remove(arvore_bst* bst, const char *str);

/**
 *  devolve a string com valor mais baixo (alfabeticamente) possivel de encontrar na arvore
 *  parametro: bst apontador para arvore
 *  retorno: NULL se ocorrer algum erro ou a string pretendida caso contrario
 */
const char *bst_min(arvore_bst* bst);

/**
 *  devolve a string com valor mais alto (alfabeticamente) possivel de encontrar na arvore
 *  parametro: bst apontador para arvore
 *  retorno: NULL se ocorrer algum erro ou a string pretendida caso contrario
 */
const char *bst_max(arvore_bst* bst);

/**
 *  devolve a string da (sub-)arvore com origem no no' especificado
 *  parametro: no raiz da (sub-)arvore
 *  retorno: -1 se no' nao existe ou a altura do no' caso contrario
 */
int bst_altura (no_bst* no);

/**
 *  percorre a arvore em pre-ordem e imprime as strings de cada no'
 *  parametro: bst apontador para arvore
 */
void bst_imprime(arvore_bst* bst);

#endif  /* _ARVOREBST_H */
