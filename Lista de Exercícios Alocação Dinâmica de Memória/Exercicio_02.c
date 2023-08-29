#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrEnd(char *s, char *t);

int main() {
    // Teste de StrEnd.
    char s[] = {"Vladilena"};
    char t[] = {"en"};
    int subEnd = StrEnd(s, t);

    if (subEnd) {
        printf("\t\"t\" ocorre no final de \"s\".\n");
    } else {
        printf("\t\"t\" nao ocorre no final de \"s\".\n");
    }

    return 0;
}

int StrEnd(char *s, char *t) {
    int lenT = strlen(t);

    while (*s) {
        s++;
    }
    
    if (strcmp(s - lenT, t) == 0) {
        return 1;
    }
    return 0;
}
