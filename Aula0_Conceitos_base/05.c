#include <stdio.h>
#include <string.h>

#define M 100

void inverte(char *strOriginal, char *strInvertida) {
    int i;
    for (i = 0; i < strlen(strOriginal); i++) {
        strInvertida[i] = strOriginal[strlen(strOriginal) - i - 1];
    }
}

int main() {
    char strOriginal[M] = {}, strInvertida[M] = {};

    while (1) {
        printf("Palavra? ");
        scanf("%s", strOriginal);

        if (strcmp(strOriginal, ".") == 0) return 0;
        inverte(strOriginal, strInvertida);
        if (strcmp(strOriginal, strInvertida) == 0) {
            printf("Resultado : %s e capicua\n", strOriginal);
        } else {
            printf("Resultado : %s nao e capicua\n", strOriginal);
        }
    }
}
