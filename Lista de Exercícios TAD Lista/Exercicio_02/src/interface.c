#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "lista.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - INSERIRL1");
    printf("\n\n\t[2] - INSERIRL2");
    printf("  \n\t[3] - PESQUISAR");
    printf("  \n\t[4] - EXCLUIR");
    printf("  \n\t[5] - IMPRIMIR");
    printf("  \n\t[6] - IGUAIS");
    printf("  \n\t[7] - SAIR");
}

void MENU(TLista *L1) {
    TLista L2;
    TProduto produto;
    FLVazia(&L2);
    int opcao = 0;

    do {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                /**
                    Codigo para opcao de menu InserirL1
                */
                printf("\n\t#1 Inserir:\n");
                LerProduto(&produto);
                Inserir(produto, L1);
                break;
            case 2:
                /**
                    Codigo para opcao de menu InserirL2
                */
                printf("\n\t#2 InserirL2:\n");
                LerProduto(&produto);
                Inserir(produto, &L2);
                break;
            case 3:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#3 Pesquisar:\n");
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
            case 4:
                /**
                    Codigo para opcao de menu Excluir
                */
                printf("\n\t#4 Excluir:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                Excluir(L1, &produto);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#5 Imprimir:\n");
                Imprimir(*L1);
                printf("\n\tTamanho da Lista: %d\n", L1->tamanho);
                system("PAUSE");
                break;
            case 6:
                /**
                    Codigo para opcao de menu Iguais
                */
                printf("\n\t#6 Iguais:\n");
                if (VerificarIgualdade(L1, &L2)) {
                    printf("\n\tAs listas sao iguais.\n");
                } else {
                    printf("\n\tAs listas nao sao iguais.\n");
                }
                system("PAUSE");
                break;
            case 7:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarLista(L1);
                LiberarLista(&L2);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 7);
}
