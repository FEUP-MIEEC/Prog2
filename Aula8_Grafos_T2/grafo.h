/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/

#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <stdio.h>
#include "vetor.h"
 
/* elemento da lista de adjacencias */
typedef struct _lista_elem
{
    int vertice;                /* indice do array de listas de adjacencias */
    struct _lista_elem *proximo;  /* apontador para proximo elemento */
} lista_elem;
 
/* lista de adjacencias */
typedef struct
{
    int tamanho;           /* numero de elementos na lista */
    lista_elem *inicio;      /* apontador para primeiro no' da lista */
} lista_adj;
 
/* grafo e' um array de listas de adjacencias.
   tamanho do array e' o numero de vertices no grafo */
typedef struct
{
    int tamanho;            /* numero de vertices do grafo*/
    lista_adj *adjacencias; /* array de listas de adjacencias */
} grafo;

/* cria grafo com n vertices */
grafo* grafo_novo (int n);

/* apaga grafo e liberta memoria */
void grafo_apaga(grafo* g);

/* verifica se existe uma aresta entre os vertices origem e destino */
int grafo_aresta(grafo *g, int origem, int destino);

/* adiciona uma aresta ao grafo*/
int grafo_adiciona(grafo *g, int origem, int destino);


/* remove uma aresta do grafo*/
int grafo_remove(grafo *g, int origem, int destino);



vetor* v_sucessores(grafo* g, int vertice);
vetor* v_antecessores(grafo* g, int vertice);
int v_grau(grafo* g, int vertice);
int v_celebridade(grafo* g, int vertice);

 
#endif
