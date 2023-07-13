#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "lista.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - INSERIR");
    printf("  \n\t[2] - INSERIR CRESCENTE");
    printf("  \n\t[3] - PESQUISAR");
    printf("  \n\t[4] - EXCLUIR");
    printf("  \n\t[5] - IMPRIMIR");
    printf("  \n\t[6] - SAIR");
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
                Inserir(produto, Lista);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Inserir em Ordem Crescente de nomes
                */
                printf("\n\t#2 Inserir Crescente:\n");
                LerProduto(&produto);
                InserirCrescente(produto, Lista);
                break;
            case 3:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#3 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                TCelula *endereco = Pesquisar(*Lista, produto);

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

                Excluir(Lista, &produto);
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Imprimir
                */
                printf("\n\t#5 Imprimir:\n");
                Imprimir(*Lista);
                printf("\n\tTamanho da Lista: %d\n", Lista->tamanho);
                system("PAUSE");
                break;
            case 6:
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
    } while(opcao != 6);
}
