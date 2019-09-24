#include<bits/stdc++.h>
using namespace std;
long long N,A,B,C,height[1005][1005];
bool visited[1005][1005];

struct lol
{
	long long x,y;
}start,finish,u;

bool inside(long long x, long long y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=N))
		return true;
	return false;
}

void BFS(long i, long j, long value)
{
	queue<lol> q;
	q.push({start.x,start.y});
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.x][u.y])&&(inside(u.x,u.y))&&(value<=height[u.x][u.y]))
		{
			visited[u.x][u.y]=true;
			
			q.push({u.x+1,u.y});
			q.push({u.x-1,u.y});
			q.push({u.x,u.y+1});
			q.push({u.x,u.y-1});
		}
	}
	
}

int main()
{
	cin>>N;
	cin>>start.x>>start.y>>finish.x>>finish.y;
	cin>>A>>B>>C;
	
	long long i,j,kiri,kanan,tengah,up;
	
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			height[i][j]=(((i-1)*N+j-1)*A+B)%C;

	kiri=0;		kanan=height[start.x][start.y];
	up=INT_MAX;
	
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		//cout<<tengah<<"\n";
		memset(visited,false,sizeof(visited));		
		BFS(start.x,start.y,tengah);
		
		if (visited[finish.x][finish.y])
		{
			up=tengah;
			kiri=tengah+1;
		}
		else
			kanan=tengah-1;
	}
	long long res=(height[start.x][start.y]-up)+(height[finish.x][finish.y]-up);
	cout<<res<<"\n";
return 0;
}
