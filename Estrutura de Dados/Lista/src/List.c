#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct {
    int codigo;
} TProduto;

typedef struct Celula {
    TProduto item;
    struct Celula *prox;
} TCelula;

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *lista) {
    lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->tamanho = 0;
}

int Vazia(TLista lista) {
    return (lista.primeiro == lista.ultimo);
}

void Inserir(TProduto x, TLista *lista) {
    lista->primeiro->prox = (TCelula *)malloc(sizeof(TCelula));
    lista->ultimo = lista->primeiro->prox;
    lista->ultimo->prox->item = x;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

TCelula* Pesquisar(TLista lista, TProduto item) {
    TCelula *Aux;
    Aux = lista.primeiro;

    while(Aux != NULL) {
        if(Aux->prox->item.codigo == item.codigo) {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void Imprimir(TLista lista) {
    TCelula *Aux;
    Aux = lista.primeiro->prox;

    while(Aux != NULL) {
        printf("%d", Aux->item.codigo);
        Aux = Aux->prox;
    }
}
