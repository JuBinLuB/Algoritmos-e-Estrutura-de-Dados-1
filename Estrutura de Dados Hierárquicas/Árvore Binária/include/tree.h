#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "pilha.h"

typedef struct arvore {
    TCelula *raiz;
    int tamanho;
} TArvore;

void Iniciar(TCelula **no);

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

void CentralIterativa(TCelula *x);

void PreOrdemIterativa(TCelula *x);

void PosOrdemIterativa(TCelula *x);

void InserirIterativa(TCelula **x, TProduto Item);

void CentralP(TCelula *x);

#endif // TREE_H_INCLUDED
