#include <stdio.h>
#include <string.h>
#include "vetor.h"

void vetor_imprime(vetor * vec);
int vetor_num_ocorrencias(vetor	*vec, char *pesquisa);
void vetor_remove_repetidas(vetor *vec);
vetor* vetor_pesquisa_parcial(vetor *vec, char *pesquisa);	

int main()
{
	FILE * f;
	char str[100];
	int N = 0, i = 0;

	vetor * plantas = vetor_novo();
	f = fopen("plantas.txt", "r");

	/*
	 *
	 Exercíco a)
	 *
	 */
	
	while(fgets(str, 100, f) != NULL)
	{
		str[strlen(str) - 1] = '\0';

		if (vetor_insere(plantas, str, N)==-1)
		{
			printf("Ocorreu um erro a inserir elementos no vetor\n");
			return -1;
		}

		N++;
	}

	printf("Foram lidas %d plantas.\n", N);
	/*[test] Print array elements*/
	vetor_imprime(plantas);


	/*
	 *
	 Exercíco b)
	 *
	 */

	printf("A planta Podocarpus macrophyllus (Thunberg) encontra-se na posicao %d\n", vetor_pesquisa(plantas, "Podocarpus macrophyllus (Thunberg)"));

	/*
	 *
	 Exercíco c)
	 *
	 */	

	if (!vetor_ordena(plantas))
	{
		vetor_imprime(plantas);
	}
	else printf("Ocorreu um erro na ordenacao do vetor\n");

	/*
	 *
	 Exercíco d)
	 *
	 */
	 printf("A planta Ginkgo biloba (L.) aparece %d vezes no vetor.\n", vetor_num_ocorrencias(plantas, "Ginkgo biloba (L.)"));

	/*
	 *
	 Exercíco e)
	 *
	 */

	 vetor_remove_repetidas(plantas);
	 printf("Apos remocao das plantas repetidas o vetor tem %d posicoes.\n", plantas->tamanho - 1);
	 
	/*
	 *
	 Exercíco f)
	 *
	 */
	 vetor * aux = 	vetor_pesquisa_parcial(plantas, "Acacia");
	 vetor_imprime(aux);
	 vetor_apaga(aux);
	 vetor_apaga(plantas);
	 fclose(f);
}

void vetor_imprime(vetor * vec)
{
	int i, n = vec->tamanho;

	for (i = 0; i < n; ++i)
	{
		printf("Pos %d - %s\n", i, vetor_elemento(vec, i));
	}
}

int	vetor_num_ocorrencias(vetor	*vec, char *pesquisa)
{
	/*
	 * Considerando que o vetor não está ordenado: Pesquisa Sequencial
	 */
	int counter = 0, n = vec->tamanho, i;

	for (i = 0; i < n; ++i)
	{
		if (!strcmp(pesquisa, vetor_elemento(vec, i)))
			counter++;
	}

	return counter;
}

void vetor_remove_repetidas(vetor *vec)
{
	int i, j;
	for (i = 0; i < vec->tamanho; ++i)
	{	
		char str[100];

		strcpy(str,vetor_elemento(vec, i));

		for (j = i+1; j < vec->tamanho; ++j)
		{
			if (!strcmp(str, vetor_elemento(vec, j))){
				if (vetor_remove(vec, j) == -1)
				{
					printf("Ocorreu um erro a remover string repetida\n");
				}
				else
				{
					j--;
				}
			}
		}
	}
}

vetor* vetor_pesquisa_parcial(vetor *vec, char *pesquisa)
{
	vetor * aux = vetor_novo();
	int i, j = 0;

	for(i = 0; i < vec->tamanho; ++i)
	{
		if (strstr(vetor_elemento(vec, i), pesquisa) != NULL)
		{
			if(vetor_insere(aux, vetor_elemento(vec, i), j) == -1)
				printf("Ocorreu um erro ao inserir uma string na pesquisa parcial\n");
		}
	}

	return aux;
}
