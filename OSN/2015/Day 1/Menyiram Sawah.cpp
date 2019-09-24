#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,ans,maze[1005][1005],N,M,Q,i,j;
bool visited[1005][1005],can1[1005][1005],can2[1005][1005];

bool inside(int x, int y)
{
	if ((x>=a)&&(x<=c)&&(y>=b)&&(y<=d))
		return true;
return false;
}

void floodfill(int x, int y, int val)
{
	if ((inside(x,y))&&(!visited[x][y])&&(val>maze[x][y]))
	{
		visited[x][y]=true;
		ans++;
		
		floodfill(x+1,y,maze[x][y]);
		floodfill(x-1,y,maze[x][y]);
		floodfill(x,y+1,maze[x][y]);
		floodfill(x,y-1,maze[x][y]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	char dummy[10];
	for (i=0;i<=6;i++)
		scanf("%c",&dummy[i]);
		
	scanf("%d %d %d",&N,&M,&Q);
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			scanf("%d",&maze[i][j]);
	
	if (dummy[5]=='5')
	{
		memset(can1,false,sizeof(can1));
		memset(can2,false,sizeof(can2));
		for (i=1;i<=M;i++)
			can1[i][i]=can2[i][i]=true;
		
		for (i=1;i<M;i++)
			for (j=i+1;j<=M;j++)
			{
				if ((can1[i][j-1])&&(maze[1][j]>maze[1][j-1]))
					can1[i][j]=true;
				if ((can2[i][j-1])&&(maze[1][j]<maze[1][j-1]))
					can2[i][j]=true;
			}
			
		while (Q--)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if (can1[b][d])
				printf("Kanan Bawah\n");
			else
			if (can2[b][d])
				printf("Kiri Atas\n");
			else
				printf("Tidak Mungkin\n");
		}	
	}
	else
	{
		while (Q--)
		{
			memset(visited,false,sizeof(visited));
			scanf("%d %d %d %d",&a,&b,&c,&d);
			memset(visited,false,sizeof(visited));
			ans=0;
			floodfill(a,b,maze[a][b]+1);
			
			if (ans==((d-b+1)*(c-a+1)))
				printf("Kiri Atas\n");
			else
			{
				memset(visited,false,sizeof(visited));
				ans=0;
				floodfill(c,d,maze[c][d]+1);
				
				if (ans==((d-b+1)*(c-a+1)))
					printf("Kanan Bawah\n");
				else
					printf("Tidak Mungkin\n");
			}
		}
	}
return 0;
}
