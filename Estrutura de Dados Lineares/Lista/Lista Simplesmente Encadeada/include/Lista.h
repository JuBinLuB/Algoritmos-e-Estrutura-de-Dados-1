#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int VaziaL(TLista Lista);

void InserirL(TProduto x, TLista *Lista);

void ImprimirL(TLista Lista);

TCelula *PesquisarL(TLista Lista, TProduto Item);

void ExcluirL(TLista *Lista, TProduto *Item);

void LiberarLista(TLista *Lista);

void InserirCrescente(TProduto x, TLista *Lista);

void ImprimirICelula(TLista Lista, int i);

void ExcluirICelula(TLista Lista, int i);

void ImprimirRecursivo(TCelula *Celula);

TCelula *PesquisarRecursivo(TCelula *Celula, TProduto Item);

void Inverter(TLista *Lista);

#endif // LISTA_H_INCLUDED
