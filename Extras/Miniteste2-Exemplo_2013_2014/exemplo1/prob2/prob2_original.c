#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void imprimirFiltro(no_avl *no)
{
	/* problema 3 - a implementar */
	return;
}

#define INT32_MIN
int imprimirMaxMinLeituras(const char *nomeFicheiro)
{
	/* problema 3 - a implementar */
	return 0;
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
