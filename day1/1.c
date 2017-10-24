/*Napraviti modul koji predstavlj
a jednostruko spregnutu listu. Modul izvesti kao statičku biblioteku.
Zatim napraviti funkciju koja jednu listu dijeli na dvije liste tako da prvi, treć
i, peti, itd. element (svaki neparni) ide u jednu listu, ostali (parni) elementi u drugu.*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct cvor
	{
		int broj;
		struct cvor *next;
		
		};
	
void dijeli(struct cvor **head)
	{
		struct cvor *end=*head;
		struct cvor *prev=NULL;
		struct cvor *curr=*head;
		
		while (end->next != NULL)
			end=end->next;
			
		struct cvor *new_end=end;
		
		//neparni
		while (curr->broj %2 != 0 && curr != end)
			{
				
					new_end->next=curr;
					curr=curr->next;
					new_end->next->next=NULL;
					new_end=new_end->next;
					
				
				}
				
		if(curr->broj %2 == 0)
			{
				//neka head pokazuje na prvi parni
				*head=curr;
				
				while(curr != end)
					{
						if ((curr->broj)%2 ==0)
							{
								prev=curr;
								curr= curr->next;
						} else
							{
								prev->next=curr->next;
								curr->next=NULL;
								new_end->next=curr;
								new_end=curr;
								curr=prev->next;
								}
				}
		
		
		} else prev=curr;
		
		if(new_end !=end && (end->broj) %2 != 0 )
			{
				prev->next=end->next;
				end->next=NULL;
				new_end->next=end;
				}
				return;
	}
	
	
	
	//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa
	/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
void push(struct cvor** head, int new_broj)
{
    /* allocate node */
    struct cvor* new_cvor = (struct cvor*) malloc(sizeof(struct cvor));
 
    /* put in the data  */
    new_cvor->broj  = new_broj;
 
    /* link the old list off the new node */
    new_cvor->next = (*head);
 
    /* move the head to point to the new node */
    (*head)    = new_cvor;
}
 
 
/* Function to print nodes in a given linked list */
void printList(struct cvor *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->broj);
        node = node->next;
    }
}
//AAAAAAAAAAAAAAAAAAAAAAAAAA
		

int main()
{
	
		struct cvor *head=NULL;
		push(&head, 1);
		push(&head, 2);
		push(&head, 3);
		push(&head, 4);
		push(&head, 15);
		
		printf("\nOriginal Linked list \n");
    printList(head);
 
    dijeli(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
    
		printf("hehe");
		return 0;
}
