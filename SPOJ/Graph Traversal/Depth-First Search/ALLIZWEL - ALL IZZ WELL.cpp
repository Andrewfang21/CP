#include<bits/stdc++.h>
using namespace std;
char maze[105][105];
bool visited[105][105],found;
int N,M,i,j;

bool check (int a, int b, int time)
{
	if ((time==1)&&(maze[a][b]=='A'))
		return true;
	if ((time==2)&&(maze[a][b]=='L'))
		return true;
	if ((time==3)&&(maze[a][b]=='L'))
		return true;
	if ((time==4)&&(maze[a][b]=='I'))
		return true;
	if ((time==5)&&(maze[a][b]=='Z'))
		return true;
	if ((time==6)&&(maze[a][b]=='Z'))
		return true;
	if ((time==7)&&(maze[a][b]=='W'))
		return true;
	if ((time==8)&&(maze[a][b]=='E'))
		return true;
	if ((time==9)&&(maze[a][b]=='L'))
		return true;
	if ((time==10)&&(maze[a][b]=='L'))
		return true;
	return false;
}

void dfs(int x, int y, int time)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)&&(!visited[x][y])&&(check(x,y,time))&&(!found))
	{
		if (time==10)
			found=true;
			
		//cout<<x<<" "<<y<<" "<<time<<" "<<maze[x][y]<<"\n";	
		
		visited[x][y]=true;
		
		if (check(x+1,y,time+1))	dfs(x+1,y,time+1);
		if (check(x-1,y,time+1))	dfs(x-1,y,time+1);
		if (check(x,y+1,time+1))	dfs(x,y+1,time+1);
		if (check(x,y-1,time+1))	dfs(x,y-1,time+1);
		
		if (check(x+1,y+1,time+1))	dfs(x+1,y+1,time+1);
		if (check(x+1,y-1,time+1))	dfs(x+1,y-1,time+1);
		if (check(x-1,y+1,time+1))	dfs(x-1,y+1,time+1);
		if (check(x-1,y-1,time+1))	dfs(x-1,y-1,time+1);
		
		visited[x][y]=false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC;
	
	cin>>TC;
	while (TC--)
	{
		found=false;
		cin>>N>>M;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>maze[i][j];
				
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=M;j++)
			{
				if ((!found)&&(check(i,j,1)))
				{
					dfs(i,j,1);
				}
				else
				if (found)
					break;	
			}
		}
		
		if (!found)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}
