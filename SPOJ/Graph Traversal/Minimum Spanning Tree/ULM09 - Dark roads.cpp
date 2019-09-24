#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int N,M,i,a,b,c;
	while (cin>>N>>M)
	{
		if ((N==0)&&(M==0))
			return 0;
		vector<pair<int,int> >adj[N+5];
		bool visited[N+5],dist[N+5];
		
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			adj[a].pb({make_pair(b,c)});
			adj[b].pb({make_pair(a,c)});
		}
		memset(visited,false,sizeof(visited));
		typedef pair<int, int>ii;
		priority_queue<ii, vector<ii> >q;
		q.push({0,0});
		ii u;
		int cost=0;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.second])
			{
				visited[u.second]=true;
				dist[u.second]=u.first;
				cout<<u.second<<" "<<dist[u.second]<<"\n";
				
				for (i=0;i<adj[u.second].size();i++)
				{
					int temp1=adj[u.second][i].first;
					int temp2=adj[u.second][i].second;
					
					if (!visited[temp1])
						q.push({temp2,temp1});
				}
			}
			
		}
		for (i=0;i<N;i++)
		{
			cost+=dist[i];
			adj[i].clear();
		}
		cout<<cost<<"\n";
	}
return 0;
}
