#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void FLVazia(TLista *Lista) {
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int VaziaL(TLista Lista) {
    return (Lista.primeiro == Lista.ultimo);
}

void InserirL(TProduto x, TLista *Lista) {
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void ImprimirL(TLista Lista) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;

    while (Aux != NULL) {
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
    }
}

TCelula *PesquisarL(TLista Lista, TProduto Item) {
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

void ExcluirL(TLista *Lista, TProduto *Item) {
    TCelula *Aux1, *Aux2;
    Aux1 = PesquisarL(*Lista, *Item);

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

/******************************
 * Lista de Exercicios
 ******************************/

// #1 - Insere elementos em ordem crescente de nomes.
void InserirCrescente(TProduto x, TLista *Lista) {
    if (Vazia(*Lista)) {
        Inserir(x, Lista);
    } else if (strcmp(x.nome, Lista->ultimo->item.nome) > 0) {
        Inserir(x, Lista);
    } else {
        TCelula *seguinte, *anterior;
        seguinte = Lista->primeiro->prox;
        anterior = Lista->primeiro;

        while (strcmp(x.nome, seguinte->item.nome) > 0) {
            seguinte = seguinte->prox;
            anterior = anterior->prox;
        }
        anterior->prox = (TCelula *)malloc(sizeof(TCelula));
        anterior->prox->item = x;
        anterior->prox->prox = seguinte;
        Lista->tamanho++;
    }
}

// #2 - Verifica se duas listas simplesmente encadeadas sao iguais.
int VerificarIgualdade(TLista *L1, TLista *L2) {
    TCelula *Aux1, *Aux2;
    Aux1 = L1->primeiro->prox;
    Aux2 = L2->primeiro->prox;

    while (Aux1 != NULL && Aux2 != NULL) {
        if (Aux1->item.codigo != Aux2->item.codigo && 
            strcmp(Aux1->item.nome, Aux2->item.nome) != 0 && 
            Aux1->item.preco != Aux2->item.preco) {
                return 0;
        }
        Aux1 = Aux1->prox;
        Aux2 = Aux2->prox;
    }

    if (Aux1 == NULL && Aux2 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// #3 - Concatena duas listas simplesmente encadeadas passadas como parametros.
void Concatenar(TLista *L1, TLista *L2) {
    if (L1 == NULL || L2 == NULL) {
        return;
    }

    TCelula *Aux;
    Aux = L2->primeiro->prox;

    while (Aux != NULL) {
        Inserir(Aux->item, L1);
        Aux = Aux->prox;
    }
}

// #4 - Divide a lista L1 pela metade em duas outras listas L2 e L3.
void DividirLista(TLista *L1, TLista *L2, TLista *L3) {
    if (L1 == NULL || L2 == NULL || L3 == NULL) {
        return;
    }
    if (L1->tamanho == 1) {
        return;
    }

    TCelula *Aux = L1->primeiro->prox;
    int atual = 0;
    int meio = L1->tamanho / 2;

    while (Aux != NULL) {
        if (atual < meio || (meio != 0 && atual == meio)) {
            Inserir(Aux->item, L2);
        } else {
            Inserir(Aux->item, L3);
        }
        atual++;
        Aux = Aux->prox;
    }
}

// #5 - Imprime os dados da i-esima celula de uma lista simplesmente encadeada.
void ImprimirICelula(TLista Lista, int i) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;
    int contador = 1;

    while (contador < i) {
        Aux = Aux->prox;
        contador++;
    }

    if (Aux != NULL) {
        ImprimirProduto(Aux->item);
    } else {
        printf("\n\tCelula nao existe.\n");
    }
}

// #6 - Remove a i-esima celula de uma lista simplesmente encadeada.
void ExcluirICelula(TLista Lista, int i) {
    TCelula *Aux;
    Aux = Lista.primeiro->prox;
    int contador = 1;

    while (contador < i) {
        Aux = Aux->prox;
        contador++;
    }

    if (Aux != NULL) {
        Excluir(&Lista, &Aux->item);
    } else {
        printf("\n\tCelula nao existe.\n");
    }
}

// #7 - Realiza a impressao de uma lista de maneira recursiva.
void ImprimirRecursivo(TCelula *Celula) {
    if (Celula->prox == NULL) {
        return;
    } else {
        ImprimirProduto(Celula->prox->item);
        ImprimirRecursivo(Celula->prox);
    }
}

// #8 - Realiza a pesquisa de um elemento, por meio do nome, de maneira recursiva.
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

// #9 - Inverte a ordem dos elementos de uma lista simplesmente encadeada.
void Inverter(TLista *Lista) {
    TCelula *anterior, *atual, *seguinte;
    anterior = Lista->primeiro->prox;
    atual = anterior->prox;
    anterior->prox = NULL;

    while (atual != NULL) {
        seguinte = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = seguinte;
    }
    Lista->ultimo = Lista->primeiro->prox;
    Lista->primeiro->prox = anterior;
}
