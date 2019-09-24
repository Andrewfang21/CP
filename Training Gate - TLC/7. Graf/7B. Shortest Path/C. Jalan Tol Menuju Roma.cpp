#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int node,jarak,tiket;
}u;

int N,L,T,awal,akhir,jalur[505][505],i,a,b,dist[505];
bool visited[505],used[505][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>L>>T>>awal>>akhir;
	for (i=1;i<=L;i++)
	{
		cin>>a>>b;
		jalur[a][b]=1;
		jalur[b][a]=1;
	}
	for (i=1;i<=T;i++)
	{
		cin>>a>>b;
		jalur[a][b]=2;
		jalur[b][a]=2;
	}
	
	queue<lol>q;
	q.push({awal,0,1});
	dist[awal]=0;
	dist[akhir]=INT_MAX;
	while(!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.node])||(!used[u.node][u.tiket]))
		{
			visited[u.node]=true;
			used[u.node][u.tiket]=true;
			
			if ((u.node==akhir)&&(u.tiket>=0))
			{
				cout<<u.jarak<<"\n";
				return 0;
			}
			else
				dist[u.node]=u.jarak;
			
			for (i=1;i<=N;i++)
			{
				if ((jalur[u.node][i]!=0)&&(u.tiket>=0)) //parent[x][y] menyatakan apakah jalur ke x melalui node y tepat sebelumnya
				{
					if (jalur[u.node][i]==1)
						q.push({i,u.jarak+1,u.tiket});
					else
					if ((jalur[u.node][i]==2)&&(u.tiket>0))
						q.push({i,u.jarak+1,u.tiket-1});
				}
			}	
		}
	}
return 0;
}