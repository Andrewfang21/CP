#include<bits/stdc++.h>
using namespace std;
long long TC,i,N,E,Q,R,j,k,a,b,x[200025],y[200025],hitung,temp,u;
bool visited[50025],special[50025],destroyed[200025];
queue<long long>q;
vector<long long>adj[50025];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	for (i=1;i<=TC;i++)
	{
		memset(visited,false,sizeof(visited));
		memset(special,false,sizeof(special));
		memset(destroyed,false,sizeof(destroyed));
		cin>>N>>E>>Q>>R;
		for (j=1;j<=E;j++)
			cin>>x[j]>>y[j];
		for (j=1;j<=Q;j++)
		{
			cin>>a;
			special[a]=true;
		}
		for (j=1;j<=R;j++)
		{
			cin>>a;
			destroyed[a]=true;
		}
		for (j=1;j<=E;j++)
		{
			if (!destroyed[j])
			{
				adj[x[j]].push_back(y[j]);
				adj[y[j]].push_back(x[j]);
			}
		}
		hitung=0;
		
		for (j=1;j<=N;j++)
		{
			if ((special[j])&&(!visited[j]))
			{
				q.push(j);
				temp=0;
				
				while(!q.empty())
				{
					u=q.front();	q.pop();
					if (!visited[u])
					{
						visited[u]=true;
						if (special[u])	temp++;
						for (k=0;k<adj[u].size();k++)
							q.push(adj[u][k]);
					}
				}
				hitung+=temp*(Q-temp);			
			}
		}
		hitung/=2;
		cout<<hitung<<"\n";
		for (j=1;j<=N;j++)
			adj[j].clear();
	}
return 0;
}
