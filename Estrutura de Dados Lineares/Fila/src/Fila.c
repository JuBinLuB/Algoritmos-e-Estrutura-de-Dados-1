#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

void FFVazia(TFila *Fila) {
    Fila->frente = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int VaziaF(TFila Fila) {
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto Item, TFila *Fila) {
    Fila->tras->prox = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = Item;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item) {
    TCelula *Aux;

    if (!VaziaF(*Fila)) {
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);

        if (Fila->frente->prox == NULL) {
            Fila->tras = Fila->frente;
        }
        Fila->tamanho--;
    }
}

void ImprimirF(TFila *Fila) {
    TFila Aux;
    TProduto x;
    FFVazia(&Aux);

    while (!VaziaF(*Fila)) {
        Desenfileirar(Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &Aux);
    }

    while (!VaziaF(Aux)) {
        Desenfileirar(&Aux, &x);
        Enfileirar(x, Fila);
    }
    free(Aux.frente);
}

int PesquisarF(TFila *Fila, TProduto *x) {
    TProduto Aux;
    int n = Fila->tamanho;
    int encontrado = 0;
    int index = 0;

    while (index < n) {
        Desenfileirar(Fila, &Aux);
        if (strcmp(Aux.nome, x->nome) == 0) {
            encontrado = 1;
        }
        Enfileirar(Aux, Fila);
        index++;
    }

    if (encontrado) {
        return 1;
    } else {
        return 0;
    }
}

void LiberarFila(TFila *Fila) {
    while (!VaziaF(*Fila)) {
        Desenfileirar(Fila, &Fila->frente->item);
    }
    free(Fila->frente);
}

/******************************
 * Exercicios
 ******************************/

// Copia os elementos de uma Fila F1 para uma Fila F2.
void CopiarF(TFila *F1, TFila *F2) {
    TFila Aux;
    TProduto x;
    FFVazia(&Aux);
    int contido = 0;

    while (!VaziaF(*F1)) {
        Desenfileirar(F1, &x);
        contido = PesquisarF(F2, &x);
        if (!contido) {
            Enfileirar(x, F2);
        }
        Enfileirar(x, &Aux);
    }

    while (!VaziaF(Aux)) {
        Desenfileirar(&Aux, &x);
        Enfileirar(x, F1);
    }
    free(Aux.frente);
}

// Inverte a ordem dos elementos em uma Fila.
void InverterF(TFila *Fila) {
    TProduto x;
    
    if (VaziaF(*Fila)) {
        return;
    } else {
        Desenfileirar(Fila, &x);
        InverterF(Fila);
        Enfileirar(x, Fila);
    }
}
