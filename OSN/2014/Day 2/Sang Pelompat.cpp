#include<bits/stdc++.h>
using namespace std;
char maze[1005][1005];
int M,N,dist[1005][1005];
bool visited[1005][1005];
struct lol
{
	int x,y;
}bla,start,finished,temp;
struct haha
{
	lol koor;
	int walk;
}u;
queue<haha>q;
void atas(int a, int b, int c)
{
	for (int i=a;i>=1;i--)
	{
		if (maze[i][b]!='.')
		{
			bla.x=i;	bla.y=b;
			q.push({bla,c+1});
			break;
		}
	}
}
void bawah(int a, int b, int c)
{
	for (int i=a;i<=M;i++)
	{
		if (maze[i][b]!='.')
		{
			bla.x=i;	bla.y=b;
			q.push({bla,c+1});
			break;
		}
	}
}
void kanan(int a, int b, int c)
{
	for (int i=b;i<=N;i++)
	{
		if (maze[a][i]!='.')
		{
			bla.x=a;	bla.y=i;
			q.push({bla,c+1});
			break;
		}
	}
}
void kiri(int a, int b, int c)
{
	for (int i=b;i>=1;i--)
	{
		if (maze[a][i]!='.')
		{
			bla.x=a;	bla.y=i;
			q.push({bla,c+1});
			break;
		}
	}
}
int main()
{
	string dummy;
	getline(cin,dummy);
	int i,j;
	cin>>M>>N;
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
		{
			cin>>maze[i][j];
			if (maze[i][j]=='S')
			{
				start.x=i;	start.y=j;
			}
			if (maze[i][j]=='T')
			{
				finished.x=i;	finished.y=j;
			}
			dist[i][j]=2*pow(10,7);
		}
	dist[finished.x][finished.y]=2*pow(10,7);
	dist[start.x][start.y]=0;
	q.push({start,0});
	memset(visited,false,sizeof(visited));
	
	while(!q.empty())
	{
		u=q.front();	q.pop();
			
		if ((!visited[u.koor.x][u.koor.y])||(dist[u.koor.x][u.koor.y]>u.walk))
		{
			visited[u.koor.x][u.koor.y]=true;
			dist[u.koor.x][u.koor.y]=u.walk;
			//cout<<u.koor.x<<" "<<u.koor.y<<"\n";
			
			if (maze[u.koor.x+1][u.koor.y]=='.')
				bawah(u.koor.x+1,u.koor.y,u.walk);
			if (maze[u.koor.x-1][u.koor.y]=='.')
				atas(u.koor.x-1,u.koor.y,u.walk);
			if (maze[u.koor.x][u.koor.y+1]=='.')
				kanan(u.koor.x,u.koor.y+1,u.walk);
			if (maze[u.koor.x][u.koor.y-1]=='.')
				kiri(u.koor.x,u.koor.y-1,u.walk);
		
			if (maze[u.koor.x+1][u.koor.y]!='.')
			{
				if ((u.koor.x+1>=1)&&(u.koor.x+1<=M)&&(u.koor.y>=1)&&(u.koor.y<=N))
				{
					temp.x=u.koor.x+1;	temp.y=u.koor.y;
					q.push({temp,u.walk});
				}
			}
			if (maze[u.koor.x-1][u.koor.y]!='.')
			{
				if ((u.koor.x-1>=1)&&(u.koor.x-1<=M)&&(u.koor.y>=1)&&(u.koor.y<=N))
				{
					temp.x=u.koor.x-1;	temp.y=u.koor.y;
					q.push({temp,u.walk});
				}
			}
			if (maze[u.koor.x][u.koor.y+1]!='.')
			{
				if ((u.koor.x>=1)&&(u.koor.x<=M)&&(u.koor.y+1>=1)&&(u.koor.y+1<=N))
				{
					temp.x=u.koor.x;	temp.y=u.koor.y+1;
					q.push({temp,u.walk});
				}
			}
			if (maze[u.koor.x][u.koor.y-1]!='.')
			{
				if ((u.koor.x>=1)&&(u.koor.x<=M)&&(u.koor.y-1>=1)&&(u.koor.y-1<=N))
				{
					temp.x=u.koor.x;	temp.y=u.koor.y-1;
					q.push({temp,u.walk});
				}
			}
		}
	}
	if (dist[finished.x][finished.y]==2*pow(10,7))
		cout<<"-1\n"; else	cout<<dist[finished.x][finished.y]<<"\n";
return 0;
}
