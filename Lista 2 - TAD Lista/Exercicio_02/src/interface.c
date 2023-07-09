#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "lista.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - INSERIR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - EXCLUIR");
    printf("  \n\t[4] - IMPRIMIR");
    printf("  \n\t[5] - IGUAIS");
    printf("  \n\t[6] - SAIR");
}

void MENU(TLista *Lista1) {
    TLista Lista2;
    TProduto produto;
    FLVazia(&Lista2);
    int opcao = 0;

    do {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                /**
                    Codigo para opcao de menu Inserir
                */
                printf("\n\t#1 Inserir:\n");
                LerProduto(&produto);
                Inserir(produto, Lista1);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                TCelula *endereco = Pesquisar(*Lista1, produto);

                if (endereco) {
                    printf("\n\tItem encontrado: ");
                    printf("\n\tEndereco: %p", endereco->prox);
                    ImprimirProduto(endereco->prox->item);
                } else {
                    printf("\n\tItem nao encontrado.\n");
                }
                system("PAUSE");
                break;
            case 3:
                /**
                    Codigo para opcao de menu Excluir
                */
                printf("\n\t#3 Excluir:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                Excluir(Lista1, &produto);
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#4 Imprimir:\n");
                Imprimir(*Lista1);
                printf("\n\tTamanho da Lista: %d\n", Lista1->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Iguais
                */
                printf("\n\t#5 Iguais:\n");
                if (VerificarIgualdade(Lista1, &Lista2)) {
                    printf("\n\tAs listas sao iguais.\n");
                } else {
                    printf("\n\tAs listas nao sao iguais.\n");
                }
                system("PAUSE");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarLista(Lista1);
                LiberarLista(&Lista2);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 6);
}
