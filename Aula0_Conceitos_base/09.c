#include <stdio.h>
#include <string.h>

#define NALBUNS 100

typedef struct {
    char artista[100];
    char titulo[100];
    int ano;
    int formato; /* 1=vinil, 2=cd, 3=dvd */
} item;

int ler_albuns(item coleccao[]) {
    int i = 0;
    char tmp[15] = {};
    while (scanf("%s %s %s %d %d", coleccao[i].artista, tmp, coleccao[i].titulo, &coleccao[i].ano,
                 &coleccao[i].formato) == 5 && i < NALBUNS) {
        strcat(coleccao[i].artista, " ");
        strcat(coleccao[i].artista, tmp);
        i++;
    }
    return i;
}

void lista_albuns(item coleccao[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s %d %d\n", coleccao[i].artista, coleccao[i].titulo, coleccao[i].ano,
               coleccao[i].formato);
    }
}

int albuns_artista(item coleccao[], int n, char artista[], int formato) {
    int i, x = 0;
    if (formato == 0) {
        for (i = 0; i < n; i++) {
            if (strcmp(artista, coleccao[i].artista) == 0) {
                x++;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (strcmp(artista, coleccao[i].artista) == 0 && formato == coleccao[i].formato) {
                x++;
            }
        }
    }
    return x;
}

int main() {
    int n;
    item colecao[NALBUNS];
    n = ler_albuns(colecao);
    lista_albuns(colecao, n);
    printf("Lista carregada com %d albuns.\n", n);
    printf("Existem %d albuns em vinil do artista Sergio Godinho.\n", albuns_artista(colecao, n, "Sergio Godinho", 1));
    printf("Existem %d albuns no total do artista Sergio Godinho.\n", albuns_artista(colecao, n, "Sergio Godinho", 0));
    return 0;
}