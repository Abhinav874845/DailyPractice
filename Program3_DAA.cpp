#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
// function to merge two sorted subarray
void merge(int a[],int low ,int mid ,int high)
{
	int n1= mid-low+1;
	int n2= high -mid;
	
	// create temporary arrays
	int *l=(int *)malloc (n1*sizeof(int));
	int *r=(int *)malloc(n2*sizeof (int));
	//copy data to temp array l[] and r[]
	for(i=0;i<n1;i++)
	{
		l[i]=a[low+i];
	}
	for(j=0;j<n2;j++)
	{
		r[j]=a[mid+1+j];
	}
	int i=0,j=0,k=low; // initial index
	 
	 // mereg the camp arrays back into a[low..high]
	 while(i<n1&&j<n2)
	 {
	 	if(l[i]<=r[j])
	 	{
	 	a[k]=l[i];
		 i++;	
		}
		else
		{
			a[k]=r[j];
			j++;
		}
		k++;
	 }
	 // copy  remaining element of l[],if any
	 while (i<n1)
	 {
	 	a[k]=l[i];
	 	i++;
	 	k++;
	 }
	 //copy remaining element of r[],if any
	 while (j<n2)
	 {
	 	a[k]=r[j];
	 	j++;
	 	k++;
	 }
	 free(l);
	 free(r);
}
// functio to perform recusive merge sort 
void recursive_merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2; // find the middle
		// recursively sort first and second halves
		recursive_merge_sort(a,low,mid);
		recursive_merge_sort(a,mid+1,high);
		// merge the sort halves
		merge (a,low,mid,high);
	}
}
// function to generate random array number in the array
void generaterandomarray(int arr[],int n)
{
	srand(time(0)); //seed the random number generate 
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100000; // random number between 0to 9999
	}
}

int main()
{
	int n;
	printf("Enter the number of element (n>5000): ");
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));
	//generate random number
	generaterandomarray(arr,n);
	//measure time taken by merge sort
	clock_t start,end ;
	double cpu_time_used;
	start=clock();// start time
	recursive_merge_sort(arr,0,n-1);
	end=clock();// stop clock
	// calculate duration in miliseconds
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC*1000;
	printf("TIme taken by merge sort: %.2f miliseconds\n",cpu_time_used);
free(arr);
return 0;	
}
