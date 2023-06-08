#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recursion.h"

// Questao #09
int recursiveSum(int *vector, int size) {
    if (size == 0) {
        return 0;
    } else {
        return vector[size - 1] + recursiveSum(vector, size - 1);
    }
}

// Questao #10
void biggerElement(int *vector, int size, int *bigger) {
    if (size == 0) {
        return;
    } else {
        if (vector[size - 1] > *bigger) {
            *bigger = vector[size - 1];
        }
        biggerElement(vector, size - 1, bigger);
    }
}

// Questao #11
int strLength(char str[], int index) {
    if (str == NULL) {
        return 0;
    } else {
        if (str[index] != '\0') {
            return strLength(str, index + 1) + 1;
        } else {
            return 0;
        }
    }
}

// Questao #12
void reverseOrder(char str[], int start, int end) {
    int aux;

    if (str == NULL) {
        return;
    } else {
        if (start < end - 1) {
            aux = str[start];
            str[start] = str[end - 1];
            str[end - 1] = aux;
            reverseOrder(str, start + 1, end - 1);
        }
    }
}

// Questao #13
void substrOf(char s[], char t[], int index, int sizeT) {
    if (strncmp(t, s + index, sizeT) == 0) {
        printf("The string \"%s\" is a substring of \"%s\"\n", t, s);
        return;
    } else {
        if (s[index] == '\0' || s[index + sizeT] == '\0') {
            printf("The string \"%s\" is not a substring of \"%s\"\n", t, s);
        } else {
            substrOf(s, t, index + 1, sizeT);
        }
    }
}

// Questao #14
int substrIndex(char s[], char t[], int index, int sizeT) {
    if (strncmp(t, s + index, sizeT) == 0) {
        return index;
    } else {
        if (s[index] == '\0' || s[index + sizeT] == '\0') {
            return -1;  // Retorna -1 indicando que a string "t" não é substring da string "s".
        } else {
            return substrIndex(s, t, index + 1, sizeT) + 0;
        }
    }
}

// Questao #15
int MDC(int n, int m) {
    if (m <= n && n % m == 0) {
        return m;
    } else if (n < m) {
        return MDC(m, n);
    } else {
        return MDC(m, n % m);
    }
}

// Questao #16
float RecursiveDiv(int p, int q) {
    if (p < q) {
        return 0;
    } else {
        return RecursiveDiv(p - q, q) + 1;
    }
}
