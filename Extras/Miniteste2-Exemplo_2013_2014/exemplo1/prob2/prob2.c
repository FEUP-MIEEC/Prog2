#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void imprimirFiltro(no_avl *no)
{
	/* problema 3 - a implementar */
	if(!no)
		return;

	int n = atoi(no->str);
	if(n < 15000)
		printf("%d\n", n);
	imprimirFiltro(no->esquerda);
	imprimirFiltro(no->direita);
}


int imprimirMaxMinLeituras(const char *nomeFicheiro)
{
	/* problema 3 - a implementar */
	int n;
	FILE * f;
	char str[10];
	const char *max, *min;

	arvore_avl * avl = avl_nova();
	if(!avl)
		return 0;

	f = fopen(nomeFicheiro, "r");

	/* Inserir elementos na AVL */
	while(fscanf(f, "%d", &n) == 1)
	{
		sprintf(str, "%d", n); /* Uma forma de converter números para uma string */
		avl_insere(avl, str);
	}

	/* Obter máximo e mínimo e imprimir resultados */
	min = avl_min(avl);
	max = avl_max(avl);

	printf("Máximo: %s\nMínimo: %s\n", max, min);

	/* Imprimir com filtro */
	imprimirFiltro(avl->raiz);

	/* Libertar memória */
	avl_apaga(avl);
	fclose(f);

	return 1;
}


/*----------------------------------*/
/*    nao alterar a funcao main     */

int main()
{
	if(imprimirMaxMinLeituras("leituras.txt") == 0)
	{
		printf("Erro ao executar funcao.\n");
		return 1;
	}

	return 0;
}
