#include <malloc.h>
#include <stdio.h>

int main() {
    int n, i;
    int begin, end;
    while (1) {
        scanf("%d", &n);
        if (!n) exit(0);
        int *b = malloc(sizeof(int) * (2 * n));
        begin = 0;
        end = n - 1;
        for (i = 0; i < n; ++i)
            b[i] = i + 1;
        int m = n;
        printf("Discarded cards: ");
        while (m > 2) {
            printf("%d, ", b[begin]);
            begin++;
            end++;
            b[end] = b[begin];
            begin++;
            m--;
        }
        printf("%d", b[begin++]);
        printf("\nRemaining card: ");
        printf("%d\n\n", b[begin]);
    }
}