#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
int dist[100005],maks,i,choose;
vector<int>adj[100005];

struct lol
{
	int node,jarak;
}u;

void BFS(int a)
{
	memset(visited,false,sizeof(visited));
	memset(dist,0,sizeof(dist));
	maks=0;
	queue<lol> q;
	q.push({a,-1});
		
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if (!visited[u.node])
		{
			visited[u.node]=true;
			dist[u.node]=u.jarak+1;
			
			if (maks<dist[u.node])
			{
				maks=dist[u.node];
				choose=u.node;
			}
			
			for (i=0;i<adj[u.node].size();i++)
			{
				if (!visited[adj[u.node][i]])
					q.push({adj[u.node][i],dist[u.node]});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,a,b,N;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		for (i=1;i<N;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		BFS(0);
		BFS(choose);		
		
		if (maks%2==0)
			cout<<maks/2<<"\n";
		else
			cout<<(maks+1)/2<<"\n";
		
		for (i=0;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
