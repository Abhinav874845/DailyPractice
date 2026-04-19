/*
Program 1- Sort a given set of n integer elements using Selection Sort method and 
compute its time complexity. Run the program for varied values of n> 5000 and
record the time taken to sort. Plot a graph of the time taken versus n.
The elements can be read from a file or can be generated using the random number generator.
Demonstrate how the brute force method works along with its time complexity analysis: 
worst case, average case and best case
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
// Function to perform Selection Sort
void selectionsort(int arr[],int n)
{
	for(i=0;i<n-1;i++)
	{
		int minindex=i;
		for(j=0;j<n;j++)
		{
			if(arr[j]<arr[minindex])
			{
			minindex=j;	
			}
		}
		// Swap the found minimum element with the first element
		int temp=arr[i];
		arr[i]=arr[minindex];
		arr[minindex]=temp;
	}
}
// Function to generate random numbers in the array
void generaterandomarray(int arr[],int n)
{
	srand(time(0));// Seed the random number generator
	for(i=0;i<n;i++)
	{
		arr[i]=rand() % 100000;// Random numbers between 0 and 99999
	}
}
int main()
{
	int n;
	printf("Enter the number of element (n>5000):  ");
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));
	//generate random number
	generaterandomarray(arr,n);
	//measure time taken by seletion sort
	clock_t start,end;
	double cpu_time_used;
	start =clock();//start time
	selectionsort(arr,n);
	end=clock();
	// Calculate duration in milliseconds
	cpu_time_used =((double)(end-start ))/CLOCKS_PER_SEC*1000;
	printf("Time taken by selection sort: % 2f miliseconds\n",cpu_time_used);
	free(arr);
	return 0;
}
