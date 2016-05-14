/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/* cria elemento da lista de adjacencias */
lista_elem *cria_elem(int v) {
    lista_elem *novo = (lista_elem *) malloc(sizeof(lista_elem));
    if (!novo)
        return NULL;
    novo->vertice = v;
    novo->proximo = NULL;
    return novo;
}

/* cria um novo grafo com n vertices */
grafo *grafo_novo(int n) {
    if (n < 1) {
        return NULL;
    }
    int i;
    grafo *g = malloc(sizeof(grafo));
    g->tamanho = n;
    g->adjacencias = malloc(sizeof(lista_adj) * n);
    for (i = 0; i < n; i++) {
        g->adjacencias[i].tamanho = 0;
        g->adjacencias[i].inicio = NULL;
    }

    return g;
}

/* elimina um grafo, libertando toda a memoria ocupada */
void grafo_apaga(grafo *g) {
    if (g == NULL) return;
    int i;
    for (i = 0; i < g->tamanho; i++) {
        lista_elem *aux = g->adjacencias[i].inicio;
        lista_elem *aux2;
        while (aux != NULL) {
            aux2 = aux;
            aux = aux->proximo;
            free(aux2);
        }
    }
    free(g->adjacencias);
    free(g);
    return;
}

/* verifica se existe uma aresta entre os vertices origem e destino */
int grafo_aresta(grafo *g, int origem, int destino) {
    if (g == NULL || origem > g->tamanho)
        return -1;
    if (destino > g->tamanho)
        return 0;
    lista_elem *aux = g->adjacencias[origem].inicio;
    while (aux != NULL) {
        if (aux->vertice == destino)
            return 1;
        aux = aux->proximo;
    }
    return 0;
}

/* adiciona ao grafo g uma aresta entre os vertices origem e destino */
int grafo_adiciona(grafo *g, int origem, int destino) {
    if (g == NULL || origem > g->tamanho || destino > g->tamanho) {
        return -1;
    }
    if (grafo_aresta(g, origem, destino) == 1) {
        return 0;
    }
    lista_elem *aux = g->adjacencias[origem].inicio;
    g->adjacencias[origem].inicio = cria_elem(destino);
    g->adjacencias[origem].inicio->proximo = aux;
    g->adjacencias->tamanho++;
    return 1;
}

/* remove uma aresta do grafo*/
int grafo_remove(grafo *g, int origem, int destino) {
    if (g != NULL && origem <= g->tamanho && destino <= g->tamanho) {
        if (g->adjacencias[origem].inicio == NULL)
            return 0;
        if (g->adjacencias[origem].inicio->vertice == destino) {
            lista_elem *aux = g->adjacencias[origem].inicio;
            g->adjacencias[origem].inicio = g->adjacencias[origem].inicio->proximo;
            g->adjacencias->tamanho--;
            free(aux);
            return 1;
        }
        lista_elem *l, *a = NULL;
        for (l = g->adjacencias[origem].inicio; l != NULL; l = l->proximo) {
            if (l->vertice == destino && a != NULL) {
                a->proximo = l->proximo;
                g->adjacencias->tamanho--;
                free(l);
                return 1;
            }
            a = l;
        }
        return 0;
    }
    return -1;
}

/* cria e retorna um vetor de inteiros contendo todos os sucessores de um vertice */
vetor *v_sucessores(grafo *g, int vertice) {
    if (g != NULL && vertice < g->tamanho && vertice >= 0) {
        int i = 0;
        vetor *v = vetor_novo();
        lista_elem *l;
        for (l = g->adjacencias[vertice].inicio; l != NULL; l = l->proximo) {
            vetor_insere(v, l->vertice, i);
            i++;
        }
        return v;
    }
    return NULL;
}

/* cria e retorna um vetor de inteiros contendo todos os antecessores de um vertice */
vetor *v_antecessores(grafo *g, int vertice) {
    if (g != NULL && vertice < g->tamanho && vertice >= 0) {
        vetor *v = vetor_novo();
        int i, j = 0;
        for (i = 0; i < g->tamanho; i++) {
            lista_elem *l;
            for (l = g->adjacencias[i].inicio; l != NULL; l = l->proximo) {
                if (l->vertice == vertice) {
                    vetor_insere(v, i, j);
                    j++;
                    break;
                }
            }
        }
        return v;
    }
    return NULL;
}

/* calcula o grau de um vertice */
int v_grau(grafo *g, int vertice) {
    if (vertice < 0) return -1;
    vetor *a = v_antecessores(g, vertice);
    vetor *b = v_sucessores(g, vertice);
    int r = vetor_tamanho(a) + vetor_tamanho(b);
    vetor_apaga(a);
    vetor_apaga(b);
    return r;
}

/* testa se um vertice e' uma celebridade */
int v_celebridade(grafo *g, int vertice) {
    if (g == NULL) return -1;
    if (g->adjacencias[vertice].tamanho != 0) return 0;

    int i, j = 0;
    for (i = 0; i < g->tamanho; i++) {
        lista_elem *l;
        for (l = g->adjacencias[i].inicio; l != NULL; l = l->proximo) {
            if (l->vertice == vertice) {
                j++;
                break;
            }
        }
    }
    if (j + 1 == g->tamanho) return 1;
    else return 0;

    /* Sugiu esta abordagem também mas mostrou-se mais lenta que a implementada
    if (vetor_tamanho(v_antecessores(g, vertice)) == g->tamanho - 1 && vetor_tamanho(v_sucessores(g, vertice)) == 0) {
        return 1;
    }*/
}