
#include<stdio.h>

#include<stdlib.h>


struct node

{

	int priority;

	int info;

	struct node *next;

}*front=NULL;


void insert(int item, int item_priority);

int del();

void display();

int isEmpty();


void main()

{

	int choice,item,item_priority;

	while(1)

	{

		printf("1.Insert\n");

		printf("2.Delete\n");
		
printf("3.Display\n");
		
printf("4.Quit\n");
		
printf("Enter your choice : ");

		scanf("%d", &choice);


		switch(choice)

		{
			
case 1:
 printf("Input the item to be added in the queue : ");

				scanf("%d",&item);

				printf("Enter its priority : ");

				scanf("%d",&item_priority);

				insert(item, item_priority);
				
break;
			
case 2: 
printf("Deleted item is %d\n",del());
				
break;
			
case 3:	
display();

				break;
			
case 4: break;
			
default :
 printf("Wrong choice\n");

		}										/*End of switch*/

	}											/*End of while*/

}												/*End of main()*/


void insert(int item,int item_priority)

{
	
struct node *tmp,*p;


	tmp=(struct node *)malloc(sizeof(struct node));

	
tmp->info=item;
	
tmp->priority=item_priority;
						/*Queue is empty or item to be added has priority more than first element*/

	if( isEmpty() || item_priority > front->priority )

	{
		
tmp->next=front;

		front=tmp;

	}
	
else

	{
	
	p = front;
	
	while( p->next!=NULL && p->next->priority >= item_priority )
			
p=p->next;
			
tmp->next=p->next;
			
p->next=tmp;

	}

}												/*End of insert()*/


int del()

{

	struct node *tmp;

	int item;

	if( isEmpty() )

	{

		printf("Queue Underflow\n");

		return;

	}

	else

	{
	
	tmp=front;
		
item=tmp->info;

		front=front->next;
	
	free(tmp);

	}
	
return item;

}												/*End of del()*/


int isEmpty()

{
	
if( front == NULL )
	
return 1;

	else
	
return 0;


}												/*End of isEmpty()*/


void display()

{

	struct node *ptr;

	ptr=front;

	if( isEmpty() )
	
printf("Queue is empty\n");

	else
	
	{
		printf("Queue is :\n");

		printf("Priority       Item\n");

		while(ptr!=NULL)

		{
			
printf("%5d        %5d\n",ptr->priority,ptr->info);

			ptr=ptr->next;

		}
	

	}

}												/*End of display() */
