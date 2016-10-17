#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "tabdispersao.h"
#include <ctype.h>

// #include & #define
// functions and procedures

#define SUM_MAX 3000

int comp (const void * elem1, const void * elem2)  // For sorting.
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int pondSum(char* str){

	int h=0, i;
	for(i=0; str[i]!='\0'; i++){
		if(str[i]=='\''){
			h|=2<<27;
		}
		else
		h|=2<<(str[i]-'a'+1);
	}

	return h;
}

void keyM(const char *valor, char *chave) {
    int i, l = 0;
    for (i = 0; i < strlen(valor); i++) {
        l += valor[i];
    }
    sprintf(chave, "%d", l);
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void str_tolower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

void readdic(tabela_dispersao *tbl, FILE *wordlist, int size) {
    char str[TAMANHO_VALOR];
    char r[10];
    while (fscanf(wordlist, "%s", str) == 1) {
        keyM(str, r);
        str_tolower(str);
        tabela_adiciona(tbl, str, r);
    }
}

void similarwords(tabela_dispersao *tbl, char *word, long *sugestoes, char *suggestions) {
    int i = 0, j, c=0;
    char sum[30];
    elemento *e;
	unsigned long wordHDS=hash_ds(word, tbl->tamanho);
	unsigned long wordPondSum=pondSum(word);
	//printf("Our word: %s - %lu - %i\n", word, hash_ds(word, tbl->tamanho), pondSum(word)); // DEBUG TOOL
    for (e = tbl->elementos[hash_ds(word, tbl->tamanho)]; e != NULL; e = e->proximo) {
		//printf("Sugestion: %s - %lu - %i\n", e->obj->chave, hash_ds(e->obj->chave, tbl->tamanho), pondSum(e->obj->chave)); // DEBUG TOOL
		if(wordHDS==hash_ds(e->obj->chave, tbl->tamanho) && wordPondSum==pondSum(e->obj->chave)){
			for(c=0, j=0; j<strlen(word);j++){
				if(word[j]!=e->obj->chave[j]){
					c++;
				}
			}
			
			if(c==2){
				if(i++){
					strcat(suggestions, ", ");
				}else{
					strcat(suggestions, " ");
				}
				strcat(suggestions, e->obj->chave);
				strcat(suggestions, "");
				(*sugestoes)++;
			}
		}
    }
}


int main(int argc, char *argv[]) {
    FILE *input, *wordlist;
    clock_t inicio, fim;
    double tempo;
    long int erros = 0, sugestoes = 0;

    if (argc != 3) {
        printf("utilização: %s <nome_ficheiro> <modo>\n", argv[0]);
        printf("modo: verboso ou silencioso\n");
        return 1;
    }

    // processa lista de palavras
    wordlist = fopen("wordlist.txt", "r");
    if (!wordlist) {
        printf("erro ao abrir ficheiro com lista de palavras\n");
        return 2;
    }
    // armazena lista de palavras em estrutura de dados adequada

    // processa ficheiro de entrada
    input = fopen(argv[1], "r");
    if (!input) {
        printf("erro ao abrir ficheiro %s\n", argv[1]);
        return 3;
    }

    if (!strcmp(argv[2], "verboso")) {
        inicio = clock();

        int i, j;
        fseek(wordlist, 0, SEEK_END);
        tabela_dispersao* tbl = tabela_nova(ftell(wordlist)/4, hash_ds);
        rewind(wordlist);
        readdic(tbl, wordlist, 0);
		//printf("Dicionário lido em %lfs.\n", (double)(clock()-inicio)/CLOCKS_PER_SEC);
        char ers[1000][300];
        i = 0;
		char c=getc(input), d;
		char sentence[1024];
		char word[TAMANHO_CHAVE];
		int sI=0;
		int wI=0;
		int errors=0;
		do{
			i++;
			sentence[sI++]=	c;
			//printf("read '%c' - %i\n", c, c);
			d=c;
			if(!(c=='\'' || isalpha(c))){
				d=' ';
			}
			
			word[wI++]=d;
			word[wI]='\0';
			if(d==' '|| c=='.' || c=='?' || c=='!' || c==';'){
				if(sI==1){
					sentence[--sI]='\0';
				}
				word[--wI]='\0';
				str_tolower(word);
				if (strlen(word)==0 && c!=10){
					c=getc(input);
					continue;
				}
				if (tabela_existe(tbl, word) == TABDISPERSAO_NAOEXISTE) {
					if(strlen(word)>1){
						erros++;
						strcpy(ers[errors], word);
						errors++;
						}
				}else{
				}
				wI=0;
			}

			if((c=='.' || c=='?' || c=='!' || c==';'|| c==10) && errors>0){ // End of sentence
				if(c==10) sentence[sI-1]='\0';
				sentence[sI]=	'\0';
				printf("%s\n", sentence);
				char suggestions[200]={'\0'};
				for (j = 0; j < errors; j++) {
					similarwords(tbl, ers[j], &sugestoes, suggestions);
                    printf("\tWord not found: %s\n\tPerhaps you meant:%s\n", ers[j], suggestions);
					suggestions[0]='\0';
                }
				errors=0;
				printf("\n");
			}
			//printf(" (%i)%d - %c ", i, c, c);
			if(c=='.' || c=='?' || c=='!' || c==';' || c==10){
				sentence[0]='\0';
				sI=0;
				wI=0;
				//printf("String cleared without errrors.\n");
			}
				
			
			c=getc(input);
		} while(c!=EOF);
       	tabela_apaga(tbl);
		fim = clock();
    } else if (!strcmp(argv[2], "silencioso")) {
        inicio = clock();
        // processa e não apresenta qualquer output
        // guarda na variável erros o número de palavras com ortografia errada encontradas
        // guarda na variável sugestoes o número de palavras sugeridas para corrigir palavras com ortografia errada encontradas
        int i, j;
        fseek(wordlist, 0, SEEK_END);
        tabela_dispersao* tbl = tabela_nova(ftell(wordlist)/4, hash_ds);
        rewind(wordlist);
        readdic(tbl, wordlist, 0);
        char ers[1000][300];
        i = 0;
		char c=getc(input), d;
		char sentence[1024];
		char word[TAMANHO_CHAVE];
		int sI=0;
		int wI=0;
		int errors=0;
		do{
			i++;
			sentence[sI++]=	c;
			d=c;
			if(!(c=='\'' || isalpha(c))){
				d=' ';
			}
			
			word[wI++]=d;
			word[wI]='\0';
			if(d==' '|| c=='.' || c=='?' || c=='!' || c==';'){
				if(sI==1){
					sentence[--sI]='\0';
				}
				word[--wI]='\0';
				str_tolower(word);
				if (strlen(word)==0 && c!=10){
					c=getc(input);
					continue;
				}
				if (tabela_existe(tbl, word) == TABDISPERSAO_NAOEXISTE) {
					if(strlen(word)>1){
						erros++;
						strcpy(ers[errors], word);
						errors++;
						}
				}else{
				}
				wI=0;
			}

			if((c=='.' || c=='?' || c=='!' || c==';'|| c==10) && errors>0){ // End of sentence
				if(c==10) sentence[sI-1]='\0';
				sentence[sI]=	'\0';
				char suggestions[200]={'\0'};
				for (j = 0; j < errors; j++) {
					similarwords(tbl, ers[j], &sugestoes, suggestions);
					suggestions[0]='\0';
                }
				errors=0;
			}
			if(c=='.' || c=='?' || c=='!' || c==';' || c==10){
				sentence[0]='\0';
				sI=0;
				wI=0;
			}
				
			
			c=getc(input);
		} while(c!=EOF);
        tabela_apaga(tbl);
		fim = clock();
    } else {
        printf("modo %s desconhecido\n", argv[2]);
        return 4;
    }

    tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na verificação (em segundos): %lf\n", tempo);
    printf("Número de palavras com ortografia errada encontradas: %li\n", erros);
    printf("Número de sugestões efetuadas: %li\n", sugestoes);

    fclose(input);
	fclose(wordlist);
	return 0;
}