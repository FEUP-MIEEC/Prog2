/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"

/* cria elemento da lista de adjacencias */
lista_elem* cria_elem(int v)
{
    lista_elem* novo = (lista_elem*)malloc(sizeof(lista_elem));
    if(!novo)
        return NULL;
    novo->vertice = v;
    novo->proximo = NULL;
    return novo;
}
 
/* cria um novo grafo com n vertices */
grafo* grafo_novo(int n)
{
	return NULL;
}
 
/* elimina um grafo, libertando toda a memoria ocupada */
void grafo_apaga(grafo* g)
{
	return;
}
 
/* verifica se existe uma aresta entre os vertices origem e destino */
int grafo_aresta(grafo *g, int origem, int destino)
{
	return INT_MIN;
}

/* adiciona ao grafo g uma aresta entre os vertices origem e destino */
int grafo_adiciona(grafo *g, int origem, int destino)
{
	return INT_MIN;
}

/* remove uma aresta do grafo*/
int grafo_remove(grafo *g, int origem, int destino)
{
	return INT_MIN;
}

/* cria e retorna um vetor de inteiros contendo todos os sucessores de um vertice */
vetor* v_sucessores(grafo* g, int vertice)
{
	return NULL;
}

/* cria e retorna um vetor de inteiros contendo todos os antecessores de um vertice */
vetor* v_antecessores(grafo* g, int vertice)
{
	return NULL;
}

/* calcula o grau de um vertice */
int v_grau(grafo* g, int vertice)
{
	return INT_MIN;
}

/* testa se um vertice e' uma celebridade */
int v_celebridade(grafo* g, int vertice)
{
	return INT_MIN;
}


