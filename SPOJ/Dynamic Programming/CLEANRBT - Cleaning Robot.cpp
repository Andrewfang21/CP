#include<bits/stdc++.h>
using namespace std;

int vis[25][25],dp[15][1<<15],INF=pow(10,6),dist[25][25],N,M,counter;
map<int, map<int, int> >place;
char maze[25][25];

int movex[]={0,0,-1,1};
int movey[]={1,-1,0,0};

struct lol
{
	int x,y,dist;
}u,pos[20];

bool inside(int i, int j)
{
	if (i>=1 && i<=M && j>=1 && j<=N)
		return true;
return false;
}

void BFS(int i)
{
	queue<lol>q;
	q.push({pos[i].x, pos[i].y, 0});
	memset(vis,-1,sizeof(vis));
	
	while (!q.empty())
	{
		u=q.front();		q.pop();
		
		if (vis[u.x][u.y]!=-1 || maze[u.x][u.y]=='x' || !inside(u.x,u.y))
			continue;
		
		vis[u.x][u.y]=u.dist;
		int now=place[u.x][u.y];
		
		if (now!=0)		// Ada sampah
			dist[i][now]=u.dist;
			
		lol nexts;
		for (int it=0;it<4;it++)
		{
			nexts.x=u.x+movex[it];
			nexts.y=u.y+movey[it];
			
			q.push({nexts.x,nexts.y,u.dist+1});
		}
	}
}

void reset()
{
	memset(dp,-1,sizeof(dp));
	
	for (int i=0;i<=counter;i++)
		for (int j=0;j<=counter;j++)
			dist[i][j]=INF;
}

bool full(int mask)
{
	for (int i=0;i<=counter;i++)
	{
		int curr=mask&(1<<i);
		
		if (curr==0)		//ada yang belum keisi
			return false;
	}
return true;			
}

int solve(int curr_pos, int mask)
{
	if (full(mask))
		return 0;
	if (dp[curr_pos][mask]!=-1)
		return dp[curr_pos][mask];
	
	int ans=INF;
	
	for (int i=0;i<=counter;i++)
	{
		int temp=mask&(1<<i);
		
		if (temp==0)		//belum ke visit
		{
			int update=mask|(1<<i);
			ans=min(ans, solve(i,update)+dist[curr_pos][i]);			
		}
	}	
return dp[curr_pos][mask]=ans;
}

void print()
{
	for (int i=0;i<=counter;i++)
		for (int j=1;j<=counter;j++)
			if (i!=j)
				cout<<i<<" "<<j<<"  "<<dist[i][j]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N>>M)
	{
		if (N==0 && M==0)
			return 0;
		
		counter=0;
		place.clear();
		
		for (int i=1;i<=M;i++)
			for (int j=1;j<=N;j++)
			{
				cin>>maze[i][j];
				
				if (maze[i][j]=='o')
				{
					place[i][j]=0;
					pos[0].x=i;		pos[0].y=j;
				}
				if (maze[i][j]=='*')
				{
					place[i][j]=++counter;	
					pos[counter].x=i;		pos[counter].y=j;
				}
			}
		reset();
		for (int i=0;i<=counter;i++)
			BFS(i);
		
	//	print();
		int ans;
		ans=solve(0,1);	
		
		if (ans>=INF)
			cout<<"-1\n";
		else
			cout<<ans<<"\n";
	}
return 0;
}
