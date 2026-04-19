#include<stdio.h>
int main()
{
	int arr[100],n,i,max;
	printf("enter the array element :");
	scanf("%d",&n);
	printf("enter %d element :\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
printf("the largest number of the element is %d :\n",max);
return 0;	
}

