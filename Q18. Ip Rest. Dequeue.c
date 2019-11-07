#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>
#define pf printf

#define sf scanf



struct node

{

	 int info;

	 struct node *next;

}*front,*temp,*rear,*ptr;


void insertr()

{

	 temp=(struct node*)malloc(sizeof(struct node));

	 pf("\nEnter elemet: ");

	 sf("%d",&temp->info);

	 temp->next=NULL;

	 if(front==NULL && rear==NULL)

	 {

		   front=rear=temp;

		   temp->next=NULL;

		   return;

	 }

	 else

	 {

		   rear->next=temp;

		   rear=rear->next;

		   rear->next=NULL;

	 }

}


void delf()

{

	 if(front==NULL)

	 {

		  pf("\nEmpty Deque\n");

		  return;

	 }

	 if(front==rear )

	 {

		  ptr=front;

		  front=rear=NULL;

		  free(ptr);

	 }

	 else

 	{

 		 ptr=front;

 		 front=front->next;

 		 free(ptr);

	 }

}


void delr()

{

 	if( rear==NULL)

 	{

 		 pf("Empty DEQUE");

 		 
return;

 	}

 	else if(rear==front)

 	{

 		 rear=front=NULL;

 		 free(rear);

 		 free(front);

 	}

 	else

 	{

 		 ptr=front;

 		 while(ptr->next!=NULL)

 		 {

 			  temp=ptr;

 			  ptr=ptr->next;

  		 } 

		temp->next=NULL;

  		free(ptr);

  		rear=temp;

 	}

}


void show()

{

	if(front==NULL && rear==NULL)

 	{

 		 pf("\nEmpty Deque\n");

		  return;

	}

	ptr=front;

 	while(ptr->next!=NULL)

	{

 		 pf("%d\t",ptr->info);

 		 ptr=ptr->next;

 	}

 	pf("%d\t",ptr->info);

}




void main()

{
	int ch1;


 	while(1)

 	{

 		pf("\n Input restricted deque");

    		pf("\n1. Insert at rear");

  
  		pf("\n2. Delete from front");

    		pf("\n3. Delete from rear");

    		pf("\n4. Show");

    		pf("\n5. Exit");

    		pf("\nEnter ur choice: ");

    		sf("%d",&ch1);

    		switch (ch1)

    		{

     			case 1: insertr(); break;

  
   			case 2: delf(); break;

     			case 3: delr(); break;

    			case 4: show(); break;

    			case 5:         break;

   			default: pf("Invalid option");

 		 }

 	}


}
