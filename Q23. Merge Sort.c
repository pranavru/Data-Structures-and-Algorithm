/* c program for merge sorting */


#include<stdio.h>


void merge(int [],int ,int ,int );

void mergesort(int [],int ,int );

int main()

{

	int arr[30];

	int i,n;

	printf("Enter total no. of elements : ");

	scanf("%d",&n);

	for(i=0; i<n; i++)
 
	{
	
	printf("Enter %d element : ",i+1);

   		scanf("%d",&arr[i]);

 	}

 	mergesort(arr,0,n-1);

 	printf("\n\t--- Merge sorted elements ---\n\n");

	for(i=0; i<n; i++)

	 	printf("%d ",arr[i]);


}




void mergesort(int arr[],int beg,int end)

{

	int mid;

	if(beg<end)
 
	{
   
		mid=(beg+end)/2;
   
		mergesort(arr,beg,mid);
   
		mergesort(arr,mid+1,end);
   
		merge(arr,beg,mid,end);

 	}

}



void merge(int arr[],int beg,int mid,int end)

{
  
	int temp[end];

	int i=beg,j=mid+1,index=beg,k;
 
 
 
  	while ((i<=mid) && (j<=end))
  
	{
     
		if(arr[i]< arr[j])
		{

		         temp[index]=arr[i];
		
         i++;
		
}

		else
		{

		        temp[index]=arr[j];

		        j++;

		}
		index++;

	}

	if(i>mid)

	{
     
		while(j<=end)
     
		{
         
			temp[index]=arr[j];
         
			j++; 
  
			index++;
     
		}
  
	}
	else

	{

		while(i<=mid)
     
		{
        
			temp[index]=arr[i];

		        i++;
       			index++;

     		}
  
	}
  
	for(k=beg; k<index; k++)
     
		arr[k]=temp[k];

}

