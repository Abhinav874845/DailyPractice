#include<stdio.h>
int main()
{
	int arr[100],n,i,sam;
	printf("enter the arr element :");
	scanf("%d",&n);
	printf("enter %d element :\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sam=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]<sam)
		{
			sam=arr[i];
		}
	}
	printf("the smallest number is : %d\n",sam);
	return 0;
}
