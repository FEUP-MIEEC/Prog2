#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char pais[50];
    char capital[50];
    int habitantes;
} capital;

capital *analisarFicheiro(FILE *ficheiro, int *num_capitais) {
    ficheiro = fopen("capitais.txt", "r");
    int i = 0;
    capital *c = malloc(sizeof(capital));
    while (fscanf(ficheiro, "%s %s %d", c[i].pais, c[i].capital, &c[i].habitantes) == 3) {
        c = realloc(c, sizeof(capital) * (i + 1));
        i++;
    }
    *num_capitais = i;
    fclose(ficheiro);
    return c;
}

void gerarRelatorio(char *nome_ficheiro, capital *resultados, int num_capitais) {
    int i;
    FILE *f;
    f = fopen(nome_ficheiro, "w");
    fprintf(f, "Capitais:\n");
    resultados = malloc(sizeof(capital));
    for (i = 0; i < num_capitais; i++) {
        resultados = realloc(resultados, sizeof(capital) * (i + 1));
        fprintf(f, "%d - %s - %s - %d", i, resultados[i].capital, resultados[i].pais, resultados[i].habitantes);
    }
    fclose(f);
}

int main() {
    int num_capitais = 0;
    capital *c;
    FILE *f;
    c = analisarFicheiro(f, &num_capitais);
    gerarRelatorio("relatorio.txt", c, num_capitais);
    return 0;
}