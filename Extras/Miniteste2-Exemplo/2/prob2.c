#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char nome[15];
	int vitorias;
} jogador;


/* problema 2 */
jogador* conta_vitorias(FILE* f, int *njogadores)
{
	return NULL;
}

/***************************************************/
/*** não alterar o ficheiro a partir deste ponto ***/
/***************************************************/

int main()
{
	FILE * f = fopen("log.txt", "r");
	jogador *j;
	int i, n=0;

	j = conta_vitorias(f, &n);
	
	fprintf(stderr, "Vencedores:\n");
	if(j != NULL)
	{
		for(i=0; i<n; i++)
			fprintf(stderr, "%s - %d\n", j[i].nome, j[i].vitorias);		
	}

	free(j);
	fclose(f);
	return 0;
}