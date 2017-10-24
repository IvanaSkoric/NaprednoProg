#include "stdio.h"
#include "stdlib.h"
#include "string.h"
	
	
	void create_list(int n);
	void invert();
	void displayList();
	
	
	int main()
	
{
	 
	 int n, choice;
	printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create_list(n);
	
	printf("\nData in the list \n");
    displayList();

    
    printf("\nPress 1 to reverse the order of singly linked list\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        invert();
    }

    printf("\nData in the list\n");
    displayList();

    return 0;
	
}



struct node
{
	int data;
	struct node *next;
	}*head;
	
	
	
	
	void create_list (int n)
	{
		struct node *newNode, *temp;
		int data, i;
		
		head= (struct node *)malloc(sizeof(struct node));
		
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
						newNode = (struct node *)malloc(sizeof(struct node));
						
							if(newNode == NULL)
								{
									printf("Memory is not allocated!");
									break;
									}
							else 
							{
								printf("Please entrer the value for %d. node:", i);
								scanf("%d", &data);
								
								newNode->data = data;
								newNode->next = NULL;

								temp->next = newNode; 
								temp = temp->next;
								}
						
						
						}
			
			
			} printf("List created successfully!");
		
		}
	
	
	
	
	
	//AAAAAAAAAAAAa
	void invert ()
	{
		struct node *prev, *curr;
		
		if (head != NULL)
			{
				prev=head;
				curr=head->next;
				head=head->next;
				
				prev->next=NULL;
				
				
				}
				while (head != NULL)
				{
					
					head = head->next;
					curr->next = prev;

					prev = curr;
					curr = head;
				}

				head = prev; 

				printf("SUCCESSFULLY REVERSED LIST\n");
	
				
		}
	//AAAAAAAAAAAAAAAAAAAa
	
	void displayList()
{
	struct node *temp;
	
	
	if(head == NULL)
    {
        printf("List is empty.");
    }else
    {
		temp=head;
		while(temp != NULL)
		{
			printf("Data: %d\n", temp->data);
			temp=temp->next;
			}
		}
}	
	


