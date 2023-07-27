#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int codigo;
    float preco;
} TProduto;

typedef struct celulaP {
    TProduto item;
    struct celulaP *prox;
} TCelulaP;

typedef struct celulaA {
    TProduto item;
    struct celulaA *pai;
    struct celulaA *esq;
    struct celulaA *dir;
} TCelulaA;

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // UTIL_H_INCLUDED
