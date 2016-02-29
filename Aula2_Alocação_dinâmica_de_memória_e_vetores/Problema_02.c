#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Para compilar (obter mais informações): 
<clang -g Problema_2.c>
<valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./a.out>

Nota: 
[clang] -g : Generate complete debug info.
[valgrind] --track-origins=yes: Memcheck also reports uses of uninitialised values, 
                                most commonly with the message "Conditional jump or move depends on 
                                uninitialised value(s)". 
                                It can be difficult to determine the root cause of these errors. 
                                Try using the --track-origins=yes to get extra information.
*/

#define NSTRINGS 3

int main()
{
    char **v;
    char str[80];
    int i, pos;
    v = malloc(NSTRINGS * sizeof(char*));

    /* [Inicializar o vetor 'v'] 
    ***
    ==32466== Conditional jump or move depends on uninitialised value(s)
    ==32466==    at 0x8048637: main (Problema_2.c:47)
    ==32466==  Uninitialised value was created by a heap allocation
    ==32466==    at 0x402C19C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
    ==32466==    by 0x80485F4: main (Problema_2.c:26)
    ***
    */
    for (int i = 0; i < NSTRINGS; ++i)
    {
        v[i] = NULL;
    }

    while(1)
    {
        for(i = 0; i < NSTRINGS; i++)
		{
			printf("[%d] ", i+1);
			if(v[i] == NULL)
				printf("(vazio)\n");
			else
            	printf("%s\n", v[i]);
		}

		do        
		{
            printf("Posicao para nova string (1 a %d): ", NSTRINGS);
            scanf("%d", &pos);
            getchar(); /* elimina \n */
		}
		while(pos < 0 || pos > NSTRINGS);

        if (pos == 0)
            break;

        printf("Nova String: ");
        fgets(str, 80, stdin);
        str[strlen(str) - 1] = '\0';

        /*
        Pequena revisão da função strcpy
        ***
        char *strcpy(char *dest, const char *src);

               The  strcpy()  function  copies  the string pointed to by
                src, including the terminating null byte ('\0'),  to  the
                buffer  pointed to by dest.  The strings may not overlap,
                and the destination string dest must be large  enough  to
                receive  the  copy.
        ***

        [ERRADO] v[pos - 1] = realloc(v[pos - 1], strlen(str));

        Nota: The strlen() function calculates the length of the string, 
                excluding the terminating null byte ('\0').
        
        Assim sendo, na função realloc, além do número de carateres da string, 
            é necessário adicionar 1 byte
            para a inclusão do '\0'. 
        Isto é essencial, caso contrário a função strcpy() vai "escrever" o carater '\0' 
            (tal como descrito acima) fora dos limites do vetor.
        */ 
        v[pos - 1] = realloc(v[pos - 1], strlen(str) + 1);
		strcpy(v[pos - 1], str);
    }

    /*
    Falta fazer free() dos (1 + NSTRINGS) vetores
    Ou seja, vetor 'v' e os vetores nele contidos 
    */
    for (int i = 0; i < NSTRINGS; ++i)
    {
        free(v[i]);
    }

    free(v);

    return 0;
}

/*
Necessita revisão
Output esperado: total heap usage: 4 allocs, 4 frees, 70 bytes allocated
Output obtido: total heap usage: 4 allocs, 4 frees, 58 bytes allocate 
*/
