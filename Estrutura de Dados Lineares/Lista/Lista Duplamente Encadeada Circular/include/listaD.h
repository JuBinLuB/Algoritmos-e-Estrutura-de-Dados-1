#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"

typedef struct celula {
    TProduto item;
    struct celula *prox;
    struct celula *ant;
} TCelula;

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void FLDVazia(TLista *ListaD);

int VaziaLD(TLista ListaD);

void InserirLD(TProduto x, TLista *ListaD);

void ImprimirLD(TLista ListaD);

TCelula *PesquisarLD(TLista ListaD, TProduto Item);

void ExcluirLD(TLista *ListaD, TProduto *Item);

void LiberarListaLD(TLista *ListaD);

#endif // LISTAD_H_INCLUDED
