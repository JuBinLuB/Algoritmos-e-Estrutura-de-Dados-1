#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

int main(void) {
    TProduto x;
    TLista Lista;

    int digito;
    int aberto = 1;

    while (aberto) {
        printf("\t--------- MENU ---------\n");
        printf("\t[1] - Fazer Lista Vazia\n");
        printf("\t[2] - Inserir\n");
        printf("\t[3] - Imprimir\n");
        printf("\t[4] - Pesquisar\n");
        printf("\t[5] - Excluir\n");
        printf("\t[6] - Encerrar\n");

        do {
            printf("\n\tEscolha uma opcao para navegar pelo Menu: ");
            fflush(stdin);
            scanf("%d", &digito);
        } while (digito < 1 && digito > 6);

        switch (digito) {
        case 1:
            // #1: Teste da funcao FLVazia.
            FLVazia(&Lista);
            int vazia = Vazia(Lista);
            printf("\n#1:\tFLVazia: %d\n", vazia);
            break;
        case 2:
            // #2:Teste da funcao Inserir.
            printf("\n#3:\tInserir:\n");

            int num;

            printf("\tInforme a quantidade de produtos: ");
            fflush(stdin);
            scanf("%d", &num);

            for (int i = 0; i < num; i++) {
                printf("\n\t#%d Produto...\n", (i + 1));
                LerProduto(&x);
                Inserir(x, &Lista);
            }
            break;
        case 3:
            // #3: Teste da funcao Imprimir.
            printf("\n#4:\tImprimir:\n");
            Imprimir(Lista);
            printf("\n\tTamanho da Lista: %d\n", Lista.tamanho);
            break;
        case 4:
            // #4: Teste da funcao Pesquisar.
            printf("\n#5:\tPesquisar:\n");
            printf("\tInforme o codigo do item: ");
            fflush(stdin);
            scanf("%d", &x.codigo);

            TCelula *endereco = Pesquisar(Lista, x);

            if (endereco) {
                printf("\n\tResultado da Pesquisa: ");
                printf("\n\tEndereco: %p", endereco->prox);
                ImprimirProduto(endereco->prox->item);
            } else {
                printf("\n\tItem nao encontrado.\n");
            }
            break;
        case 5:
            // #5:Teste da funcao Excluir.
            printf("\n#6:\tExcluir:\n");
            printf("\tInforme o codigo do item: ");
            fflush(stdin);
            scanf("%d", &x.codigo);

            Excluir(&Lista, &x);

            printf("\n\tProduto removido: ");
            ImprimirProduto(x);
            break;
        case 6:
            // Encerrar Menu.
            aberto = 0;
            printf("\n\tMenu Encerrado.");
            break;
        }
        printf("\n");
    }

    // #7: Teste impressao final da Lista.
    printf("\n#7:\tImpressao Final:\n");
    Imprimir(Lista);
    printf("\n\tTamanho: %d\n", Lista.tamanho);

    // #8: Liberando memoria alocada.
    LiberarLista(&Lista);
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
