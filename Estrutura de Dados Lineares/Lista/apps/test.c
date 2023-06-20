#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

int main(void) {
    TProduto x;
    TLista Lista;

    // #1: Teste da funcao FLVazia.
    FLVazia(&Lista);
    int vazia = Vazia(Lista);
    printf("\n#1:\tFLVazia: %d\n", vazia);

    // #2:Teste da funcao Inserir.
    printf("#2:\tInserir:\n");

    int num;

    printf("\tInforme a quantidade de produtos: ");
    fflush(stdin);
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("\n\t#%d Produto...\n", (i + 1));
        LerProduto(&x);
        Inserir(x, &Lista);
    }

    // #3: Teste da funcao Imprimir.
    printf("\n#3:\tImprimir:\n\n");
    Imprimir(Lista);
    printf("\tTamanho: %d\n\n", Lista.tamanho);

    // #4: Teste da funcao Pesquisar.
    printf("#4:\tPesquisar:\n");
    printf("\tInforme o codigo do item: ");
    fflush(stdin);
    scanf("%d", &x.codigo);

    TCelula *endereco = Pesquisar(Lista, x);

    if (endereco) {
        printf("\n\tResultado:");
        printf("\n\tEndereco: %p\n", endereco->prox);
        printf("\tItem: %s\n", endereco->prox->item.nome);
    } else {
        printf("\n\tItem nao encontrado.\n");
    }

    // #5:Teste da funcao Excluir.
    printf("#5:\tExcluir:\n");
    printf("\tInforme o codigo do item: ");
    fflush(stdin);
    scanf("%d", &x.codigo);
    Excluir(&Lista, &x);

    // #6: Teste de verificacao de Exclusao.
    printf("\n#6\tProduto Excluido:\n");
    ImprimirProduto(x);

    // #7: Teste da versao final da Lista.
    printf("\n#7:\tImpressao Final:\n\n");
    Imprimir(Lista);
    printf("\tTamanho: %d\n", Lista.tamanho);

    return 0;
}

void LerProduto(TProduto *x) {
    // Ler codigo.
    printf("\tInforme o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);
    // Ler nome.
    printf("\tInforme o nome: ");
    fflush(stdin);
    fgets(x->nome, 49, stdin);
}

void ImprimirProduto(TProduto x) {
    printf("\n\tCodigo: %d", x.codigo);
    printf("\n\tNome: %s", x.nome);
}
