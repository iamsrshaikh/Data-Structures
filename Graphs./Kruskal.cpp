#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int i,j,k,a,b,u,v,n,ne=1;
int mini,mincost=0,cost[9][9],parent[9];

class Kruskal{
public:
    int find(int i);
    int uni(int i,int j);

    
    
};

int Kruskal:: find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int Kruskal:: uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
    Kruskal k;

	cout<<"\n\tImplementation of Kruskal's algorithm\n";
	cout<<"\nEnter the no. of vertices:";
	cin>>n;
	cout<<"\nEnter the cost adjacency matrix:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	cout<<"The edges of Minimum Cost Spanning Tree are\n";
	while(ne < n)
	{
		for(i=1,mini=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < mini)
				{
					mini=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=k.find(u);
		v=k.find(v);
		if(k.uni(u,v))
		{
            
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,mini);
			mincost +=mini;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
    
    return 0;

}
