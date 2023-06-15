#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct TProduto;

typedef struct Celula TCelula;

typedef struct TLista;

void FLVazia(TLista *lista);

int Vazia(TLista lista);

void Inserir(TProduto x, TLista *lista);

void Imprimir(TLista lista);

TCelula* Pesquisar(TLista lista, TProduto item);

#endif //LIST_H_INCLUDED