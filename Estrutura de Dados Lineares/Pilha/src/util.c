#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void LerProduto(TProduto *x) {
    // Ler codigo
    printf("\tInforme o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);
    // Ler nome
    printf("\tInforme o nome: ");
    fflush(stdin);
    fgets(x->nome, 19, stdin);
    // Ler Preco
    printf("\tInforme o preco: ");
    fflush(stdin);
    scanf("%f", &x->preco);
}

void ImprimirProduto(TProduto x) {
    printf("\n\tCodigo: %d", x.codigo);
    printf("\n\tNome: %s", x.nome);
    printf("\tPreco: R$%.2f\n", x.preco);
}
