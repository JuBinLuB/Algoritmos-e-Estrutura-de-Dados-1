#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct celula {
    TProduto item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;

} TCelula;

typedef struct arvore {
    TCelula *raiz;
    int tamanho;
} TArvore;

void Central(TCelula *x);

void PreOrdem(TCelula *x);

void PosOrdem(TCelula *x);

TCelula *PesquisarA(TCelula *x, TProduto Item);

TCelula *Maximo(TCelula *x);

TCelula *Minimo(TCelula *x);

TCelula *Sucessor(TCelula *x);

TCelula *Predecessor(TCelula *x);

TCelula *criaNo(TProduto Item);

void InserirA(TCelula **x, TCelula *pai, TProduto Item);

void Transplante(TArvore *Arvore, TCelula **u, TCelula **v);

void Retirar(TArvore *Arvore, TCelula **z);

#endif // TREE_H_INCLUDED
