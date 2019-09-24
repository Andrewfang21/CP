#include<bits/stdc++.h>
using namespace std;
char maze[105][105];
bool visited[105][105][20];
int M,N,dist[105][105][20],ans;

struct lol
{
	int x,y,jarak,key;
}start,finish;

bool check (int x, int y, int mask)
{
	if ((maze[x][y]>='A')&&(maze[x][y]<='Z'))
	{
		if (maze[x][y]=='B')
		{
			if ((mask&(1<<0))!=0)
				return true;
			else
				return false;
		}
		else
		if (maze[x][y]=='Y')
		{
			if ((mask&(1<<1))!=0)
				return true;
			else
				return false;
		}
		else
		if (maze[x][y]=='R')
		{
			if ((mask&(1<<2))!=0)
				return true;
			else
				return false;
		}
		else
		if (maze[x][y]=='G')
		{
			if ((mask&(1<<3))!=0)
				return true;
			else
				return false;
		}
	}
return true;
}

bool inside(int x, int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M))
		return true;
	return false;
}

void BFS(int i, int j)
{
	lol u;
	int temp;
	queue<lol>q;
	memset(visited,false,sizeof(visited));
	while (!q.empty())
		q.pop();
		
	q.push({i,j,-1,0});		//koor-x, koor-y, distance, key(mask)
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.x][u.y][u.key])&&(inside(u.x,u.y))&&(maze[u.x][u.y]!='#'))
		{
			if (check(u.x,u.y,u.key))	//check apakah ada kunci atau tidak
			{
				temp=u.key;
				if (maze[u.x][u.y]=='b')
					temp=temp|(1<<0);
				if (maze[u.x][u.y]=='y')
					temp=temp|(1<<1);
				if (maze[u.x][u.y]=='r')
					temp=temp|(1<<2);
				if (maze[u.x][u.y]=='g')
					temp=temp|(1<<3);
				
				visited[u.x][u.y][temp]=true;
				dist[u.x][u.y][temp]=u.jarak+1;
				
				if (maze[u.x][u.y]=='X')
				{
					ans=dist[u.x][u.y][temp];
					break;
				}
				
				//cout<<u.x<<" "<<u.y<<" "<<dist[u.x][u.y][temp]<<" "<<temp<<"\n";	
					
				q.push({u.x+1,u.y,dist[u.x][u.y][temp],temp});
				q.push({u.x-1,u.y,dist[u.x][u.y][temp],temp});
				q.push({u.x,u.y+1,dist[u.x][u.y][temp],temp});
				q.push({u.x,u.y-1,dist[u.x][u.y][temp],temp});	
			}
		}
	}
}

int main()
{
	while (cin>>N>>M)
	{
		int i,j;
		if ((N==0)&&(M==0))
			return 0;
			
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='*')
					start.x=i,start.y=j;
			}
		ans=-1;	
		BFS(start.x,start.y);
		
		if (ans==-1)
			cout<<"The poor student is trapped!\n";
		else
			printf("Escape possible in %lld steps.\n",ans);
	}
return 0;
}
