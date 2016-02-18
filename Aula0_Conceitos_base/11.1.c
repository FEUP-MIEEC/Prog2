#include <stdio.h>

int invert(int a) {
    int r = 0;
    while (a != 0) {
        r = r * 10;
        r = r + a % 10;
        a = a / 10;
    }
    return r;
}

int main() {
    int i, n, a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", invert(invert(a) + invert(b)));
    }
}