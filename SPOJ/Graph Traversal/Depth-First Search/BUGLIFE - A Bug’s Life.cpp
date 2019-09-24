#include<bits/stdc++.h>
using namespace std;
short int colour[2005];
vector<int>adj[2005];
bool fail;
 
void BFS(int node)
{
	int u,temp,i;
	colour[node]=1;
	queue<int>q;
	while (!q.empty())
		q.pop();
 
	q.push(node);
	 
	while (!q.empty())
	{
		u=q.front();	q.pop();
	 
		for (i=0;i<adj[u].size();i++)
		{
			int temp=adj[u][i];
			if (colour[temp]==-1)
			{
				colour[temp]=1-colour[u];
				q.push(temp);
			}
			else
			if (colour[temp]==colour[u])
			{
				fail=true;
				break;
			}
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	int TC,it,N,M,i,a,b;
	cin>>TC;
 
	for (it=1;it<=TC;it++)
	{
		cin>>N>>M;
		for (i=1;i<=M;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		fail=false;
		memset(colour,-1,sizeof(colour));
	 
		for (i=1;i<=N;i++)
		{
			if (colour[i]==-1)
			{
				BFS(i);
				if (fail)
					break;	
			}	
		}
		cout<<"Scenario #"<<it<<":\n";
		if (fail)
			cout<<"Suspicious bugs found!\n";
		else
			cout<<"No suspicious bugs found!\n";
	 
		for (i=1;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
