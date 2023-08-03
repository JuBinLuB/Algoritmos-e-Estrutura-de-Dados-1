#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU() {
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t[1] - INSERIR");
    printf("  \n\t[2] - PESQUISAR");
    printf("  \n\t[3] - RETIRAR");
    printf("  \n\t[4] - IN-ORDEM");
    printf("  \n\t[5] - PRE-ORDEM");
    printf("  \n\t[6] - POS-ORDEM");
    printf("  \n\t[7] - MAXIMO");
    printf("  \n\t[8] - MINIMO");
    printf("  \n\t[9] - SUCESSOR");
    printf("  \n\t[10] - PREDECESSOR");
    printf("  \n\t[11] - IN-ORDEM ITERATIVA");
    printf("  \n\t[12] - PRE-ORDEM ITERATIVA");
    printf("  \n\t[13] - POS-ORDEM ITERATIVA");
    printf("  \n\t[14] - INSERIR ITERATIVA");
    printf("  \n\t[15] - IN-ORDEM W/ PILHA");
    printf("  \n\t[16] - SAIR");
}

void MENU(TArvore *Arvore) {
    TCelulaA *y;
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
                InserirA(&Arvore->raiz, NULL, produto);
                break;
            case 2:
                /**
                    Codigo para opcao de menu Pesquisar
                */
                printf("\n\t#2 Pesquisar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                y = PesquisarA(Arvore->raiz, produto);

                if (y != NULL) {
                    printf("\n\tItem %d encontrado...\n", y->item.codigo);
                    ImprimirProduto(y->item);
                } else {
                    printf("\n\tItem nao encontrado.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 3:
                /**
                    Codigo para opcao de menu Retirar
                */
                printf("\n\t#3 Retirar:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                y = PesquisarA(Arvore->raiz, produto);

                if (y != NULL){
                    printf("\n\tItem %d encontrado...\n", y->item.codigo);
                    ImprimirProduto(y->item);
                    Retirar(Arvore, &y);
                    printf("\n\tElemento removido da arvore.\n");
                } else {
                    printf("\n\tItem nao encontrado...\n");
                }
                system("PAUSE");
                break;
            case 4:
                /**
                    Codigo para opcao de menu In-Ordem
                */
                printf("\n\t#4 Caminhamento in-ordem:\n");

                if (Arvore->raiz != NULL) {
                    Central(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 5:
                /**
                    Codigo para opcao de menu Pre-Ordem
                */
                printf("\n\t#5 Caminhamento pre-ordem:\n");

                if (Arvore->raiz != NULL) {
                    PreOrdem(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 6:
                /**
                    Codigo para opcao de menu Pos-Ordem
                */
                printf("\n\t#6 Caminhamento pos-ordem:\n");

                if (Arvore->raiz != NULL) {
                    PosOrdem(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 7:
                /**
                    Codigo para opcao de menu Maximo
                */
                printf("\n\t#7 Maximo:\n");
                y = Maximo(Arvore->raiz);

                if (y != NULL) {
                    ImprimirProduto(y->item);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 8:
                /**
                    Codigo para opcao de menu Minimo
                */
                printf("\n\t#8 Minimo:\n");
                y = Minimo(Arvore->raiz);

                if (y != NULL) {
                    ImprimirProduto(y->item);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 9:
                /**
                    Codigo para opcao de menu Sucessor
                */
                printf("\n\t#9 Sucessor:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                y = PesquisarA(Arvore->raiz, produto);

                y = Sucessor(y);
                if (y != NULL) {
                    printf("\n\tSucessor:\n");
                    ImprimirProduto(y->item);
                } else {
                    printf("\n\tItem nao possui sucessor.\n");
                }
                system("PAUSE");
                break;
            case 10:
                /**
                    Codigo para opcao de menu Predecessor
                */
                printf("\n\t#10 Predecessor:\n");
                printf("\tInforme o codigo do item: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                y = PesquisarA(Arvore->raiz, produto);

                y = Predecessor(y);
                if (y != NULL) {
                    printf("\n\tPredecessor:\n");
                    ImprimirProduto(y->item);
                } else {
                    printf("\n\tItem nao possui Predecessor.\n");
                }
                system("PAUSE");
                break;
            case 11:
                /**
                    Codigo para opcao de menu In-Ordem Iterativa
                */
                printf("\n\t#11 Caminhamento in-ordem iterativo:\n");

                if (Arvore->raiz != NULL) {
                    CentralIterativa(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 12:
                /**
                    Codigo para opcao de menu Pre-Ordem Iterativa
                */
                printf("\n\t#12 Caminhamento pre-ordem iterativo:\n");

                if (Arvore->raiz != NULL) {
                    PreOrdemIterativa(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 13:
                /**
                    Codigo para opcao de menu Pos-Ordem Iterativa
                */
                printf("\n\t#13 Caminhamento Pos-ordem iterativo:\n");

                if (Arvore->raiz != NULL) {
                    PosOrdemIterativa(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 14:
                /**
                    Codigo para opcao de menu Inserir Iterativa
                */
                printf("\n\t#14 Inserir iterativa:\n");
                LerProduto(&produto);
                InserirIterativa(&Arvore->raiz, produto);
                break;
            case 15:
                /**
                    Codigo para opcao de menu In-Ordem w/ Pilha
                */
                printf("\n\t#15 Caminhamento in-ordem usando Pilha:\n");

                if (Arvore->raiz != NULL) {
                    CentralPilha(Arvore->raiz);
                } else {
                    printf("\n\tErro: Arvore vazia.\n");
                }
                printf("\n");
                system("PAUSE");
                break;
            case 16:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<< \n\n");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<< \n\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 16);
}
