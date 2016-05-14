#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"

int ncomparacoes = 0;

vetor * vetor_cria(int tamanho_maximo) {
	vetor * v = (vetor *) malloc(sizeof(vetor));
	if (!v)
		return NULL;
	v->tamanho_actual = 0;
	v->tamanho_maximo = tamanho_maximo;
	v->elementos = (elemento **) calloc(tamanho_maximo, sizeof(elemento *));
	if (!v->elementos) {
		free(v);
		return NULL;
	}
	return v;
}

vetor * vetor_criaHeap(int tamanho_maximo) {
	vetor * v = (vetor *) malloc(sizeof(vetor));
	if (!v)
		return NULL;
	v->tamanho_actual = 0;
	v->tamanho_maximo = tamanho_maximo;
	v->elementos = (elemento **) calloc(tamanho_maximo+1, sizeof(elemento *));
	if (!v->elementos) {
		free(v);
		return NULL;
	}
	return v;
}

elemento * elemento_cria(int prioridade, const char * valor) {
	elemento * elem = (elemento *) malloc(sizeof(elemento));
	if (!elem)
		return NULL;
	elem->valor = strdup(valor);
	elem->prioridade = prioridade;
	return elem;
}

int maior_que(elemento * e1, elemento * e2) {
	if (e1 == NULL || e2 == NULL) {
		printf("R U crazy?\n");
		return 0;
	}
	fflush(stdout);
	ncomparacoes++;

	return e1->prioridade > e2->prioridade;
}

int maior_que_HeapSort(elemento * e1, elemento * e2) {
	if (e1 == NULL || e2 == NULL) {
		printf("R U crazy?\n");
		return 0;
	}
	fflush(stdout);
	ncomparacoes++;

	return strcmp(e1->valor, e2->valor) < 0;
}

void vetor_imprime(vetor * v) {
	int i;
	if (v->tamanho_actual > 0) {
		printf("FILA PRIORIDADE: \n \"%s\" (%d)", v->elementos[0]->valor,
				v->elementos[0]->prioridade);
	}
	else {
		printf("FILA PRIORIDADE VAZIA.\n");
		return;
	}
	for (i = 1; i < v->tamanho_actual; i++) {
		printf(" ; \n \"%s\" (%d)", v->elementos[i]->valor, v->elementos[i]->prioridade);
	}
	printf("\n");
}

void vetor_imprimeHeap(vetor * v) {
	int i;
	if (v->tamanho_actual > 0) {
		printf("FILA PRIORIDADE: \n \"%s\" (%d)", v->elementos[1]->valor,
				v->elementos[1]->prioridade);
	}
	else {
		printf("FILA PRIORIDADE VAZIA.\n");
		return;
	}
	for (i = 2; i < v->tamanho_actual; i++) {
		printf(" ; \n \"%s\" (%d)", v->elementos[i]->valor, v->elementos[i]->prioridade);
	}
	printf("\n");
}
