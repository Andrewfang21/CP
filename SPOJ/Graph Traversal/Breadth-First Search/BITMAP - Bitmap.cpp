#include<bits/stdc++.h>
using namespace std;
int TC,i,j,N,M,dist[200][200];
char maze[200][200];

struct lol
{
	int x,y,jarak;
};

bool inside(int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

int main()
{
	cin>>TC;
	
	while (TC--)
	{
		queue<lol>q;
		cin>>N>>M;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='1')
					q.push({i,j,-1});
			}
		memset(dist,-1,sizeof(dist));
		lol u;
		while (!q.empty())
		{
			u=q.front();		q.pop();
			
			if ((dist[u.x][u.y]==-1)&&(inside(u.x,u.y)))
			{
				dist[u.x][u.y]=u.jarak+1;
				
				q.push({u.x+1,u.y,dist[u.x][u.y]});
				q.push({u.x-1,u.y,dist[u.x][u.y]});
				q.push({u.x,u.y+1,dist[u.x][u.y]});
				q.push({u.x,u.y-1,dist[u.x][u.y]});
			}
		}
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				if (j!=M)
					cout<<dist[i][j]<<" ";
				else
					cout<<dist[i][j]<<"\n";	
	}
return 0;
}
