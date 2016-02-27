#include <stdio.h>
#include <string.h>

int IsIOFunction(char * FuncName, FILE * f);
int main()
{
	int comment = 0, lines = 1, chars = 0, IOfunc = 0, IsComment = 0;
	char ch;
	FILE * f;

	f = fopen("teste.c", "r");

	while ( EOF != (ch = fgetc(f)) )
	{
		chars++;

		if (ch=='\n') ++lines;

		else if(ch == 's')
		{
			if(IsIOFunction("scanf", f)) IOfunc++;
		}

		else if(ch == 'p')
		{
			if(IsIOFunction("printf", f)) IOfunc++;
		}

		else if(ch == '/') /*possível comentário*/
		{
			if (fgetc(f) == '*' && !IsComment) /*inicio de comentário encontrado*/
			{
					/* 
					se for encontrado um conjunto de caraters / * dentro de um comentário, não deve ser considerado
					como possível inicio de comentário
					*/
					IsComment = 1;	
					chars++;
			}
			else
			{
				fseek(f, -1, SEEK_CUR);
			}
		}
		
		else if(ch == '*')
		{
			if (fgetc(f) == '/' && IsComment) /*fim de comentário encontrado*/
			{
					chars++;
					comment++;
					IsComment = 0;
			}
			else
			{
				fseek(f, -1, SEEK_CUR);
			}
		}
        
	}

	printf("Linhas de codigo: %d\n", lines);
	printf("Tamanho medio de cada linha: %f carateres\n", (float)chars/lines);
	printf("Carateres: %d\n", chars);
	printf("Numero de ocorrencias das funcoes printf/scanf: %d\n", IOfunc);
	printf("Numero de Comentarios: %d\n", comment);
	
	fclose(f);
}

int IsIOFunction(char * FuncName, FILE * f)
{
	fseek(f, -1, SEEK_CUR);
	int l = strlen(FuncName), i;
	char s[7] = ""; /*Um byte extra para o '/0'*/

	for (i = 0; i < l; ++i)
	{
		s[i] = fgetc(f);
	}

	s[i] = '\0';

	fseek(f, -l + 1, SEEK_CUR);

	if (!strcmp(FuncName, s))
	{
		return 1;
	}

	return 0;
}

