/*****************************************************************/
/*          Biblioteca vetor | PROG2 | MIEEC | 2014/15           */
/*****************************************************************/

#include "vetor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

vetor *vetor_novo() {
    vetor *vec;

    /* aloca memoria para a estrutura vetor */
    vec = (vetor *) malloc(sizeof(vetor));
    if (vec == NULL)
        return NULL;

    vec->tamanho = 0;
    vec->capacidade = 0;
    vec->elementos = NULL;

    return vec;
}

void vetor_apaga(vetor *vec) {
    int i;

    if (vec == NULL)
        return;

    /* liberta memoria de cada string */
    for (i = 0; i < vec->tamanho; i++) {
        free(vec->elementos[i].title);
    }

    /* liberta memoria dos apontares para as strings */
    free(vec->elementos);

    /* liberta memoria da estrutura vetor */
    free(vec);
}

int vetor_tamanho(vetor *vec) {
    if (vec == NULL)
        return -1;

    return vec->tamanho;
}


int vetor_insere(vetor *vec, const char *valor, int votes, float rank, int year, int pos) {
    int i, n;

    if (vec == NULL || pos < 0 || pos > vec->tamanho)
        return -1;

    /* aumenta elementos do vetor se capacidade nao for suficiente */
    if (vec->tamanho == vec->capacidade) {
        if (vec->capacidade == 0)
            vec->capacidade = 1;
        else
            vec->capacidade *= 2;

        vec->elementos = (elemento *) realloc(vec->elementos, vec->capacidade * sizeof(elemento));
        if (vec->elementos == NULL)
            return -1;
    }

    /* copia todos os elementos a partir da posicao pos ate' ao fim do vetor para pos+1 */
    for (i = vec->tamanho - 1; i >= pos; i--) {
        vec->elementos[i + 1] = vec->elementos[i];
    }

    /* aloca espaco para a nova string na posicao pos */
    vec->elementos[pos].title = (char *) calloc(strlen(valor) + 1, sizeof(char));
    if (vec->elementos[pos].title == NULL)
        return -1;

    /* copia valores */
    strcpy(vec->elementos[pos].title, valor);
    vec->elementos[pos].votes = votes;
    vec->elementos[pos].rank = rank;
    vec->elementos[pos].year = year;

    vec->tamanho++;

    return pos;
}

int vetor_pesquisa(vetor *vec, const char *valor) {
    int i;

    if (vec == NULL)
        return -1;

    /* pesquisa sequencial */
    for (i = 0; i < vec->tamanho; i++) {
        if (strcmp(vec->elementos[i].title, valor) == 0)
            return i;
    }

    return -1;
}

int vetor_ordena(vetor *vec) {
    int i, j;
    elemento tmp;

    if (vec == NULL)
        return -1;

    /* ordenacao por insercao */
    for (i = 1; i < vec->tamanho; i++) {
        tmp = vec->elementos[i];
        for (j = i; j > 0 && strcmp(tmp.title, vec->elementos[j - 1].title) < 0; j--) {
            vec->elementos[j] = vec->elementos[j - 1];
        }
        vec->elementos[j] = tmp;
    }

    return 0;
}

int vetor_ordena_ano(vetor *vec) {
    int i, j;
    elemento tmp;

    if (vec == NULL)
        return -1;

    /* ordenacao por insercao */
    for (i = 1; i < vec->tamanho; i++) {
        tmp = vec->elementos[i];
        for (j = i; j > 0 && tmp.year < vec->elementos[j - 1].year; j--) {
            vec->elementos[j] = vec->elementos[j - 1];
        }
        vec->elementos[j] = tmp;
    }

    return 0;
}

vetor *vetor_pesquisa_ano(vetor *vec, int year) {
    int i;
    vetor *results = vetor_novo();

    if (vec == NULL || results == NULL)
        return NULL;

    /* pesquisa sequencial */
    for (i = 0; i < vec->tamanho; i++) {
        elemento el = vec->elementos[i];
        if (el.year == year)
            vetor_insere(results, el.title, el.votes, el.rank, el.year, results->tamanho);
    }
    return results;
}

