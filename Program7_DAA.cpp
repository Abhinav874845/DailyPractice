#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 9999999
#define MAX 100

int main()
{
	int v,e,i,j;
	
	int g[MAX][MAX]={0};
	
	printf("Enter the number of vertices : ");
	scanf("%d",&v);
	
	printf("Entre the number of edges: ");
	scanf("%d",&e);
	
	printf("Enter the edges(u v weight): \n");
	for(i=0;i<e;i++)
	{
		int u,v,w;
		printf("edges %d: ",i+1);
		scanf("%d%d%d",&u,&v,&w);
		
		g[u][v]=w;
		g[v][u]=w;
	}
	
	int selected[MAX];
	memset(selected ,0,sizeof(selected));
	selected[0]=1;
	
	int no_edge=0;
	
	printf("\nMinimum costt spanning tree :\n");
	
	while(no_edge<v-1)
	{
		int min=INF;
		int x=-1,y=-1;
		
		for(i=0;i<v;i++)
		{
			if(selected[i])
			{
				for(j=0;j<v;j++)
				{
					if(!selected[j] && g[i][j]){
						if(g[i][j]<min){
							min=g[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		if(x!=-1&& y!=-1){
			printf("%d-%d: %d\n",x,y,g[x][y]);
			selected[y]=1;
			no_edge++;
		}
	}
	return 0;
}
