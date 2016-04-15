/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2015/16          */
/*****************************************************************/
/*                  NAO ALTERAR ESTE FICHEIRO                    */
/*****************************************************************/

#ifndef VETOR_H


/**
 * registo para armazenar cada elemento (apenas um inteiro neste caso)
*/
typedef struct
{
    int val;
} elemento_vetor;

/**
* este registo contem um vetor de elementos, um contador do tamanho e outro para a capacidade
*/
typedef struct
{
	/** numero de elementos do vetor */
	int tamanho;
    
    /** capacidade do vetor */
    int capacidade;
	
    /** array de elementos armazenados */
	elemento_vetor* elementos;
    
} vetor;

/** 
 *  cria um novo vetor com tamanho 0 e capacidade 0
 *  retorno: apontador para o vetor criado
 *  nota: se vetor nao foi criado retorna NULL
 */
vetor* vetor_novo();

/** 
 *  elimina um vetor, libertando toda a memoria ocupada
 *  parametro: vec apontador para vetor
 *  nota: se vec = NULL retorna sem fazer nada
 */
void vetor_apaga(vetor *vec);

/**
 *  indica o o numero de elementos do vetor
 *  parametro: vec apontador para vetor
 *  retorno: -1 se ocorrer algum erro ou numero de elementos do vetor
 */
int vetor_tamanho(vetor *vec);

/** 
 *  retorna o elemento armazenado na posicao especificada
 *  parametro: vec apontador para vetor
 *  parametro: pos indice do elemento
 *  retorno: inteiro na posicao correspondente
 *  nota: se ocorrer algum erro retorna NULL (p.ex. se valor pos indicar uma posicao invalida)
 */
int vetor_elemento(vetor *vec, int pos);

/**
 *  insere um elemento na posicao especificada
 *  parametro: vec apontador para vetor
 *  parametro: valor a inserir
 *  parametro: pos indice do elemento onde se pretende inserir a string, se pos=tamanho ou pos=-1 insere no fim do vetor
 *  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou o valor de pos se bem sucedido
 *  nota: se a capacidade nao for suficiente para guardar novo elemento, devera ser aumentada para 2x em relacao a capacidade anterior; inicialmente aumenta para capacidade 1
 */
int vetor_insere(vetor *vec, int valor, int pos);

/**
 *  remove o elemento da posicao especificada
 *  parametro: vec apontador para vetor
 *  parametro: pos posicao
 *  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou 0 se bem sucedido
 */
int vetor_remove(vetor* vec, int pos);

/** 
 *  atribui o valor especificado a uma posicao 
 *  parametro: vec apontador para vetor
 *  parametro: pos posicao onde colocar elemento
 *  parametro: val valor pretendido
 *  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou pos se bem sucedido 
 */
int vetor_atribui(vetor *vec, int pos, int val);

/**
 *  devolve a posicao do elemento especificado
 *  parametro: vec apontador para vetor
 *  parametro: val valor pretendido
 *  retorno: posicao do elemento ou -1 se ocorrer algum erro ou nao encontrar elemento
 */
int vetor_pesquisa(vetor *vec, int val);

/**
 *  ordena um vetor por ordem crescente
 *  parametro: vec apontador para vetor
 *  retorno: -1 se ocorrer um erro ou 0 se for bem sucedido  
 */
int vetor_ordena(vetor *vec);

#define VETOR_H
#endif
