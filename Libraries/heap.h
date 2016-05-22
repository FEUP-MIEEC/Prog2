/*****************************************************************/
/*   Fila de prioridade / min-heap | PROG2 | MIEEC | 2015/16     */      
/*****************************************************************/

#ifndef HEAP_H
#define HEAP_H

typedef struct {
	int prioridade;
	char * valor;
} elemento;

typedef struct {
	/* numero de elementos no vetor */
	int tamanho_atual;
	/* tamanho maximo do vetor */
	int tamanho_maximo;

	/* vetor de apontadores para elementos */
	elemento ** elementos;
} heap;

/* cria nova heap */
heap* heap_nova(int tamanho_maximo);

/* apaga heap */
void heap_apaga(heap *h);

/* insere elemento na heap com uma determinada prioridade */
int heap_insere(heap *h, const char * texto, int prioridade);

/* remove elemento na raiz da heap */
char * heap_remove(heap *h);

/* imprime o estado actual da heap, a partir do indice indicado */
void mostraHeap(heap *h, int indice);

#endif /* HEAP_H */