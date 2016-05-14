/*http://www.spoj.com/problems/HELLOKIT*/
#include <stdio.h>
#include <string.h>

void R_ShiftString(char *s, char *a);

void L_ShiftString(char *s, char *a);

void StringSet(char *w, char *dest, int n);

int main() {
    char word[10], strShifted[26] = "", strToFind[26], aux[26];
    int n, BoolFounded = 0;

    while (1) {
        scanf("%s", word);
        if (word[0] == '.') break;
        scanf("%d", &n);
        BoolFounded = 0;
        StringSet(word, strShifted, n);

        R_ShiftString(strShifted, strToFind);

        while (!BoolFounded) {
            if (strcmp(strShifted, strToFind) == 0) BoolFounded = 1;
            printf("%s\n", strShifted);
            strcpy(aux, strShifted);
            L_ShiftString(aux, strShifted);
        }
    }

}

void R_ShiftString(char *s, char *a) {
    int i;
    a[0] = s[strlen(s) - 1];
    for (i = 1; i < strlen(s); ++i) {
        a[i] = s[i - 1];
    }
    a[i] = '\0';
}

void L_ShiftString(char *s, char *a) {
    int i;
    a[strlen(s) - 1] = s[0];
    for (i = 1; i < strlen(s); ++i) {
        a[i - 1] = s[i];
    }
    a[i] = '\0';
}

void StringSet(char *w, char *dest, int n) {
    strcpy(dest, ""); /*Making sure that string is 'empty'*/
    for (int i = 0; i < n; ++i) {
        strcat(dest, w);
    }
}
