#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

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
