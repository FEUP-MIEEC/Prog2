#include <stdio.h>
#include <stdlib.h>

void PrintArray(int * array, int N);
int main()
{
	int n, par = 0, impar = 0;
	int * v, * vpar, * vimpar;
	
	printf("Numero de elementos: ");
	scanf("%d", &n);

	v = malloc(sizeof(int) * n);
	vpar = malloc(sizeof(int) * n);
	vimpar = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		printf("Introduza o %dº elemento: ", i + 1);
		scanf("%d", &v[i]);
		if (v[i] % 2)
		{
			vimpar[impar] = v[i];
			++impar;
			
		}
		else
		{
			vpar[par] = v[i];
			++par;
		}
	}

	vpar = realloc(vpar, sizeof(int) * par); /* Libertar memória */
	vimpar = realloc(vimpar, sizeof(int) * impar); /* Libertar memória */

	printf("Vetor Original: "); PrintArray(v, n);
	printf("Numeros pares: "); PrintArray(vpar, par);
	printf("Numeros impares: "); PrintArray(vimpar, impar);

	free(v);
	free(vpar);
	free(vimpar);
}

void PrintArray(int * array, int N)
{
	printf("[");
	for (int i = 0; i < N; ++i)
	{
		printf(" %d", array[i]);
	}
	printf(" ]\n");
}
