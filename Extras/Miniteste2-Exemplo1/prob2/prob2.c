#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "grafo.h"
#include "heap.h"

int proximas_n_chegadas(lista *tempos, lista *origens, lista *aeroportos, int n) {
    /* prob 2.1 - a implementar */
    int i, j;
    elemento *t;
    elemento *o;
    elemento *a;
    elemento *e;

    heap *ep = heap_nova(25);
	for (t = tempos->inicio, o = origens->inicio, a = aeroportos->inicio;
         a != NULL && o != NULL && t != NULL;
		 t = t->proximo, o = o->proximo, a = a->proximo) {
			 heap_insere(ep, o->str , atoi(t->str));
    }
    for (i = 0; i < n; i++) {
		e = aeroportos->inicio;
		for(j=0; j<atoi(ep->elementos[i]->valor);j++){
			e=e->proximo;
		}
        printf("%d: %s\n", i+1, e->str);
    }
    return 1;
}

lista *pesquisa_destinos(grafo *rotas, lista *aeroportos, const char *origem) {
    /* prob 2.2 - a implementar */
    int i=0, j;
	vetor *v;
	elemento *e;
	lista *l= lista_nova();
	for(e=aeroportos->inicio;e!=NULL&& strcmp(e->str, origem);e=e->proximo){
			i++;
	}
	v = v_sucessores(rotas, i);
	for(i=0;i<v->tamanho;i++){
		e = aeroportos->inicio;
		for(j=0; j<vetor_elemento(v, i);j++){
			e=e->proximo;
		}
		lista_insere(l, e->str, NULL);
	}
    return l;
}

/* Aqui começa o código de teste. Não modificar! */

grafo *carrega_rotas(lista *aeroportos, const char *filename) {
    if (!filename) return NULL;
    grafo *g = NULL;
    FILE *f;
    int origem, destino;
    f = fopen(filename, "r");
    if (!f) {
        printf("Erro na leitura do ficheiro: %s\n", filename);
        return NULL;
    }
    g = grafo_novo(lista_tamanho(aeroportos), NAODIRECIONADO);
    if (!g) {
        printf("Erro na criacao do grafo\n");
        return NULL;
    }
    while (fscanf(f, "%d\t%d", &origem, &destino) == 2) {
        grafo_adiciona(g, origem, destino);
    }
    fclose(f);
    return g;
}

int main() {
    FILE *f;
    grafo *g = NULL;
    lista *aeroportos;
    char *buff;
    size_t n;

    setvbuf(stdout, NULL, _IONBF, 0);
    f = fopen("aeroportos.txt", "r");
    aeroportos = lista_nova();
    buff = NULL;
    n = 0;
    while (getline(&buff, &n, f) != -1) {
        buff[strlen(buff) - 1] = '\0';
        lista_insere(aeroportos, buff, NULL);
    }
    free(buff);
    fclose(f);

    g = carrega_rotas(aeroportos, "rotas.txt");

    /* teste problema 2.1 */
    {
        FILE *f;
        char tempo[5], origem[10];
        lista *tempos, *origens;

        printf("* Problema 2.1 *\n");

        f = fopen("chegadas.txt", "r");
        tempos = lista_nova();
        origens = lista_nova();

        while (fscanf(f, "%s\t%s", tempo, origem) == 2) {
            lista_insere(tempos, tempo, NULL);
            lista_insere(origens, origem, NULL);
        }

        if (proximas_n_chegadas(tempos, origens, aeroportos, 5) != 1)
            printf("Erro ao executar a funcao\n");

        lista_apaga(tempos);
        lista_apaga(origens);
        fclose(f);
    }

    /* teste problema 2.2 */
    {
        printf("\n* Problema 2.2 *\n");
        const char *origem = "Lille (FR)";
        elemento *elem;
        lista *l = pesquisa_destinos(g, aeroportos, origem);
        if (l == NULL)
            printf("Destinos diretos a partir de %s = 0\n", origem);
        else {
            printf("Destinos diretos a partir de %s = %d\n",
                   origem, lista_tamanho(l));
            for (elem = l->inicio; elem != NULL; elem = elem->proximo)
                printf("%s\n", elem->str);
            lista_apaga(l);
        }
    }

    grafo_apaga(g);
    lista_apaga(aeroportos);
    return 0;
}
