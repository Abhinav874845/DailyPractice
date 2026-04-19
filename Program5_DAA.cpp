#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

# define MAX_VERTICES 10 //MAXIMUM NUMBER OF VERTICES 
int i,j,count,v;
//find the vertex with the minimum distance value
int minDistance(int dist[],bool visited[],int vertices)
{
	int min_dist=INT_MAX,min_vertex=0;
	
	for(v=0;v<vertices;v++)
	{
		if(!visited [v] && dist[v]<=min_dist)
		{
			min_dist=dist[v];
			min_vertex=v;
		}
	}
	return min_vertex;
}
//printthe shortest distance from the source vertex 

void printSolution(int dist[],int vertices,int src)
{
	printf("\n Vertex \t\tDistance from source (%d)\n",src);
	for(i=0;i<vertices ;i++)
	{
		if(dist[i]==INT_MAX)
		printf("%d \t\t\t No path\n",i);
		else
		printf("%d\t\t\t %d\n",i,dist[i]);
	}
}

void dijstra(int graph[MAX_VERTICES][MAX_VERTICES],int vertices,int src)
{
	int dist[MAX_VERTICES];
	bool visited[MAX_VERTICES];
	
	for (i=0;i<vertices;i++)
	{
		dist[i]=INT_MAX;
		visited[i]=false;
	}
	dist[src]=0;
	
	for(count=0;count<vertices-1;count++)
	{
		int u=minDistance(dist,visited,vertices);
		visited[u]=true;
		for(v=0;v<vertices;v++)
		{
			if(!visited[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	printSolution(dist,vertices,src);
}

int main()
{
	int vertices,src;
	int graph[MAX_VERTICES][MAX_VERTICES];
	
	printf("Enter the number of vertices (max %d): ",MAX_VERTICES);
	scanf("%d",&vertices);
	
	if(vertices<=0||vertices>MAX_VERTICES)
	{
		printf("Invalid number of vertices.must be between 1 and %d.\n",MAX_VERTICES);
		return 1;
	}
	printf("Enter the adjacency matrix (0 for no edge):\n");
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter the source vertex(0 to %d): ",vertices-1);
	scanf("%d",&src);
	
	if(src<0||src>=vertices)
	{
		printf("Invalid source vertex. Must be between ) and %d.\n",vertices-1);
		return 1;
	}
	dijstra(graph,vertices,src);
	return 0;
}
