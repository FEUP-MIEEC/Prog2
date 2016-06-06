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
	return NULL;
}

int tabela_redimensiona(tabela_dispersao td, int novo_tamanho)
{
	/* prob 1.2 - a implementar */
	
	return NULL;
}

lista* descobre_segredo(arvore_avl *avl, lista *l)
{
	/* prob 1.3 - a implementar */
	return NULL;
}

void descobre_segredo_recurs(no_avl *no, lista *l)
{
	/* prob 1.3 extra - a implementar */

	return;

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
