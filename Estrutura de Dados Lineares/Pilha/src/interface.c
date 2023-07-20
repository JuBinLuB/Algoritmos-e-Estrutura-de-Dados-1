#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - EMPILHAR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - DESEMPILHAR");
    printf("  \n\t[4] - IMPRIMIR");
    printf("  \n\t[5] - INVERTER");
    printf("  \n\t[6] - SAIR");
}

void MENU(TPilha *Pilha) {
    TProduto produto;
    int opcao = 0;

    do {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                /**
                    Codigo para opcao de menu Empilhar
                */
                printf("\n\t#1 Empilhar:\n");
                LerProduto(&produto);
                Empilhar(produto, Pilha);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                int encontrado = PesquisarP(Pilha, &produto);

                if (encontrado) {
                    printf("\n\tItem encontrado: ");
                    ImprimirProduto(produto);
                } else {
                    printf("\n\tItem nao encontrado.\n");
                }
                system("PAUSE");
                break;
            case 3:
                /**
                    Codigo para opcao de menu Desempilhar
                */
                printf("\n\t#3 Desempilhar:\n");
                Desempilhar(Pilha, &produto);
                printf("\n\tItem desempilhado:\n");
                ImprimirProduto(produto);
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#4 Imprimir:\n");
                ImprimirP(Pilha);
                printf("\n\tTamanho da Pilha: %d\n", Pilha->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Inverter
                */
                // InverterPA(Pilha);
                // InverterPB(Pilha);
                InverterPC(Pilha);
                printf("\n\tPilha invertida.\n");
                system("PAUSE");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarPilha(Pilha);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 6);
}
