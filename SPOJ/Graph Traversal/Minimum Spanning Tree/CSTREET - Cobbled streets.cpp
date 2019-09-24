#include<bits/stdc++.h>
using namespace std;
bool visited[1005];

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,P,N,V,a,b,c,i,INF=2*pow(10,7),cost,j,k;
	cin>>TC;
	
	while (TC--)
	{
		memset(visited,false,sizeof(visited));
		cin>>P>>N>>V;
		vector<int>adj[N+5];
		int weight[N+5][N+5],dist[N+5];
		
		for (i=1;i<=V;i++)
		{
			cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			weight[a][b]=c;
			weight[b][a]=c;
		}
		
		typedef pair<int, int> ii;
		ii u;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		q.push({0,1});
		for (i=1;i<=N;i++)
			dist[i]=INF;
			
		dist[1]=0;
		cost=0;
		while (!q.empty())
		{
			u=q.top();	q.pop();
			if (!visited[u.second])
			{
				visited[u.second]=true;
				cost+=u.first;
				
				for (j=0;j<adj[u.second].size();j++)
				{
					k=adj[u.second][j];
					if (!visited[k])
						q.push({weight[u.second][k],k});
				}
			}
		}
		cost*=P;
		cout<<cost<<"\n";
	}
return 0;
}
