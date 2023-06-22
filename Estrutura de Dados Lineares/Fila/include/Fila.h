#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct item {
    char nome[20];
    int codigo;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct fila {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

#endif // FILA_H_INCLUDED