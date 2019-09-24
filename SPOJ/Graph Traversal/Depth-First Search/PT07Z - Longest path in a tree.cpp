#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10005];
bool visited[10005];
int dist[10005],root,maks;

struct lol
{
	int node,jarak;
}u;

queue<lol>q;
void BFS(int v)
{
	q.push({v,-1});
	dist[v]=-1;
	maks=-1;
	while (!q.empty())
	{
		u=q.front();	q.pop();
		if (!visited[u.node])
		{
			visited[u.node]=true;
			dist[u.node]=u.jarak+1;
			//cout<<u.node<<" "<<dist[u.node]<<"\n";
			if (dist[u.node]>maks)
			{
				maks=dist[u.node];
				root=u.node;
			}
			for (int j=0;j<adj[u.node].size();j++)
			{
				if (!visited[adj[u.node][j]])
					q.push({adj[u.node][j],dist[u.node]});
			}
		}
	}
}

int main()
{
	memset(visited,false,sizeof(visited));
	int N,i,a,b;
	cin>>N;
	for (i=1;i<N;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	lol bla;
	bla.node=1;		bla.jarak=-1;
	BFS(1);
	memset(visited,false,sizeof(visited));
	BFS(root);
	//cout<<root<<"\n";
	cout<<maks<<"\n";
return 0;
}
