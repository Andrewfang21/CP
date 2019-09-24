#include<bits/stdc++.h>
using namespace std;

struct lol
{
	int satu,dua,jarak;
};

int main()
{
	int N,M,i,j,x,y;
	cin>>N>>M;
	char maze[M+5][N+5];
	int dist[M+5][N+5];
	bool visited[M+5][N+5],first=false;
	pair<int,int>start,finish;
	
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
		{
			cin>>maze[i][j];
			dist[i][j]=INT_MAX;
			if (maze[i][j]=='C')
			{
				if (!first)
				{
					first=true;
					start.first=i;		start.second=j;
				}
				else
				{
					finish.first=i;		finish.second=j;
				}
			}
		}
	queue<lol> q;
	dist[start.first][start.second]=-1;
	q.push({start.first,start.second,-1});
	lol u;
	memset(visited,false,sizeof(visited));
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if (!visited[u.satu][u.dua])
		{
			visited[u.satu][u.dua]=true;
			x=i=u.satu;	y=j=u.dua;
			
			while ((x-1>=1)&&(maze[x-1][j]!='*'))
			{
				if (dist[x-1][j]>dist[i][j]+1)
				{
					dist[x-1][j]=dist[i][j]+1;
					q.push({x-1,j,dist[x-1][j]});
					
					//cout<<x-1<<" "<<j<<" "<<dist[x-1][j]<<"\n";
				}
				x--;
			}
			
			while ((x+1<=M)&&(maze[x+1][j]!='*'))
			{
				if (dist[x+1][j]>dist[i][j]+1)
				{
					dist[x+1][j]=dist[i][j]+1;
					q.push({x+1,j,dist[x+1][j]});
					
					//cout<<x+1<<" "<<j<<" "<<dist[x+1][j]<<"\n";
				}
				x++;
			}
			
			while ((y+1<=N)&&(maze[i][y+1]!='*'))
			{
				if (dist[i][y+1]>dist[i][j]+1)
				{
					dist[i][y+1]=dist[i][j]+1;
					q.push({i,y+1,dist[i][y+1]});
				
					//cout<<i<<" "<<y+1<<" "<<dist[i][y+1]<<"\n";
				}
				y++;
			}
			
			while ((y-1>=1)&&(maze[i][y-1]!='*'))
			{
				if (dist[i][y-1]>dist[i][j]+1)
				{
					dist[i][y-1]=dist[i][j]+1;
					q.push({i,y-1,dist[i][y-1]});
				
					//cout<<i<<" "<<y-1<<" "<<dist[i][y-1]<<"\n";
				}
				y--;
			}
		}
	}
	cout<<dist[finish.first][finish.second]<<"\n";
	/*for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
			cout<<dist[i][j]<<" ";
		cout<<"\n";
	}*/
return 0;
}
