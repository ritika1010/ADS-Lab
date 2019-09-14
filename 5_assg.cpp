#include<iostream>
using namespace std;
int n;
void prims(int g[10][10]);
int minKey(int key[10],int vis[10]);
int print(int parent[10], int n, int graph[10][10]);

int main()
{
	int g[10][10];
	cout<<"Enter the no. of vertices";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<i<<"-"<<j<<" : ";
			cin>>g[i][j];
		}
	}
	
	prims(g[n][n]);

}

void prims(int g[10][10])
{
	int key[n],parent[n],vis[n];
	
	for(int i=0;i<n;i++)
	{
		key[i]=999;
		vis[i]=0;
	}
	
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<n;count++)
	{
		int u=minKey(key[n],vis[n]);
		vis[u]=1;
		
		for(int v=0;v<n;v++)
		{
			if(g[u][v]!=0 && vis[v]==0 && g[u][v]<key[v])
			{
				key[v]=g[u][v];
				parent[u]=v;
			}
		}
	}
	
	print(parent,n,g[][])
}

int minKey(int key[10],int vis[10])
{
	int min=999,min_index;
	
	for(int v=0;v<n;v++)
	{
		if(vis[v]==0 && key[v]<min)
		{
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}


int print(int parent[10], int n, int graph[10][10])
{
    cout<<"Edge   Weight\n";
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, g[i][parent[i]]);
}

