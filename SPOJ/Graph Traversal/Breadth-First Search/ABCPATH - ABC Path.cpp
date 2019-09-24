#include<bits/stdc++.h>
using namespace std;
bool visited[55][55];
char maze[55][55];
int TC,i,j,maks,N,M,temp;

struct lol
{
	int x,y,walk;
}start[650];

bool inside(int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

int main()
{
	TC=0;
	while(cin>>N>>M)
	{
		TC++;
		if ((N==0)&&(M==0))
			return 0;
		temp=1;
		memset(visited,false,sizeof(visited));
		
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='A')
				{
					start[temp].x=i;	start[temp].y=j;
					temp++;
				}
			}
		maks=0;
		queue<lol>q;
		lol u;
		for (i=1;i<temp;i++)
		{
			memset(visited,false,sizeof(visited));
			q.push({start[i].x,start[i].y,1});
			
			while (!q.empty())
			{
				u=q.front();	q.pop();
				if ((!visited[u.x][u.y])&&((maze[u.x][u.y]>='A')&&(maze[u.x][u.y]<='Z'))&&(inside(u.x,u.y)))
				{
					visited[u.x][u.y]=true;
					if (maks<u.walk)
						maks=u.walk;
						
					if (maze[u.x+1][u.y]==maze[u.x][u.y]+1)		q.push({u.x+1,u.y,u.walk+1});
					if (maze[u.x-1][u.y]==maze[u.x][u.y]+1)		q.push({u.x-1,u.y,u.walk+1});
					if (maze[u.x][u.y+1]==maze[u.x][u.y]+1)		q.push({u.x,u.y+1,u.walk+1});
					if (maze[u.x][u.y-1]==maze[u.x][u.y]+1)		q.push({u.x,u.y-1,u.walk+1});
		
					if (maze[u.x-1][u.y-1]==maze[u.x][u.y]+1)	q.push({u.x-1,u.y-1,u.walk+1});
					if (maze[u.x-1][u.y+1]==maze[u.x][u.y]+1)	q.push({u.x-1,u.y+1,u.walk+1});
					if (maze[u.x+1][u.y+1]==maze[u.x][u.y]+1)	q.push({u.x+1,u.y+1,u.walk+1});
					if (maze[u.x+1][u.y-1]==maze[u.x][u.y]+1)	q.push({u.x+1,u.y-1,u.walk+1});
					
				}
			}
		}	
		printf("Case %d: %d\n",TC,maks);
	}
}
