/*****************************************************************/
/*                Fila | PROG2 | MIEEC | 2015/16                 */      
/*****************************************************************/

#include <stdlib.h>
#include <string.h>
#include "fila.h"

fila* fila_nova()
{
	fila *f = (fila *) malloc(sizeof(fila));
	if (f == NULL)
		return NULL;
	f->cabeca = f->cauda = NULL;

	return f;
}

void fila_apaga(fila *f)
{
	filaItem * cur, * next;

	if(f == NULL)
		return;

	if (f->cabeca != NULL)
	{
		cur = f->cabeca;
		while (cur->proximo != NULL)
		{
			free(cur->string);
			next = cur->proximo;
			free(cur);
			cur = next;
		}
	}

	free(f);
}

int	fila_vazia(fila *f)
{
	if(f == NULL)
		return -1;

	return f->cabeca == NULL;
}

int	fila_tamanho(fila *f)
{
	int count = 0;
	filaItem *cur;

	if(f == NULL)
		return -1;

	cur = f->cabeca;
	while(cur != NULL)
	{
		count++;
		cur = cur->proximo;
	}
	return count;
}

const char* fila_front(fila *f)
{
	if (f == NULL || fila_vazia(f))
		return NULL;
	return f->cabeca->string;
}

int	fila_push(fila *f, const char *string)
{
	filaItem *novo, *ult = f->cauda;

	if(f == NULL || string == NULL)
		return -1;

	novo = (filaItem *) malloc(sizeof(filaItem));
	if(novo == NULL)
		return -1;

	novo->string = (char*) calloc(strlen(string)+1, sizeof(char));
	if(novo->string == NULL)
	{
		free(novo);
		return -1;
	}

	strcpy(novo->string, string);
	novo->proximo = NULL;

	if (ult == NULL)
		f->cabeca = f->cauda = novo;
	else
	{
		f->cauda->proximo = novo;
		f->cauda = novo;
	}

	return 1;
}

void fila_pop(fila *f)
{
	filaItem *cabeca;

	if (f == NULL || fila_vazia(f))
		return;

	cabeca = f->cabeca;
	f->cabeca = cabeca->proximo;

	if (f->cabeca == NULL)
		f->cauda = NULL;
	
	free(cabeca->string);
	free(cabeca);
}

