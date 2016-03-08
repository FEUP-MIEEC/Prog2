#include <stdio.h>
#include <stdlib.h>

typedef struct {

    /*** No fundo, trata-se esta técnica de uma forma de poupar memória.
       * Como sabemos, cada valor de r, g, ou b ocupa exatamente 1 byte.
       * O único tipo de variável que temos em C que ocupa o mesmo é a char.
       * Se usássemos ints, utilizaríamos (4-1)*3=9 vezes mais memória do que o necessário.
       **/
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void print_pixelinfo(pixel **p, int h, int w) {
    printf("Valor RGB no pixel (%i,%i): %i %i %i\n", h, w, p[h][w].r, p[h][w].g, p[h][w].b);
}

int main() {
    FILE *f;
    f = fopen("enunciado/imagem.bmp", "r");
    int i = 0, j;
    int c;

    // Vamos dividir o problema por partes, de modo a simplificar a sua resolução.

    // Primeiro, vamos garantir que estamos a lidar com um ficheiro do tipo BitMap.
    if (!(getc(f) == 'B' && getc(f) == 'M')) {
        // Parece que estamos a lidar com um ficheiro que não tem as letras BM no início.
        // Não é válido!
        printf("[ERRO] O ficheiro lido não é uma imagem BitMap válida!");
        exit(1);
    }

    // Se chegámos aqui, é porque tudo correu bem. Vamos continuar.
    // Agora vamos ler o tamanho total do ficheiro, que é composto por 4 bytes.
    int size = (getc(f)) | (getc(f) << 8) | (getc(f) << 16) | (getc(f) << 24);
    // Recordando, a operação '<<' move n bytes para a esquerda. A operação '|' faz o OU lógico.

    // Já podemos imprimir o tamanho total do nosso ficheiro:
    printf("Tamanho total do ficheiro BMP: %i\n", size);

    // Depois temos 2+2=4 bytes reservados, cuja leitura não nos interessa.
    // Vamos avançá-los.
    fseek(f, 4, SEEK_CUR); // Lembra-te! SEEK_CUR é a posição atual de leitura.

    // Segue-se a informação do byte onde começa o array de pixéis. Registemo-lo.
    // Esta informação, o offset, é composta por 4 bytes.
    int offset = (getc(f)) | (getc(f) << 8) | (getc(f) << 16) | (getc(f) << 24);

    // Ok. O cabeçalho Bitmap está lido. Vamos passar ao cabeçalho DIB, que está logo a seguir.
    /***
       * O tamanho deste cabeçalho, que é a primeira informação que nos é fornecida, não tem relevo
       * para este exercício, uma vez que já temos o valor do offset.
       * Podemos passá-lo à frente. É composto por 4 bytes.
       **/
    fseek(f, 4, SEEK_CUR);

    // Agora vamos ler coisas bastante importantes. Primeiro, a largura (width) da imagem em pixéis:
    // Esta informação é composta por 4 bytes.
    int largura = (getc(f)) | (getc(f) << 8) | (getc(f) << 16) | (getc(f) << 24);
    printf("Largura da imagem: %i\n", largura);

    // Seguida da altura (height) da imagem, também em pixéis:
    // Esta informação é composta por 4 bytes.
    int altura = (getc(f)) | (getc(f) << 8) | (getc(f) << 16) | (getc(f) << 24);
    printf("Altura da imagem: %i\n", altura);
    // Passamos ao número de planos de cor utilizados. Se não for 1, não sabemos ler!
    // Esta informação é composta por 2 bytes.
    int numerodeplanos = (getc(f)) | (getc(f) << 8);

    if (numerodeplanos != 1) {
        printf("[ERRO] Este interpretador não está preparado para processar imagens com mais do que um plano!");
        exit(2);
    }

    // Podemos continuar. Vamos ler o número de bits por pixel. Se não forem 18, não sabemos ler!
    // Esta informação é composta por 2 bytes.
    int nbpp = (getc(f)) | (getc(f) << 8);
    printf("Bits por pixel: %i\n", nbpp);
    if (nbpp != 24) {
        printf("[ERRO] Este interpretador só está preparado para processar imagens com 24 bits por pixel!");
        exit(3);
    }

    // E pronto, já lemos tudo o que é relevante do cabeçalho :D


    // Vamos arrastar o apontador no ficheiro para o início do array de pixéis.
    fseek(f, offset, SEEK_SET); // Lembra-te! SEEK_SET é a posição inicial de leitura.

    // Vamos criar a variável onde vamos guardar todas as informações.
    pixel **imagem = malloc(sizeof(pixel *) * altura);
    for (i = 0; i < altura; i++) {
        imagem[i] = malloc(sizeof(pixel) * largura);
    }

    // Vamos então ler a imagem para a nossa variável.

    for (i = altura - 1; i >= 0; i--) {
        for (j = 0; j < largura; j++) {
            imagem[i][j].b = (unsigned char) getc(f); // Lemos para aqui o byte que representa o Blue  (b) deste pixel.
            imagem[i][j].g = (unsigned char) getc(f); // Lemos para aqui o byte que representa o Green (g) deste pixel.
            imagem[i][j].r = (unsigned char) getc(f); // Lemos para aqui o byte que representa o Red 	 (r) deste pixel.
        }
    }
    // E não nos esqueçamos de fechar o ficheiro, já que já lemos tudo.

    fclose(f);

    // Vamos imprimir as informações de alguns dos pixéis, como proposto no exercício:

    print_pixelinfo(imagem, 0, 0);
    print_pixelinfo(imagem, 532, 0);
    print_pixelinfo(imagem, 408, 443);


    // Por fim, vamos libertar a memória que a nossa imagem ocupa e permitir que o programa termine bem.
    for (i = 0; i < altura; i++) {
        free(imagem[i]);
    }
    free(imagem);
}