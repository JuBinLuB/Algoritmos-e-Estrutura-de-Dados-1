#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "fila.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - ENFILEIRAR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - DESENFILEIRAR");
    printf("  \n\t[4] - IMPRIMIR");
    printf("  \n\t[5] - COPIAR");
    printf("  \n\t[6] - SAIR");
}

void MENU(TFila *Fila) {
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

                int encontrado = Pesquisar(Fila, produto);

                if (encontrado) {
                    printf("\n\tItem encontrado.");
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
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#4 Imprimir:\n");
                Imprimir(Fila);
                printf("\n\tTamanho da Fila: %d\n", Fila->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Inverter
                */
                system("cls");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarFila(Fila);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 6);
}
