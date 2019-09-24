#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int>adj[100005];

void dfs(int a)
{
	int temp;
	if (!visited[a])
	{
		visited[a]=true;
		
		for (temp=0;temp<adj[a].size();temp++)
			dfs(adj[a][temp]);
	}
}

int main()
{
	int TC,N,V,a,b,ans,i;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>V;
		for (i=1;i<=V;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(visited,false,sizeof(visited));
		ans=0;
		
		for (i=0;i<N;i++)
		{
			if (!visited[i])
			{
				if (adj[i].size()==0)	ans++;
				else
				{
					dfs(i);
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
		
		for (i=0;i<N;i++)
			adj[i].clear();
	}
return 0;
}
