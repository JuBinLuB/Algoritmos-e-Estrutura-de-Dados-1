#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct fila {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int VaziaF(TFila Fila);

void Enfileirar(TProduto Item, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void ImprimirF(TFila *Fila);

int PesquisarF(TFila *Fila, TProduto *x);

void LiberarFila(TFila *Fila);

void CopiarF(TFila *F1, TFila *F2);

void InverterF(TFila *Fila);

#endif // FILA_H_INCLUDED
