#include<bits/stdc++.h>
using namespace std;
bool visited[2005][2005];
int jarak,dist[2005][2005],num[2005][2005],N,M,K,Q,i,j,after[300005],ans[300005];
char maze[2005][2005];

struct lol
{
	int x,y,step;
}u,city[300005];

bool inside(int i, int j)
{
	if ((i>=1)&&(i<=N)&&(j>=1)&&(j<=M))
		return true;
return false;
}

int check_nearest(int i, int j)
{
	int temp1=-1;
	queue<lol>q;
	memset(dist,-1,sizeof(dist));
	q.push({i,j,-1});
	jarak=INT_MAX;
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		if ((dist[u.x][u.y]==-1)&&(inside(u.x,u.y)))
		{
			dist[u.x][u.y]=u.step+1;
			//cout<<u.x<<" "<<u.y<<" "<<dist[u.x][u.y]<<"\n";
			if ((maze[u.x][u.y]=='X')&&((u.x!=i)||(u.y!=j)))
			{
				if (jarak==INT_MAX)	//belum pernah mengunjungi
				{
					jarak=dist[u.x][u.y];
					temp1=num[u.x][u.y];	//tempat ke-berapa
				}
				else
				if (jarak==dist[u.x][u.y])	//dua tempat yang jaraknya sama
					return 0;
				else
				if (jarak<dist[u.x][u.y])
					return temp1;
			}
			q.push({u.x+1,u.y,dist[u.x][u.y]});
			q.push({u.x-1,u.y,dist[u.x][u.y]});
			q.push({u.x,u.y+1,dist[u.x][u.y]});
			q.push({u.x,u.y-1,dist[u.x][u.y]});
		}
	}
return temp1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	cin>>dummy;
	cin>>N>>M>>K>>Q;
	int temp=0,a,b;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
		{
			cin>>maze[i][j];
			if (maze[i][j]=='X')
			{
				temp++;
				city[temp].x=i;		city[temp].y=j;
				num[i][j]=temp;
			}	
		}
	for (i=1;i<=temp;i++)
	{
		after[i]=check_nearest(city[i].x,city[i].y);
		//cout<<city[i].x<<" "<<city[i].y<<" "<<num[city[i].x][city[i].y]<<" "<<after[i]<<"\n";
	}
	
	memset(ans,-1,sizeof(ans));
	
	for (i=1;i<=temp;i++)
	{
		int now=i;
		memset(visited,false,sizeof(visited));
		while (true)
		{
			int temp1=now;
			now=after[temp1];
			
			if ((now==0)||(visited[city[now].x][city[now].y]))
			{
				ans[i]=temp1;
				break;
			}
			visited[city[temp1].x][city[temp1].y]=true;	
		}
	}
		
	/*for (i=1;i<=temp;i++)
		cout<<i<<" "<<after[i]<<" "<<ans[i]<<"\n";*/
		
	if (K==1)
		ans[1]=1;
	
	while (Q--)
	{
		cin>>a>>b;
		int now=check_nearest(a,b);
		memset(visited,false,sizeof(visited));
		//cout<<now<<"\n";
		
		if (now==0)
			cout<<a<<" "<<b<<"\n";
		else
		{
			cout<<city[ans[now]].x<<" "<<city[ans[now]].y<<"\n";
		}
	}
return 0;	
}
