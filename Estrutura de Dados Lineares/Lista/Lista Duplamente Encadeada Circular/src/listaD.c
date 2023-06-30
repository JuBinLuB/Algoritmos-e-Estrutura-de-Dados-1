#include <stdio.h>
#include <stdlib.h>

#include "listaD.h"

void FLDVazia(TLista *Lista) {
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = Lista->primeiro;
    Lista->primeiro->ant = Lista->primeiro;
    Lista->tamanho = 0;
}

int VaziaLD(TLista Lista) {
    return (Lista.primeiro == Lista.ultimo);
}

void InserirLD(TProduto x, TLista *Lista) {
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo->prox->ant = Lista->ultimo;
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = Lista->primeiro;
    Lista->primeiro->ant = Lista->ultimo;
    Lista->tamanho++;
}

void ImprimirLD(TLista Lista) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;

    while (Aux != Lista.primeiro) {
        printf("\n\tCodigo: %d", Aux->item.codigo);
        printf("\n\tNome: %s", Aux->item.nome);
        printf("\tPreco: R$%.2f\n", Aux->item.preco);
        Aux = Aux->prox;
    }
}

TCelula *PesquisarLD(TLista Lista, TProduto Item) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;

    while (Aux != Lista.primeiro) {
        if (Aux->item.codigo == Item.codigo) {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void ExcluirLD(TLista *Lista, TProduto *Item) {
    TCelula *Aux;
    Aux = PesquisarLD(*Lista, *Item);

    if (Aux != NULL) {
        Aux->ant->prox = Aux->prox;
        Aux->prox->ant = Aux->ant;
        *Item = Aux->item;

        if (Aux->prox == Lista->primeiro) {
            Lista->ultimo = Aux->ant;
        }
        free(Aux);
        Lista->tamanho--;
    } else {
        printf("\n\tItem nao encontrado.\n");
    }
}

void LiberarListaLD(TLista *Lista) {
    TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;

    while (Aux1->prox != Lista->primeiro) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        Aux2->prox->ant = Aux1;
        free(Aux2);
    }
    free(Aux1);
}

void LerProduto(TProduto *x) {
    // Ler codigo.
    printf("\tInforme o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);
    // Ler nome.
    printf("\tInforme o nome: ");
    fflush(stdin);
    fgets(x->nome, 49, stdin);
    // Ler Preco.
    printf("\tInforme o preco: ");
    fflush(stdin);
    scanf("%f", &x->preco);
}

void ImprimirProduto(TProduto x) {
    printf("\n\tCodigo: %d", x.codigo);
    printf("\n\tNome: %s", x.nome);
    printf("\tPreco: R$%.2f\n", x.preco);
}
