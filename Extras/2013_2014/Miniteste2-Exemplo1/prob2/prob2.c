#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void imprimirFiltro(no_avl *no)
{
	/* problema 3 - a implementar */
	if(no==NULL) return;
	if(atoi(no->str) < 15000) printf("%s\n", no->str);
	imprimirFiltro(no->esquerda);
	imprimirFiltro(no->direita);
}

#define INT32_MIN
int imprimirMaxMinLeituras(const char *nomeFicheiro)
{
	/* problema 3 - a implementar */
	char s[6];
	FILE *f = fopen(nomeFicheiro, "r");
	if (f == NULL) return 0;
	arvore_avl *avl = avl_nova();
	while(fscanf(f, "%s", s)==1){
		avl_insere(avl, s);
	}
	printf("Minimo: %s\nMaximo: %s\n\nFiltro:\n", avl_min(avl), avl_max(avl));
	imprimirFiltro(avl->raiz);
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
