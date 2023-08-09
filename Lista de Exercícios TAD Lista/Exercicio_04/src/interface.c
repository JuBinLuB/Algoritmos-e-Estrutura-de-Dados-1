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
    printf("  \n\t[4] - IMPRIMIRL1");
    printf("  \n\t[5] - IMPRIMIRL2");
    printf("  \n\t[6] - IMPRIMIRL3");
    printf("  \n\t[7] - DIVIDIR");
    printf("  \n\t[8] - SAIR");
}

void MENU(TLista *L1) {
    TLista L2, L3;
    TProduto produto;
    FLVazia(&L2);
    FLVazia(&L3);
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
                Inserir(produto, L1);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                TCelula *endereco = Pesquisar(*L1, produto);

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

                Excluir(L1, &produto);
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu ImprimirL1
                */
                printf("\n\t#4 Imprimir L1:\n");
                Imprimir(*L1);
                printf("\n\tTamanho da Lista: %d\n", L1->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu ImprimirL2
                */
                printf("\n\t#5 Imprimir L2:\n");
                Imprimir(*L1);
                printf("\n\tTamanho da Lista: %d\n", L1->tamanho);
                system("PAUSE");
                break;
            case 6:
                /**
                    Codigo para opcao de menu ImprimirL3
                */
                printf("\n\t#6 Imprimir L3:\n");
                Imprimir(*L1);
                printf("\n\tTamanho da Lista: %d\n", L1->tamanho);
                system("PAUSE");
                break;
            case 7:
                /**
                    Codigo para opcao de menu Dividir
                */
                DividirLista(L1, &L2, &L3);
                printf("\n\tLista dividida com sucesso!\n");
                system("PAUSE");
                break;
            case 8:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarLista(L1);
                LiberarLista(&L2);
                LiberarLista(&L3);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 8);
}
