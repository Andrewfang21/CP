#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int>adj[1005];
long long res,N,M;

void DFS(int i, int depth)
{
	if (depth==2)
	{
		res+=(adj[i].size()-1);
		return;
	}
	else
	{
		for (int it=0;it<adj[i].size();it++)
		{
			int nexts=adj[i][it];
			DFS(nexts,depth+1);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	
	for (int i=1;i<=M;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for (int i=1;i<=N;i++)
		DFS(i,1);
	
	cout<<res<<"\n";
	
return 0;
}
