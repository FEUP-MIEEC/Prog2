#include <stdio.h>
#include "tabdispersao.h"
#include <string.h>
//#include "lista.h"

#define TBL_SIZE 9999

int main()
{
	char str[500], n[500], lixo[500];
	tabela_dispersao *tbl;
	FILE *f;
	f = fopen("englishwords.txt", "r");
	/*lista *lst;
	lst = lista_nova();*/

	tbl = tabela_nova(TBL_SIZE, hash_djbm);

	while(fscanf(f, "%s %s %s %s", n, str, lixo, lixo) == 4){
		tabela_adiciona(tbl, str, n);
	}
	/*fseek(f, 0, SEEK_SET);
	while(fscanf(f, "%s %s %s %s", n, str, s, s) == 4){
		lista_insere(lst, str, NULL);
	}*/

	mostraTabela(tbl);

	return 0;
}