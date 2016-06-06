/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


vetor* vetor_novo()
{
	vetor* vec;

	/* aloca memoria para a estrutura vetor */
	vec = (vetor*)malloc(sizeof(vetor));
	if(vec == NULL)
		return NULL;

	vec->tamanho = 0;
	vec->capacidade = 0;
	vec->elementos = NULL;

	return vec;
}

void vetor_apaga(vetor* vec)
{

	if(vec == NULL)
		return;


	/* liberta memoria do array de elementos */
	free(vec->elementos);

	/* liberta memoria da estrutura vetor */
	free(vec);
}

int vetor_atribui(vetor* vec, int pos, int val)
{

	if (vec == NULL || pos < 0 || pos >= vec->tamanho)
		return -1;

	/* copia valor */
	vec->elementos[pos].val = val;

	return pos;
}

int vetor_tamanho(vetor* vec)
{
	if(vec == NULL)
		return -1;

	return vec->tamanho;
}

int vetor_elemento(vetor* vec, int indice)
{
	if (vec == NULL || indice < 0 || indice >= vec->tamanho)
		return INT_MIN;

	return vec->elementos[indice].val;
}

int vetor_insere(vetor* vec, int valor, int pos)
{
	int i;

	if(vec == NULL || pos < -1 || pos > vec->tamanho)
		return -1;

	/* considera caso em que pos=-1 (ultimo) */
	if(pos == -1)
		pos = vec->tamanho;

	/* aumenta elementos do vetor se capacidade nao for suficiente */
	if(vec->tamanho == vec->capacidade)
	{
		if(vec->capacidade == 0)
			vec->capacidade = 1;
		else
			vec->capacidade *= 2;

		vec->elementos = (elemento_vetor*)realloc(vec->elementos, vec->capacidade * sizeof(elemento_vetor));
		if(vec->elementos == NULL)
			return -1;
	}

	/* copia todos os elementos a partir da posicao pos ate' ao fim do vetor para pos+1 */
	for(i=vec->tamanho-1; i>=pos; i--)
	{
		vec->elementos[i+1].val = vec->elementos[i].val;
	}

	/* copia valor */
	vec->elementos[pos].val = valor;

	vec->tamanho++;

	return pos;
}

int vetor_remove(vetor* vec, int pos)
{
	int i;

	if(vec == NULL || pos < 0 || pos >= vec->tamanho)
		return -1;

	/* copia todos os elementos a partir da posicao pos+1 ate ao fim do vetor para pos */
	for(i=pos+1; i<vec->tamanho; i++)
	{
		vec->elementos[i-1].val = vec->elementos[i].val;
	}

	vec->tamanho--;

	return 0;
}

int vetor_pesquisa(vetor* vec, int valor)
{
	int i;

	if(vec == NULL)
		return -1;

	/* pesquisa sequencial */
	for (i = 0; i < vec->tamanho; i++)
	{
		if (vec->elementos[i].val == valor)
			return i;
	}

	return -1;
}

int vetor_ordena(vetor* vec)
{
	int i, j, tmp;

	if(vec == NULL)
		return -1;

	/* ordenacao por insercao */
    for (i = 1; i < vec->tamanho; i++)
    {
		tmp = vec->elementos[i].val;
		for (j = i; j > 0 && tmp < vec->elementos[j-1].val; j--)
		{
			vec->elementos[j].val = vec->elementos[j-1].val;
		}
		vec->elementos[j].val = tmp;
    }

	return 0;
}
