#include <stdio.h>
#include "bst.h"
#include "avl.h"
#include <string.h>

int main() {
    printf("BST\n");
    char *c[10] = {"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"}, s[100];
    int i;
    arvore_bst *a = bst_nova();
    for (i = 0; i < 10; i++) bst_insere(a, c[i]);
    printf("Altura da raiz: %d\n", bst_altura(a->raiz));
    bst_imprime(a);

    printf("AVL\n");
    arvore_avl *a2 = avl_nova();
    FILE *f;
    f = fopen("cidades.txt", "r");

    while (fgets(s, 100, f) != NULL) {
        strcpy(s, strtok(s, ","));
        strcpy(s, strtok(NULL, ","));
        s[strlen(s) - 1] = '\0';
        avl_insere(a2, s);
    }
    fclose(f);
    no_avl *no = avl_pesquisa(a2, "Portugal");
    if (no != NULL) printf("%s - %d\n", no->str, no->cont);
    no = avl_pesquisa(a2, "Spain");
    if (no != NULL) printf("%s - %d\n", no->str, no->cont);
    no = avl_pesquisa(a2, "Russia");
    if (no != NULL) printf("%s - %d\n", no->str, no->cont);

    return 0;
}