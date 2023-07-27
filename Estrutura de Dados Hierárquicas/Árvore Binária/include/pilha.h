#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct {
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int VaziaP(TPilha Pilha);

void Empilhar(TProduto Item, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void LiberarPilha(TPilha *Pilha);

void ImprimirP(TPilha *Pilha);

int PesquisarP(TPilha *Pilha, TProduto *x);

void InverterPA(TPilha *Pilha);

void InverterPB(TPilha *Pilha);

void InverterPC(TPilha *Pilha);

void TransferirP(TPilha *P1, TPilha *P2);

#endif // PILHA_H_INCLUDED
