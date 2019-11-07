#include<stdio.h>

int main()
{

    int a[10],n,i,j,k,num,m, count=0;

    printf("\n Enter the no of Elements");
    scanf("%d",&n);
    for(i=0;i<10;i++)
    a[i]=-1;


    for(i=0;i<n;i++)
    {
    k=0;
  
    printf("\n Enter the %d Element: ",i);
    scanf("%d",&num);

    a:
    j=(num%10+k*(1+num%9))%10;          [num.mod n + i*num.mod(n-1)]mod n
	 if(a[j]==-1)
	  a[j]=num;
	  else
	  {
          count=count+1;
	  k++;


	  goto a;
	  }
    }

    printf("\n Elements After Double Hashing");
    for(i=0;i<n;i++)
    printf(" %d ",a[i]);
printf("\n no of collisions %d \n", count);
return 0;

}
