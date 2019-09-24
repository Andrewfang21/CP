#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int TC,money,N,M,i,j,INF=2*pow(10,8),a,b,c,d,dest,len,harga;
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>money;
		cin>>N>>M;
		int cost[N+5][N+5],weight[N+5][N+5],dist[M+5][N+5],ans=-1;
		bool visited[M+5][N+5];
		typedef pair<int, pair<int, int> >ii;	
		vector<ii>adj[N+5]; //source,destination,weight,cost
					
		for (i=1;i<=M;i++)
			for (j=1;j<=N;j++)
				dist[i][j]=INF;
				
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c>>d;
			adj[a].pb({b,make_pair(c,d)});
		}
		memset(visited,false,sizeof(visited));
		priority_queue<ii, vector<ii>, greater<ii> >q; 
		q.push({0,make_pair(money,1)});
		ii u;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.second.first][u.second.second])
			{
				visited[u.second.first][u.second.second]=true;
				dist[u.second.first][u.second.second]=u.first;
				
				//cout<<u.second.second<<" "<<u.second.first<<" "<<dist[u.second.first][u.second.second]<<"\n";
				
				if ((u.second.second==N)&&(u.second.first>=0))
				{
					ans=dist[u.second.first][u.second.second];
					break;
				}
				
				for (i=0;i<adj[u.second.second].size();i++)
				{
					dest=adj[u.second.second][i].first;	//destination
					len=adj[u.second.second][i].second.first;	//length
					harga=u.second.first-adj[u.second.second][i].second.second;	//cost
					
					if (harga>=0)
					{
						if ((dist[harga][dest]>(dist[u.second.first][u.second.second]+len))&&(!visited[harga][dest]))
							q.push({dist[u.second.first][u.second.second]+len,make_pair(harga,dest)});
					}
				}
			}
		}
		cout<<ans<<"\n";
		for (i=1;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
