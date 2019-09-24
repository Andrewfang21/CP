#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int x,y,jarak;
}u,choose,start;

bool visited[1005][1005];
long long dist[1005][1005],i,j,maks,M,N;
char maze[1005][1005];

bool check (int i, int j)
{
	if ((i>=1)&&(i<=M)&&(j>=1)&&(j<=N)&&(maze[i][j]!='#'))
		return true;
	return false;
}

void BFS(int a, int b)
{
	queue<lol>q;
	memset(visited,false,sizeof(visited));
	memset(dist,0,sizeof(dist));
	
	maks=0;
	q.push({a,b,-1});
	while (!q.empty())
		{
			u=q.front();	q.pop();
			if ((!visited[u.x][u.y])&&(check(u.x,u.y))&&(maze[u.x][u.y]!='#'))
			{
				visited[u.x][u.y]=true;
				dist[u.x][u.y]=u.jarak+1;
				
				if (dist[u.x][u.y]>maks)
				{
					maks=dist[u.x][u.y];
					choose.x=u.x;	choose.y=u.y;
				}
				
				q.push({u.x-1,u.y,dist[u.x][u.y]});
				q.push({u.x+1,u.y,dist[u.x][u.y]});
				q.push({u.x,u.y-1,dist[u.x][u.y]});
				q.push({u.x,u.y+1,dist[u.x][u.y]});
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
		bool found=false;
		cin>>N>>M;
		for (i=1;i<=M;i++)
			for (j=1;j<=N;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='.')
				{
					if (!found)
					{
						found=true;
						start.x=i;	start.y=j;
					}
				}
			}	
		BFS(start.x,start.y);
		BFS(choose.x,choose.y);	
		
		printf("Maximum rope length is %d.\n",maks);
	}
return 0;
}
