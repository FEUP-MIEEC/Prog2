#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int topSubmissoes(FILE *f)
{
	/* problema 2 - a implementar */
	heap * h = heap_cria(100);
	char grupo[20];
	int mm, ss, priority, i;

	while(fscanf(f, "%s %d %d", grupo, &mm, &ss) != EOF)
	{

		/* Definir a proridade como um inteiro do tipo mmhh */
		
		priority = mm*100;
		priority+=ss;

		heap_insere(h, grupo, priority);
	}
	
	printf("Top	5 submissoes:\n");
	for(i = 0; i < 5; ++i)
	{
		int time = h->elementos[0]->prioridade;
		mm = time/100;
		ss = time - mm*100;
		printf("Grupo %s - %dmin %dseg\n", heap_remove(h), mm, ss);
	}

	heap_apaga(h);

	return 1;
}


/* v-- nao alterar funcao main --v */

int main()
{
	FILE *f;
	
	f = fopen("submissoes.txt", "r");
	
	if(topSubmissoes(f) == 0)
	{
		puts("Erro ao executar funcao.\n");
		fclose(f);
		return 1;
	}
	
	fclose(f);
	return 0;
}