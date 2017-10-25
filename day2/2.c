#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
	
	}Node;
	
	
	
void push (struct Node** node, int value)
{
	struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
	
	
	new_node->data=value; //insert data 
	new_node->next=(*node);
	(*node)=new_node;
	
	 
	 }	
	

	
void printList(struct Node* node)
{	
		while (node != NULL)
		{
			printf("%d", node->data);
			node=node->next;
			}
		
	}


	
void split(struct Node *head, struct Node **a, struct Node **b) 
{
	struct Node *even = NULL;
	struct Node *odd = NULL;
	struct Node *list = NULL;
    struct Node *link;
    struct Node *current;

   while(list != NULL) {
      struct Node *link = (struct Node*) malloc(sizeof(struct Node));
         
      link->data = list->data;
      link->next = NULL;
         
      if(list->data%2 == 0) {
         if(even == NULL) {
            even = link;
            list = list->next;
            continue;
         }else {
            current = even;
                
            while(current->next != NULL)
            current = current->next;
                
            // Insert link at the end of the list
            current->next = link; 
         }
         list = list->next;
      }else {
         if(odd == NULL) {
            odd = link;
            list = list->next;
            continue;
         }else {
            current = odd;
            while(current->next!=NULL)
            current = current->next;
                
            // Insert link at the end of the list
            current->next = link; 

         }
         list = list->next;
      }
   }
}
	
	
	
	
	
	
	
	
	
	int main()
{
	struct Node *node=NULL;
	struct Node *c=NULL;
	struct Node *b=NULL;
	int a, i;
	for (i=0; i<5; i++)
	{
		printf("Enter the nubmer:");
		scanf("%d", &a);
		push(&node, a);
		
		}


	return 0;
}
