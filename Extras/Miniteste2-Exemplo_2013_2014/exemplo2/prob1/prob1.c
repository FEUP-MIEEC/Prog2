#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
#include "lista.h"
#include "pilha.h"
#include "tabdispersao.h"
#include "avl.h"


pilha* vetor_pilha (vetor *v)
{
	/* prob 1.1 - a implementar */
	if(!v)
		return NULL;

	pilha *p;
	lista *l;
	elemento_lista *el;
	int i, j, n;

	l = lista_nova(); p = pilha_nova();
	if(!l || !p) 
		return NULL;
	
	/* Insere elementos do vetor 'v' no vetor 'aux' e já de forma ordenada */
	for(i = 0; i < vetor_tamanho(v); i++)
	{
		j = 0;
		el = l->raiz;
		while(el != NULL)
		{
			if(strcmp(el->str, v->elementos[i].str) > 0)
			{
				el = el->proximo;
				j++;
			}
			else
				break;
		}
		printf("pos[%d]: %s\n", j, v->elementos[i].str);
		if(j >= l->tamanho)
			lista_insere(l, vetor_elemento(v, i), -1);
		else
			lista_insere(l, vetor_elemento(v, i), j);
		
	}

	/* Vamos sucessivamente encontrar o maior elemento na pilha 'aux' e fazer push para a pilha 'p' */
	el = l->raiz;
	while(el != NULL)
	{
		printf("%s\n", el->str);	
		pilha_push(p, el->str);
		el = el->proximo;
	}
	
	lista_apaga(l);
	return p;
}

int tabela_redimensiona(tabela_dispersao td, int novo_tamanho)
{
	/* prob 1.2 - a implementar */
	int n, i;

	objeto * array = tabela_elementos(td, &n);

	if(array == NULL)
		return 0;

	tabela_esvazia(td);
	/* Thanks Filipe Prado */
	td->tamanho = novo_tamanho;
	for(i = 0; i < n; i++)
		tabela_adiciona(td, &array[i]);
	
	free(array);	

	return 1;
}

lista* descobre_segredo(arvore_avl *avl, lista *l)
{
	/* prob 1.3 - a implementar */
	if(!avl || !l)
		return NULL;

	lista* lst = lista_nova();
	if(!lst)
		return NULL;

	elemento_lista* el = l->raiz;
	no_avl * no = avl->raiz;

	while(el != NULL && no != NULL)
	{
		lista_insere(lst, no->str, -1);

		if(!strcmp(el->str, "esquerda"))
			no = no->esquerda;
		else if(!strcmp(el->str, "direita"))
			no = no->direita;
		

		el = el->proximo;
	}
	lista_insere(lst, no->str, -1);

	return lst;
}

void descobre_segredo_recurs(no_avl *no, lista *l)
{
	/* prob 1.3 extra - a implementar */

	if(!no || !l)
		return;

	printf("%s\n", no->str);

	if(!l->raiz)
		return;

	
	elemento_lista* el = l->raiz;
	elemento_lista* root = l->raiz;
	l->raiz = el->proximo;

	if(!strcmp(el->str, "esquerda"))
		descobre_segredo_recurs(no->esquerda, l);
	else if(!strcmp(el->str, "direita"))
		descobre_segredo_recurs(no->direita, l);

	l->raiz = root;

}


/* v-- nao alterar funcao main --v */

int main()
{
	/* teste problema 1.1 */
	{
		vetor *v;
		pilha *res;
		int i;
		char data[][11] = {"Estocolmo", "Oslo", "Helsinquia", "Copenhaga", "Reykjavik"};
		
		printf("* Problema 1.1 *\n");
		
		v = vetor_novo();
		
		for(i=0; i<5; i++)
			vetor_insere(v, data[i], -1);
		
		printf("Vetor: ");
		for(i=0; i<v->tamanho; i++)
			printf("%s ", vetor_elemento(v, i));
		printf("\n");
		
		res = vetor_pilha(v);
		
		printf("Pilha: ");
		if(res)
		{
			while(!pilha_vazia(res))
			{
				printf("%s ", pilha_top(res));
				pilha_pop(res);
			}
		}
		printf("\n");
		
		if(v->tamanho != 5)
			printf("ERRO: Vetor original nao deve ser alterado!\n");
		else
		{
			for(i=0; i<5; i++)
				if(strcmp(data[i], vetor_elemento(v, i)) != 0)
				{
					printf("ERRO: Vetor original nao deve ser alterado!\n");
					break;
				}
		}
		
		vetor_apaga(v);
		pilha_apaga(res);
	}
	
	printf("\n");	
	
	/* teste problema 1.2 */
	{
		int res, i, ok;
		objeto obj;
		char data[][20] = { "Paul Atreides", "Leto Atreides", "Voran Atreides",
							"Vladimir Harkonnen", "Dmitri Harkonnen", "Hundro Moritani" };

		tabela_dispersao td1, td2;
		
		printf("* Problema 1.2 *\n");
		
		td1 = tabela_cria(11, hash_djbm);
		td2 = tabela_cria(7, hash_djbm);
		
		for(i=0; i<6; i++)
		{
			strcpy(obj.chave, data[i]);
			strcpy(obj.valor, data[i]);
			tabela_adiciona(td1, &obj);
			tabela_adiciona(td2, &obj);
		}
		
		res = tabela_redimensiona(td1, 7);
		if(td1->tamanho == 7)
		{
			elemento *aux1, *aux2;
			
			for(i=0; i<td1->tamanho; i++)
			{
				aux2 = td2->elementos[i];
				
				while(aux2 != NULL)
				{	
					ok = 0;
					aux1 = td1->elementos[i];
					while(aux1 != NULL)
					{
						if(strcmp(aux1->obj->chave, aux2->obj->chave) == 0)
						{
							ok = 1;
							break;
						}
						aux1 = aux1->proximo;
					}
					
					if(!ok)
					{
						printf("ERRO: Elemento %s em posicao errada\n", aux2->obj->chave);
						break;
					}
					
					aux2 = aux2->proximo;
				}
			}

			if(ok)
				printf("Tabela de dispersao redimensionada corretamente.\n");
		}
		else
			printf("ERRO: Tabela de dispersao deveria ter novo tamanho.\n");

		tabela_apaga(td1);
		tabela_apaga(td2);

		printf("\n");
	}
	
	/* teste problema 1.3 */
	{
		int i;
		arvore_avl *avl;
		lista *res, *indicacoes;
		char data[][20] = { "prog2", "mt2", "trabalho", "e'", "muito", "zzzz...",
							"dificil", "facil", "nada", "verdade"};
		
		avl = avl_nova();

		printf("* Problema 1.3 *\n");

		for(i=0; i<10; i++)
			avl_insere(avl, data[i]);


		indicacoes = lista_nova();
		lista_insere(indicacoes, "esquerda", -1);
		lista_insere(indicacoes, "esquerda", -1);
		lista_insere(indicacoes, "direita", -1);
		
		res = descobre_segredo(avl, indicacoes);
		
		printf("Segredo: ");
		if(res)
		{
			for(i=0; i<res->tamanho; i++)
				printf("%s ", lista_elemento(res, i));
		}
		
		printf("\n\nSegredo (impl. recursiva): ");
		descobre_segredo_recurs(avl->raiz, indicacoes);

		avl_apaga(avl);
		lista_apaga(indicacoes);
		lista_apaga(res);
		
		printf("\n\n");
	}
	
	return 0;
}
