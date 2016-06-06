/*****************************************************************/
/*   Arvore AVL | PROG2 | MIEEC | 2013/14                        */      
/*****************************************************************/

#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct no_avl_
{
	char *str;
	struct no_avl_ *esquerda;
	struct no_avl_ *direita;
	int altura;
} no_avl;

typedef struct
{
	no_avl *raiz;
} arvore_avl;


arvore_avl* avl_nova();
void avl_apaga(arvore_avl* avl);
no_avl* avl_pesquisa(arvore_avl* avl, const char *str);
int avl_insere(arvore_avl* avl, const char *str);
int avl_remove(arvore_avl* avl, const char *str);
const char *avl_min(arvore_avl* avl);
const char *avl_max(arvore_avl* avl);
void avl_imprime(arvore_avl* avl);


#endif  /* ARVOREAVL_H */