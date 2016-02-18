#include <stdio.h>

float avg(float x[]) {
    int i;
    float sum = 0;
    for (i = 0; i < 10; i++) {
        sum += x[i];
    }
    return sum / 10;
}

float max(float x[]) {
    int i;
    float max = x[0];
    for (i = 1; i < 10; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;
}

float min(float x[]) {
    int i;
    float min = x[0];
    for (i = 1; i < 10; i++) {
        if (x[i] < min) {
            min = x[i];
        }
    }
    return min;
}

int main() {
    int i;
    float x[10];

    for (i = 0; i < 10; i++) {
        printf("Introduza o %d numero: ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("Media: %.2f\n", avg(x));
    printf("Maximo: %.1f\n", max(x));
    printf("Minimo: %.1f\n", min(x));

    printf("Vetor:");
    for (i = 0; i < 10; i++) {
        printf(" %.1f", x[i]);
    }
    printf("\n");
    return 0;
}