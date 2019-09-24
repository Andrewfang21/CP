#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,finish,T,V,a,b,c,i,j,INF=2*pow(10,7),ans=0;
	cin>>N;
	int weight[N+5][N+5],dist[N+5];
	bool visited[N+5];
	vector<int> vec[N+5];
	cin>>finish>>T>>V;
	
	for (i=1;i<=V;i++)
	{
		cin>>a>>b>>c;
		vec[a].push_back(b);
		weight[a][b]=c;
	}
	typedef pair<int,int>ii;
	priority_queue<ii,vector<ii>,greater<ii> >q;
	
	for (i=1;i<=N;i++)	
	{
		memset(visited,false,sizeof(visited));
		for (j=1;j<=N;j++)
			dist[j]=INF;
			
		dist[i]=0;
		q.push({0,i});
		ii u;
		
		while (!q.empty())
		{
			u=q.top();	q.pop();
		
			if (!visited[u.second])
			{
				visited[u.second]=true;
				dist[u.second]=u.first;
				
				for (j=0;j<vec[u.second].size();j++)
				{
					int temp=vec[u.second][j];
					if (dist[temp]>dist[u.second]+weight[u.second][temp])
					{	
						int res=dist[u.second]+weight[u.second][temp];
						q.push({res,vec[u.second][j]});
					}
				}
			}
		}
		if (dist[finish]<=T)
			ans++;
	}
	cout<<ans<<"\n";
return 0;
}
