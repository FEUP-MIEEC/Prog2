#include <stdio.h>
#include <string.h>

void esvaziastring(char *s, int t) {
    int i = 0;
    for (i = 0; i < t; i++) {
        s[i] = 0;
    }
}

typedef struct {
    char url[205];
    char desc[205];
} entrada;

int main() {
    FILE *f;
    f = fopen("enunciado/pagina.html", "r");
    int c, i = 0, ce = 0;
    char str[200];
    entrada entradas[5];
    ce = 0;
    while (1) {
        c = getc(f);
        //printf("=== ce:%i ===\n\n", ce);
        if (c == EOF) {
            fclose(f);
            break;
        }
        //printf("%c", c);
        if (c == '<') {
            // Estamos no início de uma tag. Vamos ler 1 byte (char) e ver se é uma tag do tipo '<a href="*">*</a>'
            if (getc(f) != 'a') {
                continue;
            }
            // Encontrámos uma TAG!
            esvaziastring(str, 200);
            fseek(f, 7, SEEK_CUR); // Avançar 7 bytes

            //Vamos ler o url, que é todo o texto até à próxima aspa.

            i = 0;
            while (1) {
                c = getc(f);
                if (c == '\"') { // A aspa tem de levar uma backslash antes por causa de character escaping.
                    break;
                }
                str[i] = (char) c;
                i++;
            }
            str[i] = 0;

            strcpy(entradas[ce].url, str);
            esvaziastring(str, 200);
            fseek(f, 1, SEEK_CUR); // Avançar 1 byte

            i = 0;
            while (1) {
                c = getc(f);
                if (c == '<') {
                    break;
                }
                /* Temos de fazer a verificação
                 * abaixo por causa da forma como a consola funciona.
                 *
                 * A consola imprime valores em UTF-8, mas p ficheiro
                 * que estamos a ler está am ASCII. Como só há 1 tipo de
                 * carateres especiais neste ficheiro, que são o 'a'
                 * acentuado (á), só temos de nos preocupar com esse.
                 */
                if (c == 0xE1) {
                    str[i] = (char) 0xC3;
                    str[++i] = (char) 0xA1;
                } else {
                    str[i] = (char) c;
                }

                i++;
            }
            str[i] = 0;
            strcpy(entradas[ce].desc, str);
            esvaziastring(str, 80);
            printf("%s - %s\n", entradas[ce].desc, entradas[ce].url);
            ce++;
        }
    }

}