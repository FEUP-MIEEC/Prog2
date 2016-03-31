#include "armazem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * funcoes do armazem
 */
/* alinea b) */
armazem* armazem_novo(int comprimento, int altura)
{
	return NULL;
}

/* alinea c) */
int armazem_vazio(armazem* armz)
{
	/* devolve vazio */
	return 1;
}

/* alinea d) */
int armazem_cheio(armazem* armz)
{
	/* devolve nao cheio */
	return 0;
}

/* alinea e) */
int armazenar_contentor(armazem* armz, contentor* contr)
{
	/* devolve nao ha' espaco */
	return 0;
}

/* alinea f) */
contentor* expedir_contentor(armazem* armz)
{
	return NULL;
}
