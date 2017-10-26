#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
	
	};
	
struct Node *even = NULL;
struct Node *odd = NULL;
struct Node *list = NULL;
	
void push (int data)
{
		struct Node *link = (struct Node *)malloc(sizeof(struct Node));
		struct Node *temp;
		
		link->data=data;
		link->next=NULL;
		
		if (list == NULL)
		{
			list=link;
			return;
			}
		
		temp=list;
		
		while (temp->next != NULL)
		{
			temp=temp->next;
			}
	 
	 temp->next=link;
}	
	

	
void printList(struct Node* node)
{	
	
		while (node != NULL)
		{
			printf("%d ", node->data);
			node=node->next;
			}
		
	}


	
void split_list(int i) {
	

   struct Node *temp;

   while(list != NULL)		
    {
		struct Node *link = (struct Node*) malloc(sizeof(struct Node));
         
		link->data = list->data;
		link->next = NULL;
         
			if(list->data%i == 0)
			 {
					if(even == NULL) 
					{
							even = link;
							list = list->next;
							continue;
					}	else
						{
							temp = even;
                
							while(temp->next != NULL)
							temp = temp->next;
								
							// Insert link at the end of the list
							temp->next = link; 
						}
						
						list = list->next;
			}	
			
			
			
			
			
			else
				{
					if(odd == NULL) 	
					{
						odd = link;
						list = list->next;
						continue;
					}else 
						{
							temp = odd;
							while(temp->next!=NULL)
							temp = temp->next;
                
							// Insert link at the end of the list
							temp->next = link; 
	
						}
								list = list->next;
      }
   }
}

	
	
	
	
	
	
	
	
	
	int main()
{
	int i;
    
   for(i=1; i<=20; i++)
   {
      push(i);
	}
	printf("Cijela lista: \n");
    printList(list);
    
    printf("\nOdaberite broj?");
    scanf("%d", &i);
    
    split_list(i);
    
    printf("\nNisu djeljivi s odabranim brojem: ");
    printList(odd);

    printf("\nDjeljivi s odabarnim brojem: ");
    printList(even);


	return 0;
}
