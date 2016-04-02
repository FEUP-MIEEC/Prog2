#include "vetor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void skipC(FILE *f, char c) {
    while (getc(f) == (int) c);
    fseek(f, -1, SEEK_CUR);
}

void readFile(char *filename, vetor *vec) {
    int votes, year;
    float rank;
    char aux[200], c;
    FILE *file;

    file = fopen(filename, "r");
    while (fgetc(file) != EOF) {
        fseek(file, 16, SEEK_CUR);
        /*A coluna 'New distribution' tem 16 carateres
            Opcionalemnte podiamos fazer fscanf de um inteiro e desprezar o valor obtido.*/

        fscanf(file, "%d", &votes); /* Ler numero de votos */
        fscanf(file, "%f", &rank); /*Obter rank*/

        fseek(file, 2, SEEK_CUR); /*Avançar dois carateres, corresponde aos dois espaços entre Rank e Title*/

        fgets(aux, 200, file); /* Ler o título inclusive o ano: (yyyy)*/

        /*
            *Obtem um apontador para a última ocorrência de um espaço
                que corresponde ao espaço entre título e ano <title> <year>
            *Substituimos o espaço pelo carater Nulo. É uma forma de remover
                o ano da string, que queremos que seja apenas o título do filme
        */
        char *ptr = rindex(aux, (int) ' ');
        *ptr = '\0';

        /*
            Deslocamos a posição atual 7 carateres para trás
            Nota: Ao fazer fgets, a posição atual corresponde ao '\n'
            Então, os 7 carateres equivalem a: (yyyy)\n
            De seguida podemos ler o ano
        */
        fseek(file, -7, SEEK_CUR);
        fscanf(file, "%d", &year);

        /*
            A posição atual corresponde ao carater ), após efetuado o fscanf()
            Em todas as linhas, exceto a última, verifica-se a seguinte sequência: )\r\n
            Vamos deslocar dois carateres para a frente
                ->Se o próximo é \n, signnifica que teremos mais elementos (filmes)
                ->Se não, é o fim do ficheiro, podemos parar o ciclo

            TODO: A condição do fgetc() no while não está a funcionar devidamente, a última linha é lida duas vezes sem
                o If abaixo; why??
        */
        fseek(file, 2, SEEK_CUR);
        vetor_insere(vec, aux, votes, rank, year, vec->tamanho);
        if (fgetc(file) != (int) '\n')
            break;
    }

    fclose(file);
}

void printArray(vetor *vec) {
    if (vec == NULL || vec->tamanho == 0)
        return;

    for (int i = 0; i < vec->tamanho; ++i) {
        elemento el = vec->elementos[i];
        printf("Votes:%d\tRank:%.1f\tYear:%d\tTitle:", el.votes, el.rank, el.year);
        puts(el.title);
    }
}

int main() {
    vetor *v = vetor_novo();
    vetor *results;
    readFile("IMDB.txt", v);

    /* Leitura e preenchimento do vetor de filmes */
    printf("[INICIO] TESTAR LEITURA DO FICHEIRO\n");
    printArray(v);
    printf("[FIM] TESTAR LEITURA DO FICHEIRO\n");

    /* Ordenação */
    printf("[INICIO] ORDENAR O VETOR ALFABETICAMENTE\n");
    if (!vetor_ordena(v))
        printArray(v);
    else {
        printf("Ocorreu um erro\n");
        return -1;
    }
    printf("[FIM] ORDENAR O VETOR ALFABETICAMENTE\n");
    //
    //
    printf("[INICIO] ORDENAR O VETOR TENDO EM CONTA O 'ANO' (ORDEM CRESCENTE)\n");
    if (!vetor_ordena_ano(v))
        printArray(v);
    else {
        printf("Ocorreu um erro\n");
        return -1;
    }
    printf("[FIM] ORDENAR O VETOR TENDO EM CONTA O 'ANO' (ORDEM CRESCENTE)\n");

    printf("[INICIO] PESQUISAR E CRIAR VETOR COM TODOS OS FILMES DO ANO YYYY\n");
    results = vetor_pesquisa_ano(v, 100);
    if (results->tamanho == 0)
        printf("Não foram encontrandas correspondências\n");
    else
        printArray(results);
    printf("[FIM] PESQUISAR E CRIAR VETOR COM TODOS OS FILMES DO ANO YYYY\n");

    vetor_apaga(v);
    vetor_apaga(results);
}


