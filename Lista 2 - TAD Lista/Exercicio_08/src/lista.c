#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void FLVazia(TLista *Lista) {
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista) {
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista) {
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void Imprimir(TLista Lista) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;

    while (Aux != NULL) {
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
    }
}

TCelula *Pesquisar(TLista Lista, TProduto Item) {
    TCelula *Aux;
    Aux = Lista.primeiro;

    while (Aux->prox != NULL) {
        if (Aux->prox->item.codigo == Item.codigo) {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item) {
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);

    if (Aux1 != NULL) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;

        if (Aux1->prox == NULL) {
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;
    } else {
        printf("\n\tItem nao encontrado.\n");
    }
}

void LiberarLista(TLista *Lista) {
    TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;

    while (Aux1->prox != NULL) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        free(Aux2);
    }
    free(Aux1);
}

TCelula *PesquisarRecursivo(TCelula *Celula, TProduto Item) {
    if (Celula->prox == NULL) {
        return NULL;
    }
    if (strcmp(Celula->prox->item.nome, Item.nome) == 0) {
        return Celula;
    } else {
        return PesquisarRecursivo(Celula->prox, Item);
    }
}
