#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int x,y,jarak;
};

bool check(int a, int b)
{
	if ((a>=1)&&(a<=8)&&(b>=1)&&(b<=8))
		return true;
	return false;
}
int main()
{
	int TC;
	cin>>TC;
	while (TC--)
	{
		string a,b;
		int dist[10][10],visited[10][10],INF=2*pow(10,7);
		lol start,finish,u;
		queue<lol>q;
		
		cin>>a>>b;
		start.x=(int) a[0]-96;
		start.y=(int) a[1]-48;
		
		finish.x=(int) b[0]-96;
		finish.y=(int) b[1]-48;
		
		dist[finish.x][finish.y]=INF;
		dist[start.x][start.y]=-1;
		
		q.push({start.x,start.y,-1});
		memset(visited,false,sizeof(visited));
		
		while (!q.empty())
		{
			u=q.front();	q.pop();
			
			if ((!visited[u.x][u.y])&&(check(u.x,u.y)))
			{
				visited[u.x][u.y]=true;
				dist[u.x][u.y]=u.jarak+1;
					
				q.push({u.x+2,u.y+1,dist[u.x][u.y]});
				q.push({u.x+2,u.y-1,dist[u.x][u.y]});
				q.push({u.x-2,u.y+1,dist[u.x][u.y]});
				q.push({u.x-2,u.y-1,dist[u.x][u.y]});
				
				q.push({u.x+1,u.y+2,dist[u.x][u.y]});
				q.push({u.x-1,u.y+2,dist[u.x][u.y]});
				q.push({u.x+1,u.y-2,dist[u.x][u.y]});
				q.push({u.x-1,u.y-2,dist[u.x][u.y]});
			}
		}
		cout<<dist[finish.x][finish.y]<<"\n";
	}
}
