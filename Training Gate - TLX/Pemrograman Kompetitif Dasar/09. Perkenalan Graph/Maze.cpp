#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int x,y,dist;
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	int N,M,i,j;
	cin>>N>>M;
	int maze[N+5][M+5],walk[N+5][M+5];
	bool visited[N+5][M+5];
	memset(visited,false,sizeof(visited));
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin>>maze[i][j];
	lol src,u;
	cin>>src.x>>src.y;
 
	queue<lol>q;
	q.push({src.x,src.y,0});
 
	while(!q.empty())
	{
		u=q.front();	q.pop();
		visited[u.x][u.y]=true;
		walk[u.x][u.y]=u.dist+1;
		if ((u.x==1)||(u.x==N)||(u.y==1)||(u.y==M))
		{
			cout<<walk[u.x][u.y]<<"\n";
			break;
		} else
 
		{
			if ((maze[u.x+1][u.y]!=-1)&&(!visited[u.x+1][u.y]))	q.push({u.x+1,u.y,walk[u.x][u.y]});
			if ((maze[u.x-1][u.y]!=-1)&&(!visited[u.x-1][u.y]))	q.push({u.x-1,u.y,walk[u.x][u.y]});
			if ((maze[u.x][u.y+1]!=-1)&&(!visited[u.x][u.y+1]))	q.push({u.x,u.y+1,walk[u.x][u.y]});
			if ((maze[u.x][u.y-1]!=-1)&&(!visited[u.x][u.y-1]))	q.push({u.x,u.y-1,walk[u.x][u.y]});
		}
	}
return 0;	
}
