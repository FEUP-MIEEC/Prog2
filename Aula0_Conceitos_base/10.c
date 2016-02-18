#include <stdio.h>

#define NTODOS 100
#define NCHARS 30

typedef struct {
    char nome[NCHARS];
    char tipo[NCHARS];
    int duracao;
    int diaConclusao;
} tarefa;

int nova_tarefa(tarefa *nova) {
    if (scanf("%s %s %d %d", nova[0].nome, nova[0].tipo, &nova[0].duracao, &nova[0].diaConclusao) == 4) return 1;
    else return 0;
}

int ler_tarefas(tarefa lista[]) {
    int i = 0;
    while (nova_tarefa(&lista[i]) && i < NTODOS) {
        i++;
    }
    return i;
}

void lista_tarefas(tarefa lista[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s %d %d\n", lista[i].nome, lista[i].tipo, lista[i].duracao, lista[i].diaConclusao);
    }
}

float analisa_tarefas(tarefa lista[], int n, tarefa *maisLonga) {
    int i, sum = 0, max = 0;
    for (i = 0; i < n; i++) {
        sum += lista[i].duracao;
        if (lista[i].duracao > max) {
            max = lista[i].duracao;
            *maisLonga = lista[i];
        }
    }
    return (float) sum / i;
}

int main() {
    int n;
    tarefa lista[NTODOS], maisLonga;
    n = ler_tarefas(lista);
    lista_tarefas(lista, n);
    printf("Numero de tarefas lidas : %d\n", n);
    printf("Duracao media das tarefas : %.1f\n", analisa_tarefas(lista, n, &maisLonga));
    printf("Tarefa mais longa: %s\n", maisLonga.nome);

}