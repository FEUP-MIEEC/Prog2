#include <stdio.h>
#include "pilha.h"
#include <string.h>

float calcula_total(char* expressao_rpn){
	int i;
	pilha *p = pilha_nova();
	for (i = 0; i<strlen(expressao_rpn)/2; i+=2)
	{
		float a, b;
		/*switch(expressao_rpn[i]){
			case '+':
			a = *pilha_top(p);
			pilha_pop(p);
			b = *pilha_top(p);
			pilha_pop(p);
			pilha_push(p, a+b);
			break;
			case '-':
			a = *pilha_top(p);
			pilha_pop(p);
			b = *pilha_top(p);
			pilha_pop(p);
			pilha_push(p, a-b);
			break;
			case '/':
			a = *pilha_top(p);
			pilha_pop(p);
			b = *pilha_top(p);
			pilha_pop(p);
			pilha_push(p, a/b);
			break;
			case '*':
			a = *pilha_top(p);
			pilha_pop(p);
			b = *pilha_top(p);
			pilha_pop(p);
			pilha_push(p, a*b);
			break;
			default:
			pilha_push(p, &expressao_rpn[i]);
			break;
		}*/
	}
	return pilha_top(p);
}

int main(){
	char s[50];
	printf("Expressão: ");
	scanf("%s", s);
	printf("Resultado: %f", calcula_total(s));
	return 0;
}