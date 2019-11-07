#include <stdio.h>

#include <stdlib.h>


//#include <conio.h>


struct node

{

	int data;

	struct node *next;

};


struct node *start=NULL;

struct node *start1;

struct node *create_list(struct node *);

struct node *display(struct node *);

struct node *insert_after(struct node *);



int main()

{

	int option;

	//clrscr();

	printf("------------MENU------------");

	printf("\n 1. Create List");

	printf("\n 2. Display List");

	printf("\n 3. Add node after node");

	printf("\n 4. Delete node before node");

	printf("\n 5. EXIT.");
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

	}while(option!=5);



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

		new_node=(struct node *)malloc(sizeof(struct node*));

		new_node->data=num;

		if(start==NULL)

		{

			new_node->next=NULL;

			start=new_node;

			ptr=start;

		}

		else

		{

			ptr->next=new_node;

			new_node->next=NULL;

			ptr=ptr->next;

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

	while(ptr!=NULL)

	{

		printf("\n%d",ptr->data);

		ptr=ptr->next;

	}

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

	printf("\n Enter the node after which new node is to be inserted :");

	scanf("%d",&val);

	while(preptr->data!=val)

	{

		preptr=ptr;

		ptr=ptr->next;

	}

	new_node->next=ptr;

	preptr->next=new_node;

	return start;

}



struct node *delete_before(struct node *start)

{

	struct node *ptr, *preptr;

	int val;

	printf("\n Enter value after which node is to be deleted: ");

	scanf("%d", &val);

	ptr=start;

	preptr=start;

	while(ptr->data!=val)

	{

		preptr=ptr;

		ptr=ptr->next;

	}

	if(ptr==start)

		printf("\n no node before the given node can be deleted.");

	else

	{

		ptr->prev=preptr->prev;

		free(preptr);

		printf("\n  node deleted");

	}

	return start;

}




