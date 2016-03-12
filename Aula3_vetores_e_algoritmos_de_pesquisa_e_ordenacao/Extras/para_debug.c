
/////////////////////////  A  ///////////////////////////////////
/*
#include <stdio.h>

int main(){

	int i,j,n, v[5];

	for(i=0; i<=10;i++)
		for(j=-10;j<10;j++)
			v[i]=i/j;
}*/

/////////////////////////  B  ///////////////////////////////////

//Nota: quando introduz o indice 1, deve-se obter a vogal [a]
/*
#include <stdio.h>

char vogalindex(int idx){

	char vogal2;

	switch (idx)
	{
	case 1:
		vogal2='a';
            break;
	case 2:
		vogal2='e';
            break;
	case 3:
		vogal2='i';
            break;
	case 4:
		vogal2='o';
            break;
	case 5:
		vogal2='u';
            break;
	default:
		vogal2='c';
            break;
	}
	return vogal2;
}

int main(){

	char vogal;
	int  indice;

	printf("Introduza um indice\n");
	scanf("%d",&indice);
	vogal=vogalindex(indice);
	printf("Vogal:%c",vogal);
	return 0;
}
*/

/////////////////////////  C  ///////////////////////////////////
/*
#include <string.h>
#include <stdio.h>

int main(){

	int v[10];
	int *vptr=v;
	int i;

	//Inicializa��o de um vector a zero
	for(i=0;i<5;i++)
	{
	   *(vptr+i)=0;
	   printf("%d\n",v[i--]);
	}

	return 0;

}
*/

/////////////////////////  D  ///////////////////////////////////
/*
// Devera receber strings de tamanho superior 
#include <stdio.h>
#include <stdlib.h>

void main(){

	char *v;
	gets(v);
	printf("%s",v);
}
*/

/////////////////////////  E  ///////////////////////////////////
/*
#include <stdio.h>
#include <string.h>

void main(){

	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *s3 = strcat(s1, s2);

    printf("%s",s1);
	printf("%s\n",s2);
	printf("%s",s3);
}

*/

/////////////////////////  F  ///////////////////////////////////
/*
//Nota: verificar o c�digo at� que a frase Hello World seja escrita na consola
#include <stdio.h>
#include <string.h>

char *GetMemory(void)
{          
     char v[12]= "hello world";
     return v;
}

void main(void)
{
     char *str = NULL;
     str = GetMemory();         
     printf(str);
}
*/


/////////////////////////  G  ///////////////////////////////////
/*
// Nota: No final dever� imprimir "String" na consola
#include <stdio.h>
#include <string.h>

struct S
{
	char *v;
};

void main(void) {
	struct S *s;
	(*s).v="String";
	printf("%s",(*s).v);
}
*/

//////////////////////////////////////////////////////////////
