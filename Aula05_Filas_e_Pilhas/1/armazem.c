#include "armazem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * funcoes do armazem
 */
/* alinea b) */
armazem* armazem_novo(int comprimento, int altura)
{
	int i;
	armazem* a=malloc(sizeof(armazem));
	a->comprimento = comprimento;
	a->altura = altura;
	a->contentores=fila_nova();
	return a;
}

/* alinea c) */
int armazem_vazio(armazem* armz)
{
	if(armz== NULL || fila_tamanho(armz->contentores)==0) return 1;
	return 0;
}

/* alinea d) */
int armazem_cheio(armazem* armz)
{
	if(armazem_vazio(armz)) return 0;
	if(fila_tamanho(armz->contentores) == armz->comprimento && fila_back(armz->contentores)->tamanho == armz->altura) return 1;
	return 0;
}

/* alinea e) */	
int armazenar_contentor(armazem* armz, contentor* contr)
{
	pilha *p= pilha_nova();
	if (armz == NULL || contr == NULL || armazem_cheio(armz)) return 0;
	if (armazem_vazio(armz)) fila_push(armz->contentores, pilha_nova());
	if(fila_back(armz->contentores)->tamanho== armz->altura) fila_push(armz->contentores, p);
	pilha_push(fila_back(armz->contentores), contr);
	return 1;
}

/* alinea f) */
contentor* expedir_contentor(armazem* armz)
{
	if (armazem_vazio(armz) || pilha_top(fila_front(armz->contentores)) ==NULL) return NULL;
	contentor *c = contentor_novo(pilha_top(fila_front(armz->contentores))->destino, pilha_top(fila_front(armz->contentores))->valor);
	if(fila_front(armz->contentores)->tamanho <=1) fila_pop(armz->contentores);
	else pilha_pop(fila_front(armz->contentores));
	return c;
}
