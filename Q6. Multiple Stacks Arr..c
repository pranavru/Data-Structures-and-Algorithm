#include<stdio.h>

#define max 10

int stack[max], topA=-1, topB=max;

void pushA(int val)

{ 

     if(topA==topB-1)

     	printf("overflow");

     else
     stack[++topA]=val;


}



void pushB(int val)

{
	
if(topB-1==topA)

	        printf("overflow");

	else

		stack[--topB]=val;

}


int popA()

{

	int val;

	if(topA==-1)

		printf("underflow");

	else

		val=stack[topA--];

	return  val;

}


int popB()

{

	int val;

	if(topB==max)

		printf("underflow");

	else

		val=stack[topB++];

		return  val;

}

void display_stackA()

{
	

int i;

	if(topA==-1)

		printf("stack is empty");

	else

	{

		for(i=0; i<=topA; i++)

			printf("\t %d", stack[i]);

	}

}


void display_stackB()

{

	
int i;

	if(topB == max)

		printf("stack is empty");

	else

	{

		for(i=topB; i<max; i++)

			printf("\t %d", stack[i]);

	}

}

void main()

{
	int option, val;

	printf("\n 1. push in stack A");

	printf("\n 2. push in stack B");

	printf("\n 3. pop from  stack A");

	printf("\n 4. pop from  stack B");

	printf("\n 5. display stack A");

	printf("\n 6. display stack B");

	printf("\n 7. Exit");

	printf("\n Enter the option: ");

	scanf("%d", &option);

	do
	{

		switch (option)

		{

		case 1:
 
			printf("\n enter value to be pushed on stack A");

			scanf("%d", &val);

			pushA(val);

			break;


		case 2: 
			printf("\n enter value to be pushed on stack B");

			scanf("%d", &val);

			pushB(val);

			break;


		case 3: 
			val=popA();

			printf("\n value popped from stack A is %d",val);

			break;

		case 4: 
			val=popB();

			printf("\n value popped from stack B is %d",val);

			break;


		case 5: 
			printf("\ndisplay stack A");

                        display_stackA();

			break;


		case 6: 
			printf("\ndisplay stack B");

                        display_stackB();

			break;

		
case 7: 
			break;

		}

		printf("\n Enter the option: ");

		scanf("%d", &option);

	}while(option!=20);





}
 