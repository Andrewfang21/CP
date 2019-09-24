#include<bits/stdc++.h>
using namespace std;
int TC,N,M,i,j;
bool visited[10005];
long long dist[10005],weight[10005][10005],INF=2*pow(10,8),a,b,cost;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	string kota;
	vector<int>adj[10005];
	
	while (TC--)
	{
		cin>>N;
		for (i=1;i<=10000;i++)
			for (j=1;j<=10000;j++)
				weight[i][j]=INF;
				
		memset(visited,false,sizeof(visited));		
		for (i=1;i<=N;i++)
		{
			cin>>kota>>M;
			for (j=1;j<=M;j++)
			{
				cin>>a>>b;
				adj[i].push_back(a);
				adj[a].push_back(i);
				
				weight[i][a]=min(weight[i][a],b);		weight[a][i]=min(weight[a][i],b);
			}
		}
		
		typedef pair<int,int> ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		q.push({0,1});
		ii u;
		cost=0;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.second])
			{
				visited[u.second]=true;
				dist[u.second]=u.first;
				cost+=dist[u.second];
				
				for (i=0;i<adj[u.second].size();i++)
				{
					int temp=adj[u.second][i];
					q.push({weight[u.second][temp],temp});
				}
			}
		}
		cout<<cost<<"\n";
		for (i=1;i<=10000;i++)
			adj[i].clear();
	}
return 0;
}
