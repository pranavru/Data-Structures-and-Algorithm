#include <stdio.h>

int main()

{

    int arr[30];

    int i,  flag=1,  gapsize, temp, n;

    printf("Enter total no. of elements : ");

    scanf("%d", &n);

    printf("\nEnter %d numbers: ", n);

 
   for (i =  0 ; i < n; i++)
    
    {

        scanf("%d", &arr[i]);

    }

    gapsize=n;

    while(flag==1 || gapsize>1)

    {
	
flag=0;

	gapsize=(gapsize+1)/2;
	
for (i =  0 ; i < (n-gapsize); i++)

	{
	
	if(arr[i+gapsize]<arr[i])

		{
			
temp=arr[i+gapsize];
			
arr[i+gapsize]=arr[i];
	
		arr[i]=temp;
			
flag=0;

		}
	
}

    }

    printf("\n Sorted array is: ");

    for (i = 0; i < n; i++)

        printf("%d ", arr[i]);

    return 0;

}
