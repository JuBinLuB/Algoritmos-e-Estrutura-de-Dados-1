#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct TProduto;

typedef struct celula TCelula;

typedef struct TLista;

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

void Imprimir(TLista Lista);

TCelula *Pesquisar(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

#endif //LIST_H_INCLUDED