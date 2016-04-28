/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define INICIA_TESTE() \
    int erros = 0;

#define ERRO(msg) \
    { \
    printf("\n\t"#msg); \
        erros++; \
    }

#define FINALIZA_TESTE() \
    if (!erros) \
        printf("OK\n"); \
    else \
        printf("\n"); \
    return erros;

lista *_l(int n, ...) {
    va_list argp;
    lista *l;
    elemento *ult;
    int i;

    l = (lista *) malloc(sizeof(lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = n;
    va_start(argp, n);
    for (i = 0; i < n; i++) {
        char *str = va_arg(argp, char *);
        if (i == 0) {
            l->inicio = (elemento *) malloc(sizeof(elemento));
            ult = l->inicio;
            ult->anterior = NULL;
        }
        else {
            ult->proximo = (elemento *) malloc(sizeof(elemento));
            ult->proximo->anterior = ult;
            ult = ult->proximo;
        }

        ult->str = (char *) malloc(strlen(str) + 1);
        strcpy(ult->str, str);
    }

    va_end(argp);
    ult->proximo = NULL;
    l->fim = ult;

    return l;
}

const char *_f(lista *l, int p) {
    int i;
    elemento *aux;
    if (l == NULL) return 0;
    aux = l->inicio;
    for (i = 0; i < p && aux != NULL; i++)
        aux = aux->proximo;
    if (p == i) return aux->str;
    else return "";
}

int teste_lista_nova() {
    INICIA_TESTE()

    lista *lst;

    printf("lista_nova(): ");

    lst = lista_nova();
    if (!lst) {
        printf("\n\tnova lista invalida");
        erros++;
        FINALIZA_TESTE();
    }

    if (lst->tamanho != 0) ERRO("tamanho da lista deveria ser 0")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int teste_lista_insere() {
    INICIA_TESTE()

    elemento *ret;
    const char *str1 = "ola";
    const char *str2 = "prog2";

    lista *lst;
    lst = _l(2, str1, str1);

    printf("lista_insere(): ");

    ret = lista_insere(lst, str2, lst->inicio->proximo);
    if (ret == NULL) ERRO("retorno deveria ser diferente de NULL")

    if (lst->tamanho != 3) ERRO("tamanho da lista deveria ser 3 depois de inserir string")

    if (lst->tamanho != 3) {
        FINALIZA_TESTE()
    }

    if (strcmp(lst->inicio->str, str1) != 0 || strcmp(lst->inicio->proximo->str, str2) != 0 ||
        strcmp(lst->inicio->proximo->proximo->str, str1) != 0) ERRO("conteudo da lista errado depois de inserir string")

    ret = lista_insere(lst, str2, lst->inicio);
    if (ret != lst->inicio) ERRO("retorno deveria ser apontador para o inicio")

    if (lst->tamanho != 4) ERRO("tamanho da lista deveria ser 4 depois de inserir string")

    if (lst->tamanho != 4) {
        FINALIZA_TESTE()
    }

    if (strcmp(lst->inicio->str, str2) != 0 || strcmp(lst->inicio->proximo->str, str1) != 0 ||
        strcmp(lst->inicio->proximo->proximo->str, str2) != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->str, str1) != 0) ERRO(
            "conteudo da lista errado depois de inserir string")

    lista_insere(lst, "prog2", NULL);

    if (lst->tamanho != 5) ERRO("tamanho da lista deveria ser 5 depois de inserir string")

    if (lst->tamanho != 5) {
        FINALIZA_TESTE()
    }

    if (strcmp(lst->inicio->proximo->proximo->proximo->proximo->str, "prog2") != 0) ERRO(
            "conteudo da lista errado depois de inserir string")

    lista_apaga(lst);

    lst = lista_nova();

    lista_insere(lst, "prog2", NULL);
    if (lst->tamanho != 1) ERRO("tamanho da lista deveria ser 1 depois de inserir string")

    if (lista_tamanho(lst) != 1) {
        FINALIZA_TESTE()
    }

    if (strcmp(lst->inicio->str, "prog2") != 0) ERRO("conteudo da lista errado depois de inserir string")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int teste_lista_remove() {
    INICIA_TESTE()

    elemento *ret;

    lista *lst;
    lst = _l(5, "a1", "a2", "a3", "a4", "a5");

    printf("lista_remove(): ");

    ret = lista_remove(lst, lst->inicio->proximo->proximo->proximo);
    if (ret != lst->fim) ERRO("retorno deveria ser apontador para seguinte elemento")

    if (lst->tamanho != 4) ERRO("tamanho da lista deveria ser 9 depois de remover string")

    if (strcmp(lst->inicio->str, "a1") != 0 || strcmp(lst->inicio->proximo->str, "a2") != 0 ||
        strcmp(lst->inicio->proximo->proximo->str, "a3") != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->str, "a5") != 0) ERRO(
            "conteudo da lista errado depois de remover string")

    ret = lista_remove(lst, NULL);
    if (ret != NULL) ERRO("retorno deveria ser NULL com posicao invalida")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int teste_lista_pesquisa() {
    INICIA_TESTE()

    const char *str1 = "ola";
    const char *str2 = "p2";

    lista *lst;
    lst = _l(7, str1, str1, str1, str1, str2, str1, str1);

    printf("lista_pesquisa(): ");

    if (lista_pesquisa(lst, str2, INICIO) != lst->inicio->proximo->proximo->proximo->proximo) ERRO(
            "pesquisa de uma string deveria retornar apontador onde se encontra")

    if (lista_pesquisa(lst, "blabla", INICIO) != NULL) ERRO(
            "pesquisa de uma string que nao existe deveria retornar NULL")

    if (lista_pesquisa(lst, str1, FIM) != lst->inicio->proximo->proximo->proximo->proximo->proximo->proximo) ERRO(
            "pesquisa de uma string deveria retornar apontador onde se encontra")

    if (lista_pesquisa(lst, "blabla", FIM) != NULL) ERRO("pesquisa de uma string que nao existe deveria retornar NULL")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int teste_lista_ordena() {
    INICIA_TESTE()

    int ret;
    lista *lst;
    lst = _l(5, "aa", "bb", "zz", "ll", "mm");

    printf("lista_ordena(): ");

    ret = lista_ordena(NULL);
    if (ret != -1) ERRO("retorno deveria ser -1 com lista invalida")

    lista_ordena(lst);

    if (strcmp(lst->inicio->str, "aa") != 0 || strcmp(lst->inicio->proximo->str, "bb") != 0 ||
        strcmp(lst->inicio->proximo->proximo->str, "ll") != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->str, "mm") != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->proximo->str, "zz") != 0) ERRO(
            "conteudo da lista errado depois de ordenar (inicio->fim)")

    if (strcmp(lst->fim->str, "zz") != 0 || strcmp(lst->fim->anterior->str, "mm") != 0 ||
        strcmp(lst->fim->anterior->anterior->str, "ll") != 0 ||
        strcmp(lst->fim->anterior->anterior->anterior->str, "bb") != 0 ||
        strcmp(lst->fim->anterior->anterior->anterior->anterior->str, "aa") != 0) ERRO(
            "conteudo da lista errado depois de inverter (fim->inicio)")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int teste_lista_inverte() {
    INICIA_TESTE()

    int ret;
    lista *lst;
    lst = _l(5, "aa", "bb", "zz", "ll", "mm");

    printf("lista_inverte(): ");

    ret = lista_inverte(NULL);
    if (ret != -1) ERRO("retorno deveria ser -1 com lista invalida")

    ret = lista_inverte(lst);

    if (lst->tamanho != 5) ERRO("tamanho da lista não deve ser alterado")

    if (strcmp(lst->inicio->str, "mm") != 0 || strcmp(lst->inicio->proximo->str, "ll") != 0 ||
        strcmp(lst->inicio->proximo->proximo->str, "zz") != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->str, "bb") != 0 ||
        strcmp(lst->inicio->proximo->proximo->proximo->proximo->str, "aa") != 0) ERRO(
            "conteudo da lista errado depois de inverter (inicio->fim)")

    if (strcmp(lst->fim->str, "aa") != 0 || strcmp(lst->fim->anterior->str, "bb") != 0 ||
        strcmp(lst->fim->anterior->anterior->str, "zz") != 0 ||
        strcmp(lst->fim->anterior->anterior->anterior->str, "ll") != 0 ||
        strcmp(lst->fim->anterior->anterior->anterior->anterior->str, "mm") != 0) ERRO(
            "conteudo da lista errado depois de inverter (fim->inicio)")

    lista_apaga(lst);

    FINALIZA_TESTE()
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    int erros = 0;
    erros += teste_lista_nova();
    erros += teste_lista_insere();
    erros += teste_lista_remove();
    erros += teste_lista_pesquisa();
    erros += teste_lista_ordena();
    erros += teste_lista_inverte();

    if (!erros)
        printf("FIM DE TODOS OS TESTES.\n");
    else
        printf("FOI ENCONTRADO UM TOTAL DE %d ERROS.\n", erros);
    return 0;
}
