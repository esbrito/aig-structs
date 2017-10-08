#include <stdio.h>
#include <stdlib.h>
#include "ponteiros.h"

int main(void)
{
	int number_of_aig_nodes = 0;
	printf("Escolha quantos nós do gráfico AIG (exemplo: 5)\n");
	scanf("%d", &number_of_aig_nodes);
	fflush(stdin);	

	AIG_NODE *aig_table[number_of_aig_nodes];

	int i;
	for (i = 0; i < number_of_aig_nodes; i++)
	{
		aig_table[i] = (AIG_NODE *) malloc(sizeof(AIG_NODE));		
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


int empty_aig(AIG_NODE *aig_table)
{
	if (aig_table->next == NULL)
		return 1;
	else
		return 0;
}

void insert(AIG_NODE *aig_node)
{
	AIG_NODE *new = (AIG_NODE *)malloc(sizeof(AIG_NODE));
	if (!new)
	{
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Qual Nó é adjacente a este Nó AIG? \nDigite o nó adjacente a este:  ");
	scanf(" %d", &new->adjacent);
	fflush(stdin);
	printf("É invertido? (1 - Sim / 0 - Não) \n");
	scanf(" %d", &new->inverted);
	fflush(stdin);		
	new->next = NULL;
	if (empty_aig(aig_node))
		aig_node->next = new;
	else
	{
		AIG_NODE *tmp = aig_node->next;
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = new;
	}
}

int print_aig(AIG_NODE *aig_node)
{
	if (empty_aig(aig_node))
	{
		return 1;
	}
	AIG_NODE *tmp;
	tmp = aig_node->next;
	while (tmp != NULL)
	{
		printf("* %d", tmp->adjacent); 
		printf(" - Invertido: %d \n", tmp->inverted);		
		tmp = tmp->next;
	}
	printf("\n\n");
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

void options(AIG_NODE *aig_table[], int opt, int number_of_aig_nodes)
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
			printf("Lista de adjacências de %d:\n", i);
			if(print_aig(aig_table[i])) printf("\tNó AIG %d sem adjacência!\n\n", i);
		}
		break;

	case 2:
		printf("Deseja adicionar adjacência em qual nó AIG?\n");
		fflush(stdin);				
		scanf(" %d", &aig_number);
		fflush(stdin);
		if(aig_number < number_of_aig_nodes){
		insert(aig_table[aig_number]);
		}else{
			printf("Erro! Deve ser um valor entre 0 e %d!\n", number_of_aig_nodes);
		}
		break;

	default:
		printf("Comando inválido!\n\n");
	}
}
