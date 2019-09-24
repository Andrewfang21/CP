#include<bits/stdc++.h>
using namespace std;
int dist[1005][1005],N,M;
bool visited[1005][1005];
char maze[1005][1005];

struct lol
{
	int x,y,jarak;
}u,temp,start,finish;

void BFS(int i, int j)
{
	queue<lol>q;
	q.push({i,j,-1});
	memset(dist,-1,sizeof(dist));
	while (!q.empty())
	{
		u=q.front();		q.pop();
		
		if (!visited[u.x][u.y])
		{
			visited[u.x][u.y]=true;
			dist[u.x][u.y]=u.jarak+1;
			
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x-1>=1)&&(maze[temp.x-1][temp.y]!='X')&&(!visited[temp.x-1][temp.y]))
			{
				q.push({temp.x-1,temp.y,dist[u.x][u.y]});
				temp.x--;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x+1<=N)&&(maze[temp.x+1][temp.y]!='X')&&(!visited[temp.x+1][temp.y]))
			{
				q.push({temp.x+1,temp.y,dist[u.x][u.y]});
				temp.x++;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x-1>=1)&&(temp.y-1>=1)&&(maze[temp.x-1][temp.y-1]!='X')&&(!visited[temp.x-1][temp.y-1]))
			{
				q.push({temp.x-1,temp.y-1,dist[u.x][u.y]});
				temp.x--;	temp.y--;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x+1<=N)&&(temp.y+1<=M)&&(maze[temp.x+1][temp.y+1]!='X')&&(!visited[temp.x+1][temp.y+1]))
			{
				q.push({temp.x+1,temp.y+1,dist[u.x][u.y]});
				temp.x++;	temp.y++;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.y-1>=1)&&(maze[temp.x][temp.y-1]!='X')&&(!visited[temp.x][temp.y-1]))
			{
				q.push({temp.x,temp.y-1,dist[u.x][u.y]});
				temp.y--;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.y+1<=M)&&(maze[temp.x][temp.y+1]!='X')&&(!visited[temp.x][temp.y+1]))
			{
				q.push({temp.x,temp.y+1,dist[u.x][u.y]});
				temp.y++;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x-1>=1)&&(temp.y+1<=M)&&(maze[temp.x-1][temp.y+1]!='X')&&(!visited[temp.x-1][temp.y+1]))
			{
				q.push({temp.x-1,temp.y+1,dist[u.x][u.y]});
				temp.x--;	temp.y++;
			}
			temp.x=u.x;		temp.y=u.y;
			while ((temp.x+1<=N)&&(temp.y-1>=1)&&(maze[temp.x+1][temp.y-1]!='X')&&(!visited[temp.x+1][temp.y-1]))
			{
				q.push({temp.x+1,temp.y-1,dist[u.x][u.y]});
				temp.x++;	temp.y--;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC;
	cin>>TC;
	
	while (TC--)
	{
		int i,j;
		cin>>N>>M;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='S')
				{
					start.x=i;		start.y=j;
				}
				else
				if (maze[i][j]=='F')
				{
					finish.x=i;		finish.y=j;
				}
			}
		memset(visited,false,sizeof(visited));
		
		BFS(start.x,start.y);
		
		if (!visited[finish.x][finish.y])
			cout<<"-1\n";
		else
			cout<<dist[finish.x][finish.y]<<"\n";	
	}
return 0;
}
