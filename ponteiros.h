typedef struct Node
{
    int adjacent;
    int inverted;
	struct Node *next;
} AIG_NODE;

void insert(AIG_NODE *aig_node);
int empty_aig(AIG_NODE *aig_table);
int print_aig(AIG_NODE *aig_node);
int menu(void);
void options(AIG_NODE *aig_table[], int opt, int number_of_aig_nodes);
