#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct lol
{
	int x,y,jarak;
}start,finish,temp,u;

bool inside (int x, int y)
{
	if ((x>=0)&&(x<8)&&(y>=0)&&(y<8))
		return true;
return false;
}

int main()
{
	while (cin>>start.x>>start.y>>finish.x>>finish.y)
	{
		int i,j,dist[10][10],INF=2*pow(10,8);
		
		vector<int>movex,movey;
		
		movex.pb(1);	movex.pb(1);	movex.pb(-1);	movex.pb(-1);
		movex.pb(2);	movex.pb(2);	movex.pb(-2);	movex.pb(-2);
		
		
		movey.pb(2);	movey.pb(-2);	movey.pb(2);	movey.pb(-2);
		movey.pb(1);	movey.pb(-1);	movey.pb(1);	movey.pb(-1);

		for (i=0;i<=8;i++)
			for (j=0;j<=8;j++)
				dist[i][j]=INF;
		queue<lol>q;
		
		q.push({start.x,start.y,0});
		while (!q.empty())
		{
			u=q.front();	q.pop();
			dist[u.x][u.y]=min(dist[u.x][u.y],u.jarak);
			
			/*if ((u.x==finish.x)&&(u.y==finish.y))
				cout<<u.x<<" "<<u.y<<" "<<dist[u.x][u.y]<<"\n";*/
				
			for (i=0;i<8;i++)
			{
				temp.x=u.x+movex[i];
				temp.y=u.y+movey[i];
				int ans=(temp.x*u.x)+(temp.y*u.y);
				
				if (inside(temp.x,temp.y))
					if (dist[temp.x][temp.y]>dist[u.x][u.y]+ans)
						q.push({temp.x,temp.y,dist[u.x][u.y]+ans});	
			}
		}
		cout<<dist[finish.x][finish.y]<<"\n";
		/*for (i=0;i<8;i++)
		{
			for (j=0;j<8;j++)
				cout<<dist[i][j]<<" ";
			cout<<"\n";
		}*/
	}
return 0;
}
