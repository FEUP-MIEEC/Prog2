#ifndef vetor_H_
#define vetor_H_

/**
 * Estrutura que guarda um elemento de um vetor. Cada elemento contém uma string e uma prioridade (inteiro)
 */
typedef struct {
	int prioridade;
	char * valor;
} elemento;

/**
 * Estrutura que guarda dados relativos a um vetor de elementos.
 */
typedef struct {
	/* este campo diz o número de elementos correntemente no vetor */
	int tamanho_actual;
	/* este campo indica o tamanho maximo do vetor */
	int tamanho_maximo;

	/* vetor de apontadores para elementos */
	elemento ** elementos;
} vetor;

/**
 * variavel global (inicializada em vetor.c) que contabiliza o numero de vezes que maior_que é chamado
 */
extern int ncomparacoes;

/**
 * esta funcao cria um vetor vazio com o tamanho maximo especificado
 */
vetor * vetor_cria(int tamanho_maximo);

/**
 * esta funcao cria um vetor vazio com o tamanho maximo especificado + 1
 * para que os indices do heap comecem em 1
 */
vetor * vetor_criaHeap(int tamanho_maximo);

/**
 * esta funcao cria um elemento com o valor e prioridade especificados
 */
elemento * elemento_cria(int prioridade, const char * valor);

/**
 * esta funcao imprime o vetor passado como argumento no ecra
 */
void vetor_imprime(vetor * v);

/**
 * esta funcao imprime o heap passado como argumento no ecra
 */
void vetor_imprimeHeap(vetor * v);

/**
 * esta funcao retorna 1 caso o elemento e1 tenha prioridade maior que e2 ou 0 em qualquer dos outros casos (igual ou menor)
 */
int maior_que(elemento * e1, elemento * e2);


/**
 * esta funcao retorna 1 caso o elemento e1 tenha um valor "alfabeticamente superior" e2 ou 0 em qualquer dos outros casos (igual ou menor)
 */
int maior_que_HeapSort(elemento * e1, elemento * e2);



#endif /* vetor_H_ */
