#include <stdio.h>
#include <stdlib.h>
#include "inteiros.h"

int main(void)
{
    int number_of_aig_nodes = 0;
    printf("Escolha quantos nós do gráfico AIG (exemplo: 5)\n");
    scanf("%d", &number_of_aig_nodes);
    fflush(stdin);

    AIG_NODE aig_table[number_of_aig_nodes];

    int i;
    for (i = 0; i < number_of_aig_nodes; i++)
    {
        aig_table[i].adjacent1 = -1;
        aig_table[i].adjacent2 = -1;
    }

    int option_number;
    do
    {
        option_number = menu();
        options(aig_table, option_number, number_of_aig_nodes);
        printf("\n\n----------------------------\n");

    } while (option_number);

    free(aig_table);
    return 0;
}

AIG_NODE insert(AIG_NODE aig_node)
{

    printf("Qual Nó possui sua saída conectada a entrada deste Nó AIG selecionado \nDigite o nó (digite '-1' se não houver):  ");
    scanf(" %d", &aig_node.adjacent1);
    fflush(stdin);
    if (aig_node.adjacent1 != -1)
    {
        printf("É invertido? (1 - Sim / 0 - Não) \n");
        scanf(" %d", &aig_node.inverted1);
        fflush(stdin);
    }

    printf("Qual Nó possui sua saída conectada a entrada deste Nó AIG selecionado \nDigite o nó (digite '-1' se não houver):  ");
    scanf(" %d", &aig_node.adjacent2);
    fflush(stdin);
    if (aig_node.adjacent2 != -1)
    {
        printf("É invertido? (1 - Sim / 0 - Não) \n");
        scanf(" %d", &aig_node.inverted2);
    }

    return aig_node;
}

int print_aig(AIG_NODE aig_node)
{
    if(aig_node.adjacent1 == -1 && aig_node.adjacent2 == -1){
        return 1;
    }
    if (aig_node.adjacent1 != -1)
    {
        printf("\tSaída do AIG %d (Invertido? %d) conectada a entrada deste AIG\n", aig_node.adjacent1, aig_node.inverted1);
    }
    if (aig_node.adjacent2 != -1)
    {
        printf("\tSaída do AIG %d (Invertido? %d) conectada a entrada deste AIG\n", aig_node.adjacent2, aig_node.inverted2);
    }     
    return 0;
}

int menu(void)
{
    int option_number;

    printf("Escolha a opção desejada:\n");
    printf("0. Sair\n");
    printf("1. Exibir representação do grafo AIG\n");
    printf("2. Adicionar adjacência\n");
    printf("Digite o número da opção: ");
    scanf("%d", &option_number);
    fflush(stdin);

    return option_number;
}

void options(AIG_NODE aig_table[], int opt, int number_of_aig_nodes)
{
    int aig_number = 0;
    int i = 0;

    switch (opt)
    {
    case 0:
        exit(0);
        break;

    case 1:
        for (i = 0; i < number_of_aig_nodes; i++)
        {
            printf("\nLista de adjacências de %d:\n", i);
            if (print_aig(aig_table[i]))
                printf("\tNó AIG %d sem adjacência!\n\n", i);
        }
        break;

    case 2:
        printf("Deseja adicionar adjacências em qual nó AIG?\n");
        fflush(stdin);
        scanf(" %d", &aig_number);
        fflush(stdin);
        if (aig_number < number_of_aig_nodes)
        {
            aig_table[aig_number] = insert(aig_table[aig_number]);
        }
        else
        {
            printf("Erro! Deve ser um valor entre 0 e %d!\n", number_of_aig_nodes);
        }
        break;

    default:
        printf("Comando inválido!\n\n");
    }
}
