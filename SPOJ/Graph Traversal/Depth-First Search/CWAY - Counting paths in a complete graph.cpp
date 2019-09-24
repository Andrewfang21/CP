#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
int N,cnt,i,j;
vector<int>adj[1005];

void DFS(int node)
{
	if (!visited[node])
	{
		visited[node]=true;
		if (node==2)
			cnt++;
		
		for (int i=0;i<adj[node].size();i++)
			if (!visited[adj[node][i]])
				DFS(adj[node][i]);
		visited[node]=false;
	}
}

int main()
{
	cin>>N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			if (i!=j)
				adj[i].push_back(j);
		}
	cnt=0;
	DFS(1);
	cout<<cnt<<"\n";
return 0;
}
