#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char palavra[100];
	int ocorrencias;
}
registo;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/*** exercicio 2.1 ***/
registo *analisarFicheiro(FILE *ficheiro, int *num_palavras)
{
	registo *v = malloc(sizeof(registo));
	int i, n=0;
	char str[50];
	while (fscanf(ficheiro, "%s", str) != EOF) {
		for (i = 0; i <= n; i++) {
			if (strcmp(str, v[i].palavra) == 0){
                v[i].ocorrencias++;
                break;
            }
			if (i == n) { /* palavra nao existe*/
				v = realloc(v, sizeof(registo) * (n + 1));
				strcpy(v[n].palavra, str);
				v[n].ocorrencias = 1;
				n++;
                break;
			}
		}

	}
	*num_palavras = n;
	return v;
}

/*** exercicio 2.2 ***/
void gerarRelatorio(FILE *ficheiro, registo *resultados, int num_palavras)
{
	int i;
    fprintf(ficheiro, "Palavras encontradas:\n------------------------------\n");
	for (i=0; i<num_palavras; i++){
		fprintf(ficheiro, "%d: %s (%d)\n", i+1, resultados[i].palavra, resultados[i].ocorrencias);
	}
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

int main()
{
	FILE *fin, *fout;
	char nomeIn[50], nomeOut[50];
	registo *resultados;
	int n;

	printf("Ficheiro de entrada? ");
	scanf("%s", nomeIn);
	printf("Ficheiro de saida? ");
	scanf("%s", nomeOut);

	fin = fopen(nomeIn, "r");
	if(fin == NULL)
		return 1;

	fout = fopen(nomeOut, "w");
	if(fout == NULL)
		return 1;

	resultados = analisarFicheiro(fin, &n);
	gerarRelatorio(fout, resultados, n);

	fclose(fin);
	fclose(fout);
	free(resultados);

	return 0;
}