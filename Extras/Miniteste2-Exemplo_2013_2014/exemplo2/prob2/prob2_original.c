#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int topSubmissoes(FILE *f)
{
	/* problema 2 - a implementar */
	
	return 0;
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
