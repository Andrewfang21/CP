#include<bits/stdc++.h>
#define fi first
#define sec second
using namespace std;
struct lol
{
	int x,y;
};

int main()
{
	int M,N,i,j,INF,d;
	lol start,ends;
	INF=2*pow(10,7);
	scanf("%d %d",&M,&N);
	int matriks[M+5][N+5],dist[M+5][N+5];
	bool visited[M+5][N+5];
	memset(visited,false,sizeof(visited));
	
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
		{
			scanf("%d",&matriks[i][j]);
			dist[i][j]=INF;
		}
			
	scanf("%d %d",&start.x,&start.y);
	scanf("%d %d",&ends.x,&ends.y);
	typedef pair<int,int >uu;
	typedef pair<int, pair<int,int> > ii;
	uu temp,node;
	ii u;
	
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	temp.fi=start.x;
	temp.sec=start.y;
	dist[temp.fi][temp.sec]=0;
	pq.push({0,temp});
	
	while(!pq.empty())
	{
		u=pq.top();	pq.pop();
		d=u.fi;
		node.fi=u.sec.fi;	node.sec=u.sec.sec;	
		if ((!visited[node.fi][node.sec])&&(d<=dist[node.fi][node.sec]))
		{
			visited[node.fi][node.sec]=true;
			dist[node.fi][node.sec]=d;
			
			if ((node.fi+1>0)&&(node.fi+1<=M)&&(node.sec>0)&&(node.sec<=N)&&(!visited[node.fi+1][node.sec])&&(matriks[node.fi+1][node.sec]!=-1))
			{
				temp.fi=node.fi+1;
				temp.sec=node.sec;
				pq.push({max(d,matriks[temp.fi][temp.sec]),temp});
			}
			
			if ((node.fi-1>0)&&(node.fi-1<=M)&&(node.sec>0)&&(node.sec<=N)&&(!visited[node.fi-1][node.sec])&&(matriks[node.fi-1][node.sec]!=-1))
			{
				temp.fi=node.fi-1;
				temp.sec=node.sec;
				pq.push({max(d,matriks[temp.fi][temp.sec]),temp});
			}
			
			if ((node.fi>0)&&(node.fi<=M)&&(node.sec+1>0)&&(node.sec+1<=N)&&(!visited[node.fi][node.sec+1])&&(matriks[node.fi][node.sec+1]!=-1))
			{
				temp.fi=node.fi;
				temp.sec=node.sec+1;
				pq.push({max(d,matriks[temp.fi][temp.sec]),temp});
			}
		
			if ((node.fi>0)&&(node.fi<=M)&&(node.sec-1>0)&&(node.sec-1<=N)&&(!visited[node.fi][node.sec-1])&&(matriks[node.fi][node.sec-1]!=-1))
			{
				temp.fi=node.fi;
				temp.sec=node.sec-1;
				pq.push({max(d,matriks[temp.fi][temp.sec]),temp});
			}
		}
	}
	printf("%d\n",dist[ends.x][ends.y]);

return 0;
}
