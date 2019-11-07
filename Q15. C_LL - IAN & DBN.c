#include <stdio.h>

#include <stdlib.h>


//#include <conio.h>


struct node

{

	int data;

	struct node *next;

       // struct node *prev;


};


struct node *start=NULL;

//struct node *start1;

struct node *create_list(struct node *);

struct node *display(struct node *);

struct node *insert_after(struct node *);
struct node *delete_before(struct node *);
int main()

{

	int option;

	//clrscr();

	printf("------------MENU------------");

	printf("\n 1. Create List");

	printf("\n 2. Display List");

	printf("\n 6. Add node after a given node");

	printf("\n 9. delete node before a given node ");
	        printf("\n Enter the option: ");

	scanf("%d", &option);

	do

	{

		switch (option)

		{

		case 1: start=create_list(start);

			printf("\n Linked list created");

			break;


		case 2: start=display(start);

			break;


		case 3: start=insert_after(start);
			break;
		case 4: start=delete_before(start);

			break;


		case 5:
			break;

		}

		printf("\n Enter the option: ");

		scanf("%d", &option);

	}while(option!=20);


	//getch();


}




struct node *create_list(struct node *start)

{

	struct node *new_node,*ptr;

	int num;

	start=NULL;

	printf("\n Enter -1 to end the creation of list");

	printf("\n Enter the data: ");

	scanf("%d",&num);

        while(num!=-1)

	{
       
		if(start==NULL)

		{

			new_node=(struct node *)malloc(sizeof(struct node*));

       			new_node->data=num;

			
//start=new_node;

			//new_node->prev=NULL;

			new_node->next=new_node;

			start=new_node;

		}

		else

		{
 	
		new_node=(struct node *)malloc(sizeof(struct node*));

       			new_node->data=num;

			ptr=start;

			while(ptr->next!=start)

				ptr=ptr->next;

			//new_node->prev=ptr;

			new_node->next=start;

			ptr->next=new_node;

			//start->prev=new_node;

		}

		printf("\n Enter the data: ");

		scanf("%d",&num);

	}

	return (start);

}


struct node *display(struct node *start)

{

	struct node *ptr;

	ptr=start;

	while(ptr->next!=start)

	{

		printf("\n%d",ptr->data);

		ptr=ptr->next;

	}

	printf("\n%d",ptr->data);

	return start;

}




struct node *insert_after(struct node *start)

{

	int num, val;

	struct node *ptr, *new_node, *preptr;

	printf("\n Enter the value to insert:");

	scanf("%d",&num);

	new_node=(struct node*)malloc(sizeof(struct node *));


	new_node->data=num;

	ptr=start;

	preptr=ptr;

	printf("\n Enter the node after whoch new node is to be inserted :");

	scanf("%d",&val);

	while(preptr->data!=val)

	{

	        preptr=ptr;

		ptr=ptr->next;

	}

        if(ptr==start)

	{
 
               new_node->next=ptr;

		preptr->next=new_node;

       		start=new_node;

		return start;
	}

	else
	{

		new_node->next=ptr;

		preptr->next=new_node;

	       
	return start;
	}

}





struct node *delete_before(struct node *start)

{

	struct node *ptr, *preptr;

	int val;

	printf("\n Enter value before which node is to be deleted: ");

	scanf("%d", &val);

	ptr=start;

	preptr=start;

	while(ptr->next->data!=val)
         //ptr points the Data to be deleted.
	{

		preptr=ptr;

		ptr=ptr->next;

	}

	
preptr->next=ptr->next;

	return start;

}

