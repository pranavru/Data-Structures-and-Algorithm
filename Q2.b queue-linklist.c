
#include<stdio.h>

#include<malloc.h>
struct Node

{

        int Data;

        struct Node* next;

 }*rear, *front;


void delQueue()

{

       struct Node *temp, *var=front;

       if(var==front)

       {

            front  = front->next;

            free(var);

       }

       else

       printf("\nQueue Empty");

}


void insert(int value)

{

     struct Node *temp;

     temp=(struct Node *)malloc(sizeof(struct Node));

     temp->Data=value;

     if (front == NULL && rear==NULL)

     {

           front=rear=temp;

           temp->next=NULL;

     }

     else

     {

           rear->next=temp;

           rear=rear->next;

	   rear->next=NULL;

     }

}


void display()

{

     struct Node *var=front;

     if(var!=NULL)

     {

           printf("\nElements are as:  ");

           while(var!=NULL)

           {

                printf("\t%d",var->Data);

                var=var->next;

           }

     printf("\n");

     }
 
    else

     printf("\nQueue is Empty");

}


int main()

{

     int i=0;

     front=rear=NULL;

     printf(" \n1.  insert in Queue");

     printf(" \n2. delete from Queue");

     printf(" \n3. Display Data of Queue");

     printf(" \n4. Exit\n");

     while(1)

     {

          printf(" \nChoose Option: ");

          scanf("%d",&i);

          switch(i)

          {

                case 1:

                {

                     int value;

                     printf("\nEnter a value to push into Queue: ");

                     scanf("%d",&value);

                     insert(value);
 
                    display();

                     break;

                }

                case 2:

                {

                     delQueue();

                     display();

                     break;

                }

                case 3:

                {

                     display();

                     break;

                }

                default:

                {

                     printf("\nwrong choice for operation");

                }

          }

     }


}
