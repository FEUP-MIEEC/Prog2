/*****************************************************************/
/*   Grafo c/ lista de adjacencias | PROG2 | MIEEC | 2015/16     */      
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/* cria no da lista de adjacencias */
lista_no* cria_no(int v)
{
    lista_no* novo = (lista_no*)malloc(sizeof(lista_no));
    if(!novo)
        return NULL;
 
    novo->vertice = v;
    novo->proximo = NULL;
 
    return novo;
}
 
/* cria grafo com n vertices */
grafo* grafo_novo(int n, tipo_grafo tipo)
{
    int i;
    grafo* g = (grafo*)malloc(sizeof(grafo));
    if(g == NULL)
        return NULL;

    g->tamanho = n;
    g->tipo = tipo;
 
    /* cria array de listas de adjacencias */
    g->adjacencias = (lista_adj*)calloc(n, sizeof(lista_adj));
    if(g->adjacencias == NULL)
    {
        free(g);        
        return NULL;
    }
 
    return g;
}
 
/* apaga grafo e liberta memoria */
void grafo_apaga(grafo* g)
{
    if(g == NULL)
        return;

    if(g->adjacencias != NULL)
    {
        int v;
        for (v = 0; v < g->tamanho; v++)
        {
            while (g->adjacencias[v].inicio)
            {
                lista_no* aux = g->adjacencias[v].inicio;
                g->adjacencias[v].inicio = g->adjacencias[v].inicio->proximo;
                free(aux);
            }
        }
        free(g->adjacencias);
    }
    free(g);
}
 
/* adiciona uma aresta ao grafo*/
void grafo_adiciona(grafo *g, int origem, int dest)
{
    lista_no* novo;

    if (g == NULL || grafo_aresta(g, origem, dest))
        return;

    /* adiciona uma aresta de origem para dest na lista de adjacencias */
    novo = cria_no(dest);
    novo->proximo = g->adjacencias[origem].inicio;
    g->adjacencias[origem].inicio = novo;
    g->adjacencias[origem].tamanho++;
 
    if(g->tipo == NAODIRECIONADO)
    {
        /* adiciona tambem aresta de dest para origem */
        novo = cria_no(origem);
        novo->proximo = g->adjacencias[dest].inicio;
        g->adjacencias[dest].inicio = novo;
        g->adjacencias[dest].tamanho++;
    }
}

/* remove uma aresta do grafo*/
void grafo_remove(grafo *g, int origem, int dest)
{
    lista_no *aux, *prev;

    if (g == NULL || g->adjacencias[origem].inicio == NULL)
        return;

    aux = g->adjacencias[origem].inicio;
    /* caso especial: primeiro no' da lista */
    if(aux->vertice == dest)
    {
        g->adjacencias[origem].inicio = aux->proximo;
        free(aux);
    }
    else
    {
        prev = aux;
        aux = aux->proximo;
        while(aux != NULL)
        {
            if(aux->vertice == dest)
            {
                prev->proximo = aux->proximo;
                free(aux);
                break;         
            }
            prev = aux;
            aux = aux->proximo;
        }
    }

    if(g->tipo == NAODIRECIONADO)
    {
        /* remove tambem aresta de dest para origem */
        /* caso especial: primeiro no' da lista */
        aux = g->adjacencias[dest].inicio;
        if(aux->vertice == origem)
        {
            g->adjacencias[dest].inicio = aux->proximo;
            free(aux);
        }
        else
        {
            prev = aux;
            aux = aux->proximo;
            while(aux != NULL)
            {
                if(aux->vertice == origem)
                {
                    prev->proximo = aux->proximo;
                    free(aux);
                    break;         
                }
                prev = aux;
                aux = aux->proximo;
            }            
        }
    }

}

/* verifica se existe uma aresta entre os vertices origem e dest */
int grafo_aresta(grafo *g, int origem, int dest)
{
    if (g == NULL)
        return 0;

    lista_no* aux = g->adjacencias[origem].inicio;
    while (aux)
    {
        if(aux->vertice == dest)
            return 1;
        aux = aux->proximo;
    }
    return 0;
}
 
/* imprime as listas de adjacencias do grafo */
void grafo_imprime(grafo* g)
{
    int i;
    for (i = 0; i < g->tamanho; i++)
    {
        lista_no* aux = g->adjacencias[i].inicio;
        printf("%d: ", i);
        if(aux)
        {
            printf("%d", aux->vertice);
            aux = aux->proximo;

            while (aux)
            {
                printf("->%d", aux->vertice);
                aux = aux->proximo;
            }
        }   
        printf("\n");
    }
}

/* cria e retorna um vetor de inteiros contendo todos os sucessores directos de um vertice */
vetor* v_sucessores(grafo* g, int vertice)
{
	int k;
	vetor *v;
	if (g==NULL || vertice < 0 || vertice >= g->tamanho)
		return NULL;
	v = vetor_novo();
	for(k=0; k<g->tamanho; k++)
		if (grafo_aresta(g,vertice,k))
			vetor_insere(v,k,-1);
	return v;
}

/* cria e retorna um vetor de inteiros contendo todos os antecessores directos de um vertice */
vetor* v_antecessores(grafo* g, int vertice)
{
	int k;
	vetor *v;
	if (g==NULL || vertice < 0 || vertice >= g->tamanho)
		return NULL;
	v = vetor_novo();
	for(k=0; k<g->tamanho; k++)
		if (grafo_aresta(g,k,vertice))
			vetor_insere(v,k,-1);
	return v;
}

int dfs_helper(grafo *g, int inicio, int fim, int profundidade, int *visitados)
{
    int i, d;

    if(visitados[inicio])
        return 0;

    visitados[inicio] = profundidade;

    if(inicio == fim)
        return profundidade;

    for(i=0; i < g->tamanho; i++)
    {
        if(grafo_aresta(g, inicio, i))
        {
            d = dfs_helper(g, i, fim, profundidade + 1, visitados);
            if(d)
                return d;
        }
    }
    visitados[inicio] = 0;
    return 0;
}

/* retorna caminho entre origem e dest usando depth-first search (DFS)
   n guarda o tamanho do caminho
   nao garante caminho mais curto */
int* grafo_dfs(grafo *g, int inicio, int fim, int *n)
{
    int *visitados, *caminho;
    int profundidade, i, ret_i;

    if(g==NULL)
        return 0;

    visitados = calloc(g->tamanho, sizeof(int));
    profundidade = dfs_helper(g, inicio, fim, 1, visitados);

    if(profundidade == 0)
    {
        free(visitados);
        *n=0;
        return NULL;
    }

    /* reconstrucao do caminho */
    caminho = calloc(profundidade, sizeof(int));
    for (ret_i = 0; ret_i < profundidade; ret_i++)
        for (i = 0; i< g->tamanho; i++)
            if(visitados[i] == ret_i + 1)
            {
                caminho[ret_i] = i;
                break;
            }
    *n = profundidade;
    free(visitados);
    return caminho;
}


/* retorna caminho entre origem e dest usando breadth-first search (BFS)
   n guarda o tamanho do caminho
   garante caminho mais curto */
int* grafo_bfs(grafo *g, int inicio, int fim, int *n)
{
    int *caminho, *visitados, *fila;
    int profundidade, i, j, fila_inicio = 0, fila_fim=0;

    if(g==NULL)
        return 0;

    visitados = calloc(g->tamanho, sizeof(int));
    fila = calloc(g->tamanho, sizeof(int));

    for(i = 0; i < g->tamanho; i++)
        visitados[i] = -1;

    visitados[inicio] = inicio;
    fila[fila_fim++] = inicio;

    while(fila_inicio != fila_fim)
    {
        i = fila[fila_inicio];
        fila_inicio = (fila_inicio + 1) % g->tamanho;
        for(j = 0; j < g->tamanho; j++)
            if(grafo_aresta(g, i, j) && visitados[j] == -1)
            {
                visitados[j] = i;
                fila[fila_fim] = j;
                fila_fim = (fila_fim + 1) % g->tamanho;
            }
    }

    /* reconstrucao do caminho */
    profundidade = 0;
    if(visitados[fim] >= 0)
    {
        int tmp = fim;
        profundidade = 1;
        while(visitados[tmp] != tmp)
        {
            profundidade++;
            tmp = visitados[tmp];
        }

        caminho = malloc(profundidade  * sizeof(int));
        tmp = fim;
        i = 0;
        while(i++ < profundidade)
        {
            caminho[profundidade - i] = tmp;
            tmp = visitados[tmp];
        }
    }

    free(fila);
    free(visitados);

    *n=profundidade;
    return caminho;
}