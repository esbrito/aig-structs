#include <stdio.h>
#include <stdlib.h>

struct Node{
	int adjacent;
	struct Node *next;
};
typedef struct Node node;

void init(node *list)
{
	list->next = NULL;
}

int empty_list(node *list)
{
	if(list->next == NULL)
		return 1;
	else
		return 0;
}


void insert(node *list)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->adjacent);
	novo->next = NULL;
	if(empty_list(list))
		list->next=novo;
	else{
		node *tmp = list->next;
		while(tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = novo;
	}
}

void print_list(node *list)
{
	if(empty_list(list)){
		printf("List is empty\n\n");
		return ;
	}
	node *tmp;
	tmp = list->next;
	while( tmp != NULL){
		printf("%5d", tmp->adjacent);
		tmp = tmp->next;
	}
	printf("\n\n");
}


int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir list\n");
	printf("2. Adicionar\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *list, int op)
{
	switch(op){
		case 0:
			exit(0);
			break;

		case 1:
			print_list(list);
			break;

		case 2:
			insert(list);
			break;

		default:
			printf("Comando invalido\n\n");
	}
}


int main(void)
{
	node *list = (node *) malloc(sizeof(node));
	if(!list){
		exit(1);
	}
	init(list);
  int opt;
  do{
		opt=menu();
		opcao(list,opt);
	}while(opt);

	free(list);
	return 0;
}
