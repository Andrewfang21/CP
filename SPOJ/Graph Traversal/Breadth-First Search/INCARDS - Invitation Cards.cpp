#include<bits/stdc++.h>
using namespace std;
int i,TC,ans,N,M,a,b,c,INF=2*pow(10,8);
bool visited[1000005];
long long dist1[1000005],dist2[1000005];
vector<int> adj[1000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		ans=0;
		cin>>N>>M;
		map<long long, long long>weight[N+5];

		memset(visited,false,sizeof(visited));
		
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			cout<<i<<"\n";
			adj[a].push_back(b);
			weight[a][b]=c;
		}
		
		for (i=1;i<=N;i++)
			dist1[i]=dist2[i]=INF;
			
		typedef pair<int,int> ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		ii u;
		
		q.push({0,1});
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if (!visited[u.second])
			{
				visited[u.second]=true;
				dist1[u.second]=u.first;
				
				for (i=0;i<adj[u.second].size();i++)
				{
					int temp=adj[u.second][i];
					if (dist1[temp]>(dist1[u.second]+weight[u.second][temp]))
						q.push({dist1[u.second]+weight[u.second][temp],temp});
				}
			}
		}
		for (i=1;i<=N;i++)
		{
			cout<<i<<" "<<dist1[i]<<"\n";
			ans+=dist1[i];
		}
			
		for (i=1;i<=N;i++)
		{
			for (int j=1;j<=N;j++)
				dist2[j]=INF;
				
			while (!q.empty())
				q.pop();
			
			memset(visited,false,sizeof(visited));
			q.push({0,i});
			
			while (!q.empty())
			{
				u=q.top();		q.pop();
				
				if (!visited[u.second])
				{
					visited[u.second]=true;
					dist2[u.second]=u.first;
					
					if (u.second==1)
					{
						ans+=dist2[u.second];
						break;			
					}
					for (int temp1=0;temp1<adj[u.second].size();temp1++)
					{
						int temp=adj[u.second][temp];
						if (dist2[temp]>(dist2[u.second]+weight[u.second][temp]))
							q.push({dist2[u.second]+weight[u.second][temp],temp});
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
return 0;
}
