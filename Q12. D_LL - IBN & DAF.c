
#include <stdio.h>

#include <stdlib.h>


//#include <conio.h>


struct node

{

	int data;

	struct node *next;

        struct node *prev;


};


struct node *start=NULL;

//struct node *start1;

struct node *create_list(struct node *);

struct node *display(struct node *);

struct node *insert_before(struct node *);

struct node *delete_after(struct node *);

int main()

{

	int option;

	//clrscr();

	printf("------------MENU------------");

	printf("\n 1. Create List");

	printf("\n 2. Display List");

	printf("\n 3. Add node before node");
	printf("\n 4. delete node after the given end");

	
printf("\n 5. Exit.");
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


			case 3: start=insert_before(start);

				break;


			case 4: start-delte_after(start);
				break;
			case 5:
				break;
		}
	printf("\n Enter the option: ");

		scanf("%d", &option);

	}while(option!=5);


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
			 while(ptr->next!=NULL)

			 	ptr=ptr->next;

			 ptr->next=new_node;

			 new_node->prev=ptr;

			 new_node->next=NULL;

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



struct node *insert_before(struct node *start)

{

	struct node *new_node, *ptr;

	int num,val;

	printf("\n Enter the data to be inserted: ");

	scanf("%d",&num);

	new_node=(struct node*)malloc(sizeof(struct node *));

	new_node->data=num;

	ptr=start;

	printf("\n Enter the value before which node is to be inserted: ");

	scanf("%d", &val);

	while(ptr->data!=val)

	{

		ptr=ptr->next;

	}

	new_node->next=ptr;

 	new_node->prev=ptr->prev;

	ptr->prev->next=new_node;

	ptr->prev=new_node;

	return start;

}



struct node *delete_after(struct node *start)

{

	struct node *ptr, *temp;

	int val;

	printf("\n Enter value after which node is to be deleted: ");

	scanf("%d", &val);

	ptr=start;

	
while(ptr->data!=val)

	{

		
ptr=ptr->next;

	}

	temp=ptr->next;

	ptr->next=temp->next;

	temp->next->prev=ptr;

	free(temp);

	return start;

}