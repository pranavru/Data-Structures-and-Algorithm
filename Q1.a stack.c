#include<stdio.h>

#include<math.h>

#define size 5

int top=-1;
int stack[5];

void push()
					//Inserting an Element.
{
	
	int item;

	if(top==size-1)
	{

		printf("Stack Overflow. Element can not be pushed.");

	}
	
	else{

		printf("\nEnter the Item:\t");

		scanf("%d",&item);

		top=top+1;

		stack[top]=item;

		printf("\n%d pushed into the Stack",item);

	}

}

void pop()					//Deleting an Element.

{

	if(top==-1)
	{

		printf("Stack Underflow. Element can not be poped.");

	}
	
	else{

		printf("\n%d poped from the stack",stack[top]);

		stack[top]=NULL;

		top=top-1;
	
	}

}

void peek()					//To view TOP-MOST Element.

	{

	if(top==-1)
	{

		printf("\nStack Underflow. No element in the stack");

	}
	
	else
	{

		printf("\nPeek Element is %d",stack[top]);

	}

}

void display()					//To DISPLAY the STACK.
 
	{

	int i;

	if(top==-1)
	{

		printf("\nNo Element in the stack.");

	}

	else

	{

		printf("\nElements in the stack are:\n");

		for(i=0;i<=top;i++)

		{

			printf("%d\t",stack[i]);

		}

	}

}


void main()

{

	int i,ch,n;

	do{

		printf("\n Press 1 to push.\n Press 2 to pop.\n Press 3 to peek.\n Press 4 to Display.\n Press 5 to Exit.\nEnter the choice:\t");

		scanf("%d",&ch);

		switch(ch)
		{

			case 1:

					push();

					break;

			case 2:

					pop();

					break;

			case 3:

					peek();

					break;

			case 4:

					display();

					break;

			case 5:

					printf("Thank You.");

					break;

			default:

					printf("\nInvalid Input");

		}
	
	}while(ch!=5);

}
	
