#include<bits/stdc++.h>
#define jarak first
#define node second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,M,K,source,to,i,a,b,c,temp;
	long long ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M>>K>>source>>to;
		vector<int>adj[N+5],add[N+5];
		map<long long, long long> weight[N+5],weight1[N+5];
		long long dist_source[N+5],dist_end[N+5];
		bool visited[N+5];
		
		memset(visited,false,sizeof(visited));
		
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			adj[a].push_back(b);
			add[b].push_back(a);
			weight[a][b]=c;
			weight1[b][a]=c;
		}
		
		for (i=1;i<=N;i++)
		{
			dist_source[i]=2000000000;
			dist_end[i]=2000000000;
		}
		
		dist_source[source]=0;
		typedef pair<int, int> ii;
		priority_queue<ii,vector<ii>,greater<ii> >q;
		q.push({0,source});
		ii u;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.node])
			{
				visited[u.node]=true;
				if (dist_source[u.node]>u.jarak)
					dist_source[u.node]=u.jarak;
				
				for (i=0;i<adj[u.node].size();i++)
				{
					temp=adj[u.node][i];
					if (dist_source[temp]>dist_source[u.node]+weight[u.node][temp])
						q.push({dist_source[u.node]+weight[u.node][temp],temp});
				}
			}
		}
		/*for (i=1;i<=N;i++)
			cout<<i<<" "<<dist_source[i]<<"\n";*/
			
		memset(visited,false,sizeof(visited));
		dist_end[to]=0;
		q.push({0,to});
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.node])
			{
				visited[u.node]=true;
				if (dist_end[u.node]>u.jarak)
					dist_end[u.node]=u.jarak;
					
				for (i=0;i<add[u.node].size();i++)
				{
					temp=add[u.node][i];
					if (dist_end[temp]>dist_end[u.node]+weight1[u.node][temp])
						q.push({dist_end[u.node]+weight1[u.node][temp],temp});
				}
			}
		}
	
		/*for (i=1;i<=N;i++)
			cout<<i<<" "<<dist_end[i]<<"\n";*/
		
		ans=dist_source[to];
		
		
		for (i=1;i<=K;i++)
		{
			cin>>a>>b>>c;
			ans=min(ans,min(dist_source[a]+c+dist_end[b],dist_source[b]+c+dist_end[a]));
			//cout<<ans<<"\n";
		}
		if (ans==2000000000)
			cout<<"-1\n";
		else
			cout<<ans<<"\n";
				
		for (i=1;i<=N;i++)
		{
			adj[i].clear();
			add[i].clear();
			weight[i].clear();
			weight1[i].clear();
		}
	}
return 0;
}
