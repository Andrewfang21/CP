#include<bits/stdc++.h>
using namespace std;
bool visited[25][25][15];
char maze[25][25][15];
int N,M,dist[25][25][15],res,pattern;

bool inside (int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

struct lol
{
	int x,y,tipe,jarak;
}u;

void BFS(int i, int j, int type)
{
	queue<lol>q;
	memset(visited,false,sizeof(visited));
	while (!q.empty())
		q.pop();
		
	q.push({1,1,1,-1});	//koor-x, koor-y, type, distance
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.x][u.y][u.tipe])&&(inside(u.x,u.y))&&(maze[u.x][u.y][u.tipe]!='1'))
		{
			visited[u.x][u.y][u.tipe]=true;
			dist[u.x][u.y][u.tipe]=u.jarak+1;
			
			//cout<<u.x<<" "<<u.y<<" "<<u.tipe<<" "<<dist[u.x][u.y][u.tipe]<<"\n";
			
			if ((u.x==N)&&(u.y==M))
			{
				res=dist[u.x][u.y][u.tipe];
				/*for (int temp1=1;temp1<=N;temp1++)
				{
					for (int temp2=1;temp2<=M;temp2++)
						cout<<dist[temp1][temp2][u.tipe];
					cout<<"\n";
				}*/
				break;
			}
			
			if (u.tipe+1>pattern)
			{
				q.push({u.x,u.y,1,dist[u.x][u.y][u.tipe]});
				q.push({u.x+1,u.y,1,dist[u.x][u.y][u.tipe]});	
				q.push({u.x-1,u.y,1,dist[u.x][u.y][u.tipe]});
				q.push({u.x,u.y+1,1,dist[u.x][u.y][u.tipe]});
				q.push({u.x,u.y-1,1,dist[u.x][u.y][u.tipe]});
			}	
			else
			{
				q.push({u.x,u.y,u.tipe+1,dist[u.x][u.y][u.tipe]});
				q.push({u.x+1,u.y,u.tipe+1,dist[u.x][u.y][u.tipe]});	
				q.push({u.x-1,u.y,u.tipe+1,dist[u.x][u.y][u.tipe]});
				q.push({u.x,u.y+1,u.tipe+1,dist[u.x][u.y][u.tipe]});
				q.push({u.x,u.y-1,u.tipe+1,dist[u.x][u.y][u.tipe]});
			}
		}	
	}	
}


int main()
{
	int TC=0,i,j,k,INF=2*pow(10,8);
	while (cin>>N>>M>>pattern)
	{
		TC++;
		if ((N==0)&&(M==0)&&(pattern==0))
			return 0;
			
		for (i=1;i<=pattern;i++)
			for (j=1;j<=N;j++)
				for (k=1;k<=M;k++)
				{
					cin>>maze[j][k][i];
					dist[j][k][i]=INF;
				}
		res=-1;			
		BFS(1,1,1);
		if (res==-1)
			cout<<"Case "<<TC<<": Luke and Leia cannot escape.\n";
		else
			cout<<"Case "<<TC<<": Luke and Leia can escape in "<<res<<" steps.\n";
		
		/*for (int temp1=1;temp1<=N;temp1++)
		{
			for (int temp2=1;temp2<=M;temp2++)
				cout<<dist[temp1][temp2][pattern]<<" ";
			cout<<"\n";
		}*/
	}
return 0;
}
