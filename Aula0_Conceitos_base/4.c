#include <stdio.h>
#include <stdlib.h>

int ordenado(int src[], int n) {
    int i, a = src[0];
    for (i = 1; i < n; i++) {
        if (src[i] < a) {
            return 0;
        }
        a = src[i];
    }
    return 1;
}

int main() {
    int i, *src, n;
    printf("Introduza o número de numeros: ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So sao permitidas sequencias ate 100 numeros");
        n = 100;
    }
    src = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        printf("Introduza o %d numero: ", i + 1);
        scanf("%d", &src[i]);
    }

    if (ordenado(src, n)) {
        printf("\nO vetor esta ordenado!\nElementos do vetor por ordem decrescente\n{");
        for (i = n - 1; i > 0; i--) {
            printf("%d,", src[i]);
        }
        printf("%d}\n", src[i]);
    } else {
        printf("\nO vetor não esta ordenado\n");
    }
    return 0;
}
