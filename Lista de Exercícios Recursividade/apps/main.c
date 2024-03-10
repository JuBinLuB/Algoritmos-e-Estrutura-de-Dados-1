#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "recursion.h"

int *fillVector(int *vector, int size, int limit);

void printVector(int *vector, int size);

int main(void) {

    int n = 10;
    int *vector = (int *)malloc(n * sizeof(int));

    // Preenchendo vetor com valores aleatorios.
    vector = fillVector(vector, n, 100);

    // Imprimindo o vetor.
    printf("Vetor: ");
    printVector(vector, n);

    // #9: Somando todos os elementos do vetor.
    int result = recursiveSum(vector, n);
    printf("\n#9:\tSoma: %d\n", result);

    // #10: Buscando o maior elemento do vetor.
    int bigger = 0;
    biggerElement(vector, n, &bigger);
    printf("#10:\tMaior: %d\n", bigger);

    // #11: Descobrindo o comprimento de uma string.
    char str[] = "Kaguya Shinomiya";
    int strLeng = strLength(str, 0);
    printf("#11:\tString: %s\n", str);
    printf("\tComprimento: %d\n", strLeng);

    // #12: Invertendo a ordem dos caracteres de uma string.
    printf("#12:\tAntes de inverter: ");
    printf("%s\n", str);
    reverseOrder(str, 0, strLeng);
    printf("\tDepois de inverter: ");
    printf("%s\n", str);

    // #13: Verificando se uma string "t" eh uma substring da string "s".
    char s[] = {"Vladilena Milize"};
    char t[] = {"lena"};
    int sizeT = strlen(t);
    printf("#13:\t");
    int substr = substrOf(s, t, 0, sizeT);
    printf("%d\n", substr);

    // #14: Retornando a posição inicial da primeira substring da string "s" que eh igual a string "t".
    int index = substrIndex(s, t, 0, sizeT);
    printf("#14:\tIndex: %d\n", index);

    // #15: Retornando o maior divisor comum de dois inteiros "n" e "m".
    int mdc = MDC(12, 20);
    printf("#15:\tMDC: %d\n", mdc);

    // #16: Divisao recursiva.
    int divRec = RecursiveDiv(10, 2);
    printf("#16:\tDivisaoRec: %d\n", divRec);

    free(vector);
    return 0;
}

int *fillVector(int *vector, int size, int limit) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        vector[i] = rand() % limit;
    }
    return vector;
}

void printVector(int *vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
