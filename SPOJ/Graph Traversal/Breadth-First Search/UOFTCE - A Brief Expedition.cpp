#include<bits/stdc++.h>
using namespace std;
int M,N,dist[105][105];
bool visited[105][105];
char maze[105][105];

struct lol
{
	int x,y,jarak;
}finish[10005],start;

queue<lol>q;
vector<int> ans;
bool inside(int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
		return true;
	return false;
}

void BFS(int i, int j)
{
	lol u;
	for (int temp1=1;temp1<=N;temp1++)
		for (int temp2=1;temp2<=M;temp2++)
			dist[temp1][temp2]=INT_MAX;
			
	memset(visited,false,sizeof(visited));
	q.push({i,j,-1});
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		
		if ((!visited[u.x][u.y])&&(inside(u.x,u.y))&&(maze[u.x][u.y]!='#'))
		{
			visited[u.x][u.y]=true;
			if (dist[u.x][u.y]>u.jarak+1)
				dist[u.x][u.y]=u.jarak+1;
				
			q.push({u.x+1,u.y,dist[u.x][u.y]});
			q.push({u.x-1,u.y,dist[u.x][u.y]});
			q.push({u.x,u.y+1,dist[u.x][u.y]});
			q.push({u.x,u.y-1,dist[u.x][u.y]});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,j,temp,res;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		temp=res=0;
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='S')
				{
					finish[temp].x=i;	finish[temp].y=j;
					temp++;
				}
				if (maze[i][j]=='C')
				{
					start.x=i;		start.y=j;
				}
			}
		}
		
		BFS(start.x,start.y);
		
		for (i=0;i<temp;i++)
			ans.push_back(dist[finish[i].x][finish[i].y]);
		
		sort(ans.begin(),ans.end(),greater<int>() );
	
		for (i=0;i<ans.size();i++)
		{
			if (i==0)
				res+=ans[i];
			else
				res+=(2*ans[i]);
			res+=60;
		}
		cout<<res<<"\n";
		ans.clear();
		
		/*for (i=1;i<=N;i++)
		{
			for (j=1;j<=M;j++)
				cout<<dist[i][j]<<" ";
			cout<<"\n";
		}*/
	}	
return 0;
}
