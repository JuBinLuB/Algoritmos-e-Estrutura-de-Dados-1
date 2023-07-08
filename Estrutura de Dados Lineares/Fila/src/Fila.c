#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void FFVazia(TFila *Fila) {
    Fila->frente = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila) {
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

    if (!Vazia(*Fila)) {
        Aux = Fila->frente->prox;
        Fila->frente = Aux;
        *Item = Aux->item;
        free(Aux);

        if (Fila->frente->prox == NULL) {
            Fila->tras = Fila->frente;
        }
        Fila->tamanho--;
    }
}

void Imprimir(TFila *Fila) {
    TFila Aux;
    TProduto x;
    FFVazia(&Aux);

    while (!Vazia(*Fila)) {
        Desenfileirar(Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &Aux);
    }

    while (!Vazia(Aux)) {
        Desenfileirar(&Aux, &x);
        Enfileirar(x, Fila);
    }
    free(Aux.frente);
}

int Pesquisar(TFila *Fila, TProduto *x) {
    TProduto Aux;
    int flag = 0;

    while (!Vazia(*Fila)) {
        Desenfileirar(Fila, &Aux);
        if (strcmp(Aux.nome, x->nome) == 0) {
            flag = 1;
        }
        Enfileirar(Aux, Fila);
    }

    if (flag = 1) {
        return 1;
    } else {
        return 0;
    }
}

void LiberarFila(TFila *Fila) {
    TProduto x;

    while (!Vazia(*Fila)) {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

void copiarFila(TFila *F1, TFila *F2) {
    TFila Aux;
    TProduto x;
    FFVazia(&Aux);

    while (!Vazia(*F1)) {
        Desenfileirar(F1, &x);
        Enfileirar(x, F2);
        Enfileirar(x, &Aux);
    }

    while (!Vazia(Aux)) {
        Desenfileirar(&Aux, &x);
        Enfileirar(x, F1);
    }
    free(Aux.frente);
}
