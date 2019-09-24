#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,j,k,cost,ans;
	cin>>N;
	long long weight[N+5][N+5],dist[N+5],parent[N+5];
	bool visited[N+5];
	
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin>>weight[i][j];
		
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
			dist[j]=INT_MAX;
		memset(visited,false,sizeof(visited));
		
		dist[i]=0;
		typedef pair<int, int> ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		ii u;
		cost=0, ans=INT_MAX;
		
		q.push({0,i});
		
		while (!q.empty())
		{
			u=q.top();	q.pop();
			
			if (!visited[u.second])
			{
				//cout<<u.second<<" "<<parent[u.second]<<"\n";
				visited[u.second]=true;
				dist[u.second]=u.first;
				cost+=u.first;
				for (k=1;k<=N;k++)
				{
					if (!visited[k])
					{
						q.push({weight[u.second][k],k});
						parent[k]=u.second;
					}
				}
				
			}
		}
		//cout<<i<<" "<<cost<<"\n";
		if (ans>cost)
			ans=cost;
	}
	cout<<cost<<"\n";
return 0;
}