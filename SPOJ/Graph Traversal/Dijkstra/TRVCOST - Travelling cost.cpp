#include<bits/stdc++.h>
using namespace std;
int source,N,i,dist[505],INF=2*pow(10,7),a,b,c,weight[505][505];
vector<int>adj[505];
bool visited[505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	memset(visited,false,sizeof(visited));
		
	for (i=0;i<=500;i++)
		dist[i]=INF;
	
	for (i=1;i<=N;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(b);	adj[b].push_back(a);
		weight[a][b]=weight[b][a]=c;
	}
	cin>>source;
	typedef pair<int,int> ii;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	ii u;
	q.push({0,source});
	
	while (!q.empty())
	{
		u=q.top();		q.pop();
		
		if (!visited[u.second])
		{
			visited[u.second]=true;
			dist[u.second]=u.first;
			
			for (i=0;i<adj[u.second].size();i++)
			{
				int temp=adj[u.second][i];
				if (dist[temp]>dist[u.second]+weight[u.second][temp])
					q.push({dist[u.second]+weight[u.second][temp],temp});
			}
		}
	}
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>a;
		if (dist[a]!=INF)
			cout<<dist[a]<<"\n";
		else
			cout<<"NO PATH\n";
	}
return 0;
}
