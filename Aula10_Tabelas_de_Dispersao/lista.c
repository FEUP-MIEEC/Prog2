/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/

#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

lista *lista_nova() {
    lista *lst;

    lst = (lista *) malloc(sizeof(lista));
    if (lst == NULL)
        return NULL;

    lst->tamanho = 0;

    return lst;
}

void lista_apaga(lista *lst) {
    if (lst == NULL)
        return;
    if (lista_tamanho(lst) == 0) {
        free(lst);
        return;
    }
    elemento *toFree = lst->inicio;
    if (toFree != NULL) {
        elemento *ptnext = toFree->proximo;
        while (ptnext != NULL) {
            ptnext = toFree->proximo;
            free(toFree->str);
            free(toFree);
            toFree = ptnext;
        }
    }
    free(lst);
    return;
}

int lista_tamanho(lista *lst) {
    if (lst == NULL)
        return -1;
    return lst->tamanho;
}

elemento *lista_inicio(lista *lst) {
    if (lst == NULL)
        return NULL;
    return lst->inicio;
}

elemento *lista_fim(lista *lst) {
    if (lst == NULL)
        return NULL;
    return lst->fim;
}

elemento *lista_insere(lista *lst, const char *valor, elemento *pos) {
    if (lst == NULL) {
        return NULL;
    }

    // A lista não está vazia. Vamos continuar.
    elemento *e = malloc(sizeof(elemento)); // Criação do elemento
    e->str = (char *) malloc(sizeof(char) * (strlen(valor) + 1));
    strcpy(e->str, valor); //Alocação da memória para a string e cópia desta.
    // Podemos querer inserir no fim da lista, no meio da lista, no fim da lista, ou ainda numa lista vazia.
    // Vamos averiguar cada situação:
    if (lst->tamanho == 0) {
        // Estamos a inserir um elemento numa lista vazia. Tomemos cuidado com as especificidades desta situação.
        e->anterior = NULL;
        e->proximo = NULL;
        lst->inicio = e;
        lst->fim = e;
    }
    else // Este Else é seguro pois sabemos que se a lista não estiver vazia, então vamos certamente inserir no início/meio/fim.
    {
        if (pos == NULL) {
            //Vamos inserir no fim, então. Ora vejamos:
            //printf("Inserção do valor \"%s\" no final da lista\n", valor);
            e->proximo = NULL;
            e->anterior = lst->fim;
            lst->fim->proximo = e;
            lst->fim = e;
        } else {
            //Isto ocorre se POS for diferente de NULL, i.e., ser 0 ou pertencer a N.
            if (pos == lst->inicio) {
                //Vamos inserir no início:
                //printf("Inserção do valor \"%s\" no inicio da lista\n", valor);
                e->anterior = NULL;
                e->proximo = lst->inicio;
                lst->inicio = e;
				lst->inicio->anterior = e; // FALTOU
            } else {
                //Parece que vamos inserir a meio:
                //printf("Inserção do valor \"%s\" a meio da lista\n", valor);

                pos->anterior->proximo = e;
                e->anterior = pos->anterior;
                e->proximo = pos;
                pos->anterior = e;

            }
        }
    }
    lst->tamanho++; // E devemos incrementar o tamanho da lista
    return e;
}

elemento *lista_remove(lista *lst, elemento *pos) {
    if (pos == NULL)
        return NULL;
    elemento *e = pos->proximo;
    if (pos == lst->inicio) {
        pos->proximo->anterior = NULL;
        lst->inicio = pos->proximo;
    }
    else if (pos == lst->fim) {
        pos->anterior->proximo = NULL; // POS proximo ´e null se for unico
        lst->fim = pos->anterior;
    }
    else {
        pos->anterior->proximo = pos->proximo;
        pos->proximo->anterior = pos->anterior;
    }
    free(pos->str);
    free(pos);
    lst->tamanho--;
    return e;
}

elemento *lista_pesquisa(lista *lst, const char *str, int origem) {
    elemento *e;
    int i;
	if (lst == NULL) return NULL; // FALTOU
    if (origem == 0) {
        e = lst->inicio;
        for (i = 0; i < lst->tamanho; i++) {
            if (strcmp(e->str, str) == 0)
                return e;
            e = e->proximo;
        }
    }
    else if (origem == 1) {
        e = lst->fim;
        for (i = 0; i < lst->tamanho; i++) {
            if (strcmp(e->str, str) == 0)
                return e;
            e = e->anterior;
        }
    }
    return NULL;
}

int lista_ordena(lista *lst) {
    if (lst == NULL)
        return -1;
    if (lst->tamanho == 0)return 0;
    char *t;
    elemento *e = lst->inicio;
    elemento *t1;
    while (e != lst->fim) {
        t1 = e;
        while (strcmp(e->str, e->proximo->str) > 0) {
            t = e->str;
            e->str = e->proximo->str;
            e->proximo->str = t;
            if (e != lst->inicio)
                e = e->anterior;
        }
        e = t1->proximo;
    }
    return 0;
}

int lista_inverte(lista *lst) {
    if (lst == NULL) return -1;
	if (lst->tamanho == 0) return 0;
    int i;
    char *tmp;
    elemento *s = lst->inicio;
    elemento *f = lst->fim;
    for (i = 0; i < lst->tamanho / 2; i++) {
        tmp = strdup(s->str);
        s->str = strdup(f->str);
        f->str = strdup(tmp);
        s = s->proximo;
        f = f->anterior;
    }
    return 0;
}