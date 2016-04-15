/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define INICIA_TESTE() \
	int erros = 0;

#define ERRO(msg) \
	{ \
	printf("\n\t"#msg); \
		erros++; \
	}

#define FINALIZA_TESTE() \
	if (!erros) \
		printf("OK\n"); \
	else \
		printf("\n"); \
	return erros;

grafo* _g(int m, int n, ...)
{
	va_list argp; grafo *g;
	int i;

	g = (grafo *) malloc(sizeof(grafo));
	va_start(argp, n);
	g->adjacencias = (lista_adj*)calloc(m, sizeof(lista_adj));
	for(i=0; i<n; i+=2)
	{
		int x = va_arg(argp, int);
		int y = va_arg(argp, int);
	    lista_elem* n = (lista_elem*)calloc(1, sizeof(lista_elem));
	    n->vertice = y;
		n->proximo = g->adjacencias[x].inicio;
		g->adjacencias[x].inicio = n;
		g->adjacencias[x].tamanho++;
	}
	va_end(argp);
	g->tamanho = m;
	return g;
}

int _f(vetor* v, int p)
{
	int i;
    if(v==NULL) return 0;
    for(i=0; i<v->tamanho; i++)
    	if(vetor_elemento(v,i)==p) return 1;
    return 0;
}

int teste_grafo_novo()
{
	INICIA_TESTE()

	grafo *g;

	printf("grafo_novo(): ");

	g = grafo_novo(10);
	if(!g)
	{
		ERRO("novo grafo invalido")
		FINALIZA_TESTE();
	}
	if(g->tamanho != 10)
		ERRO("tamanho do grafo deveria ser 10")

	grafo_apaga(g);

	g = grafo_novo(1);
	if(!g)
	{
		ERRO("novo grafo invalido")
		FINALIZA_TESTE();
	}
	if(g->tamanho != 1)
		ERRO("tamanho do grafo deveria ser 1")

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_grafo_aresta()
{
	INICIA_TESTE()

	grafo *g=_g(8,22,3,2,7,2,0,2,7,5,5,4,4,0,4,6,1,1,7,6,6,3,0,1);

	printf("grafo_aresta(): ");

	if(grafo_aresta(g,5,4) != 1)
		ERRO("pesquisa de uma aresta existente deveria retornar 1")

	if(grafo_aresta(g,7,6) != 1)
		ERRO("pesquisa de uma aresta existente deveria retornar 1")

	if(grafo_aresta(g,7,1) != 0)
		ERRO("pesquisa de uma aresta nao existente deveria retornar 0")

	if(grafo_aresta(NULL,2,7) != -1)
		ERRO("retorno deveria ser -1 ao pesquisar em grafo NULL")

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_grafo_adiciona()
{
	INICIA_TESTE()

	grafo *g=_g(9,4,3,2,7,2);

	printf("grafo_adiciona(): ");

	if(grafo_adiciona(g,2,7) != 1)
		ERRO("retorno deveria ser 1 ao adicionar aresta inexistente")

	if(g->adjacencias[2].inicio==NULL || g->adjacencias[2].inicio->vertice!=7)
		ERRO("aresta nao existente depois de adicionada")

	if(grafo_adiciona(g,3,8) != 1)
		ERRO("retorno deveria ser 1 ao adicionar aresta inexistente")

	if(g->adjacencias[3].inicio==NULL || g->adjacencias[3].inicio->proximo==NULL || g->adjacencias[3].inicio->proximo->proximo!=NULL \
			|| ((g->adjacencias[3].inicio->vertice!=2 || g->adjacencias[3].inicio->proximo->vertice!=8) && (g->adjacencias[3].inicio->vertice!=8 || g->adjacencias[3].inicio->proximo->vertice!=2)))
		ERRO("arestas inconsistentes depois de adicionada uma aresta")

	if(grafo_adiciona(g,2,7) != 0)
		ERRO("retorno deveria ser 0 ao adicionar aresta existente")

	if(grafo_adiciona(g,22,7) != -1)
		ERRO("retorno deveria ser -1 com vertice origem invalido")

	if(grafo_adiciona(NULL,2,7) != -1)
		ERRO("retorno deveria ser -1 ao adicionar a grafo NULL")

	grafo_apaga(g);

	FINALIZA_TESTE()
}


int teste_grafo_remove()
{
	INICIA_TESTE()

	grafo *g=_g(9,6,3,2,7,2,7,1);

	printf("grafo_remove(): ");

	if(grafo_remove(g,7,1) != 1)
		ERRO("retorno deveria ser 1 ao remover uma aresta existente")

	if(g->adjacencias[7].inicio==NULL || g->adjacencias[7].inicio->proximo!=NULL || g->adjacencias[7].inicio->vertice!=2)
		ERRO("arestas inconsistentes depois de removida uma aresta")

	if(grafo_remove(g,7,2) != 1)
		ERRO("retorno deveria ser 1 ao remover uma aresta existente")

	if(g->adjacencias[7].inicio!=NULL)
		ERRO("arestas inconsistentes depois de removida uma aresta")

	if(grafo_remove(g,4,0) != 0)
		ERRO("retorno deveria ser 0 ao remover uma aresta inexistente")

	if(grafo_remove(g,7,22) != -1)
		ERRO("retorno deveria ser -1 com vertice destino invalido")

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_v_sucessores()
{
	INICIA_TESTE()

	grafo *g=_g(8,22,3,2,7,2,0,2,7,5,5,4,4,0,4,6,1,1,7,6,6,3,0,1);

	printf("v_sucessores(): ");

	vetor *v;

	if(!(v=v_sucessores(g,7)))
		ERRO("vetor de sucessores nao deveria ser NULL")

	if(!v)
	{
		FINALIZA_TESTE()
	}

	if(v->tamanho!=3)
		ERRO("vetor de sucessores tem tamanho errado")

	if(!_f(v,2)||!_f(v,5)||!_f(v,6))
		ERRO("vetor de sucessores tem conteudo errado")

	vetor_apaga(v);

	if(!(v=v_sucessores(g,2)))
		ERRO("vetor de sucessores nao deveria ser NULL, mesmo que vazio")

	if(!v)
	{
		FINALIZA_TESTE()
	}

	if(v->tamanho!=0)
		ERRO("vetor de sucessores deveria ter tamanho 0")

	vetor_apaga(v);

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_v_antecessores()
{
	INICIA_TESTE()

	grafo *g=_g(8,22,3,2,7,2,0,2,7,5,5,4,4,0,4,6,1,1,7,6,6,3,0,1);

	printf("v_antecessores(): ");

	vetor *v;

	if(!(v=v_antecessores(g,2)))
		ERRO("vetor de antecessores nao deveria ser NULL")

	if(!v)
	{
		FINALIZA_TESTE()
	}

	if(v->tamanho!=3)
		ERRO("vetor de antecessores tem tamanho errado")

	if(!_f(v,0)||!_f(v,3)||!_f(v,7))
		ERRO("vetor de antecessores tem conteudo errado")

	vetor_apaga(v);

	if(!(v=v_antecessores(g,7)))
		ERRO("vetor de antecessores nao deveria ser NULL, mesmo que vazio")

	if(!v)
	{
		FINALIZA_TESTE()
	}

	if(v->tamanho!=0)
		ERRO("vetor de antecessores deveria ter tamanho 0")

	vetor_apaga(v);

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_v_grau()
{
	INICIA_TESTE()

	grafo *g=_g(8,22,3,2,7,2,0,2,7,5,5,4,4,0,4,6,1,1,7,6,6,3,0,1);

	printf("v_grau(): ");

	if(v_grau(g,-4) != -1)
		ERRO("retorno deveria ser -1 com vertice negativo")

	if(v_grau(g,7) != 3)
		ERRO("retorno errado ao testar vertice de grau 3")

	if(v_grau(g,5) != 2)
		ERRO("retorno errado ao testar vertice de grau 2")

	grafo_apaga(g);

	FINALIZA_TESTE()
}

int teste_v_celebridade()
{
	INICIA_TESTE()

	grafo *g=_g(8,30,3,2,7,2,0,2,7,5,5,4,4,0,4,6,1,1,7,6,6,3,0,1,1,2,6,2,4,2,5,2);

	printf("v_celebridade(): ");

	if(v_celebridade(g,7) != 0)
		ERRO("retorno deveria ser 0 ao testar com nao celebridade")

	if(v_celebridade(g,2) != 1)
		ERRO("retorno deveria ser 1 ao testar com celebridade")

	grafo_apaga(g);

	FINALIZA_TESTE()
}


int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	int erros = 0;
	erros += teste_grafo_novo();
	erros += teste_grafo_aresta();
	erros += teste_grafo_adiciona();
	erros += teste_grafo_remove();
	erros += teste_v_sucessores();
	erros += teste_v_antecessores();
	erros += teste_v_grau();
	erros += teste_v_celebridade();

	if (!erros)
		printf("FIM DE TODOS OS TESTES.\n");
	else
		printf("FOI ENCONTRADO UM TOTAL DE %d ERROS.\n", erros);
	return 0;
}
