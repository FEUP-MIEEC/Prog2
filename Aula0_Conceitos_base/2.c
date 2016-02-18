#include <stdio.h>

int main() {
    int i, j, v1[5] = {}, v2[5] = {};

    printf("Vetor 1:\n");
    for (i = 0; i < 5; i++) {
        printf("Introduza %d numero: ", i + 1);
        scanf("%d", &v1[i]);
    }

    printf("Vetor 2:\n");
    for (i = 0; i < 5; i++) {
        printf("Introduza %d numero: ", i + 1);
        scanf("%d", &v2[i]);
    }

    printf("\n");

    printf("Comuns:");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (v1[i] == v2[j]) {
                printf(" %d", v1[i]);
            }
        }
    }
    printf("\n");
    return 0;
}