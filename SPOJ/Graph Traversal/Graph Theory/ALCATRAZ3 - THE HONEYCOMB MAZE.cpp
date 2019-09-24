#include<bits/stdc++.h>
using namespace std;
bool visited[105][105],success;
char maze[105][105];
int k,N,M;

struct lol
{
	int x,y;
}start;

bool inside(int x,int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M))
		return true;
	return false;
}

void DFS(int x, int y, int cnt)
{
	if ((!visited[x][y])&&(!success)&&(inside(x,y))&&(maze[x][y]!='*'))
	{
		visited[x][y]=true;
		
		DFS(x-1,y,cnt+1);
		DFS(x+1,y,cnt+1);
		DFS(x,y-1,cnt+1);
		DFS(x,y+1,cnt+1);
		visited[x][y]=false;
	}
	else
	if ((x==start.x)&&(y==start.y)&&(cnt>=k)&&(cnt!=0))
		success=true;
}

int main()
{
	int i,j;
	cin>>N>>M;
	cin>>k;
	cin>>start.x>>start.y;
	
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin>>maze[i][j];
	success=false;
	DFS(start.x,start.y,0);
	if (success)
		cout<<"YES\n";
	else
		cout<<"NO\n";
return 0;
}
