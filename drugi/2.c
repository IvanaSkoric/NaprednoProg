#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};
	
	
void push(struct Node** node, int value)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	new_node->data = value;
	new_node->next = *node;
	*node = new_node;
}

void printList(struct Node* node)
{	
	
		while (node != NULL)
		{
			printf("%d", node->data);
			node=node->next;
			}
		
	}
	
void svaki_drugi(struct Node* node) {
	
struct Node *parni = NULL;
struct Node *neparni = NULL;
int brojac = 0;

	
	while (node != NULL)
	{

		if (brojac %2 == 0)
		{
		
				push(&neparni, node->data);
		}
		else 
			{
				push(&parni, node->data);
			}
			
			
		node=node->next;
		brojac++;
	}

}


	
	int main()
{
	struct Node *node=NULL;
	
	int i;
	for (i=0; i<10; i++)
	{
		push(&node, i);
		}
		
	svaki_drugi(node);
	printf("\n Elementi s parnim indeksom: ");
	printList(parni);
	printf("\n Elementi s neparnim indeksom: ");
	printList(neparni);
	return 0;
	
	
}
