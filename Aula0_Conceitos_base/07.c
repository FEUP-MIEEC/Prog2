#include <stdio.h>

float media(float *notas, int n) {
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) {
        if (notas[i] >= 9.3 && notas[i] < 9.5) sum += 9.5;
        else sum += notas[i];
    }
    return sum / (float) n;
}

int lernotas(float *notas) {
    float nt, np;
    int i = 0;
    while (scanf("%f %f", &nt, &np) == 2) {
        notas[i] = (float) ((nt * 0.6) + (np * 0.4));
        i++;
    }
    return i;
}

int main() {
    float notas[100] = {0};
    int n = lernotas(notas);
    printf("A media das notas da turma foi %.2f\n", media(notas, n));
    return 0;
}