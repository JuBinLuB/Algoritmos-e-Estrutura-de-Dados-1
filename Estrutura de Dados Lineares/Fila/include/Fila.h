#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"

typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct fila {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

void Enfileirar(TProduto Item, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void Imprimir(TFila *Fila);

int Pesquisar(TFila *Fila, TProduto *x);

void LiberarFila(TFila *Fila);

void copiarFila(TFila *F1, TFila *F2);

#endif // FILA_H_INCLUDED
