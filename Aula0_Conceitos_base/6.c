#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char c, *max, *p;
    int n = 0, l = 0, i = 0;
    printf("Frase? ");
    max = (char *) malloc(sizeof(char));
    p = (char *) malloc(sizeof(char));
    while (scanf("%c", &c) == 1) {
        if (c == ' ' || c == '\n') {
            if (strlen(p) > strlen(max)) {
                max = (char *) realloc(max, sizeof(char) * strlen(p));
                strcpy(max, p);
            }
            n++;
            i = 0;
            if (c == '\n') break;
        }
        else {
            p = (char *) realloc(p, sizeof(char) * (i + 1));
            p[i] = c;
            l++;
            i++;
        }
    }
    printf("Numero de palavras: %d\n", n);
    printf("Palavra maior: %s\n", max);
    printf("Comprimento medio: %.1f\n", (float) l / (float) n);
    return 0;
}