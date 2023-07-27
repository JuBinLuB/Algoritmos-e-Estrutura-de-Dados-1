#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int codigo;
    float preco;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct celula {
    TProduto item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // UTIL_H_INCLUDED
