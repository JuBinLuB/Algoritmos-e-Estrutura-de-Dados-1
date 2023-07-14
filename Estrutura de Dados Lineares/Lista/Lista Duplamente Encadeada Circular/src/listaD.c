#include <stdio.h>
#include <stdlib.h>

#include "listaD.h"

void FLDVazia(TLista *ListaD) {
    ListaD->primeiro = (TCelula *)malloc(sizeof(TCelula));
    ListaD->ultimo = ListaD->primeiro;
    ListaD->primeiro->prox = ListaD->primeiro;
    ListaD->primeiro->ant = ListaD->primeiro;
    ListaD->tamanho = 0;
}

int VaziaLD(TLista Lista) {
    return (Lista.primeiro == Lista.ultimo);
}

void InserirLD(TProduto x, TLista *ListaD) {
    ListaD->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    ListaD->ultimo->prox->ant = ListaD->ultimo;
    ListaD->ultimo = ListaD->ultimo->prox;
    ListaD->ultimo->item = x;
    ListaD->ultimo->prox = ListaD->primeiro;
    ListaD->primeiro->ant = ListaD->ultimo;
    ListaD->tamanho++;
}

void ImprimirLD(TLista ListaD) {
    TCelula *Aux;
    Aux = ListaD.primeiro->prox;

    while (Aux != ListaD.primeiro) {
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
    }
}

TCelula *PesquisarLD(TLista ListaD, TProduto Item) {
    TCelula *Aux;
    Aux = ListaD.primeiro->prox;

    while (Aux != ListaD.primeiro) {
        if (Aux->item.codigo == Item.codigo) {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void ExcluirLD(TLista *ListaD, TProduto *Item) {
    TCelula *Aux;
    Aux = PesquisarLD(*ListaD, *Item);

    if (Aux != NULL) {
        Aux->ant->prox = Aux->prox;
        Aux->prox->ant = Aux->ant;
        *Item = Aux->item;

        if (Aux->prox == ListaD->primeiro) {
            ListaD->ultimo = Aux->ant;
        }
        free(Aux);
        ListaD->tamanho--;
    } else {
        printf("\n\tItem nao encontrado.\n");
    }
}

void LiberarListaLD(TLista *ListaD) {
    TCelula *Aux1, *Aux2;
    Aux1 = ListaD->primeiro;

    while (Aux1->prox != ListaD->primeiro) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        Aux2->prox->ant = Aux1;
        free(Aux2);
    }
    free(Aux1);
}
