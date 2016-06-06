#include <string.h>
#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
	int i, j;
	char *word="line";
    for (i = 0; i < strlen(word); ++i) {
        for (j = i + 1; j < strlen(word); j++) {
            swap(&word[j], &word[j]);
            tabela existe bla bla bla
            swap(&word[j], &word[j]);
        }
    }
	return 0;
}