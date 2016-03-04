#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"

#define NSTRINGS 3

int main() {
    vetor *v;
    char str[100];
    int i, pos;
    v = vetor_novo();

    while (1) {
        for (i = 0; i < NSTRINGS; i++) {
            printf("[%d] ", i + 1);
            if (vetor_elemento(v, i) == NULL)
                printf("(vazio)\n");
            else
                printf("%s\n", vetor_elemento(v, i));
        }

        do {
            printf("Posicao para nova string (1 a %d): ", NSTRINGS);
            scanf("%d", &pos);
            getchar(); /* elimina \n */
        }
        while (pos < 0 || pos > NSTRINGS);

        if (pos == 0)
            break;

        printf("Nova String: ");
        fgets(str, 80, stdin);
        str[strlen(str) - 1] = '\0';

        vetor_insere(v, str, i);
        vetor_apaga(v);
    }
    return 0;
}
