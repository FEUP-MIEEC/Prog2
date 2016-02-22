#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int in_array(int a, int *v, int len){
	int i=0;
	for(i=0; i<=len; i++){
		if(v[i]==a){
			return 1;
		}
	}
	return 0;
}

void imprime_vetor(int *v, int len){
	int i;
	for(i=0; i<=len; i++){
		
	}
}


int main(){
	FILE *f;
	int v_a[8]={192, 193, 194, 195, 224, 225, 226, 227};
	int v_e[4]={201, 202, 233, 234};
	int v_i[2]={205, 237};
	int v_o[6]={211, 212, 213, 243, 244, 245};
	int v_u[2]={218, 250};
	int v_c[2]={199, 231};
	f=fopen("lusiadas.txt", "r");
	int c, i=0;
	int freq[26]={};
	//printf("%d\n", in_array(198, v_a, sizeof(v_a)/sizeof(int))); exit(1);
	while (1){
		c=getc(f);
		if (c==EOF){
			break;
		}
		if (in_array(c, v_a, sizeof(v_a)/sizeof(int))){
			c='a';
		} else if(in_array(c, v_e, sizeof(v_e)/sizeof(int))){
			c='e';
		} else if(in_array(c, v_i, sizeof(v_i)/sizeof(int))){
			c='i';
		} else if(in_array(c, v_o, sizeof(v_o)/sizeof(int))){
			c='o';
		} else if(in_array(c, v_u, sizeof(v_u)/sizeof(int))){
			c='u';
		} else if(in_array(c, v_c, sizeof(v_c)/sizeof(int))){
			c='c';
		}
		
		c=tolower(c);
		c-=97;
		if (c<=25 && c>=0){
			freq[c]++;
			//printf("%c", c+97);
			i++;
		}
	};
	int nl=i;
	fclose(f);
	printf("\n\n");
	printf("Número de carateres lidos: %i.\n", i);

	for(i=0; i<=25; i++){
		printf("Letra %c = %005.2f%%\n", i+97, (float) freq[i]/nl*100);
	}
	
	
}