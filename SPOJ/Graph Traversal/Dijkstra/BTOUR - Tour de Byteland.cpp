#include<bits/stdc++.h>
#define pb push_back
using namespace std;
bool visited[1005];
vector<pair<int,int> >adj[1005];
long long INF=2*pow(10,10),N,dist[1005];

pair<long long, long long> Dijkstra(int node)
{
	int i;
	memset(visited,false,sizeof(visited));
	typedef pair<long long,pair<int,int> > ii;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	ii u;
	for (i=1;i<=N;i++)
		dist[i]=INF;
	
	q.push({0,make_pair(node,-1)});
	
	while (!q.empty())
	{
		u=q.top();		q.pop();
		
		if ((!visited[u.second.first])||(u.second.first==node))
		{
			visited[u.second.first]=node;
			dist[u.second.first]=u.first;
			
			if ((u.second.first==node)&&(dist[u.second.first]!=0))
				return make_pair(dist[u.second.first],u.second.second);
			
			for (i=0;i<adj[u.second.first].size();i++)
			{
				int temp=adj[u.second.first][i].first;
				long long len=adj[u.second.first][i].second;
				
				if ((temp==node)||(dist[temp]>dist[u.second.first]+len))
				{
					q.push({dist[u.second.first]+len,make_pair(temp,u.second.second+1)});	
				}
			}
		}
	}
return make_pair(INF,INF);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,M,a,b,c,i;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			adj[a].pb({make_pair(b,c)});
		}
		pair<long long, long long> ans=make_pair(INF,INF),temp;
		
		for (i=1;i<=N;i++)
		{
			if (adj[i].size()>0)
				temp=Dijkstra(i);
				if (ans.first>temp.first)
				{
					ans.first=temp.first;
					ans.second=temp.second;
				}
		}
		if ((ans.first==INF)&&(ans.second==INF))
			cout<<"0 0\n";
		else
			cout<<ans.first<<" "<<ans.second<<"\n";
		for (i=1;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
