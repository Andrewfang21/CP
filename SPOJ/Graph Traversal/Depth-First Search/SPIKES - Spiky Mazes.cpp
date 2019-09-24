#include<bits/stdc++.h>
using namespace std;
bool success,visited[45][45][1605];
char maze[45][45];
int limit,N,M,treasure=0;

struct lol
{
	int x,y;
}start;

bool inside(int i, int j)
{
	if ((i>=1)&&(i<=N)&&(j>=1)&&(j<=M))
		return true;
	return false;
}

void DFS(int x, int y, int cnt, int damage)
{
	if ((inside(x,y))&&(!visited[x][y][cnt])&&(maze[x][y]!='#')&&(damage<=limit))
	{
		cout<<x<<" "<<y<<" "<<cnt<<" "<<damage<<"\n";
		
		visited[x][y][cnt]=true;
		if ((x==start.x)&&(y==start.y)&&(cnt==1))
		{
			success=true;
			return;
		}
		
		if (maze[x][y]=='s')
		{
			DFS(x+1,y,cnt,damage+1);
			DFS(x-1,y,cnt,damage+1);
			DFS(x,y+1,cnt,damage+1);
			DFS(x,y-1,cnt,damage+1);
		}
		else
		if (maze[x][y]=='x')
		{
			DFS(x+1,y,cnt+1,damage);
			DFS(x-1,y,cnt+1,damage);
			DFS(x,y+1,cnt+1,damage);
			DFS(x,y-1,cnt+1,damage);
		}
		else
		{
			DFS(x+1,y,cnt,damage);
			DFS(x-1,y,cnt,damage);
			DFS(x,y+1,cnt,damage);
			DFS(x,y-1,cnt,damage);
		}
	}
}

int main()
{
	int i,j;
	cin>>N>>M>>limit;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
		{
			cin>>maze[i][j];
			if (maze[i][j]=='@')
			{
				start.x=i;		start.y=j;
			}
		}
		
	DFS(start.x,start.y,0,0);
	
	if (success)
		cout<<"SUCCESS\n";
	else
		cout<<"IMPOSSIBLE\n";
return 0;
}
