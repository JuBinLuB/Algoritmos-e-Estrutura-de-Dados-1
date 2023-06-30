#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

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
    struct celula *ant;
} TCelula;

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void FLDVazia(TLista *Lista);

int VaziaLD(TLista Lista);

void InserirLD(TProduto x, TLista *Lista);

void ImprimirLD(TLista Lista);

TCelula *PesquisarLD(TLista Lista, TProduto Item);

void ExcluirLD(TLista *Lista, TProduto *Item);

void LiberarListaLD(TLista *Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // LISTA_DUPLA_H_INCLUDED
