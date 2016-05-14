#include <stdio.h>

int main() {
    float i, imax, inc, a;

    printf("Qual o valor de a? ");
    scanf("%f", &a);
    printf("Qual o intervalo? ");
    scanf("%f", &i);
    scanf("%f", &imax);
    printf("Qual o incremento? ");
    scanf("%f", &inc);

    for (i = 0; i <= imax; i += inc) {
        printf("f(%.1f)=%.1f\n", i, a * i * i);
    }
    return 0;
}