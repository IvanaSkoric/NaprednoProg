#include<stdio.h>
#include<stdlib.h>
#

struct Node 
{
	float data;
	struct Node *next;
};
	
	
void push(struct Node** node, float value)
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
			printf(" %.2f ", node->data);
			node=node->next;
			}
		
	}
	

void direktno (struct Node *node)
{
	float sum;
	while (node != NULL)
	{
		sum += node->data;
		node=node->next;
		}
	printf("%f", sum);
	
	}
	
	
	
void posredno (struct Node *prva, struct Node *druga)
{
		float rez=0;
		while (prva != NULL) //dok ima el u prvoj listi, mnozi prvi el sa svakim, mnozi drugi el sa svakim...itd
		{ 
			while (druga != NULL)
			{
				rez += (prva->data)*(druga->data);
				druga=druga->next;
				
				}
				
			
				prva=prva->next;
				printf("aaa %f	", rez);
			}
	
	
	printf("%f", rez);
	}
	
	
	
	
int main()
{
	struct Node *a=NULL;
	struct Node *b=NULL;
	
	push(&a, 1);
	push(&a, 2);

	
	push(&b, 3);
	push(&b, 4);
	push(&b, 5);
	push(&b, 6);

	printf("Ovo je prva lista: ");
	printList(a);
	printf("\nOvo je druga lista: ");
	printList(b);
	
	printf("\nOvo j direktno:");
	direktno(a);
	
	printf("\nOvo j posredno:");
	posredno(a, b);


	return 0;
	
	
}	
