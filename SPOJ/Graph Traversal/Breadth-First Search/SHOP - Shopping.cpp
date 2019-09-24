#include<bits/stdc++.h>
using namespace std;
int M,N,dist[25][25];
char maze[25][25];

struct lol
{
	int x,y,jarak;
}start,finish;

bool inside(int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

int check(int a, int b)
{
	if ((maze[a][b]>='1')&&(maze[a][b]<='9'))
		return (maze[a][b]-'0');
	else
		return 0;
}

void BFS(int i, int j)
{
	queue<lol>q;
	lol u;
	q.push({i,j,0});
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((dist[u.x][u.y]>(u.jarak+check(u.x,u.y)))&&(maze[u.x][u.y]!='X')&&(inside(u.x,u.y)))
		{
			dist[u.x][u.y]=u.jarak+check(u.x,u.y);
			
			q.push({u.x+1,u.y,dist[u.x][u.y]});
			q.push({u.x-1,u.y,dist[u.x][u.y]});
			q.push({u.x,u.y+1,dist[u.x][u.y]});
			q.push({u.x,u.y-1,dist[u.x][u.y]});
		}
	}
}

int main()
{
	int i,j,INF=2*pow(10,7);
	
	while (cin>>M>>N)
	{
		if ((M==0)&&(N==0))
			return 0;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='S')
					start.x=i,start.y=j;
				if (maze[i][j]=='D')
					finish.x=i,finish.y=j;
				dist[i][j]=INF;
			}
	BFS(start.x,start.y);
	cout<<dist[finish.x][finish.y]<<"\n";
	
	/*for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
			cout<<dist[i][j]<<" ";
		cout<<"\n";
	}*/
	}
return 0;
}
