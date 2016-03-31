
#include "pilha_contentores.h"
#include <stdlib.h>

pilhaItem* pilha_novo_elemento(contentor* contr)
{
	/* aloca memoria para a estrutura pilhaItem */
	pilhaItem *item = (pilhaItem *) malloc(sizeof(pilhaItem));
	if(item == NULL)
		return NULL;

	/* cria novo contentor */
	item->elemento = contentor_novo(contr->destino, contr->valor);
	if(item->elemento == NULL)
	{
		free(item);
		return NULL;
	}
	/* item ainda nao tem proximo */
  item->proximo = NULL;

	return item;
}

pilha* pilha_nova()
{
	/* cria pilha */
	pilha *p = (pilha*) malloc(sizeof(pilha));
	if(p == NULL)
		return NULL;

	/* pilha esta' vazia */
	p->raiz = NULL;
	p->tamanho = 0;

  return p;
}


void pilha_apaga(pilha *p)
{
	pilhaItem *aux;

	if(p==NULL)
		return;

	/* percorre toda a pilha e liberta memoria de cada item */
	while(p->raiz)
	{
		aux = p->raiz;
		p->raiz = p->raiz->proximo;
		contentor_apaga(aux->elemento);
		free(aux);
	}

	free(p);
	return;
}


int pilha_tamanho(pilha *p)
{
	if (p == NULL)
		return -1;

	return p->tamanho;
}


contentor* pilha_top(pilha *p)
{
	pilhaItem *aux;

	if (p == NULL || p->tamanho == 0)
		return NULL;

	aux = p->raiz;
	return aux->elemento;
}

void pilha_push(pilha *p, contentor* valor)
{
	pilhaItem *novo = NULL;

	if (p == NULL)
		return;

	/* cria novo item */
	novo = pilha_novo_elemento(valor);
	if (novo == NULL)
    return;

	p->tamanho++;

	/* inserir no topo da pilha */
	/* se a pilha esta vazia */
	if (p->raiz == NULL)
	{
		p->raiz = novo;
		return;
	}

	/* primeiro elemento */
	novo->proximo = p->raiz;
	p->raiz = novo;
}

void pilha_pop(pilha *p)
{
	pilhaItem *curr;

	if (p == NULL || p->tamanho == 0)
		return;

	curr = p->raiz;
	p->raiz = curr->proximo;
	p->tamanho--;

	/* liberta memoria associada ao item removido */
	contentor_apaga(curr->elemento);
	free(curr);
}
