#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "tabdispersao.h"
#include <ctype.h>

// #include & #define
// functions and procedures

#define SUM_MAX 3000

void str_tolower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

void readdic(tabela_dispersao *tbl, FILE *wordlist, int size) {
    char str[TAMANHO_VALOR];
    while (fscanf(wordlist, "%s", str) == 1) {
        str_tolower(str);
        tabela_adiciona(tbl, str, "55");
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *wordlist;
    clock_t inicio, fim;
    double tempo;
    long int erros = 0, sugestoes = 0;

    if (argc != 3) {
        printf("utilização: %s <nome_ficheiro> <modo>\n", argv[0]);
        printf("modo: verboso ou silencioso\n");
        return 1;
    }

    // processa lista de palavras
    wordlist = fopen("wordlist.txt", "r");
    if (!wordlist) {
        printf("erro ao abrir ficheiro com lista de palavras\n");
        return 2;
    }
    // armazena lista de palavras em estrutura de dados adequada

    // processa ficheiro de entrada
    input = fopen(argv[1], "r");
    if (!input) {
        printf("erro ao abrir ficheiro %s\n", argv[1]);
        return 3;
    }

    if (!strcmp(argv[2], "verboso")) {
        inicio = clock();
        fseek(wordlist, 0, SEEK_END);
        tabela_dispersao *tbl = tabela_nova(ftell(wordlist) / 4, hash_djbm);
        rewind(wordlist);
        readdic(tbl, wordlist, 0);
        //mostraTabela(tbl);
        //printf("%s\nWord not found: %s\nPerhaps you meant: %s\n", sentence, str, similarwords(str));

        fim = clock();
    } else if (!strcmp(argv[2], "silencioso")) {
        inicio = clock();
        // processa e não apresenta qualquer output
        // guarda na variável erros o número de palavras com ortografia errada encontradas
        // guarda na variável sugestoes o número de palavras sugeridas para corrigir palavras com ortografia errada encontradas
        fim = clock();
    } else {
        printf("modo %s desconhecido\n", argv[2]);
        return 4;
    }

    tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na verificação (em segundos): %lf\n", tempo);
    printf("Número de palavras com ortografia errada encontradas: %li\n", erros);
    printf("Número de sugestões efetuadas: %li\n", sugestoes);

    fclose(input);
    fclose(wordlist);
    return 0;
}