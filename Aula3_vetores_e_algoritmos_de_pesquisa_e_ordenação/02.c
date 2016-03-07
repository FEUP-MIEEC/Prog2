#include <stdio.h>
#include <string.h>

/*
  Este exercício tem como objetivo desenvolver algoritmos genéricos de
  ordenação e pesquisa em vetores.  Os algoritmos deverão ser
  genéricos tanto no tipo de dados que ordenam tal como na ordem que
  aplicam aos dados (ex., ordem ascendente, descendente, etc..).
  Estes algoritmo irão, de certa forma, replicar o comportamento das
  funções "qsort", "lsearch" e "bsearch" da stdlib (man 3 qsort lsearch bsearch).

  Para atingir este fim, iremos declarar um tipo "comp" que representa
  um apontador para uma função de comparação.

  Uma função que implemente esta assinatura deverá retornar:
  - -1 se a < b
  - 0 se a == b
  - 1 se a > b
*/

typedef int (*comp)(const void * a, const void * b);

/*
  A função de comparação que se segue exemplifica a comparação de ints
  de forma ascendente:
*/

int comp_int_asc(const void * a, const void * b){
    int a_tmp = *((int*) a);
    int b_tmp = *((int*) b);

    if(b_tmp > a_tmp)
        return -1;
    if(a_tmp > b_tmp)
        return 1;
    return 0;
}

/*
  Note que o primeiro passo nesta função é fazer a conversão de
  apontadores genéricos (void *) para o tipo de apontador pretendido
  (neste caso, int *).  De seguida, é feita a comparação entre os
  valores de forma a atingir a ordenação pretendida.

  Note também que os argumentos "a" e "b", tem o tipo "const void *",
  o que significa que estes não podem ser alterados dentro da função
  de comparação. Em geral, sempre que um argumento de uma função é
  declarado como "const", significa que é um argumento só de leitura
  (ver por exemplo "man 3 strcpy").
*/



/*
  A função de ordenação genérica deverá receber com argumentos as seguintes variáveis:
  - ptr: apontador para o inicio do vetor
  - size: numero de elementos no vetor
  - elem_size: espaço de memoria ocupado por cada elemento do vetor
  - order: apontador para uma função de ordenação
*/

void sort(void * ptr, int size, int elem_size, comp order);

/*
  Para utilizar esta função para ordenar um vetor de ints de forma
  ascendente poderia-se utilizar a seguinte instrução:

  int vec [] = {3,2,4,5,9,1};
  int size = 6;
  sort(vec, size, sizeof(int), comp_int_asc);

  Relembre que os apontadores genéricos não tem a noção do tamanho do
  tipo para o qual apontam.  Para facilitar o processo de aceder aos
  elementos do vetor, deverá utilizar as seguintes funções:
*/

void * get_elem(void * ptr, int n, int elem_size) {
    return ((char*)ptr) + n * elem_size;
}

void swap(void * ptr_a, void * ptr_b, int elem_size) {
    for(int i = 0; i < elem_size; i++) {
        char tmp = ((char*)ptr_a)[i];
        ((char *)ptr_a)[i] = ((char*)ptr_b)[i];
        ((char *)ptr_b)[i] = tmp;
    }
}

/*
  Para aceder à posição "n" de um vetor deverá utilizar a seguinte instrução:

  void * elem = get_elem(ptr, n, elem_size);

  Para trocar dois elementos de posição deverá utilizar a seguinte instrução:

  void * elem1 = get_elem(ptr, n, elem_size);
  void * elem2 = get_elem(ptr, n+1, elem_size);

  swap(elem1, elem2, elem_size);
*/



/*
  A função que se segue exemplifica um possível algoritmo de
  ordenação:
*/

void sort(void * ptr, int size, int elem_size, comp order) {
    for(int i = 0; i < size; i++) {
        void * cur_ptr = get_elem(ptr, i, elem_size);
        void * swap_ptr = cur_ptr;

        for(int j = i+1; j < size; j++) {
            void * tmp_ptr = get_elem(ptr, j, elem_size);

            if(order(tmp_ptr, swap_ptr) < 0)
                swap_ptr = tmp_ptr;
        }

        swap(swap_ptr, cur_ptr, elem_size);
    }
}



/*
   Ex 1: Implemente um algoritmo de pesquisa linear. Esta função
   deverá retornar um apontador para o elemento no vetor caso esteja
   presente, ou NULL caso contrário.
*/

void * linear_search(const void * elem, const void * ptr, int size, int elem_size, comp order) {
    return NULL;
}

/*
   Ex 2: Implemente um algoritmo de pesquisa binária.  Esta função
   deverá retornar um apontador para o elemento no vetor caso esteja
   presente, ou NULL caso contrário.
*/

void * binary_search(const void * elem, const void * ptr, int size, int elem_size, comp order) {
    return NULL;
}

/*
  Ex 3: Implemente o algoritmo de ordenação por inserção.
*/

void insertion_sort(void * ptr, int size, int elem_size, comp order) {

}

/*
   Ex 4: Implemente uma função de comparação para "char" que ordene
   os elementos de forma descendente e posicione letras minúsculas
   antes das maiúsculas (eg: "AzbB" -> "zbBA"). Assuma que só existem
   caracteres alfabéticos (A->Z e a->z).
*/

int comp_char_desc(const void * a, const void * b){
    char a_tmp = *((char*) a);
    char b_tmp = *((char*) b);
    return 0;
}

#define SIZE 6

int main()
{
    int vec [SIZE] = {3,-2,4,5,9,1};
    int tmp [SIZE];

    memcpy(tmp, vec, SIZE * sizeof(int));

    puts("-- Exemplo --");
    printf("Antes:");
    for(int i = 0; i < SIZE; i++) printf(" %d", tmp[i]);
    puts("");

    sort(tmp, SIZE, sizeof(int), comp_int_asc);

    printf("Depois:");
    for(int i = 0; i < SIZE; i++) printf(" %d", tmp[i]);
    puts("");

    memcpy(tmp, vec, SIZE * sizeof(int));

    puts("-- Ex1 --");
    int num = 4;
    void * elem = linear_search(&num, tmp, SIZE, sizeof(int), comp_int_asc);

    if(elem) {
        printf("Elemento %d contido na posicao %ld do vetor\n", num, ((int*)elem) - tmp);
    }
    else {
        printf("Elemento %d nao contido no vetor\n", num);
    }

    memcpy(tmp, vec, SIZE * sizeof(int));
    sort(tmp, SIZE, sizeof(int), comp_int_asc);

    puts("-- Ex2 --");
    elem = binary_search(&num, tmp, SIZE, sizeof(int), comp_int_asc);

    if(elem) {
        printf("Elemento %d contido na posicao %ld do vetor\n", num, ((int*)elem) - tmp);
    }
    else {
        printf("Elemento %d nao contido no vetor\n", num);
    }

    memcpy(tmp, vec, SIZE * sizeof(int));

    puts("-- Ex3 --");
    printf("Antes:");
    for(int i = 0; i < SIZE; i++) printf(" %d", tmp[i]);
    puts("");

    insertion_sort(tmp, SIZE, sizeof(int), comp_int_asc);

    printf("Depois:");
    for(int i = 0; i < SIZE; i++) printf(" %d", tmp[i]);
    puts("");

    puts("-- Ex4 --");

    char str[] = "AbZa";

    printf("Antes:");
    puts(str);

    sort(str, strlen(str), sizeof(char), comp_char_desc);

    printf("Depois:");
    puts(str);

}