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


void search_node(struct node *start)

{

	struct node *ptr;

	int val,count;

	count=1;

	ptr=start;

	printf("\n Enter the value to be searched: ");

	scanf("%d", &val);

	while(ptr!=NULL)


	{

		if(ptr->data==val)

		{

			//pos=ptr;

			printf("\nvalue found in node %d", count);

			break;

		}

		else

		{

			ptr=ptr->next;

			count++;

		}

	}

//return count;

}

struct node *copy_list(struct node *start)

{

	struct node *new_list, *ptr, *new_node, *new_node1;

	ptr=start;

	if(ptr==NULL)

	{

		printf("\n Empty list. Can not copy. ");

	}

	else  //list not empty
	
	{

		new_node=(struct node *)malloc(sizeof(struct node *));

		new_list=new_node;

		new_node->data=ptr->data;

		while(ptr->next!=NULL)

		{

			new_node1=(struct node *)malloc(sizeof(struct node *));

			new_node->next=new_node1;

			ptr=ptr->next;

			new_node1->data=ptr->data;

			new_node=new_node1;


		}

	}

	printf("\n Copied List is: \n");

	start=display(new_list);

	return(start);

}


struct node *concat_list(struct node *start1, struct node *start2)

{

	struct node *start3, *ptr, *preptr;

       //	start1=creat_list(start);

       //	start=NULL;

       //	start2=create_list(start);

	ptr=start1;

	while(ptr!=NULL)

	{

		preptr=ptr;

		ptr=ptr->next;

	}

	preptr->next=start2;

	return (start1);

}


void split_list(struct node *start)

{

	struct node *start2, *ptr, *preptr;

	int val;

	start2=NULL;

	ptr=start;


	if (ptr==NULL)

	{

		printf("\n List empty. can not split.");

		start=create_list(start);

		ptr=start;

	}
		printf("\n The created list is as follows:\n");
		start=display(start);



		printf("\n Enter the value from where u want to split the list: ");

		scanf("%d", &val);

		if(ptr->data==val)

			printf("\n List can not be split at first node");

		else

		{

			preptr=ptr;

			ptr=ptr->next;

			while(ptr->data!=val)

			{

				preptr=ptr;

				ptr=ptr->next;

			}

			preptr->next=NULL;

			start2=ptr;

		}

		printf("\n List1 is: ");

		display(start);

		printf("\n List2 is: ");

		display(start2);



}


struct node *reverse_list(struct node *start)

{

	struct node *ptr, *preptr, *ptr1, *ptr2;

	ptr=start;

	ptr1=NULL;

	while(ptr!=NULL)

	{

		ptr2=ptr1;

		ptr1=ptr;

		ptr=ptr->next;

		ptr1->next=ptr2;

	}

	start=ptr1;

	return (start);

}

struct node *count_node(struct node *start)
{
	int count;
	struct node *ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	printf("The no. of nodes created in the Linked List are : %d.",count);
}
int main()

{

	int option = 0;

	//clrscr();

	
		printf("------------MENU------------");

		printf("\n 1. Create List");

		printf("\n 2. Display List");

		printf("\n 3. Search the node");

		printf("\n 4. Copy List");

		printf("\n 5. Concatenate two Lists");
	
		printf("\n 6. Split list");

		printf("\n 7. Reverse List");

		printf("\n 8. Count the no. of nodes in the List");
		printf("\n 9. EXIT.");
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


		case 3: search_node(start);

			break;


		case 4: start=copy_list(start);

			break;

		case 5: if(start==NULL)

			{

				printf("\n Create two lists");

				printf("\n List 1:");

				start=create_list(start);

				start1=NULL;

				printf("\n List2 : ");

				start1=create_list(start1);

				start=concat_list(start, start1);

				printf("\n Concatenated List is \n");

				display(start);

				break;

			}

			else

			{
       				printf("\n Create another list");

				start1=NULL;

				start1=create_list(start1);

				start=concat_list(start, start1);

				printf("\n Concatenated List is \n");

				start=display(start);

				break;

			}

		case 6: split_list(start);

			 break;


		case 7: start=reverse_list(start);

			 start=display(start);

			 break;

		case 8: 
			start=count_node(start);
			break;
		case 9: 
			break;
		}

		printf("\n Enter the option: ");

		scanf("%d", &option);

	}while(option!=9);


	//getch();


}