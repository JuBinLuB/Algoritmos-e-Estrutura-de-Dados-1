#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *destino, char *origem);
int StrLen(char *string);
int StrCmp(char *string1, char *string2);

int main() {
    // a) Teste StrCat(char *destino, char *origem).
    char destino[50] = {"Algoritmos e "};
    StrCat(destino, "Estrutura de Dados");
    printf("Resultado: |%s|\n", destino);

    // b) Teste StrLen(char *string).
    char str[] = {"Kaguya Shinomiya"};
    int len = StrLen(str);
    printf("Tamanho: %d\n", len);

    // c) Teste StrCmp(char *string1, char *string2).
    char str1[] = {"Bom."};
    char str2[] = {"Bom."};
    int cmp = StrCmp(str1, str2);
    printf("Iguais: %d\n", cmp);

    return 0;
}

// Letra a)
char *StrCat(char *destino, char *origem) {
    while (*destino) {
        destino++;
    }

    while (*origem) {
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
    return destino;
}

// Letra b)
int StrLen(char *string) {
    int length = 0;

    while (*string) {
        length++;
        string++;
    }
    return length;
}

// Letra c)
int StrCmp(char *string1, char *string2) {
    while (*string1 || *string2) {
        if (*string1 != *string2) {
            return *string1 - *string2;
        }
        string1++;
        string2++;
    }
    return 0;
}
