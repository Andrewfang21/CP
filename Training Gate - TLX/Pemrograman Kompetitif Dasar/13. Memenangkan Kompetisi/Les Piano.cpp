#include<bits/stdc++.h>
using namespace std;

int main()
{
	short int V,E,start,ends,temp,i,j,a,b,c,jarak,node;
	cin>>V>>E>>start>>ends;
	short int weight[V+5][V+5];
	int dist[V+5],INF;
	bool visited[V+5];
	INF=2*pow(10,7);
	
	for (i=1;i<=V;i++)
	{
		for (j=1;j<=V;j++)
		{
			weight[i][j]=INF;
			dist[i]=INF;
		}
	}
		
	for (i=1;i<=E;i++)
	{
		cin>>a>>b>>c;
		if ((weight[a][b]>c)&&weight[b][a]>c)
		{
			weight[a][b]=c;
			weight[b][a]=c;
		}
	}
	
	typedef pair<int, int>ii;
	pair<int,int>u;
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	pq.push(ii(0,start));
	dist[start]=0;
	memset(visited,false,sizeof(visited));
	
	while (!pq.empty())
	{
		u=pq.top();	pq.pop();
		jarak=u.first;
		node=u.second;
		
		visited[node]=true;
		
		for (i=1;i<=V;i++)
		{
			if ((weight[node][i]!=INF)&&(!visited[i])&&(dist[i]>dist[node]+weight[node][i])&&(i!=node))
			{
				dist[i]=dist[node]+weight[node][i];
				pq.push(ii(dist[i],i));
			}
		}
	}
	printf("%d\n",dist[ends]);

return 0;
}
