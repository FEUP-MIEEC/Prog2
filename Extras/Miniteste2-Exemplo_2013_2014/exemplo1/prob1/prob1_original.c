#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "tabdispersao.h"

pilha* fila_transforma(fila *f)
{
	/* problema 1.1 - a implementar */

	return NULL;
}

int pilha_remove(pilha *p, const char* string)
{	
	/* problema 1.2 - a implementar */

	return 0;
}

tabela_dispersao tabela_copia_todos(tabela_dispersao origem, hash_func * h)
{
	/* problema 1.3 - a implementar */
	return NULL;	

}

/*----------------------------------*/
/* nao alterar as restantes funcoes */

void imprime_pilha(pilha *p)
{
	pilhaItem* aux;
	
	if(p == NULL) return;
	
	aux = p->raiz;
	
	while(aux != NULL)
	{
		printf("%s ", aux->elemento);
		aux = aux->proximo;
	}
	puts("");
		
	return;
}

void imprime_fila(fila *f)
{
	filaItem* aux;
	
	if(f == NULL) return;
	
	aux = f->cabeca;
	
	while(aux != NULL)
	{
		printf("%s ", aux->string);
		aux = aux->proximo;
	}
	puts("");
		
	return;
}


/* teste problema 1.1 */
void teste_11()
{
	fila *f;
	pilha *p;

	f = fila_nova(10);
	
	fila_push(f, "F");
	fila_push(f, "R");
	fila_push(f, "O");
	fila_push(f, "G");

	printf("Fila: ");
	imprime_fila(f);

	p = fila_transforma(f);
	
	printf("Pilha: ");
	imprime_pilha(p);
	
	fila_apaga(&f);
	pilha_apaga(p);
}

/* teste problema 1.2 */
void teste_12()
{
	pilha *p;

	p = pilha_nova();
	pilha_push(p, "P4");
	pilha_push(p, "P3");
	pilha_push(p, "P1");
	pilha_push(p, "P3");
	pilha_push(p, "P2");
	pilha_push(p, "P1");
	
	printf("Antes de pilha_remove: ");
	imprime_pilha(p);

	pilha_remove(p, "P1");

	printf("Depois de pilha_remove: ");
	imprime_pilha(p);

	pilha_remove(p, "P3");

	printf("Depois de pilha_remove: ");
	imprime_pilha(p);

	pilha_apaga(p);
}

/* teste problema 1.3 */
#include <stdarg.h>
#define TAMANHO_VETOR_ELEMS	103

tabela_dispersao _tabela(hash_func *hfunc, ...)
{
	va_list argp;
	tabela_dispersao td;
	int hash_val;
	elemento * elem;

	td = (tabela_dispersao) malloc(sizeof(struct tab_dispersao));
	td->elementos = (elemento **) calloc(TAMANHO_VETOR_ELEMS,
			sizeof(elemento *));
	td->tamanho=TAMANHO_VETOR_ELEMS;
	td->hfunc = hfunc;
	va_start(argp, hfunc);
	hash_val = va_arg(argp, int);
	while (hash_val >= 0)
	{
		elem = (elemento *) malloc(sizeof(elemento));
		elem->obj = (objeto *) malloc(sizeof(objeto));

		strcpy(elem->obj->chave, va_arg(argp, char *));
		strcpy(elem->obj->valor, va_arg(argp, char *));
		elem->proximo = NULL;
		if (td->elementos[hash_val])
			elem->proximo = td->elementos[hash_val];
		td->elementos[hash_val] = elem;
		hash_val = va_arg(argp, int);
	}

	va_end(argp);

	return td;
}

int teste_13() {

	int i, erros;
	tabela_dispersao t, copia;
	char tmp[80];
	objeto obj;
	
	erros = 0;
	printf("tabela_copia_todos():\n"); fflush(stdout);

	t = _tabela(hash_djbm, -1);
	copia = tabela_copia_todos(t, hash_krm);

	if(copia==NULL) {
		printf("\ttabela nova nao foi criada.\n");
		erros++;
		return erros;
	}

	if (copia->tamanho != t->tamanho) {
		printf("\ttamanho da tabela original e copia nao coincidem.\n");
		erros++;
	}

	for (i = 0; i < 1000; i++) {
		sprintf(obj.chave, "%d", i*7);
		strcpy(obj.valor, obj.chave);
		tabela_adiciona(t, &obj);
	}

	if (copia->tamanho != t->tamanho) {
		printf("\ttamanho da tabela original e copia nao coincidem.\n");
		erros++;
	}

	tabela_apaga(copia);
	copia = tabela_copia_todos(t, hash_krm);
	for (i = 0; i < 1000; i++) {
		sprintf(tmp, "%d", i*7);
		if(!tabela_existe(copia, tmp)) {
			printf("\tO elemento %s nao foi copiado.\n", tmp);
			erros++;
		}
	}
	tabela_apaga(copia); /* This was missing */
	tabela_apaga(t); /* This was missing */

	if (!erros) {
		printf("\tsem erros.\n");
	}
	return erros;
}


int main()
{
	puts("* Teste 1.1 *");
	teste_11();
	puts("\n");
	puts("* Teste 1.2 *");
	teste_12();
	puts("\n");
	puts("* Teste 1.3 *");
	teste_13();

	return 0;
}

