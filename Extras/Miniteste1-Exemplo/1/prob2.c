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
int FindWord(registo *reg, char * word, int *n)
{
    int i;
    for(i = 0;i < *n; i++)
        {
            if(strcmp(word, reg[i].palavra) == 0)
                return i; /* Retorna a posição no Registo onde foi encontrada a palavra */
        }
        
    return -1; /* Palavra não encontrada */    
}
registo *analisarFicheiro(FILE *ficheiro, int *num_palavras)
{
    registo *reg = malloc(sizeof(registo));
    *num_palavras = 0;
    char w[100];
    int pos;
    
    if(reg == NULL)
        return NULL;
    
    while(fscanf(ficheiro, "%s", w) == 1)
    {
        if((pos = FindWord(reg, w, num_palavras)) == -1) /* Redimensionar reg e inserir nova struct para a nova palavra*/
        {
            reg = realloc(reg, sizeof(registo)*(*num_palavras + 1));
            reg[*num_palavras].ocorrencias = 1;
            strcpy(reg[*num_palavras].palavra, w);
            *num_palavras = *num_palavras + 1;
        }
        else
            reg[pos].ocorrencias++;
        
    }
    
    /* PARA TESTAR
    for(pos = 0; pos < *num_palavras; pos++)
    {
        printf("palavra %s ; ocorrencias %d\n", reg[pos].palavra, reg[pos].ocorrencias);
    }
    */
    return reg;
}

/*** exercicio 2.2 ***/
void gerarRelatorio(FILE *ficheiro, registo *resultados, int num_palavras)
{
    int i;
    fprintf(ficheiro, "Palavra encontradas:\n-----------------------\n");
    for(i = 0; i < num_palavras; i++)
    {
        fprintf(ficheiro, "%d:\t%s: (%d)\n", i+1, resultados[i].palavra, resultados[i].ocorrencias);
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
