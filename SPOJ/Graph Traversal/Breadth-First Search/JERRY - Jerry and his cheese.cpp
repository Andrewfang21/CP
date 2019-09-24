#include<bits/stdc++.h>
using namespace std;
int N;
bool visited[15][105][105];
int dist[15][105][105];
char maze[105][105];
vector<int>movex,movey;

struct lol
{
	int x,y,jarak,cnt;
}start[1005],u;

bool inside (int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=N))
		return true;
return false;
}

void daftar()
{
	movex.push_back(-1);	movey.push_back(0);
	movex.push_back(0);		movey.push_back(1);
	movex.push_back(1);		movey.push_back(0);
	movex.push_back(0);		movey.push_back(-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int cnt,TC,K,C,i,j,temp=0,INF=2*pow(10,7),ans;
	daftar();
	cin>>TC;
	
	while (TC--)
	{
		temp=cnt=0;
		memset(visited,false,sizeof(visited));
		cin>>N>>K>>C;
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				cin>>maze[i][j];
				if (maze[i][j]=='*')
				{
					start[temp].x=i;		start[temp].y=j;
					temp++;
				}
			}
		queue<lol>q;
		
		ans=INF;
		for (i=0;i<temp;i++)
		{
			q.push({start[i].x,start[i].y,-1,1});	//koor-x,koor-y,dist,jumlah keju
			memset(visited,false,sizeof(visited));
			
			while (!q.empty())
			{
				u=q.front();		q.pop();
				
				if ((!visited[u.cnt][u.x][u.y])&&(inside(u.x,u.y)))
				{
					visited[u.cnt][u.x][u.y]=true;
					dist[u.cnt][u.x][u.y]=u.jarak+1;
					
					//cout<<u.x<<" "<<u.y<<" "<<u.cnt<<" "<<dist[u.cnt][u.x][u.y]<<"\n";
						
					if (u.cnt==C)
					{
						ans=min(ans,dist[u.cnt][u.x][u.y]);
						break;	
					}	
					
					for (j=0;j<4;j++)
					{
						int temp1=u.x+movex[j];		int temp2=u.y+movey[j];
						
						if (maze[temp1][temp2]=='*')
							q.push({temp1,temp2,dist[u.cnt][u.x][u.y],u.cnt+1});
						else
							q.push({temp1,temp2,dist[u.cnt][u.x][u.y],u.cnt});
					}
				}	
			}
		}
		cout<<ans<<"\n";
	}
return 0;
}
