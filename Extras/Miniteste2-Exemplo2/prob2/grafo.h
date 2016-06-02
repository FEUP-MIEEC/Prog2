/*****************************************************************/
/*   Grafo c/ lista de adjacencias | PROG2 | MIEEC | 2014/15     */      
/*****************************************************************/

#ifndef _GRAFO_H_
#define _GRAFO_H_
 
typedef enum {NAODIRECIONADO=0,DIGRAFO} tipo_grafo;
 
/* no da lista de adjacencias */
typedef struct _lista_no
{
    int vertice;                /* indice do array de listas de adjacencias */
    struct _lista_no *proximo;  /* apontador para proximo no' */
} lista_no;
 
/* lista de adjacencias */
typedef struct
{
    int tamanho;           /* numero de nos na lista */
    lista_no *inicio;      /* apontador para primeiro no' da lista */
} lista_adj;
 
/* grafo e' um array de listas de adjacencias.
   tamanho do array e' o numero de vertices no grafo */
typedef struct
{
    tipo_grafo tipo;        /* digrafo ou nao direcionado */
    int tamanho;            /* numero de vertices */
    lista_adj *adjacencias; /* array de listas de adjacencias */
} grafo;

/* cria grafo com n vertices */
grafo* grafo_novo(int n, tipo_grafo tipo);

/* apaga grafo e liberta memoria */
void grafo_apaga(grafo* g);

/* adiciona uma aresta ao grafo*/
void grafo_adiciona(grafo *g, int origem, int dest);

/* remove uma aresta do grafo*/
void grafo_remove(grafo *g, int origem, int dest);

/* verifica se existe uma aresta entre os vertices origem e dest */
int grafo_existe(grafo *g, int origem, int dest);

/* imprime as listas de adjacencias do grafo */
void grafo_imprime(grafo* g);

/* retorna caminho entre origem e dest usando depth-first search (DFS)
   n guarda o tamanho do caminho
   _nao garante_ caminho mais curto */
int* grafo_dfs(grafo *g, int inicio, int fim, int *n);

/* retorna caminho entre origem e dest usando breadth-first search (BFS)
   n guarda o tamanho do caminho
   _garante_ caminho mais curto */
int* grafo_bfs(grafo *g, int inicio, int fim, int *n);

 
#endif