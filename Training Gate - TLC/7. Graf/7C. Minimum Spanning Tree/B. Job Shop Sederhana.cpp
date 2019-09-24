#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,j,k,a;
	cin>>N;
	vector<int>adj[N+5];
	int dist[N+5],cost,weight[N+5][N+5];
	bool visited[N+5];
	
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			cin>>a;
			adj[i].push_back(j);
			weight[i][j]=a;
		}
	typedef pair<int,int> ii;
	ii u;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	int ans=INT_MAX;
	
	for (j=1;j<=N;j++)
		dist[j]=INT_MAX;
	
	memset(visited,false,sizeof(visited));
	cost=dist[u.second]=0;
	q.push({0,1});
	
	while (!q.empty())
	{
		u=q.top();	q.pop();
		
		if (!visited[u.second])
		{
			visited[u.second]=true;
			dist[u.second]=u.first;
			cost+=u.first;
			//cout<<u.second<<" "<<cost<<"\n";
				
			for (j=0;j<adj[u.second].size();j++)
			{
				k=adj[u.second][j];
				q.push({weight[u.second][k],k});
			}
		}
	}
	if (ans>cost)
		ans=cost;
	
	cout<<ans<<"\n";
}