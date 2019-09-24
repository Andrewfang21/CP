#include<bits/stdc++.h>
using namespace std;
int N,M;
struct lol
{
	int x,y,jarak;
};

bool check (int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int i,j,TC,INF=2*pow(10,7);
	lol mouse,cat1,cat2,u;
	cin>>N>>M;
	bool visited[N+5][M+5];
	int mouse_dist[N+5][M+5],cat_dist[N+5][M+5];
	cin>>TC;
	
	while (TC--)
	{
		cin>>mouse.x>>mouse.y>>cat1.x>>cat1.y>>cat2.x>>cat2.y;
		memset(visited,false,sizeof(visited));
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				mouse_dist[i][j]=cat_dist[i][j]=INF;
		
		mouse_dist[mouse.x][mouse.y]=-1;
		queue<lol> q;
		q.push({mouse.x,mouse.y,-1});
		
		while (!q.empty())
		{
			u=q.front();	q.pop();
			
			if ((!visited[u.x][u.y])&&(check(u.x,u.y)))
			{
				visited[u.x][u.y]=true;
				mouse_dist[u.x][u.y]=u.jarak+1;
				
				q.push({u.x+1,u.y,mouse_dist[u.x][u.y]});
				q.push({u.x-1,u.y,mouse_dist[u.x][u.y]});
				q.push({u.x,u.y+1,mouse_dist[u.x][u.y]});
				q.push({u.x,u.y-1,mouse_dist[u.x][u.y]});
			}
		}
		memset(visited,false,sizeof(visited));
		cat_dist[cat1.x][cat1.y]=-1;
		
		q.push({cat1.x,cat1.y,-1});
		
		while (!q.empty())
		{
			u=q.front();	q.pop();
			
			if ((!visited[u.x][u.y])&&(check(u.x,u.y)))
			{
				visited[u.x][u.y]=true;
				cat_dist[u.x][u.y]=u.jarak+1;
						
				q.push({u.x+1,u.y,cat_dist[u.x][u.y]});
				q.push({u.x-1,u.y,cat_dist[u.x][u.y]});
				q.push({u.x,u.y+1,cat_dist[u.x][u.y]});
				q.push({u.x,u.y-1,cat_dist[u.x][u.y]});
			}
		}
	
		memset(visited,false,sizeof(visited));
		cat_dist[cat2.x][cat2.y]=-1;
		
		q.push({cat2.x,cat2.y,-1});
		
		while (!q.empty())
		{
			u=q.front();	q.pop();
			
			if ((!visited[u.x][u.y])&&(check(u.x,u.y)))
			{
				visited[u.x][u.y]=true;
				cat_dist[u.x][u.y]=u.jarak+1;
				
				if ((check(u.x+1,u.y))&&(cat_dist[u.x+1][u.y]>cat_dist[u.x][u.y]+1))
					q.push({u.x+1,u.y,cat_dist[u.x][u.y]});
				
				if ((check(u.x-1,u.y))&&(cat_dist[u.x-1][u.y]>cat_dist[u.x][u.y]+1))
					q.push({u.x-1,u.y,cat_dist[u.x][u.y]});
				
				if ((check(u.x,u.y+1))&&(cat_dist[u.x][u.y+1]>cat_dist[u.x][u.y]+1))
					q.push({u.x,u.y+1,cat_dist[u.x][u.y]});
				
				if ((check(u.x,u.y-1))&&(cat_dist[u.x+1][u.y-1]>cat_dist[u.x][u.y]+1))
					q.push({u.x,u.y-1,cat_dist[u.x][u.y]});
				
			}
		}
		bool found=false;
		for (i=1;i<=M;i++)
		{
			if ((mouse_dist[1][i]<cat_dist[1][i])||(mouse_dist[N][i]<cat_dist[N][i]))
			{
				found=true;
				cout<<"YES\n";
				break;
			}
		}
		
		if (!found)
		{
			for (i=1;i<=N;i++)
			{
				if ((mouse_dist[i][1]<cat_dist[i][1])||(mouse_dist[i][M]<cat_dist[i][M]))
				{
					found=true;
					cout<<"YES\n";
					break;
				}
			}
		}
		
		if (!found)
			cout<<"NO\n";
	}
}
