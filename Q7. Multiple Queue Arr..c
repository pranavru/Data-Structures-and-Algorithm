
#include<stdio.h>

#define max 10

int queue[max], rearA=-1, frontA=-1;
rearB=max, frontB=max;

void insertA(int val)

{ 

	if(rearA==rearB-1)

     		printf("overflow");

	else
 if(rearA==-1 && frontA==-1)

	     {

		rearA=frontA=0;
		
queue[rearA]=val;

	     }

	else 

		queue[++rearA]=val;

}



int deleteA()

{

	int val;
	
if(frontA==-1)
		
printf("underflow");

	else
	
{

		val=queue[frontA++];

		if(frontA>rearA)

			frontA=rearA=-1;

		return  val;

	}

}


void display_queueA()

{

	
int i;

	if(frontA==-1)

		printf("queueA is empty");
	
else

	{

		for(i=frontA; i<=rearA; i++)

			printf("\t %d", queue[i]);

	}

}



void insertB(int val)

{

	if(rearA==rearB-1)

		printf("overflow");

	
else
	
{

		if(rearB==max && frontB==max)

		{
			
rearB=frontB=max-1;

			queue[rearB]=val;

		}

		else
queue[--rearB]=val;

	
}

}



int deleteB()

{

	int val;

	if(frontB==max)

		printf("underflow");

	else
		
val=queue[frontB--];

	if(frontB<rearB)

		frontB=rearB=max;

		return  val;

}


void display_queueB()

{

	
int i;

	if(frontB == max)

		printf("queue is empty");

	else

	{

		for(i=frontB; i>=rearB; i--)

			printf("\t %d", queue[i]);

	}

}

void main()

{
	int option, val;


	printf("\n 1. insert in queue A");

	printf("\n 2. insert in queue B");

	printf("\n 3. delete from  queue A");

	printf("\n 4. delete from  queue B");

	printf("\n 5. display queue A");

	printf("\n 6. display queue B");

	printf("\n 7. Exit");

	printf("\n Enter the option: ");

	scanf("%d", &option);

	do

        {

	switch (option)

		{

		case 1:
 
			printf("\n enter value to be inserted on queue A");

			scanf("%d", &val);

			insertA(val);

			break;


		case 2: 
			printf("\n enter value to be inserted on queue B");

			scanf("%d", &val);

			insertB(val);

			break;


		case 3: 
			val=deleteA();

			printf("\n value popped from queue A is %d",val);

			break;

		case 4: 
			val=deleteB();

			printf("\n value popped from queue B is %d",val);

			break;


		case 5: 
			printf("\ndisplay queue A");

                        display_queueA();

			break;


		case 6: 
			printf("\ndisplay queue B");

                        display_queueB();

			break;

		case 7: 
			break;

		}

	printf("\n Enter the option: ");

	scanf("%d", &option);

	}while(option!=20);


}
