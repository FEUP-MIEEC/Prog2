#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSTRINGS 3

int main()
{
    char **v;
    char str[80];
    int i, pos;
    v = malloc(NSTRINGS * sizeof(char*));

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

        v[pos - 1] = realloc(v[pos - 1], strlen(str));
		strcpy(v[pos - 1], str);
    }
    return 0;
}
