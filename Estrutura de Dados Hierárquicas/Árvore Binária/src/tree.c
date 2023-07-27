#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void Iniciar(TCelula **no) {
    *no = NULL;
}

void Central(TCelula *x) {
    if (x != NULL) {
        Central(x->esq);
        ImprimirProduto(x->item);
        Central(x->dir);
    }
}

void PreOrdem(TCelula *x) {
    if (x != NULL) {
        ImprimirProduto(x->item);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

void PosOrdem(TCelula *x) {
    if (x != NULL) {
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        ImprimirProduto(x->item);
    }
}

TCelula *PesquisarA(TCelula *x, TProduto Item) {
    if (x == NULL || x->item.codigo == Item.codigo) {
        return x;
    }
    if (Item.codigo < x->item.codigo) {
        return PesquisarA(x->esq, Item);
    } else {
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
    TCelula *no = (TCelula*)malloc(sizeof(TCelula));
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

// Substitui subarvore enraizada no no' "u" pela subarvore enraizada no no' "v".
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

// Retira um no' "z" na arvore "Arvore".
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

/*
    >>>>> Lista de Exercicios <<<<<
*/

// Questao 06 - Versao iterativa de in-ordem.
void CentralIterativa(TCelula *x) {
    int visitado = 0;

    while (x != NULL) {
        if (!visitado) {
            while (x->esq != NULL) {
                x = x->esq;
            }
        }

        ImprimirProduto(x->item);
        visitado = 1;

        if (x->dir != NULL) {
            x = x->dir;
            visitado = 0;
        } else if (x->pai != NULL) {
            while (x->pai != NULL && x == x->pai->dir) {
                x = x->pai;
            }

            if (x->pai == NULL) {
                break;
            }
            x = x->pai;
        } else {
            break;
        }
    }
}

// Questao 06 - Versao iterativa de pre-ordem.
void PreOrdemIterativa(TCelula *x) {

}

// Questao 06 - Versao iterativa de pos-ordem.
void PosOrdemIterativa(TCelula *x) {

}

// Questao 07 - Versao iterativa da funcao Inserir.
void InserirIterativa(TCelula **raiz, TProduto Item) {
    TCelula *Aux1, *Aux2;
    Aux1 = *raiz;
    Aux2 = NULL;

    while (Aux1 != NULL) {
        Aux2 = Aux1;
        if (Item.codigo < Aux1->item.codigo) {
            Aux1 = Aux1->esq;
        } else {
            Aux1 = Aux1->dir;
        }
    }

    Aux1 = criaNo(Item);
    Aux1->pai = Aux2;

    if (Aux2 == NULL) {
        *raiz = Aux1;
    } else if (Item.codigo < Aux2->item.codigo) {
        Aux2->esq = Aux1;
    } else {
        Aux2->dir = Aux1;
    }
}

// Questao 08 - Versao iterativa de in-ordem utilizando TAD Pilha como estrutura de dados auxiliar.
void CentralP(TCelula *x) {
    TCelula *Aux = x;
    TProduto produto;
    TPilha Pilha;
    FPVazia(&Pilha);

    int finalizado = 0;
    while (!finalizado) {
        if (Aux != NULL) {
            Empilhar(Aux->item, &Pilha);
            Aux = Aux->esq;
        } else {
            if (!VaziaP(Pilha)) {
                Desempilhar(&Pilha, &produto);
                ImprimirProduto(produto);
                Aux = Aux->dir;
            } else {
                finalizado = 1;
            }
        }
    }
}
