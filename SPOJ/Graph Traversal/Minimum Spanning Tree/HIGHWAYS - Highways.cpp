#include<bits/stdc++.h>
using namespace std;
int TC,N,V,start,finish,i,a,b,c,k;
bool visited[100025];
int dist[100025];
map<int,int>weight[100025];
vector<int> adj[100025];

int main()
{
	cin>>TC;
	
	for (int temp1=1;temp1<=TC;temp1++)
	{
		cin>>N>>V>>start>>finish;
	
		memset(visited,false,sizeof(visited));
			
		for (i=1;i<=N;i++)
			dist[i]=INT_MAX;
		for (i=1;i<=V;i++)
		{
			cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			weight[a][b]=c;
			weight[b][a]=c;
		}
		dist[start]=0;
		typedef pair<int, int>ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		ii u;
		q.push({0,start});
		
		while (!q.empty())
		{
			u=q.top();	q.pop();
			if (!visited[u.second])
			{
				visited[u.second]=true;
				dist[u.second]=u.first;
				
				for (i=0;i<adj[u.second].size();i++)
				{
					k=adj[u.second][i];
					if (dist[k]>dist[u.second]+weight[u.second][k])
						q.push({dist[u.second]+weight[u.second][k],k});
				}
			}
		}
		if (dist[finish]==INT_MAX)
			cout<<"NONE\n";
		else
			cout<<dist[finish]<<"\n";
		
		for (i=1;i<=N;i++)
			adj[i].clear();	
	}
return 0;
}
