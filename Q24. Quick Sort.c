
#include<stdio.h>

int partition( int a[], int beg, int end );

void quicksort( int a[], int beg, int end );

void main()

{

	int a[50], i, n;
 
	
	printf("\nEnter no. of elements: "); 
 
	scanf("%d", &n);
 
	
	printf("\nEnter the elements: \n");
 
	for (i=0; i<n; i++)
  
		scanf ("%d", &a[i]);

	
	printf("\nUnsorted elements: \n");
 
	for (i=0; i<n; i++)
  
		printf(" %d ", a[i]);
	printf("\n");
	
	
quicksort(a,0,n-1);
 
	
	printf("\nSorted elements: \n");
 
	for (i=0; i<n; i++)
  
		printf(" %d ", a[i]);
 
	printf("\n");
 

}									//end main
 
 



void quicksort( int a[], int beg, int end )

{
 
	int pivot;
 							// Termination condition! (base case)
 
	if(beg < end)
 
	{
  
		pivot = partition( a, beg, end );
  
		quicksort( a, beg, pivot-1 );
  
		quicksort( a, pivot+1, end );
 
	}

}									//end quicksort


int partition( int a[], int beg, int end )

{
 
	int left, right,temp,pivot,flag;
 
  
	pivot = left = beg;
	right = end;
	
flag=0;
	
while(flag!=1)

	{								// Move right while item > pivot 
  
		while((a[right] >= a[pivot]) && (pivot!=right))
   
			right--;
  
		if (pivot==right)
	
			flag=1;
  
		else if (a[pivot]>a[right])

			{
	
				temp=a[pivot];

				a[pivot]=a[right];
			
	a[right]=temp;
			
	pivot=right;

			}
		
if(flag!=1)

		{							// Move left while item < pivot 
  
			while(( a[left] <= a[pivot]) &&(pivot!=left))
   
				left++;
  
  
			if ( pivot==left ) 
				
flag=1;
			
else if (a[pivot]<a[left])
			
{
	
				temp=a[pivot];
	
				a[pivot]=a[left];
	
				a[left]=temp;
	
				pivot=left;

			}

		}
	
}
	return pivot;

}
   
