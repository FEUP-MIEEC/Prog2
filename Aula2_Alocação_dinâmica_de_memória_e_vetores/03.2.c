#include "vetor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void imprime(vetor* v){
	int i;
	for(i=0;i<5;i++){
		printf("A %d string guardada é: %s\n", i+1,  vetor_elemento(v, i));
	}
}

int main(){
	int i;
	char a[100];
	vetor *v;
	v=vetor_novo();

	for(i=0;i<5;i++){
		printf("Insira a %d string", i+1);
		fgets(a, 100, stdin);
		a[strlen(a) - 1] = '\0';
		vetor_insere(v, a, i);
	}
	imprime(v);
	printf("Intruduza a string a eliminar: ");
	scanf("%s", a);
	if(vetor_remove(v, vetor_pesquisa(v, a))!=0) printf("String não encontrada\n");
	else imprime(v);
	if(vetor_ordena(v)!=0) printf("Não foi possivel ordenar o vetor");
	printf("Vetor ordenado:\n");
	imprime(v);
	return 0;
}
