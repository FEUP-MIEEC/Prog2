#include <stdio.h>

int in_array(int a, int *v, int len) {
    int i = 0;
    for (i = 0; i <= len; i++) {
        if (v[i] == a) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *f;
    int v_a[2] = {131, 163};
    int v_o[2] = {149, 181};
    int v_c[2] = {135, 167};
    f = fopen("enunciado/lusiadas-utf8.txt", "r");
    int c = 0;
    int freq[3] = {};
    char letras[3] = {'A', 'O', 'C'};
    int i;
    while (c != EOF) {
        c = getc(f);
        if (c == 195) {
            c = getc(f);
            if (in_array(c, v_a, sizeof(v_a) / sizeof(int))) {
                freq[0]++;
            } else if (in_array(c, v_o, sizeof(v_o) / sizeof(int))) {
                freq[1]++;
            } else if (in_array(c, v_c, sizeof(v_c) / sizeof(int))) {
                freq[2]++;
            }
        }
    };
    int nl = i;
    fclose(f);
    for (i = 0; i < 2; i++) { // Neste caso apenas são dois, mas é uma boa prática fazê-lo
        printf("Letra %c com til = %d\n", letras[i], freq[i]);
    }
    printf("Letra %c com cedilha = %d\n", letras[i], freq[2]);
}
