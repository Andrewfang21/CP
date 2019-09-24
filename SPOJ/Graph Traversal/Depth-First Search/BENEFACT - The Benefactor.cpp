#include<bits/stdc++.h>
using namespace std;
bool visited[50005];
long long maks,choose;
map<long long, long long>weight[50005];
vector<int>adj[50005];

void dfs(int a,int length)
{
	int i;
	if (!visited[a])
	{
		visited[a]=true;
		//cout<<a<<" "<<length<<"\n";
		
		if (maks<length)
		{
			maks=length;
			choose=a;
		}
			
		for (i=0;i<adj[a].size();i++)
		{
			int temp=adj[a][i];
			dfs(adj[a][i],length+weight[a][temp]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,i,a,b,c;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		
		for (i=0;i<N-1;i++)
		{
			cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			weight[a][b]=weight[b][a]=c;
		}
		memset(visited,false,sizeof(visited));
		maks=0;
		
		for (i=1;i<=N;i++)
		{
			if (adj[i].size()!=0)
			{
				dfs(i,0);
				break;
			}
		}
		memset(visited,false,sizeof(visited));
		dfs(choose,0);
		cout<<maks<<"\n";
		
		for (i=1;i<=N;i++)
		{
			adj[i].clear();
			weight[i].clear();
		}
	}
return 0;
}
