/*****************************************************************/
/*      Biblioteca lista ligada | PROG2 | MIEEC | 2015/16        */         
/*****************************************************************/

#include "lista.h"
#include <string.h>
#include <stdlib.h>

elemento* novo_str(const char* valor)
{
	/* aloca memoria para a estrutura lista */
	elemento *item = (elemento *) malloc(sizeof(elemento));
	if(item == NULL) 
		return NULL;

	/* aloca memoria para string */
    item->str = (char *) malloc((strlen(valor)+1)*sizeof(char));
	if(item->str == NULL) 
	{
		free(item);
		return NULL;
	}

	/* copia valor */
	strcpy(item->str, valor);

	/* item ainda nao tem proximo */
    item->proximo = NULL;
    item->anterior = NULL;

	return item;
}

lista* lista_nova()
{
	/* cria lista */
	lista *lst = (lista*) malloc(sizeof(lista));
	if(lst == NULL)
		return NULL;
	
	/* lista esta' vazia */
	lst->inicio = NULL;
	lst->fim = NULL;
	lst->tamanho = 0;

    return lst; 
}


void lista_apaga(lista *lst)
{
	elemento *aux;
	
	if(lst == NULL)
		return;

	/* percorre toda a lista e liberta memoria de
	   cada item e respectiva string */
	while(lst->inicio)
	{
		aux = lst->inicio;
		lst->inicio = lst->inicio->proximo;
		free(aux->str);
		free(aux);
	}
	
	free(lst);

	return;
}


int lista_tamanho(lista *lst)
{
	if(lst == NULL)
		return -1;
	return lst->tamanho;
}


elemento* lista_inicio(lista *lst)
{
	if(lst == NULL)
		return NULL;
	return lst->inicio;	
}


elemento* lista_fim(lista *lst)
{
	if(lst == NULL)
		return NULL;
	return lst->fim;	
}


elemento* lista_insere(lista *lst, const char* valor, elemento *pos)
{
	elemento *curr = NULL;

	if (lst == NULL || valor == NULL)
		return NULL;

	/* cria novo item */
	curr = novo_str(valor);
	
	if (curr == NULL)
        return NULL;
	
	lst->tamanho++;
	
	/* caso especial: inserir no fim da lista */
	if(pos == NULL)
	{
		/* se e' primeiro elemento */
		if (lst->inicio == NULL)
		{
			lst->inicio = lst->fim = curr;    
		}
		else
		{
			curr->anterior = lst->fim;
			lst->fim->proximo = curr;
			lst->fim = curr;
		}	
		return curr;
	}

	/* caso especial: inserir no inicio da lista */
	if (pos == lst->inicio) 
	{
		curr->proximo = lst->inicio;  
		lst->inicio->anterior = curr;
		lst->inicio = curr;
        return curr;
	}

	/* troca apontadores para inserir item */
	curr->anterior = pos->anterior;
	curr->proximo = pos;
	pos->anterior->proximo = curr;
	pos->anterior = curr;
 
	return curr;
}


elemento* lista_remove(lista *lst, elemento *pos)
{
	elemento *aux;

	if (lst == NULL || pos == NULL)
		return NULL;
	
	lst->tamanho--;
	
	/* troca apontadores para remover item */
	if(pos->anterior != NULL)
		pos->anterior->proximo = pos->proximo;
	else /* e' o primeiro */
		lst->inicio = pos->proximo;
	if(pos->proximo != NULL)
		pos->proximo->anterior = pos->anterior;
	else /* e' o ultimo */
		lst->fim = pos->anterior;

	/* liberta memoria associada ao item removido */
	aux = pos->proximo;
	free(pos->str);
	free(pos);

	return aux;
}


elemento* lista_pesquisa(lista *lst, const char* str, int origem)
{
	elemento *aux;
	
	if(lst == NULL || str == NULL || (origem != INICIO && origem != FIM))
		return NULL;

	if(origem == INICIO)
	{
		/* pesquisa sequencial: a partir do inicio */
		for (aux = lst->inicio; aux != NULL; aux = aux->proximo) 
		{
			if (strcmp(aux->str, str) == 0)
			{
				return aux;
			}
		}
		return NULL;	
	}

	/* pesquisa sequencial: a partir do fim */
	for (aux = lst->fim; aux != NULL; aux = aux->anterior) 
	{
		if (strcmp(aux->str, str) == 0)
		{
			return aux;
		}
	}
	return NULL;		
}


int lista_ordena(lista *lst)
{
    elemento *next, *curr, *min;
    char *aux;
	
	if(lst == NULL)
		return -1;

	/* algoritmo de ordenacao por seleccao */
    for(curr = lst->inicio; curr->proximo != NULL; curr=curr->proximo)
    {
		min = curr;
		next = curr->proximo;
		while(next != NULL)
		{
            if(strcmp(next->str, min->str) < 0)
            	min = next;
            next = next->proximo;
		}
		/* basta trocar strings */
		if (min != curr)
		{
            aux = curr->str;
	    	curr->str = min->str;
	    	min->str = aux;
		}
    }
	
	return 0;
}


int lista_inverte(lista *lst)
{
	int i;
	elemento *curr, *prox;

	if(lst == NULL)
		return -1;

	/* lista com tamanho 0 ou 1 => nada a fazer */
	if(lst->tamanho < 2)
		return 0;

	/* nota: tambem se podia usar estrategia usada na
	         funcao ordena - trocar strings */
	
	/* o primeiro elemento e' mantido */
	curr = lst->inicio->proximo;
	for(i=0; i<lst->tamanho-2; i++)
	{
		/* restantes elementos sao removidos... */
		curr->anterior->proximo = curr->proximo;
		curr->proximo->anterior = curr->anterior;

		/* ...e novamente colocados no inicio da lista */
		prox = curr->proximo;
		curr->proximo = lst->inicio;
		lst->inicio->anterior = curr;
		lst->inicio = curr;
		curr = prox;
	}

	/* falta passar o ultimo para o inicio */
	curr = lst->fim;
	lst->fim = curr->anterior;
	lst->fim->proximo = NULL;
	curr->anterior = NULL;
	curr->proximo = lst->inicio;
	lst->inicio->anterior = curr;
	lst->inicio = curr;

	return 0;
}

