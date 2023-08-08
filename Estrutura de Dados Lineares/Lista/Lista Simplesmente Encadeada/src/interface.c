#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - INSERIR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - EXCLUIR");
    printf("  \n\t[4] - IMPRIMIR");
    printf("  \n\t[5] - INSERIR CRESCENTE");
    printf("  \n\t[6] - IMPRIMIR I-ESIMA CELULA");
    printf("  \n\t[7] - EXCLUIR I-ESIMA CELULA");
    printf("  \n\t[8] - IMPRIMIR RECURSIVO");
    printf("  \n\t[9] - PESQUISAR RECURSIVO");
    printf("  \n\t[10] - INVERTER");
    printf("  \n\t[11] - SAIR");
}

void MENU(TLista *Lista) {
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
                    Codigo para opcao de menu Inserir
                */
                printf("\n\t#1 Inserir:\n");
                LerProduto(&produto);
                InserirL(produto, Lista);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                TCelula *endereco = PesquisarL(*Lista, produto);

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

                ExcluirL(Lista, &produto);
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#4 Imprimir:\n");
                ImprimirL(*Lista);
                printf("\n\tTamanho da Lista: %d\n", Lista->tamanho);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Inserir Crescente
                */
                printf("\n\t#2 Inserir Crescente:\n");
                LerProduto(&produto);
                InserirCrescente(produto, Lista);
                break;
            case 6:
                /**
                    Codigo para opcao de menu Imprimir I-esima Celula
                */
                printf("\n\t#5 Imprimir I-Celula:\n");
                int i = 0;

                printf("\tInforme a celula: ");
                fflush(stdin);
                scanf("%d", &i);
                ImprimirICelula(*Lista, i);
                system("PAUSE");
                break;
            case 7:
                /**
                    Codigo para opcao de menu Excluir I-esima Celula
                */
                printf("\n\t#5 Excluir I-Celula:\n");
                int i = 0;

                printf("\tInforme a celula: ");
                fflush(stdin);
                scanf("%d", &i);
                ExcluirICelula(*Lista, i);
                system("PAUSE");
                break;
            case 8:
                /**
                    Codigo para opcao de menu Imprimir Recursivo
                */
                printf("\n\t#4 Imprimir:\n");
                TCelula *celula;
                celula = Lista->primeiro;

                ImprimirRecursivo(celula);

                printf("\n\tTamanho da Lista: %d\n", Lista->tamanho);
                system("PAUSE");
                break;
            case 9:
                /**
                    Codigo para opcao de menu Pesquisar Recursivo
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o nome do item: ");
                fflush(stdin);
                fgets(produto.nome, 19, stdin);

                TCelula *celula = Lista->primeiro;
                TCelula *endereco = PesquisarRecursivo(celula, produto);

                if (endereco) {
                    printf("\n\tItem encontrado: ");
                    printf("\n\tEndereco: %p", endereco->prox);
                    ImprimirProduto(endereco->prox->item);
                } else {
                    printf("\n\tItem nao encontrado.\n");
                }
                system("PAUSE");
                break;
            case 10:
                /**
                    Codigo para opcao de menu Inverter
                */
                system("cls");
                Inverter(Lista);
                break;
            case 11:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                LiberarLista(Lista);     
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 11);
}
