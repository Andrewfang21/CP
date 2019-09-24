#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long N,M,i,a,b,c,INF=2*pow(10,7),cost,j,k;
	cin>>N>>M;
	vector<long long>adj[N+5];
	long long weight[N+5][M+5],dist[N+5];
	bool visited[N+5];
	
	for (i=1;i<=M;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		weight[a][b]=c;
		weight[b][a]=c;
	}
	for (i=1;i<=N;i++)
		dist[i]=INF;
	dist[1]=cost=0;
	typedef pair<long long, long long> ii;
	ii u;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	q.push({0,1});
	memset(visited,false,sizeof(visited));
	
	while (!q.empty())
	{
		u=q.top();	q.pop();
		
		if (!visited[u.second])
		{
			visited[u.second]=true;
			cost+=u.first;
			
			for (j=0;j<adj[u.second].size();j++)
			{
				long long k=adj[u.second][j];
				if (!visited[k])
					q.push({weight[u.second][k],k});
			}
		}
	}
	cout<<cost<<"\n";
return 0;
}
