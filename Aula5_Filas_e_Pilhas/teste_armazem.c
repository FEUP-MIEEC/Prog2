#include <stdio.h>
#include <stdlib.h>
#include "fila_contentores.h"
#include "armazem.h"

void imprimeArmazem(armazem *armz);

int main()
{
	int i;
	contentor *c11,*c12,*c13,*c14,*c15,*c16,*c17,*c18,*c19,*c110,*c111,*c112,*c113,*c2;
	armazem *armz = armazem_novo(4,3);

	printf("Armazem Portuario\n\n");

	c11 = contentor_novo("Brazil", 230);
	c12 = contentor_novo("UK", 250);
	c13 = contentor_novo("France", 530);
	c14 = contentor_novo("Spain", 710);
	c15 = contentor_novo("China", 380);
	c16 = contentor_novo("Germany", 390);
	c17 = contentor_novo("Venezuela", 100);
	c18 = contentor_novo("Turkey", 80);
	c19 = contentor_novo("Netherlands", 380);
	c110 = contentor_novo("Iceland", 150);
	c111 = contentor_novo("Thailand", 270);
	c112 = contentor_novo("India", 430);
	c113 = contentor_novo("Finland", 200);

	printf("\n* Dia 0: Carga em armazem\n");
	imprimeArmazem(armz);

	printf("\n\n* Dia 1: Movimentacao de carga\n");
	if(armazenar_contentor(armz, c11)) printf("Contentor com destino %s armazenado.\n",c11->destino);
	if(armazenar_contentor(armz, c12)) printf("Contentor com destino %s armazenado.\n",c12->destino);
	if(armazenar_contentor(armz, c13)) printf("Contentor com destino %s armazenado.\n",c13->destino);
	if(armazenar_contentor(armz, c14)) printf("Contentor com destino %s armazenado.\n",c14->destino);

	printf("\n* Dia 1: Carga em armazem\n");
	imprimeArmazem(armz);

	printf("\n\n* Dia 2: Movimentacao de carga\n");
	if(armazenar_contentor(armz, c15)) printf("Contentor com destino %s armazenado.\n",c15->destino);
	if(armazenar_contentor(armz, c16)) printf("Contentor com destino %s armazenado.\n",c16->destino);
	if(armazenar_contentor(armz, c17)) printf("Contentor com destino %s armazenado.\n",c17->destino);
	if(armazenar_contentor(armz, c18)) printf("Contentor com destino %s armazenado.\n",c18->destino);
	if(armazenar_contentor(armz, c19)) printf("Contentor com destino %s armazenado.\n",c19->destino);
	if(armazenar_contentor(armz, c110)) printf("Contentor com destino %s armazenado.\n",c110->destino);
	if(armazenar_contentor(armz, c111)) printf("Contentor com destino %s armazenado.\n",c111->destino);
	if(armazenar_contentor(armz, c112)) printf("Contentor com destino %s armazenado.\n",c112->destino);

	printf("\n* Dia 2: Carga em armazem\n");
	imprimeArmazem(armz);

	if(armazem_cheio(armz))
		printf("Armazem cheio\n");
	else
		printf("Erro: O armazem deveria estar cheio.\n");

	if(armazenar_contentor(armz, c113)) printf("Erro. Contentor com destino %s nao deveria ter espaco para ser armazenado\n",c13->destino);


	printf("\n\n* Dia 3: Movimentacao de carga\n");
	for (i = 0; i < 8; i++) {
		c2 = expedir_contentor(armz);
		printf("Carregado contentor em navio.\n");
		contentor_imprime(c2);
	}

	printf("\n* Dia 3: Carga em armazem\n");
	imprimeArmazem(armz);

	printf("\n\n* Dia 4: Movimentacao de carga\n");
	for (i = 0; i < 4; i++) {
		c2 = expedir_contentor(armz);
		printf("Carregado contentor em navio.\n");
		contentor_imprime(c2);
	}

	printf("\n* Dia 4: Carga em armazem\n");
	imprimeArmazem(armz);
	if(armazem_vazio(armz))
		printf("Armazem vazio\n");
	else
		printf("Erro: O armazem deveria estar vazio.\n");
	return 0;
}

void imprimeArmazem(armazem *armz)
{
	int i, j, n, valor=0;
	int *nContentores;
	filaItem *p;

	if(armz && armz->contentores)
	{
		nContentores = (int*)calloc(armz->contentores->tamanho, sizeof(int));
		n = armz->contentores->tamanho;

		p = armz->contentores->raiz;
		i = 0;
		while(p)
		{
			nContentores[i] = p->elemento->tamanho;
			p = p->proximo;
			i++;
		}

		printf("\n");
		for(j = armz->altura; j > 0; j--)
		{
			printf("  ");
			for(i = 0; i < n; i++)
			{
				if(nContentores[i] >= j)
					printf("[]  ");
				else
					printf("    ");
			}
			printf("\n");
		}
		printf("==");
		for(i = 0; i < armz->comprimento; i++)
		{
			printf("====");
		}
		printf("\n\n");

		free(nContentores);
	}
}
