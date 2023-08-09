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

void LiberarArvore(TCelulaA *x) {
    if (x == NULL) {
        return;
    } else {
        LiberarArvore(x->esq);
        LiberarArvore(x->dir);
        free(x);
    }
}

/******************************
 * Lista de Exercicios
 ******************************/

// Questao 06 - Versao iterativa de in-ordem.
void CentralIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int esqVisitada = 0;

    while (Aux != NULL) {
        if (!esqVisitada) { // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
            while (Aux->esq != NULL) { // Enquanto a celula atual tiver um filho a esquerda, o caminhamento continua para a esquerda.
                Aux = Aux->esq;
            }
        }

        ImprimirProduto(Aux->item); // Imprime o item da celula atual.
        esqVisitada = 1; // Sinaliza que o filho a esquerda ja foi visitado.

        if (Aux->dir != NULL) { // Verifica se a celula atual tem filho a direita.
            Aux = Aux->dir;
            esqVisitada = 0; // Filho a esquerda da nova celula ainda nao foi visitado.
        } else if (Aux->pai != NULL) {
            while (Aux->pai != NULL && Aux == Aux->pai->dir) { // Enquanto Aux tiver pai e for um filho a direita de seu pai.
                Aux = Aux->pai;
            }

            if (Aux->pai == NULL) { // Se o pai da celula atual for nulo, termine o caminhamento.
                break;
            }
            Aux = Aux->pai;
        } else {
            break; // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
        }
    }
}

// Questao 06 - Versao iterativa de pre-ordem.
void PreOrdemIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int esqVisitada = 0;

    while (Aux != NULL) {
        if (!esqVisitada) { // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
            ImprimirProduto(Aux->item); // Imprime o item da celula atual.

            if (Aux->esq != NULL) { // Verifica se a celula atual tem filho a esquerda.
                Aux = Aux->esq;
                continue; // Passa para a proxima iteracao do loop.
            }
        }

        esqVisitada = 1; // Sinaliza que o filho a esquerda ja foi visitado.

        if (Aux->dir != NULL) { // Verifica se a celula atual tem filho a direita.
            Aux = Aux->dir;
            esqVisitada = 0; // Filho a esquerda da nova celula ainda nao foi visitado.
        } else if (Aux->pai != NULL) {
            while (Aux->pai != NULL && Aux == Aux->pai->dir) { // Enquanto Aux tiver pai e for um filho a direita de seu pai.
                Aux = Aux->pai;
            }

            if (Aux->pai == NULL) { // Se o pai da celula atual for nulo, termine o caminhamento.
                break;
            }
            Aux = Aux->pai;
        } else {
            break; // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
        }
    }
}

// // Questao 06 - Versao iterativa de pos-ordem.
void PosOrdemIterativa(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    int esqVisitada = 0;

    while (Aux != NULL) {
        if (!esqVisitada) { // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
            while (Aux->esq != NULL) { // Avanca para a extrema esquerda.
                Aux = Aux->esq;
            }
        }

        esqVisitada = 1; // Sinaliza que o filho a esquerda ja foi visitado.

        if (Aux->dir != NULL) { // Verifica se a celula atual tem filho a direita.
            Aux = Aux->dir;
            esqVisitada = 0; // Filho a esquerda da nova celula ainda nao foi visitado.
        } else if (Aux->pai != NULL) {
            ImprimirProduto(Aux->item); // Imprime o item da celula atual.

            while (Aux->pai != NULL && Aux == Aux->pai->dir) { // Enquanto Aux tiver pai e for um filho a direita de seu pai.
                Aux = Aux->pai;
                ImprimirProduto(Aux->item); // Imprime o item da celula atual pos avancar para o pai da celula anterior.
            }
            
            if (Aux->pai == NULL) { // Se o pai da celula atual for nulo, termine o caminhamento.
                break;
            }

            Aux = Aux->pai;
        } else {
            break; // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
        }
    }
}

// Questao 07 - Versao iterativa da funcao INSERIR.
void InserirIterativa(TCelulaA **raiz, TProduto Item) {
    TCelulaA *Aux1, *Aux2;
    Aux1 = *raiz; // Aux1 aponta para a mesma regiao que a raiz.
    Aux2 = NULL;

    while (Aux1 != NULL) {
        Aux2 = Aux1; // Aux2 percorre a arvore juntamente de Aux1.
        if (Item.codigo < Aux1->item.codigo) { // Verifica onde o item devera ser inserido.
            Aux1 = Aux1->esq; // Caso menor, avanca para a esquerda.
        } else {
            Aux1 = Aux1->dir; // Caso contrario, avanca para a direita.
        }
    }

    Aux1 = criaNo(Item); // Cria uma nova celula, atribuindo-a a Aux1.
    Aux1->pai = Aux2; // Faz Aux2 ser o pai da celula recem-criada.

    if (Aux2 == NULL) { // Se Aux2 for nulo, a arvore era vazia.
        *raiz = Aux1; // Logo, a raiz apontara para a celula recem-criada, apontada por Aux1.
    } else if (Item.codigo < Aux2->item.codigo) { // Verifica se a celula recem-criada sera filho a esquerda ou a direita.
        Aux2->esq = Aux1;
    } else {
        Aux2->dir = Aux1;
    }
}

// Questao 08 - Versao iterativa de in-ordem utilizando TAD Pilha como estrutura de dados auxiliar.
void CentralPilha(TCelulaA *raiz) {
    TCelulaA *Aux = raiz;
    TProduto produto;
    TPilha Pilha;
    FPVazia(&Pilha);

    int esqVisitada = 0;

    while (Aux != NULL) {
        if (!esqVisitada) { // Verifica se a celula atual ainda nao teve seu filho a esquerda visitado.
            Empilhar(Aux->item, &Pilha); // Empilha o item da celula atual.

            if (Aux->esq != NULL) { // Verifica se a celula a esquerda da celula atual existe.
                Aux = Aux->esq;
                continue;
            }
        }

        esqVisitada = 1; // Sinaliza que o filho a esquerda ja foi visitado.

        if (!VaziaP(Pilha)) { // Verifica se a Pilha contem itens.
            Desempilhar(&Pilha, &produto);
            ImprimirProduto(produto); // Imprime o item desempilhado do topo da Pilha.
        }
        
        if (Aux->dir != NULL) { // Verifica se a celula atual tem filho a direita.
            Aux = Aux->dir;
            esqVisitada = 0; // Filho a esquerda da nova celula ainda nao foi visitado.
        } else if (Aux->pai != NULL) {
            while (Aux->pai != NULL && Aux == Aux->pai->dir) { // Enquanto Aux tiver pai e for um filho a direita de seu pai.
                Aux = Aux->pai;
            }

            if (Aux->pai == NULL) { // Se o pai da celula atual for nulo, termine o caminhamento.
               break;
            }
            Aux = Aux->pai;
        } else {
            break; // Se a celula atual nao tiver filho a direita, nem pai, termine o caminhamento.
        }
    }
}
