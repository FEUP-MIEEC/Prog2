#include <stdio.h>
#include <string.h>

int lerpontuacoes(char clubes[][50], int pontos[]) {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d", clubes[i], &pontos[i]);
    }
    return n;
}

void primeiroUltimo(char clubes[][50], int pontos[], int n, char primeiro[50], char ultimo[50]) {
    int i, max = pontos[0], min = pontos[0];
    for (i = 1; i < n; i++) {
        if (pontos[i] > max) {
            max = pontos[i];
            strcpy(primeiro, clubes[i]);
        }
        if (pontos[i] < min) {
            min = pontos[i];
            strcpy(ultimo, clubes[i]);
        }
    }
}

int main() {
    int n, pontos[20] = {};
    char clubes[20][50] = {}, primeiro[50] = {}, ultimo[50] = {};
    n = lerpontuacoes(clubes, pontos);
    primeiroUltimo(clubes, pontos, n, primeiro, ultimo);
    printf("Classificacao de %d Clubes\n", n);
    printf("Campeao: %s\n", primeiro);
    printf("Ultimo classificado: %s\n", ultimo);
    return 0;
}