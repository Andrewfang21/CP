#include<bits/stdc++.h>
using namespace std;
bool visited[1005][1005];
int N,M,dist[1005][1005],INF=2*pow(10,8);
char maze[1005][1005];
 
bool inside(int x, int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M))
		return true;
return false;
}
 
void BFS(int i, int j)
{
	memset(visited,false,sizeof(visited));
	typedef pair<int, pair<int,int> >ii;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	q.push({0,make_pair(i,j)});
	ii u;
		
	while (!q.empty())
	{
		u=q.top();		q.pop();
		
		if ((!visited[u.second.first][u.second.second])&&(inside(u.second.first,u.second.second)))
		{
			visited[u.second.first][u.second.second]=true;
			dist[u.second.first][u.second.second]=u.first;
		
			if ((u.second.first==N)&&(u.second.second==M))
			{
				cout<<dist[N][M]<<"\n";
				break;
			}
			if (inside(u.second.first+1,u.second.second))
				if (maze[u.second.first+1][u.second.second]!=maze[u.second.first][u.second.second])
					q.push({dist[u.second.first][u.second.second]+1,make_pair(u.second.first+1,u.second.second)});
				else
					q.push({dist[u.second.first][u.second.second],make_pair(u.second.first+1,u.second.second)});	
				
			if (inside(u.second.first-1,u.second.second))
				if (maze[u.second.first-1][u.second.second]!=maze[u.second.first][u.second.second])
					q.push({dist[u.second.first][u.second.second]+1,make_pair(u.second.first-1,u.second.second)});
				else
					q.push({dist[u.second.first][u.second.second],make_pair(u.second.first-1,u.second.second)});	
				
			if (inside(u.second.first,u.second.second+1))	
				if (maze[u.second.first][u.second.second+1]!=maze[u.second.first][u.second.second])
					q.push({dist[u.second.first][u.second.second]+1,make_pair(u.second.first,u.second.second+1)});
				else
					q.push({dist[u.second.first][u.second.second],make_pair(u.second.first,u.second.second+1)});	
				
			if (inside(u.second.first,u.second.second-1))
				if (maze[u.second.first][u.second.second-1]!=maze[u.second.first][u.second.second])
					q.push({dist[u.second.first][u.second.second]+1,make_pair(u.second.first,u.second.second-1)});
				else
					q.push({dist[u.second.first][u.second.second],make_pair(u.second.first,u.second.second-1)});	
		}	
	}		
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,j;
	cin>>TC;
 
	while (TC--)
	{
		cin>>N>>M;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>maze[i][j];
 
		BFS(1,1);
 	}
return 0;
}
