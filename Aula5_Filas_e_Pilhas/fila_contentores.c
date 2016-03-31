
#include "fila_contentores.h"
#include <stdlib.h>

filaItem* fila_novo_elemento(pilha* valor)
{
	/* aloca memoria para a estrutura filaItem */
	filaItem *item = (filaItem *) malloc(sizeof(filaItem));
	if(item == NULL) 
		return NULL;

	/* aponta para pilha de contentores (novo elemento) */
	item->elemento = valor;
	if(item->elemento == NULL) 
	{
		free(item);
		return NULL;
	}

	/* item ainda nao tem proximo */
	item->proximo = NULL;

	return item;
}

fila* fila_nova()
{
	/* cria fila */
	fila *f = (fila*) malloc(sizeof(fila));
	if(f == NULL)
		return NULL;
	
	/* fila esta' vazia */
	f->raiz = NULL;
	f->tamanho = 0;

	return f; 
}


void fila_apaga(fila *f)
{
	filaItem *aux;
	
	if(f==NULL)
		return;

	/* percorre toda a fila e liberta memoria de
		 cada item e respectiva string */
	while(f->raiz)
	{
		aux = f->raiz;
		f->raiz = f->raiz->proximo;
		pilha_apaga(aux->elemento);
		free(aux);
	}
	
	free(f);

	return;
}


int fila_tamanho(fila *f)
{
	if (f == NULL)
		return -1;

	return f->tamanho;
}


pilha* fila_front(fila *f)
{ 
	filaItem *aux;

	if (f == NULL || f->tamanho == 0)
		return NULL;
	
	aux = f->raiz;
	return aux->elemento;
}

pilha* fila_back(fila *f)
{ 
	filaItem *aux;

	if (f == NULL || f->tamanho == 0)
		return NULL;
	
	aux = f->raiz;
	/* percorre fila ate' ao fim */
	while (aux->proximo != NULL)
		aux = aux->proximo;

	return aux->elemento;
}

void fila_push(fila *f, pilha* valor)
{
	int i=0;
	filaItem *curr = NULL, *temp;

	if (f == NULL)
		return;
	
	temp = f->raiz;

	/* cria novo item */
	curr = fila_novo_elemento(valor);
	
	if (curr == NULL)
				return;
	
	f->tamanho++;
	
	/* inserir no fim da fila */
	/* se e' primeiro elemento */
	if (temp == NULL)
	{
		f->raiz = curr;	 
		return;		
	}

	/* percorre fila ate' chegar ao ultimo item */
	while (temp->proximo != NULL) 
	{
		temp = temp->proximo;	
	}
	temp->proximo = curr;
}

void fila_pop(fila *f)
{
	int i = 0;
	filaItem *curr;

	if (f == NULL || f->tamanho == 0)
		return;
	
	curr = f->raiz;

	/* proximo elemento passa a ser primeiro */
	f->tamanho--;
	f->raiz = curr->proximo;	

	/* liberta memoria associada ao item removido */
	pilha_apaga(curr->elemento);
	free(curr);
}
