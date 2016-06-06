/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2013/14          */      
/*****************************************************************/

#include "lista.h"
#include <string.h>
#include <stdlib.h>

elemento_lista* novo_str(const char* valor)
{
	/* aloca memoria para a estrutura lista */
	elemento_lista *item = (elemento_lista *) malloc(sizeof(elemento_lista));
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

	return item;
}

lista* lista_nova()
{
	/* cria lista */
	lista *lst = (lista*) malloc(sizeof(lista));
	if(lst == NULL)
		return NULL;
	
	/* lista esta' vazia */
	lst->raiz = NULL;
	lst->tamanho = 0;

    return lst; 
}


void lista_apaga(lista *lst)
{
	elemento_lista *aux;
	
	if(lst == NULL)
		return;

	/* percorre toda a lista e liberta memoria de
	   cada item e respectiva string */
	while(lst->raiz)
	{
		aux = lst->raiz;
		lst->raiz = lst->raiz->proximo;
		free(aux->str);
		free(aux);
	}
	
	free(lst);

	return;
}


int lista_tamanho(lista *lst)
{
	if (lst == NULL)
		return -1;

	return lst->tamanho;
}


const char* lista_elemento(lista *lst, int pos)
{ 
	int i=0;
	elemento_lista *aux;

	if (lst == NULL || pos < 0)
		return NULL;
	
	aux = lst->raiz;

	/* procura item na posicao pos */
	for (i = 0; i < pos && aux != NULL; i++)
		aux = aux->proximo;
	
	/* se aux e' NULL entao nao existe posicao pos */
	if (aux == NULL)
		return NULL;

	return aux->str;
}


int lista_atribui(lista *lst, int pos, const char* str)
{
	int i=0;
	elemento_lista *aux;

	if (lst == NULL || pos < 0)
		return -1;

	aux = lst->raiz;

	/* procura item na posicao pos */
	for (i = 0; i < pos && aux != NULL; i++)
		aux = aux->proximo;

	/* se aux e' NULL entao nao existe posicao pos */
	if (aux == NULL)
		return -1;

	/* realoca o espaco */
	aux->str = (char *) realloc(aux->str, sizeof(char) * (strlen(str)+1));
	
	/* copia string */
	strcpy(aux->str, str);

	return pos;
}


int lista_insere(lista *lst, const char* valor, int pos)
{
	int i=0;
	elemento_lista *curr = NULL, *temp;

	if (lst == NULL || pos < -1 || (pos !=0 && pos >= lst->tamanho))
		return -1;
	
	temp = lst->raiz;

	/* cria novo item */
	curr = novo_str(valor);
	
	if (curr == NULL)
        return -1;
	
	lst->tamanho++;
	
	/* caso especial: inserir no fim da lista */
	if(pos == -1)
	{
		/* se e' primeiro str */
		if (temp == NULL)
		{
			lst->raiz = curr;    
		}
		else
		{
			/* percorre lista ate' chegar ao ultimo item */
			while (temp->proximo != NULL) 
			{
				temp = temp->proximo;  
			}
			temp->proximo = curr;
		}
		
		return lst->tamanho-1;
	}

	/* caso especial: inserir no inicio da lista */
	if (pos == 0) 
	{
		curr->proximo = temp;  
		lst->raiz = curr;
        return pos;
	}

	/* procura item na posicao pos-1 */
	for (i = 0; i < pos-1 && temp != NULL; i++)
		temp = temp->proximo;  

	/* troca apontadores para inserir item */
	curr->proximo = temp->proximo;
    temp->proximo = curr;
 
	return pos;
}


int lista_remove(lista *lst, int pos)
{
	int i = 0;
	elemento_lista *prev, *curr;

	if (lst == NULL || pos < 0 || pos >= lst->tamanho)
		return -1;
	
	curr = lst->raiz;
	
	lst->tamanho--;

	/* caso especial: remover item no inicio da lista */
	if(pos == 0)
	{
		lst->raiz = curr->proximo;
		free(curr->str);
		free(curr);
		return 0;
	}

	/* procura item na posicao pos-1 */
	for(i = 0; i < pos && curr->proximo; i++)
	{
		prev = curr;
		curr = curr->proximo;
	}

	prev->proximo = curr->proximo;

	/* liberta memoria associada ao item removido */
	free(curr->str);
	free(curr);

	return 0;
}


int lista_pesquisa(lista *lst, const char* str, int origem)
{
    int i=0, pos=-1;
	elemento_lista *aux;
	
	if(lst == NULL)
		return -1;

	/* pesquisa sequencial */
	for (aux = lst->raiz; aux != NULL; aux = aux->proximo, i++) 
	{
		if (strcmp(aux->str, str) == 0)
		{
			if(origem == INICIO)
				return i;
			else if(origem == FIM)
				pos = i;
		}
	}
	return pos;
}


int lista_ordena(lista *lst)
{
    elemento_lista *next, *curr, *left, *prev_left;
	
	if(lst == NULL)
		return -1;

	curr = lst->raiz;

    for (next = curr->proximo; next!= NULL; next = curr->proximo) 
    {
		/* o ultimo str do lado direito e o primeiro do lado esq. estao desordenados */
		if (strcmp(curr->str,next->str) > 0)       
        { 
			/* remove o primeiro str do lado direito (desordenado) */
            curr->proximo = next->proximo;
			/* posiciona o apontador left no inicio do lado esquerdo, i.e. inicio da lista */
            prev_left = left = lst->raiz;      
            
			/* enquanto nao chegar ao penultimo str do lado esquerdo */
			while (next->proximo != curr)   
            {
                if (strcmp(left->str,next->str) > 0) 
                {
                    next->proximo = left;   /* insere 'a esquerda */
					
					/* se inseriu no inicio da lista, e' necessario alterar o apontador raiz */
                    if (left == lst->raiz)     
                        lst->raiz = next;
                    else 
                        prev_left->proximo = next;                  
                    
			        /* ja ordenou e sai do ciclo while */
					break;
                 }

				 /* avanca para o str seguinte do lado esquerdo */
                 prev_left = left;
                 left = left->proximo;
            }
        }
        else 
			/* o str esta ordenado e avanca para o str seguinte do lado direito */
            curr = curr->proximo;
    }
	
	return 0;
}


int lista_compara(lista *lst1, lista *lst2)
{
	int i;
	elemento_lista *curr1, *curr2;

	if(lst1 == NULL || lst2 == NULL)
		return -1;

	if(lst1->tamanho != lst2->tamanho)
		return 0;

	curr1 = lst1->raiz;
	curr2 = lst2->raiz;
	while(curr1 != NULL)
	{
		/* se os strs na mesma posicao sao diferentes, as listas sao diferentes */
		if(strcmp(curr1->str, curr2->str) !=0)
			return 0;

		curr1 = curr1->proximo;
		curr2 = curr2->proximo;
	}

	/* se ambas as listas nao terminam, ha um erro */
	if(curr2 != NULL)
		return -1;

	return 1;
}


lista* lista_inverte(lista *lst)
{
	lista *inv;
	elemento_lista *curr;

	if(lst == NULL)
		return NULL;

	inv = lista_nova();
	if(inv == NULL)
		return NULL;

	curr = lst->raiz;
	while(curr != NULL)
	{
		lista_insere(inv, curr->str, 0);
		curr = curr->proximo;
	}

	return inv;
}