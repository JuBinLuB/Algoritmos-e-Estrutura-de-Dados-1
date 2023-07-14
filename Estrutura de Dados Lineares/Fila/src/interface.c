#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - ENFILEIRAR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - DESENFILEIRAR");
    printf("  \n\t[4] - IMPRIMIR F1");
    printf("  \n\t[5] - IMPRIMIR F2");
    printf("  \n\t[6] - COPIAR");
    printf("  \n\t[7] - INVERTER");
    printf("  \n\t[8] - SAIR");
}

void MENU(TFila *Fila) {
    TFila F2;
    TProduto produto;
    FFVazia(&F2);
    int opcao = 0;

    do {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                /**
                    Codigo para opcao de menu Enfileirar
                */
                printf("\n\t#1 Enfileirar:\n");
                LerProduto(&produto);
                Enfileirar(produto, Fila);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o nome do item: ");
                fflush(stdin);
                fgets(produto.nome, 19, stdin);

                int encontrado = PesquisarF(Fila, &produto);

                if (encontrado) {
                    printf("\n\tItem encontrado.\n");
                } else {
                    printf("\n\tItem nao encontrado.\n");
                }
                system("PAUSE");
                break;
            case 3:
                /**
                    Codigo para opcao de menu Desenfileirar
                */
                printf("\n\t#3 Desenfileirar:\n");
                Desenfileirar(Fila, &produto);
                printf("\n\tItem removido: ");
                ImprimirProduto(produto);
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu Imprimir F1
                */
                printf("\n\t#4 Imprimir F1:\n");
                ImprimirF(Fila);
                printf("\n\tTamanho da Fila: %d\n", Fila->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Imprimir F2
                */
                printf("\n\t#5 Imprimir F2:\n");
                if (!VaziaF(F2)) {
                    ImprimirF(&F2);
                } else {
                    printf("\n\tErro: Fila vazia.\n");
                }
                printf("\n\tTamanho da Fila: %d\n", F2.tamanho);
                system("PAUSE");
                break;
            case 6:
                /**
                    Codigo para opcao de menu Copiar
                */
                CopiarF(Fila, &F2);
                printf("\n\tFila copiada.\n");
                system("PAUSE");
                break;
            case 7:
                /**
                    Codigo para opcao de menu Inverter
                */
                InverterF(Fila);
                printf("\n\tFila invertida.\n");
                system("PAUSE");
                break;
            case 8:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarFila(Fila);
                LiberarFila(&F2);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 8);
}
