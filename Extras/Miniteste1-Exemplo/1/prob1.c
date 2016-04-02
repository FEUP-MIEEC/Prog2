#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vetor.h"
#include "lista.h"

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

void retira_duplicados(vetor *vec) {
    int i, j;
    for (i = 0; i < vetor_tamanho(vec) - 1; i++) {
        for (j = i + 1; j < vetor_tamanho(vec); j++) {
            if (strcmp(vetor_elemento(vec, i), vetor_elemento(vec, j)) == 0) {
                vetor_remove(vec, j);
                j--;
            }
        }
    }
    return;
}

vetor *interseta(lista *l1, lista *l2) {
    vetor *v = vetor_novo();
    elemento *e = l1->inicio;
    int i, j = 0;
    for (i = 0; i < l1->tamanho || e != NULL; i++) {
        if (strcmp(e->str, lista_pesquisa(l2, e->str, INICIO) == NULL ? "" : lista_pesquisa(l2, e->str, INICIO)->str) == 0) {
            vetor_insere(v, e->str, j);
            j++;
        }
        e = e->proximo;
    }
    return v;
}

vetor *anteriores(lista *lst, const int ano) {
    int i=0;
    vetor *v;
    elemento *e;
    v = vetor_novo();
    for (e = lst->inicio; e != NULL; e = e->proximo) {
        if (lista_pesquisa(lst, e->str, INICIO) && atoi(e->str + strlen(e->str) - 5) < ano){
            vetor_insere(v, e->str, i);
            i++;
        }
    }
    return v;
}


/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

vetor *lerAtores(FILE *ficheiro) {
    char buffer[256], *nlptr;
    vetor *atores;

    if (ficheiro == NULL)
        return NULL;

    atores = vetor_novo();

    while (!feof(ficheiro)) {
        fgets(buffer, 255, ficheiro);
        nlptr = strchr(buffer, '\n');
        if (nlptr)
            *nlptr = '\0';

        vetor_insere(atores, buffer, atores->tamanho);
    }

    return atores;
}

lista *lerFilmes(FILE *ficheiro) {
    char buffer[256], *nlptr;
    lista *filmes;

    if (ficheiro == NULL)
        return NULL;

    filmes = lista_nova();

    while (!feof(ficheiro)) {
        fgets(buffer, 255, ficheiro);
        nlptr = strchr(buffer, '\n');
        if (nlptr)
            *nlptr = '\0';

        lista_insere(filmes, buffer, NULL);
    }

    return filmes;
}

int main() {
    FILE *fa, *ff, *ff2;
    vetor *atores, *resultado, *resultado1;
    lista *filmes, *filmes2;

    /* testes */
    fa = fopen("atores2.txt", "r");
    ff = fopen("filmes.txt", "r");
    ff2 = fopen("filmes2.txt", "r");

    atores = lerAtores(fa);
    filmes = lerFilmes(ff);
    filmes2 = lerFilmes(ff2);

    /* testa retira_duplicados */
    printf("Total inicial: %d\n", vetor_tamanho(atores));
    retira_duplicados(atores);
    printf("Unicos: %d (esperado: 30)\n\n", vetor_tamanho(atores));

    /* testa interseta */
    resultado = interseta(filmes, filmes2);
    if (resultado)
        printf("Intersecao: %d (esperado: 75)\n", vetor_tamanho(resultado));
    else
        printf("Intersecao: vetor NULL\n");

    /* testa anteriores */
    resultado1 = anteriores(filmes, 2000);
    if (resultado1)
        printf("\nAnteriores: %d (esperado: 107)\n", vetor_tamanho(resultado1));
    else
        printf("\nAnteriores: vetor NULL\n");

    vetor_apaga(atores);
    vetor_apaga(resultado);
    vetor_apaga(resultado1);
    lista_apaga(filmes);
    lista_apaga(filmes2);

    fclose(fa);
    fclose(ff);
    fclose(ff2);

    return 0;
}
