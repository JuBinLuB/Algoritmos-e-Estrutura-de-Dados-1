#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "pilha.h"

typedef struct arvore {
    TCelulaA *raiz;
    int tamanho;
} TArvore;

void Iniciar(TCelulaA **no);

void Central(TCelulaA *x);

void PreOrdem(TCelulaA *x);

void PosOrdem(TCelulaA *x);

TCelulaA *PesquisarA(TCelulaA *x, TProduto Item);

TCelulaA *Maximo(TCelulaA *x);

TCelulaA *Minimo(TCelulaA *x);

TCelulaA *Sucessor(TCelulaA *x);

TCelulaA *Predecessor(TCelulaA *x);

TCelulaA *criaNo(TProduto Item);

void InserirA(TCelulaA **x, TCelulaA *pai, TProduto Item);

void Transplante(TArvore *Arvore, TCelulaA **u, TCelulaA **v);

void Retirar(TArvore *Arvore, TCelulaA **z);

void CentralIterativa(TCelulaA *x);

void PreOrdemIterativa(TCelulaA *x);

void PosOrdemIterativa(TCelulaA *x);

void InserirIterativa(TCelulaA **x, TProduto Item);

void CentralPilha(TCelulaA *x);

#endif // TREE_H_INCLUDED
