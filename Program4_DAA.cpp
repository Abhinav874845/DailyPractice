#include<stdio.h>

struct item {
	int weight;
	int value;
	float ratio;
};

void swap(struct item*a,struct item *b)
{
	struct item temp=*a;
	*a=*b;
	*b=temp;
}
int i,j;
void sortitems(struct item items[],int n)
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(items[j].ratio>items[i].ratio)
			{
			swap(&items[j],&items[i]);
			}
		}
	}
}

float knapsack(struct item items[],int n,int capacity)
{
	float totalvalue=0.0;
	for(i=0;i<n;i++)
	{
		if(capacity>=items[i].weight)
		{
			capacity-=items[i].weight;
			totalvalue+=items[i].value;
		}
		else
		{
			totalvalue+=items[i].value*((float)capacity/items[i].weight);
			break;
		}
	}
	return totalvalue;
}
int main()
{
	int n,capacity;
	printf("Enter the number of items: ");
	scanf("%d",&n);
	
	struct item items[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter values and weight for item %d: ",i+1);
		scanf("%d %d",&items[i].value,&items[i].weight);
		items[i].ratio=(float)items[i].value/items[i].weight;
	}
	
	printf("Enter the knapsack capacity: ");
	scanf("%d",&capacity);
	
	sortitems(items, n);
	
	float maxvalue=knapsack(items,n,capacity);
	printf("\n Maximum value in knapsack=%.2f\n",maxvalue);
	
	return 0;
}
