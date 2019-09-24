#include<bits/stdc++.h>
using namespace std;
int cnt_sheep,cnt_wolves,N,M,sheep,wolves;
bool visited[255][255],success;
char maze[255][255];

bool inside(int i, int j)
{
	if ((i>=1)&&(i<=N)&&(j>=1)&&(j<=M))
		return true;
return false;
}

void dfs(int x, int y)
{
	if ((inside(x,y))&&(maze[x][y]!='#')&&(!visited[x][y]))
	{
		visited[x][y]=true;
		if (maze[x][y]=='k')
			cnt_sheep++;
		else
		if (maze[x][y]=='v')
			cnt_wolves++;
		
		if ((x==1)||(x==N)||(y==1)||(y==M))
			success=true;
			
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
		
	}
}

int main()
{
	int i,j;
	cin>>N>>M;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin>>maze[i][j];
			
	memset(visited,false,sizeof(visited));
	sheep=wolves=0;
	
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
		{
			if (((maze[i][j]=='k')||(maze[i][j]=='v'))&&(!visited[i][j]))
			{
				success=false;
				cnt_sheep=cnt_wolves=0;
				dfs(i,j);
			
				//cout<<i<<" "<<j<<" "<<cnt_sheep<<" "<<cnt_wolves<<"\n";
					
				if (success)
				{
					sheep+=cnt_sheep;
					wolves+=cnt_wolves;
				}
				else
				if (cnt_sheep>cnt_wolves)
					sheep+=cnt_sheep;
				else
					wolves+=cnt_wolves;	
			}
		}
	cout<<sheep<<" "<<wolves<<"\n";
return 0;
}
