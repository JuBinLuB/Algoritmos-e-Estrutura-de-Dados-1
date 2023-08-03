#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void Iniciar(TCelulaA **no) {
    *no = NULL;
}

void Central(TCelulaA *x) {
    if (x != NULL) {
        Central(x->esq);
        ImprimirProduto(x->item);
        Central(x->dir);
    }
}

void PreOrdem(TCelulaA *x) {
    if (x != NULL) {
        ImprimirProduto(x->item);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

void PosOrdem(TCelulaA *x) {
    if (x != NULL) {
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        ImprimirProduto(x->item);
    }
}

TCelulaA *PesquisarA(TCelulaA *x, TProduto Item) {
    if (x == NULL || x->item.codigo == Item.codigo) {
        return x;
    }
    if (Item.codigo < x->item.codigo) {
        return PesquisarA(x->esq, Item);
    } else {
        return PesquisarA(x->dir, Item);
    }
}

TCelulaA *Maximo(TCelulaA *x) {
    if (x == NULL || x->dir == NULL) {
        return x;
    } else {
        return Maximo(x->dir);
    }
}

TCelulaA *Minimo(TCelulaA *x) {
    if (x == NULL || x->esq == NULL) {
        return x;
    } else {
        return Minimo(x->esq);
    }
}

TCelulaA *Sucessor(TCelulaA *x) {
    if (x == NULL) {
        return NULL;
    }
    if (x->dir != NULL) {
        return Minimo(x->dir);
    }
    TCelulaA *y = x->pai;
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

TCelulaA *Predecessor(TCelulaA *x) {
    if (x == NULL) {
        return NULL;
    }
    if (x->esq != NULL) {
        return Maximo(x->esq);
    }
    TCelulaA *y = x->pai;
    while (y != NULL && x == y->esq) {
        x = y;
        y = y->pai;
    }
    return y;
}

TCelulaA *criaNo(TProduto Item){
    TCelulaA *no = (TCelulaA*)malloc(sizeof(TCelulaA));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void InserirA(TCelulaA **x, TCelulaA *pai, TProduto Item) {
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
void Transplante(TArvore *Arvore, TCelulaA **u, TCelulaA **v) {
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
void Retirar(TArvore *Arvore, TCelulaA **z) {
    if (*z == NULL) {
        printf("\n>>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if ((*z)->esq == NULL) {
        Transplante(Arvore, z, &(*z)->dir);
    } else if ((*z)->dir == NULL) {
        Transplante(Arvore, z, &(*z)->esq);
    } else {
        TCelulaA *y = Minimo((*z)->dir);
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

/************************************
 * Lista de Exercicios TAD Arvore
 ************************************/

// Questao 06 - Versao iterativa de in-ordem.
void CentralIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int foiVisitado = 0;

    while (Aux != NULL) {
        // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
        if (!foiVisitado) {
            // Enquanto a celula atual tiver um filho a esquerda, o caminhamento continua para a esquerda.
            while (Aux->esq != NULL) {
                Aux = Aux->esq;
            }
        }

        // Imprime o item da celula atual.
        ImprimirProduto(Aux->item);
        // Sinaliza que o filho a esquerda ja foi visitado.
        foiVisitado = 1;

        // Verifica se a celula atual tem filho a direita.
        if (Aux->dir != NULL) {
            Aux = Aux->dir;
            // Filho a esquerda da nova celula ainda nao foi visitado.
            foiVisitado = 0;
        } else if (Aux->pai != NULL) {
            // Enquanto Aux tiver pai e for um filho a direita de seu pai.
            while (Aux->pai != NULL && Aux == Aux->pai->dir) {
                Aux = Aux->pai;
            }

            // Se o pai da celula atual for nulo, termine o caminhamento.
            if (Aux->pai == NULL) {
                break;
            }
            Aux = Aux->pai;
        } else {
            // Se a celula, atual nao tiver filho a direita, nem pai, termine o caminhamento.
            break;
        }
    }
}

// Questao 06 - Versao iterativa de pre-ordem.
void PreOrdemIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int esqVisitada = 0;

    while (Aux != NULL) {
        // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
        if (!esqVisitada) {
            // Imprime o item da celula atual.
            ImprimirProduto(Aux->item);

            // Verifica se a celula atual tem filho a esquerda.
            if (Aux->esq != NULL) {
                Aux = Aux->esq;
                // Passa para a proxima iteracao do loop.
                continue;
            }
        }

        // Sinaliza que o filho a esquerda ja foi visitado.
        esqVisitada = 1;

        // Verifica se a celula atual tem filho a direita.
        if (Aux->dir != NULL) {
            Aux = Aux->dir;
            // Filho a esquerda da nova celula ainda nao foi visitado.
            esqVisitada = 0;
        } else if (Aux->pai != NULL) {
            // Enquanto Aux tiver pai e for um filho a direita de seu pai.
            while (Aux->pai != NULL && Aux == Aux->pai->dir) {
                Aux = Aux->pai;
            }

            // Se o pai da celula atual for nulo, termine o caminhamento.
            if (Aux->pai == NULL) {
                break;
            }
            Aux = Aux->pai;
        } else {
            // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
            break;
        }
    }
}

// // Questao 06 - Versao iterativa de pos-ordem.
void PosOrdemIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int esqVisitada = 0;

    while (Aux != NULL) {
        // Verifica se a celula atual tem filho a esquerda.
        if (!esqVisitada) {
            // Avanca para a extrema esquerda.
            while (Aux->esq != NULL) {
                Aux = Aux->esq;
            }
        }

        // Sinaliza que o filho a esquerda ja foi visitado.
        esqVisitada = 1;

        // Verifica se a celula atual tem filho a direita.
        if (Aux->dir != NULL) {
            Aux = Aux->dir;
            // Filho a esquerda da nova celula ainda nao foi visitado.
            esqVisitada = 0;
        } else if (Aux->pai != NULL) {
            // Enquanto Aux tiver pai e for um filho a direita de seu pai.
            while (Aux->pai != NULL && Aux == Aux->pai->dir) {
                Aux = Aux->pai;
            }

            // Se o pai da celula atual for nulo, termine o caminhamento.
            if (Aux->pai == NULL) {
                break;
            }
            Aux = Aux->pai;
        } else {
            // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
            break;
        }
    }
}

// Questao 07 - Versao iterativa da funcao INSERIR.
void InserirIterativa(TCelulaA **raiz, TProduto Item) {
    TCelulaA *Aux1, *Aux2;
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
void CentralPilha(TCelulaA *x) {
    TCelulaA *Aux1, *Aux2;
    TPilha Pilha;
    TProduto produto;
    FPVazia(&Pilha);

    Aux1 = x;
    Aux2 = NULL;
    int finalizado = 0;

    while (!finalizado) {
        if (Aux1 != NULL) {
            Empilhar(Aux1->item, &Pilha);
            Aux2 = Aux1;
            Aux1 = Aux2->esq;
        } else {
            if (!VaziaP(Pilha)) {
                Desempilhar(&Pilha, &produto);
                ImprimirProduto(produto);
                Aux1 = Aux2->dir;
                Aux2 = Aux2->pai;
            } else {
                finalizado = 1;
            }
        }

    }
}
