#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

void FPVazia(TPilha*Pilha) {
    Pilha->topo = (TCelula *)malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int VaziaP(TPilha Pilha) {
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha) {
    TCelula *Aux;
    Aux = (TCelula *)malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item) {
    TCelula *q;

    if (VaziaP(*Pilha)) {
        printf("Erro: Pilha Vazia!\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

void LiberarPilha(TPilha *Pilha) {
    while (!VaziaP(*Pilha)) {
        Desempilhar(Pilha, &Pilha->topo->item);
    }
    free(Pilha->topo);
}

void ImprimirP(TPilha *Pilha) {
    TPilha Aux;
    TProduto x;
    FPVazia(&Aux);

    while (!VaziaP(*Pilha)) {
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux);
    }

    while (!VaziaP(Aux)) {
        Desempilhar(&Aux, &x);
        ImprimirProduto(x);
        Empilhar(x, Pilha);
    }
    free(Aux.topo);
}

int PesquisarP(TPilha *Pilha, TProduto *Item) {
    TPilha Aux;
    TProduto x;
    FPVazia(&Aux);
    int encontrado = 0;

    while(!VaziaP(*Pilha)) {
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux);
    }

    while (!VaziaP(Aux)) {
        Desempilhar(&Aux, &x);
        if (strcmp(x.nome, Item->nome) == 0) {
            encontrado = 1;
            *Item = x;
        } else {
            Item->codigo = -1;
        }
        Empilhar(x, Pilha);
    }

    if (encontrado) {
        return 1;
    } else {
        return 0;
    }
}

void InverterPA(TPilha *Pilha) {
    TFila Fila;
    TProduto x;
    FFVazia(&Fila);

    while (!VaziaP(*Pilha)) {
        Desempilhar(Pilha, &x);
        Enfileirar(x, &Fila);
    }

    while (!VaziaF(Fila)) {
        Desenfileirar(&Fila, &x);
        Empilhar(x, Pilha);
    }
}

void InverterPB(TPilha *P1) {
    TPilha P2, P3;
    TProduto x;
    FPVazia(&P2);
    FPVazia(&P3);

    while (!VaziaP(*P1)) {
        Desempilhar(P1, &x);
        Empilhar(x, &P2);
    }

    while (!VaziaP(P2)) {
        Desempilhar(&P2, &x);
        Empilhar(x, &P3);
    }

    while (!VaziaP(P3)) {
        Desempilhar(&P3, &x);
        Empilhar(x, P1);
    }
}

void InverterPC(TPilha *Pilha) {
    TPilha Aux;
    TProduto x;
    FPVazia(&Aux);

    while (!VaziaP(*Pilha)) {
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux);
    }

    while (!VaziaP(Aux)) {
        Desempilhar(&Aux, &x);
        Empilhar(x, Pilha);
    }
}
