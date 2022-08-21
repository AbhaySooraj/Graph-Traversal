/*Develop a program to implement the graph traversal methods*/
#include<stdio.h>
#include<stdlib.h>

#define n 5

int r=-1,f=0; 

void init(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
}

void addedge(int arr[][n],int a ,int b)
{
	arr[a][b]=1;
}

void adjmtrx(int arr[][n])
{
	int i,j;
	printf("\n Adjacency Matrix \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}

void dfs(int i,int df[],int graph[][n])
{
	int j;
	df[i]=1;
	printf("%d\t",i);
	for(j=0;j<n;j++)
	{
		if(graph[i][j]==1)
		{
			if(!df[j])
			{
				dfs(j,df,graph);
			}
			
		}
	}
}

void bfs(int i,int bf[],int q[],int graph[][n])
{
	int j;
	for(j=0;j<n;j++)
	{
		if(graph[i][j] && !bf[j])
		{
			r++;
			q[r]=i;
		}
	}
	if(f<=r)
	{
		bf[q[f]]=1;
		printf("%d\t",q[f]);
		f++;
		bfs(q[f],bf,q,graph);
	}
	
}	
		 

void main()
{
	int graph[n][n],i,option;
	int df[n],bf[n],q[i];
	init(graph);
	addedge(graph,0,1);
	addedge(graph,0,2);
	addedge(graph,1,3);
	addedge(graph,3,2);
	adjmtrx(graph);
	
				
	while(1)
	{	
		printf("\n\n\n MENU \n 1: DFS \n 2: BFS \n 3: EXIT \n ENTER YOUR CHOICE :");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				for(i=0;i<n;i++)
				{
					df[i]=0;
				}
				printf("\n");
				dfs(0,df,graph);
				break;
				
			}
			
			case 2:
			{
				for(i=0;i<n;i++)
				{
					bf[i]=0;
					q[i]=0;
				}
				printf("\n");
				bfs(0,bf,q,graph);
				break;
			}
				
			case 3:
			{
				printf(" \n EXITING \n ");
				exit(0);
			}
			default:
			{
				printf(" WRONG OPTION ");
				break;
			}
		}		
	}
}
