/*****************************************************************/
/*   Arvore Binaria de Pesquisa (BST) | PROG2 | MIEEC | 2015/16  */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* declaracao das funcoes utilitarias */
no_bst *bst_pesquisa_impl(no_bst *no, const char *str);

no_bst *bst_insere_impl(no_bst *no, const char *str);

no_bst *bst_remove_impl(no_bst *no, const char *str);

no_bst *bst_no_valormin(no_bst *no);

no_bst *bst_no_valormax(no_bst *no);

int bst_altura(no_bst *no);

void bst_preordem_impl(no_bst *no);

arvore_bst *bst_nova() {
    arvore_bst *bst = (arvore_bst *) malloc(sizeof(arvore_bst));
    if (bst == NULL)
        return NULL;

    bst->raiz = NULL; /* arvore vazia */

    return bst;
}

void bst_apaga(arvore_bst *bst) {
    while (bst->raiz != NULL) {
        bst->raiz = bst_remove_impl(bst->raiz, bst->raiz->str);
    }

    free(bst);
}

no_bst *bst_pesquisa(arvore_bst *bst, const char *str) {
    if (bst == NULL || str == NULL)
        return NULL;

    return bst_pesquisa_impl(bst->raiz, str);
}

int bst_insere(arvore_bst *bst, const char *str) {
    if (bst == NULL || str == NULL)
        return -1;

    bst->raiz = bst_insere_impl(bst->raiz, str);

    return 0;
}

int bst_remove(arvore_bst *bst, const char *str) {
    if (bst == NULL || str == NULL)
        return -1;

    bst->raiz = bst_remove_impl(bst->raiz, str);

    return 0;
}

const char *bst_min(arvore_bst *bst) {
    if (bst == NULL)
        return NULL;

    return bst_no_valormin(bst->raiz)->str;
}

const char *bst_max(arvore_bst *bst) {
    if (bst == NULL)
        return NULL;

    return bst_no_valormax(bst->raiz)->str;
}

void bst_imprime(arvore_bst *bst) {
    if (bst == NULL)
        return;

    bst_preordem_impl(bst->raiz);

    printf("\n");
}


/*************************************************/
/* funcoes utilitarias                           */
/*************************************************/

/*  cria um novo no dada uma string */
no_bst *bst_novo_no(const char *str) {
    no_bst *no = (no_bst *) malloc(sizeof(no_bst));
    no->str = (char *) malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(no->str, str);
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

/* dada uma arvore binaria de pesquisa, retorna o no' com o valor minimo
   que se pode encontrar nessa arvore */
no_bst *bst_no_valormin(no_bst *no) {
    no_bst *curr = no;

    /* percorre a arvore para encontrar o filho mais 'a esquerda */
    while (curr->esquerda != NULL)
        curr = curr->esquerda;

    return curr;
}

/* dada uma arvore binaria de pesquisa, retorna o no' com o valor maximo
   que se pode encontrar nessa arvore */
no_bst *bst_no_valormax(no_bst *no) {
    no_bst *curr = no;

    /* percorre a arvore para encontrar o filho mais 'a direita */
    while (curr->direita != NULL)
        curr = curr->direita;

    return curr;
}

no_bst *bst_pesquisa_impl(no_bst *no, const char *str) {
    if (no == NULL)
        return NULL;

    if (strcmp(str, no->str) < 0)
        return bst_pesquisa_impl(no->esquerda, str);

    else if (strcmp(str, no->str) > 0)
        return bst_pesquisa_impl(no->direita, str);

    else
        return no;
}


no_bst *bst_insere_impl(no_bst *no, const char *str) {
    if (no == NULL)
        return bst_novo_no(str);

    /* se a str a ser inserida é menor do que a str da raiz,
       entao devera ser inserida na sub-arvore esquerda */
    if (strcmp(str, no->str) < 0)
        no->esquerda = bst_insere_impl(no->esquerda, str);

        /* se a str a ser inserida é maior do que a str da raiz,
           entao devera ser inserida na sub-arvore direita */
    else if (strcmp(str, no->str) > 0)
        no->direita = bst_insere_impl(no->direita, str);

    return no;
}

no_bst *bst_remove_impl(no_bst *no, const char *str) {
    if (no == NULL)
        return no;

    /* se a str a ser removida é menor do que a str da raiz,
       entao esta' na sub-arvore esquerda */
    if (strcmp(str, no->str) < 0)
        no->esquerda = bst_remove_impl(no->esquerda, str);

        /* se a str a ser removida é maior do que a str da raiz,
           entao esta' na sub-arvore direita */
    else if (strcmp(str, no->str) > 0)
        no->direita = bst_remove_impl(no->direita, str);

        /* se a str a ser removida é igual a str da raiz,
           entao e' este no a remover */
    else {
        /* no' com apenas um filho ou sem filhos */
        if ((no->esquerda == NULL) || (no->direita == NULL)) {
            no_bst *temp = no->esquerda ? no->esquerda : no->direita;

            /* caso sem filhos */
            if (temp == NULL) {
                temp = no;
                no = NULL;
            }
            else /* caso de um filho */
            {
                /* copia os conteudos do filho que não está vazio */
                no->str = realloc(no->str, (strlen(temp->str) + 1) * sizeof(char));
                strcpy(no->str, temp->str);
                no->esquerda = temp->esquerda;
                no->direita = temp->direita;
            }

            free(temp->str);
            free(temp);
        }
        else {
            /* no' com dois filhos: obtem sucessor em-ordem (menor da arvore direita) */
            no_bst *temp = bst_no_valormin(no->direita);

            /* copia o valor em.ordem do sucessor para este no' */
            no->str = realloc(no->str, (strlen(temp->str) + 1) * sizeof(char));
            strcpy(no->str, temp->str);

            /* apaga o sucessor em-ordem */
            no->direita = bst_remove_impl(no->direita, temp->str);
        }
    }

    return no;
}

int bst_altura (no_bst* no)
{
    /* a implementar na alinea 1.b) */
    int r = 0, l = 0;
    if(no == NULL)
        return -1;
    else
    {
        printf("teste");
        r += bst_altura(no->direita);
        l += bst_altura(no->esquerda);

        if(r > l)
            return (r + 1);
        else
            return (l + 1);
    }
}

void bst_preordem_impl(no_bst *no) {
    /* a implementar na alinea 1.c) */
    return;
}