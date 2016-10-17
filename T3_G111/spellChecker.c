#include <stdio.h>
#include <string.h>
#include <time.h>

// #include & #define
#include <stdlib.h>
#include "tabdispersao.h"
#include "fila.h"
#include "lista.h"
#define T 150000
// functions and procedures
int wordin(char word[], tabela_dispersao *td, fila *fila){
	int i, end=0;
	char *wordaux;
	//minusculas
	for(i=0; i<strlen(word); i++){
		if(word[i]>64 && word[i]<91){
			word[i]=word[i]+32;
		}
	}
	//fim de frase?
	//caracteres
	if(word[strlen(word)-1]=='.' || word[strlen(word)-1]==';' || word[strlen(word)-1]=='?' || word[strlen(word)-1]=='!'){
		end=1;
		word[strlen(word)-1]='\0';
	}
	while(!(word[0]=='\0')){
		if((word[0]>96 && word[0]<123) || word[0]==39){break;}
		for(i=0; i<strlen(word); i++){
			word[i]=word[i+1];
		}
	}
	while(!((word[strlen(word)-1]>96 && word[strlen(word)-1]<123) || word[strlen(word)-1]==39)){
		if(strlen(word)==0) break;
		word[strlen(word)-1]='\0';
	}
	for(i=0; i<strlen(word); i++){
		if(!(word[i]>96 && word[i]<123)){
			if(word[i]==39) break;
			wordaux = strchr(word, word[i]);
			if(wordin(wordaux, td, fila)==1) end=1;
			memcpy(word, word, i);
			word[i]='\0';
		}
	}
	for(i=0; i<strlen(word); i++){
		if(word[i]>96 && word[i]<123)
			break;
	}
	if(i==strlen(word))
		return end;
	if((word[0]>96 && word[0]<123) || word[0]==39){
		if(tabela_existe(td, word)==TABDISPERSAO_NAOEXISTE){
			fila_push(fila, word);
		}
	}
	return end;
}

int main(int argc, char* argv[])
{
	FILE *input, *wordlist;
	clock_t inicio, fim;
  double tempo;
	long int erros=0, sugestoes=0;
	char word[20], wordaux[20], *frase;
	int i, x, n, end, len;
	tabela_dispersao *tab;
	fila *fila;
	lista *lista;

	if(argc != 3)
	{
		printf("utilização: %s <nome_ficheiro> <modo>\n", argv[0]);
		printf("modo: verboso ou silencioso\n");
		return 1;
	}

	// processa lista de palavras
	wordlist = fopen("wordlist.txt", "r");
	if(!wordlist)
	{
		printf("erro ao abrir ficheiro com lista de palavras\n");
		return 2;
	}
	// armazena lista de palavras em estrutura de dados adequada
	tab = tabela_nova(T, hash_djbm);
	while(fscanf( wordlist, "%s", word)==1){
		for(i=0; i<strlen(word); i++){
				if(word[i]>64 && word[i]<91){
					word[i]=word[i]+32;
				}
		}
		tabela_adiciona(tab, word, word);
	}
	// processa ficheiro de entrada
	input = fopen(argv[1], "r");
	if(!input)
	{
		printf("erro ao abrir ficheiro %s\n", argv[1]);
		return 3;
	}

	if(!strcmp(argv[2],"verboso")){
		inicio = clock();
		// processa e imprime output como indicado no enunciado
		fila = fila_nova();
		frase=(char*)malloc(sizeof(char));
		while(fscanf(input, "%s", word)==1){
			n++;
			frase=(char*)realloc(frase, n*(sizeof(word) + sizeof(char)));
			strcat(frase, word);
			strcat(frase, " ");
			end = wordin(word, tab, fila);
			if(end==1){
				// guarda na variável erros o número de palavras com ortografia errada encontradas
				erros=erros+fila_tamanho(fila);
				printf("%s\n", frase);
				while(fila_tamanho(fila)!=0){
					strcpy(word, fila_front(fila));
					fila_pop(fila);
					printf("Word not found: %s\nPerhaps you meant: ", word);
					for(i=0; i<strlen(word); i++){
						if(word[i]=='\0') break;
					}
					len=i;
					lista=lista_nova();
					for(i=0; i<len; i++){
						for(x=0; x<len; x++){
							strcpy(wordaux, word);
							wordaux[i]=word[x];
							wordaux[x]=word[i];
							if(tabela_existe(tab, wordaux)==TABDISPERSAO_EXISTE){
								if(lista_pesquisa(lista, wordaux, INICIO)==NULL){
									printf("%s, ", wordaux);
									lista_insere(lista, wordaux, NULL);
									// guarda na variável sugestoes o número de palavras sugeridas para corrigir palavras com ortografia errada encontradas
									sugestoes++;
								}
							}
						}
					}
					printf("\n");
					lista_apaga(lista);
				}
				printf("\n");
				frase[0]='\0';
				n=0;
			}
		}
		free(frase);
		fila_apaga(fila);
		tabela_apaga(tab);
		fim = clock();
	} else if(!strcmp(argv[2],"silencioso")){
		inicio = clock();
		// processa e imprime output como indicado no enunciado
		fila = fila_nova();
		frase=(char*)malloc(sizeof(char));
		while(fscanf(input, "%s", word)==1){
			n++;
			frase=(char*)realloc(frase, n*(sizeof(word) + sizeof(char)));
			strcat(frase, word);
			strcat(frase, " ");
			end = wordin(word, tab, fila);
			if(end==1){
				// guarda na variável erros o número de palavras com ortografia errada encontradas
				erros=erros+fila_tamanho(fila);
				while(fila_tamanho(fila)!=0){
					strcpy(word, fila_front(fila));
					fila_pop(fila);
					for(i=0; i<strlen(word); i++){
						if(word[i]=='\0') break;
					}
					len=i;
					lista=lista_nova();
					for(i=0; i<len; i++){
						for(x=0; x<len; x++){
							strcpy(wordaux, word);
							wordaux[i]=word[x];
							wordaux[x]=word[i];
							if(tabela_existe(tab, wordaux)==TABDISPERSAO_EXISTE){
								if(lista_pesquisa(lista, wordaux, INICIO)==NULL){
									lista_insere(lista, wordaux, NULL);
									// guarda na variável sugestoes o número de palavras sugeridas para corrigir palavras com ortografia errada encontradas
									sugestoes++;
								}
							}
						}
					}
					lista_apaga(lista);
				}
				frase[0]='\0';
				n=0;
			}
		}
		free(frase);
		fila_apaga(fila);
		tabela_apaga(tab);
		fim = clock();
	} else{
		printf("modo %s desconhecido\n", argv[2]);
		return 4;
	}

	tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("Tempo gasto na verificação (em segundos): %lf\n", tempo);
	printf("Número de palavras com ortografia errada encontradas: %li\n", erros);
	printf("Número de sugestões efetuadas: %li\n", sugestoes);
	fclose(input);
	fclose(wordlist);
	return 0;
}
