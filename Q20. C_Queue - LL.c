#include<stdio.h>
 
struct node


{


	int data;
	
struct node *next;


};


struct node *front=NULL,*rear=NULL,*temp;


void insert()


{

	
struct  node *newnode;

	newnode=(struct node*)malloc(sizeof(struct node));

 
	printf("\nEnter the node value : ");

 
	scanf("%d",&newnode->data);

 
	newnode->next=NULL;

 
	if(rear==NULL && front==NULL)

		front=rear=newnode;

 
	else

 
	{

 
		rear->next=newnode;
	

 	rear=newnode;
		// newnode will become rear(i.e the last element)
	}
	rear->next=front;
	// since circular queue


}


void delet()


{

 
	temp=front;

 
	if(front==NULL)

 
		printf("\nUnderflow :");

 
	else

 
	{

 
		if(front==rear)

		{

 
			printf("\n%d",front->data);

			front=rear=NULL;

		
}

		else

 
		{

 
			printf("the element deleted is \n%d",front->data);


			front=front->next;
			
rear->next=front;
		}

		
//temp->next=NULL;

		free(temp);


	 }


}


void traverse()


{

 
	temp=front;

 
	if(front==NULL)

		printf("\nEmpty");

	else
	{
		printf("\n");

		
struct node *var=front;

  	        printf("\nElements are as:  ");

	        while(var->next!=front)						// since its a circular queue

 	        {

	                printf("\t%d",var->data);

	                var=var->next;

 	        }

		printf("\t%d",var->data);

		printf("\n");

 	}
}


 




void main()


{


	int ch;


	while( ch != 4)

	{

	printf("\npress 1 to insert the element : ");

	printf("\npress 2 to delete the element : ");
	printf("\npress 3 to traverse the queue : ");
	printf("\npress 4 to exit from main : ");

		
	printf("\nEnter choice : ");
	scanf("%d",&ch);
		switch(ch)

		{
		case 1:

 insert();
			break;


		case 2:

 delete();

			break;


		case 3:

 traverse();


			break;


		case 4:

 
			break;
		default:

 
			printf("\nInvalid choice :");

		}

	printf("\nEnter choice : ");
	scanf("%d",&ch);
	}


}


