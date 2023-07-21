#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void Central(TCelula *x) {
    if (x != NULL) {
        Central(x->esq);
        printf("%d", x->item.codigo);
        Central(x->dir);
    }
}

void PreOrdem(TCelula *x) {
    if (x != NULL) {
        printf("%d", x->item.codigo);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

void PosOrdem(TCelula *x) {
    if (x != NULL) {
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        printf("%d", x->item.codigo);
    }
}

TCelula *PesquisarA(TCelula *x, TProduto Item) {
    if (x == NULL || x->item.codigo == Item.codigo) {
        return x;
    }
    if (Item.codigo < x->item.codigo) {
        return PesquisarA(x->esq, Item);
    } else if (Item.codigo > x->item.codigo) {
        return PesquisarA(x->dir, Item);
    }
}

TCelula *Maximo(TCelula *x) {
    if (x == NULL || x->dir == NULL) {
        return x;
    } else {
        return Maximo(x->dir);
    }
}

TCelula *Minimo(TCelula *x) {
    if (x == NULL || x->esq == NULL) {
        return x;
    } else {
        return Minimo(x->esq);
    }
}

TCelula *Sucessor(TCelula *x) {
    if (x == NULL) {
        return NULL;
    }
    if (x->dir != NULL) {
        return Minimo(x->dir);
    }
    TCelula *y = x->pai;
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

TCelula *Predecessor(TCelula *x) {
    if (x == NULL) {
        return NULL;
    }
    if (x->esq != NULL) {
        return Maximo(x->esq);
    }
    TCelula *y = x->pai;
    while (y != NULL && x == y->esq) {
        x = y;
        y = y->pai;
    }
    return y;
}

TCelula *criaNo(TProduto Item){
    TCelula *no = (TCelula*) malloc(sizeof(TCelula));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void InserirA(TCelula **x, TCelula *pai, TProduto Item) {
    if ((*x) == NULL) {
        (*x) = criaNo(Item);
        if (pai != NULL) {
            (*x)->pai = pai;
        }
        return;
    }
    if ((*x)->item.codigo > Item.codigo) {
        InserirA(&(*x)->esq, *x, Item);
        return;
    }
    if ((*x)->item.codigo < Item.codigo) {
        InserirA(&(*x)->dir, *x, Item);
    }
}

void Transplante(TArvore *Arvore, TCelula **u, TCelula **v) {
    if ((*u)->pai == NULL) {
        Arvore->raiz = (*v);
    } else if ((*u) == (*u)->pai->esq) {
        (*u)->pai->esq = *(v);
    } else {
        (*u)->pai->dir = (*v);
    }
    if (*v != NULL) {
        (*v)->pai = (*u)->pai;
    }
}

void Retirar(TArvore *Arvore, TCelula **z) {
    if (*z == NULL) {
        printf("\n>>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if ((*z)->esq == NULL) {
        Transplante(Arvore, z, &(*z)->dir);
    } else if ((*z)->dir == NULL) {
        Transplante(Arvore, z, &(*z)->esq);
    } else {
        TCelula *y = Minimo((*z)->dir);
        if (y->pai != (*z)) {
            Transplante(Arvore, &y, &y->dir);
            y->dir = (*z)->dir;
            y->dir->pai = y;
        }
        Transplante(Arvore, z, &y);
        y->esq = (*z)->esq;
        y->esq->pai = y;
    }
    free(*z);
    *z = NULL;
}
