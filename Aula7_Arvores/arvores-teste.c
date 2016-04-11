#include <stdio.h>
#include "bst.h"

int main() {
    char c[10] = {'G', 'C', 'A', 'F', 'L', 'J', 'V', 'M', 'N', 'O'};
    int i;
    arvore_bst *a = bst_nova();
    for (i = 0; i < 10; i++) {
        bst_insere(a, &c[i]);
    }
    printf("%d", bst_altura(a->raiz));
}