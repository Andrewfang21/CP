#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int>vec,adj[1005];

void DFS(int node)
{
	if (!visited[node])
	{
		visited[node]=true;
		vec.push_back(node);
		
		for (int i=0;i<adj[node].size();i++)
		{
			int temp=adj[node][i];
			if (!visited[temp])
				DFS(temp);
		}
	}
}

void BFS(int node)
{
	queue<int>q;
	memset(visited,false,sizeof(visited));
	q.push(node);
	
	while (!q.empty())
	{
		int u=q.front();	q.pop();
		
		if (!visited[u])
		{
			visited[u]=true;
			q.push(u);
			vec.push_back(u);
			
			for (int temp=0;temp<adj[u].size();temp++)	
				if (!visited[adj[u][temp]])
					q.push(adj[u][temp]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,tc,N,M,a,b,i,j;
	cin>>TC;
	
	for (tc=1;tc<=TC;tc++)
	{
		cin>>N;
		for (i=1;i<=N;i++)
		{
			cin>>a>>M;
			for (j=1;j<=M;j++)
			{
				cin>>b;
				adj[a].push_back(b);
			}
		}
		int vertex,tipe;
		cout<<"graph "<<tc<<"\n";
		while (cin>>vertex>>tipe)
		{
			if ((vertex==0)&&(tipe==0))
				break;
			if (tipe==0)
			{
				vec.clear();
				memset(visited,false,sizeof(visited));
				DFS(vertex);	
			}
			else
			if (tipe==1)
			{
				vec.clear();
				BFS(vertex);
			}
			for (int temp=0;temp<vec.size();temp++)
			{
				if (temp==vec.size()-1)
					cout<<vec[temp]<<"\n";
				else
					cout<<vec[temp]<<" ";
			}
		}
		for (i=1;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
