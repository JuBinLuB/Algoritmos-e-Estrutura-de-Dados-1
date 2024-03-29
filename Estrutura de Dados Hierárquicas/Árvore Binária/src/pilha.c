#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

void FPVazia(TPilha *Pilha) {
    Pilha->topo = (TCelulaP *)malloc(sizeof(TCelulaP));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int VaziaP(TPilha Pilha) {
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha) {
    TCelulaP *Aux;
    Aux = (TCelulaP *)malloc(sizeof(TCelulaP));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item) {
    TCelulaP *q;

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
        }
        Empilhar(x, Pilha);
    }
    free(Aux.topo);

    if (encontrado) {
        return 1;
    } else {
        Item->codigo = -1;
        return 0;
    }
}

/******************************
 * Exercicios
 ******************************/

// Inverter uma Pilha utilizando duas Pilhas auxiliares.
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
    free(P2.topo);
    free(P3.topo);
}

// Transfere os elementos da Pilha P1 para P2 sem alterar a ordem dos elementos.
void TransferirP(TPilha *P1, TPilha *P2) {
    TProduto x;
    
    if (VaziaP(*P1)) {
        return;
    } else {
        Desempilhar(P1, &x);
        TransferirP(P1, P2);
        Empilhar(x, P2);
    }
}

// Inverter uma Pilha utilizando somente uma Pilha auxiliar.
void InverterPC(TPilha *Pilha) {
    TPilha Aux;
    TProduto x;
    FPVazia(&Aux);

    TransferirP(Pilha, &Aux);

    while (!VaziaP(Aux)) {
        Desempilhar(&Aux, &x);
        Empilhar(x, Pilha);
    }
    free(Aux.topo);
}
