#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int codigo;
    float preco;
} TProduto;

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // UTILIDADES_H_INCLUDED
