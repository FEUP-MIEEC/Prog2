#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "grafo.h"
#include "heap.h"

int proximas_n_chegadas(lista *tempos, lista *origens, lista *aeroportos, int n) {
    /* prob 2.1 - a implementar */
    /* _1_> Alocar memória para lista de aeroportos. */
	elemento *a=aeroportos->inicio; int i=0;
	char** aero = malloc(sizeof(char**)*aeroportos->tamanho);
	while(a!=NULL){	
		aero[i]=malloc(sizeof(char*)*50);
		strcpy(aero[i], a->str);
		a=a->proximo;
		i++;
	}
	
	/* FIM _1_ */
	
	/* _2_> Inserir na Heap */
	
	heap* heapvoos=heap_nova(tempos->tamanho);
	elemento* tempo=tempos->inicio;
	elemento* orig=origens->inicio;
	while(tempo!=NULL){
		heap_insere(heapvoos, aero[atoi(orig->str)], atoi(tempo->str));
		tempo=tempo->proximo;
		orig=orig->proximo;
	}
	
	// Libertar memória já não necessária
	for(i=0; i<aeroportos->tamanho; i++){
		free(aero[i]);
	}
	free(aero);
	
	/* FIM _2_*/
	
	/* _3_> Retirar da Heap */
	
	for (int i = 0; i < n; ++i)
    {
        char * str;
        printf("[%d]: %s\n", i+1, str = heap_remove(heapvoos));
        free(str);
    }
	
    heap_apaga(heapvoos);	
	/* FIM _3_*/
	
	
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

    vetor_apaga(v);
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
