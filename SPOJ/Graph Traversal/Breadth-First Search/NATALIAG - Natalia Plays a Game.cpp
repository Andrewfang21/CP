#include<bits/stdc++.h>
using namespace std;
int M,N,dist[105][105];
char maze[105][105];
bool visited[105][105];

struct lol
{
	int x,y,jarak;
}u,start,finish;
queue<lol>q;

bool inside(int a,int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

void BFS(int i, int j)
{
	memset(visited,false,sizeof(visited));
	q.push({i,j,-1});
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.x][u.y])&&(inside(u.x,u.y))&&(maze[u.x][u.y]!='*'))
		{
			visited[u.x][u.y]=true;
			dist[u.x][u.y]=u.jarak+1;
			
			q.push({u.x+1,u.y,dist[u.x][u.y]});
			q.push({u.x-1,u.y,dist[u.x][u.y]});
			q.push({u.x,u.y+1,dist[u.x][u.y]});
			q.push({u.x,u.y-1,dist[u.x][u.y]});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,j,INF=2*pow(10,7);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='$')
				{
					start.x=i;	start.y=j;
				}
				else
				if (maze[i][j]=='#')
				{
					finish.x=i;		finish.y=j;
				}
				dist[i][j]=INF;
			}
			
		BFS(start.x,start.y);
		
		if (dist[finish.x][finish.y]==INF)
			cout<<"-1\n";
		else
			cout<<dist[finish.x][finish.y]<<"\n";
	}
return 0;
}
