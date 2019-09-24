#include<bits/stdc++.h>
using namespace std;
bool visited[10005];
int cnt,a,b,N,M,i,maks,choose;
vector<int>adj[10005];

void dfs(int node)
{
	int temp;
	if (!visited[node])
	{
		visited[node]=true;
		cnt++;
		
		for (int temp=0;temp<adj[node].size();temp++)
			dfs(adj[node][temp]);
	}
}

int main()
{
	maks=INT_MIN;	choose=-1;
	cin>>N>>M;
	for (i=1;i<=M;i++)
	{
		cin>>b>>a;
		adj[a].push_back(b);
	}
	for (i=1;i<=N;i++)
	{
		if (adj[i].size()!=0)
		{
			cnt=0;
			memset(visited,false,sizeof(visited));
			dfs(i);
			if (cnt>maks)
			{
				maks=cnt;
				choose=i;
			}
			//cout<<i<<" "<<cnt<<"\n";
		}
	}
	cout<<choose<<"\n";
return 0;
}
