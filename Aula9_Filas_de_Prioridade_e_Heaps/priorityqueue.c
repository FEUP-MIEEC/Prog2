#define RAIZ 			(1)
#define PAI(x) 			(x/2)
#define FILHO_ESQ(x) 	(x*2)
#define FILHO_DIR(x) 	((x*2)+1)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vetor.h"

typedef int (* compara)(elemento *, elemento *);

int fp_insere(vetor * fp, char * valor, int prioridade) {
	if (fp == NULL) return -1;

	if (fp->tamanho_actual == fp->tamanho_maximo) return 0;

	elemento *e = elemento_cria(prioridade, valor);
	int i, j;
	for (i = 0; i < fp->tamanho_actual; i++)
		if (maior_que(fp->elementos[i], e) == 0)
			break;
	for(j = fp->tamanho_actual; j >= i; j--)
		fp->elementos[j+1] = fp->elementos[j];

	fp->elementos[i] = e;
	fp->tamanho_actual++;
	return 1;
}

char * fp_remove(vetor * fp) {
	if(fp == NULL || fp->tamanho_actual ==0) return NULL;
	elemento *e = fp->elementos[0];
	int i;

	for(i = 0; i<fp->tamanho_actual; i++)
		fp->elementos[i] = fp->elementos[i+1];
	fp->tamanho_actual--;
	return e->valor;
	return NULL;
}

void fp_carrega(vetor * fp, const char * filename) {

	char texto[256];
	int prioridade;

	FILE * file = fopen(filename, "r");
	if (!file) {
		printf("Nao foi possivel abrir ficheiro!\n");
		return;
	}

	while(!feof(file)) {
		fscanf(file, "%d ", &prioridade);
		fgets(texto, 256, file);
		texto[strlen(texto)-1] = '\0';
		fp_insere(fp, texto, prioridade);
	}

	fclose(file);
}


int heap_insere(vetor * h, compara cmp, char * texto, int prioridade) {

	return 1;
}

char * heap_remove(vetor * h, compara cmp) {

	return NULL;
}

void heap_carrega(vetor * v, compara cmp, const char * filename) {

	char texto[256];
	int prioridade;

	FILE * file = fopen(filename, "r");
	if (!file) {
		printf("Nao foi possivel abrir ficheiro!\n");
		return;
	}

	while(!feof(file)) {
		fscanf(file, "%d ", &prioridade);
		fgets(texto, 256, file);
		texto[strlen(texto)-1] = '\0';
		heap_insere(v, cmp, texto, prioridade);
	}

	fclose(file);
}


int main(int argc, char **argv) {
	vetor * v = vetor_cria(42);
	int i;

	printf("Teste da implementacao de fila de prioridade com vetor\n");

	fp_carrega(v, "dados.txt");
	printf("Comparacoes necessarias para carregar o ficheiro: %d.\n", ncomparacoes);

	vetor_imprime(v);

	if (v->tamanho_actual != 42) {
		printf("Tamanho actual do vetor devia ser 42!\n");
		return 1;
	}

	if (strcmp("Maurice V. Wilkes", fp_remove(v))) {
		printf("[ERRO] Elemento com maior prioridade devia ser \"Maurice V. Wilkes\".\n");
		return 1;
	}

	ncomparacoes = 0;
	fp_remove(v);
	printf("Comparacoes necessarias para remover um valor: %d.\n", ncomparacoes);

	ncomparacoes = 0;
	fp_insere(v, "Novo elemento", 99);
	printf("Comparacoes necessarias para inserir valor com maxima prioridade: %d.\n", ncomparacoes);
	fp_remove(v);

	ncomparacoes = 0;
	fp_insere(v, "Novo elemento", 0);
	printf("Comparacoes necessarias para inserir valor com minima prioridade: %d.\n", ncomparacoes);
	fp_remove(v);

	ncomparacoes = 0;
	fp_insere(v, "Novo elemento", 42);
	printf("comparacoes necessarias para inserir valor com media prioridade: %d.\n", ncomparacoes);

	/******* 2 *******/

	printf("\n\nTeste da implementacao de fila de prioridade com heap\n");

	vetor * v1 = vetor_criaHeap(42);
	int (* compara1)(elemento *, elemento *);
	compara1 = maior_que;

	heap_carrega(v1, compara1, "dados.txt");
	printf("comparacoes necessarias para carregar o ficheiro: %d.\n", ncomparacoes);

	vetor_imprimeHeap(v1);

	if (v1->tamanho_actual != 42) {
		printf("Tamanho actual do vetor deviar ser 42!\n");
		return 1;
	}

	if (strcmp("Maurice V. Wilkes", heap_remove(v1, compara1))) {
		printf("[ERRO] Elemento com maior prioridade devia ser \"Maurice V. Wilkes\".\n");
		return 1;
	}

	ncomparacoes = 0;
	heap_remove(v1, compara1);
	printf("comparacoes necessarias para remover um valor: %d.\n", ncomparacoes);

	ncomparacoes = 0;
	heap_insere(v1, compara1, "Novo elemento", 99);
	printf("comparacoes necessarias para inserir valor com maxima prioridade: %d.\n", ncomparacoes);

	heap_remove(v1, compara1);

	ncomparacoes = 0;
	heap_insere(v1, compara1, "Novo elemento", 0);
	printf("comparacoes necessarias para inserir valor com minima prioridade: %d.\n", ncomparacoes);
	heap_remove(v1, compara1);

	ncomparacoes = 0;
	heap_insere(v1, compara1, "Novo elemento", 42);
	printf("comparacoes necessarias para inserir valor com media prioridade: %d.\n", ncomparacoes);


	/******* 3 *******/

	v1 = vetor_criaHeap(42);
	int (* compara)(elemento * e1, elemento * e2);
	compara = maior_que_HeapSort;

	heap_carrega(v1, compara, "dados.txt");
	printf("comparacoes necessarias para carregar o ficheiro: %d.\n", ncomparacoes);

	char *ordenados[42];

	for(i = 0; i < 42; i++)
	  printf("%s\n", heap_remove(v1, compara));

	return 0;
}



