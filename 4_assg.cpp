#include<iostream>
using namespace std;

class graph
{
public:
	int n;
	string c[20];
	int g[20][20];
	int visited[20];
	int key[20],parent[20],vis[20];
	
	void create();
	int city_index(string c);
	void insertedge();
	void insertvertex();
	void deledge();
	void delvertex();
	void display();
	void indeg();
	void outdeg();
	void DFS(int i);
	
void prims()
{
	
	
	for(int i=0;i<n;i++)
	{
		key[i]=999;
		vis[i]=0;
	}
	
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<n;count++)
	{
		int u=minKey();
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
	
	print();
}

int minKey()
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


int print()
{
    cout<<"Edge   Weight\n";
    for (int i = 1; i < n; i++)
       cout<< parent[i]<<" "<< i <<" "<< g[i][parent[i]]<<endl;
}
	
};

void graph:: create()
{
	cout<<"Enter no. of cities:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter city";
		cin>>c[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j]=0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
}

int graph::city_index(string ch)
{
	int poa=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]==ch)
		{
			poa=1;
			return i;
		}
		else 
		continue;
	}
	if(poa==-1)
	return -1;
}

void graph:: insertedge()
{
	int in1,in2;
	string c1,c2;
	cout<<"\nEnter 1st city:";
	cin>>c1;
	in1=city_index(c1);
	
	cout<<"\nEnter connecting city";
	cin>>c2;
	in2=city_index(c2);
	
	if(in1!=-1 && in2!=-1)
	{
		cout<<"\nenter distance betwwen cities";
		cin>>g[in1][in2];
	}
	else 
	{
		cout<<"\ncity does not exist";
	}
}

void graph::insertvertex()
{
	string temp;
	cout<<"Enter city";
	cin>>temp;
	
	int tin;
	tin=city_index(temp);
	
	if(tin==-1)
	{
		c[n]=temp;
		for(int j=0;j<n;j++)
		{
			g[n][j]=0;		//***
			g[j][n]=0;
		}
		g[n][n]=0;
		n++;
	}
	else
	{
		cout<<"\nCity already exists!";
	}
}

void graph::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g[i][j]==0)
			continue;
			
			else
			cout<<c[i]<<"->"<<c[j]<<"="<<g[i][j]<<"hrs"<<endl;
		}
	}
}

void graph:: deledge()
{
	int in1,in2;
	string c1,c2;
	cout<<"\nEnter 1st city:";
	cin>>c1;
	in1=city_index(c1);
	
	cout<<"\nEnter connecting city";
	cin>>c2;
	in2=city_index(c2);
	
	if(in1!=-1 && in2!=-1)
	{
		g[in1][in2]=0;
	}
	else 
	{
		cout<<"\ncity does not exist";
	}
}

void graph::delvertex()
{
	string temp;
	cout<<"Enter city";
	cin>>temp;
	
	int tin;
	tin=city_index(temp);
	
	if(tin==-1)
	{
		cout<<"\ncity does not exist";
	}
	else
	{
		for(int j=0;j<n;j++)
		{
			g[tin][j]=0;		//***
			g[j][tin]=0;
		}
		c[tin]=" ";
		
	}
}

void graph:: indeg()
{
	string temp;
	cout<<"Enter city";
	cin>>temp;
	
	int tin,count=0;
	tin=city_index(temp);
	
	if(tin==-1)
	{
		cout<<"\ncity does not exist";
	}
	else
	{
		for(int j=0;j<n;j++)
		{
			if(g[j][tin]!=0)
				count++;
			else
				continue;
		}
	}
	
	cout<<"indegree"<<count;
	
}
void graph:: outdeg()
{
	string temp;
	cout<<"Enter city";
	cin>>temp;
	
	int tin,count=0;
	tin=city_index(temp);
	
	if(tin==-1)
	{
		cout<<"\ncity does not exist";
	}
	else
	{
		for(int j=0;j<n;j++)
		{
			if(g[tin][j]!=0)
				count++;
			else
				continue;
		}
	}
	
	cout<<"outdegree"<<count;
	
}

void graph::DFS(int i)
{
	cout<<"\n"<<c[i];
	visited[i]=1;
	for(int j=0;j<n;j++)
	{
		if(visited[j]==0 &&  g[i][j]!=0)
		{
			DFS(j);
		}
	}
	
}

int main()
{
	graph g;
	int flag=0,ch;
	while(flag==0)
	{
		cout<<"\n\n1.create graph\n2.insert vertex\n3.insert edge\n4.delete edge\n5.delete vertex\n6.display\n7.indeg\n8.outdeg\n9.dfs";
		cout<<"\n10.prims\n11.kruskals\n";
		cin>>ch;
		switch(ch)
		{
			case 1:g.create();
			break;
			
			case 2:g.insertvertex();
			break;
			
			case 3:g.insertedge();
			break;
			
			case 4:g.deledge();
			break;
			
			case 5:g.delvertex();
			break;
			
			case 6:g.display();
			break;
			
			case 7:g.indeg();
			break;
			
			case 8:g.outdeg();
			break;
			
			case 9:g.DFS(0);
			break;
			
                        case 10:g.prims();
			break;
			
			/*case 11:g.kruskals();
                        break;*/
			
			default:flag=1;
			break;
			
		}
	}
	
}
