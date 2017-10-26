#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct Node 
{
	int data;
	struct Node *prev;
	struct Node *next;
	}Node;
	
	
void push (struct Node** head, int value)
{
	struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
	
	
	new_node->data=value; //insert data 
	
	new_node->next=(*head); //next of new node is head
	new_node->prev=NULL;	//prev of new node is null
	
	if((*head) != NULL)		//prev of head node is the new node
		(*head)->prev=new_node;
		
	 (*head)=new_node; //head is now the new_node
	 
	 }
	 
void printList (struct Node *node)
{

	struct Node *fast=node;
	struct Node *slow=node;
	struct Node *lijevo;
	if (node != NULL)
		{
			while (fast != NULL && fast->next !=NULL)
				{
					fast=fast->next->next;
					slow=slow->next;
					
					} printf("Niz %d", slow->data);
					lijevo=slow;
					while (lijevo->next != NULL && slow->prev != NULL)
					{
						lijevo=lijevo->next;
						slow=slow->prev;
						printf("%d", slow->data);
						printf ("%d", lijevo->data);
						
						}

			}	
	
}

	


int main()
{
	struct Node *node=NULL;
	int i;
	for (i=0; i<9; i++)
	{
		
		push(&node, i);
		
		}
	
	
	printList(node);

	return 0;
}
