#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int>adj[100005];

void DFS(int node)
{
	if (!visited[node])
	{
		visited[node]=true;
		
		for (int temp=0;temp<adj[node].size();temp++)
		{
			int temp1=adj[node][temp];
			if (!visited[temp1])
				DFS(temp1);
		}
	}
}

int main()
{
	int TC,N,M,i,j,a,b;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		for (i=1;i<=M;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);	adj[b].push_back(a);
		}
		memset(visited,false,sizeof(visited));
		DFS(1);
		
		bool fail=false;
		
		for (i=1;i<=N;i++)
		{
			adj[i].clear();
			if (!visited[i])
				fail=true;
		}
		if (fail)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
return 0;
}
