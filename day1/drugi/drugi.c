#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include<assert.h>
	
	
	void create_list(int n);
	void displayList();
	
struct Node
{
    int data;
    struct Node* next;
};
 
/* pull off the front node of the source and put it in dest */
void MoveNode(struct Node** destRef, struct Node** sourceRef) ;
 
/* Given the source list, split its nodes into two shorter lists.
  If we number the elements 0, 1, 2, ... then all the even elements
  should go in the first list, and all the odd elements in the second.
  The elements in the new lists may be in any order. */
void AlternatingSplit(struct Node* source, struct Node** aRef, 
                            struct Node** bRef) 
{
  /* split the nodes of source to these 'a' and 'b' lists */
  struct Node* a = NULL; 
  struct Node* b = NULL;
   
  struct Node* current = source;
  while (current != NULL) 
  {
    MoveNode(&a, &current); /* Move a node to list 'a' */
    if (current != NULL) 
    {
       MoveNode(&b, &current); /* Move a node to list 'b' */
    }
  }
  *aRef = a;
  *bRef = b;
}
 
/* Take the node from the front of the source, and move it to the front of the dest.
   It is an error to call this with the source list empty. 
    
   Before calling MoveNode():
   source == {1, 2, 3}   
   dest == {1, 2, 3}
       
   Affter calling MoveNode():
   source == {2, 3}      
   dest == {1, 1, 2, 3}      
*/
void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{
  /* the front source node  */
  struct Node* newNode = *sourceRef; 
  assert(newNode != NULL);
   
  /* Advance the source pointer */
  *sourceRef = newNode->next;
   
  /* Link the old dest off the new node */
  newNode->next = *destRef; 
   
  /* Move dest to point to the new node */
  *destRef = newNode; 
}
	
	
	
	
	
	
	
	
	
	int main()
	
{
	struct Node* head = NULL;
	struct Node* a = NULL;
	struct Node* b = NULL;
	int n;
	printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create_list(n);
    
    AlternatingSplit(head, &a, &b);
    
	
	printf("\nData in the list \n");
    displayList();


    return 0;
	
}




	
	
	
	
	void create_list (int n)
	{
		struct Node *head, *temp;
		int data, i;
		
		head= (struct Node *)malloc(sizeof(struct Node));
		
		if(head == NULL)
		{
			printf("Memory is not allocated!");
			}
		else
		{
			printf("Enter the number fot the first node please:");
			scanf("%d", &data);
			
			head->data=data;
			head->next=NULL;
			
			temp=head;
			
			for(i=2; i<=n; i++)
					{
						head = (struct Node *)malloc(sizeof(struct Node));
						
							if(head == NULL)
								{
									printf("Memory is not allocated!");
									break;
									}
							else 
							{
								printf("Please entrer the value for %d. node:", i);
								scanf("%d", &data);
								
								head->data = data;
								head->next = NULL;

								temp->next = head; 
								temp = temp->next;
	
								}
						
						
						}
			
			
			} printf("List created successfully!");
		
		}
	

		
	//AAAAAAAAAAAAAAAAAAAa
	
	void displayList(struct Node *node)
{
	
		while(node!=NULL)
		  {
		   printf("%d ", node->data);
		   node = node->next;
		  }
}	
	


