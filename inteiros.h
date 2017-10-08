typedef struct Node
{
    int adjacent1;
    int inverted1;
    int adjacent2;
    int inverted2;    
} AIG_NODE;

AIG_NODE insert(AIG_NODE aig_node);
int print_aig(AIG_NODE aig_node);
int menu(void);
void options(AIG_NODE aig_table[], int opt, int number_of_aig_nodes);
