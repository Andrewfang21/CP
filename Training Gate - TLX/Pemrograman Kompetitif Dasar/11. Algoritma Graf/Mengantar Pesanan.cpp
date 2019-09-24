#include<bits/stdc++.h>
using namespace std;

long long now,nexts,res,weight,N,M,Q,MAXX=pow(10,10);
long long dist[205][205];
bool travelled[205];

void read()
{
	for (int i=1;i<=200;i++)
		for (int j=1;j<=200;j++)
		{
			if (i==j)
				dist[i][j]=0;
			else
				dist[i][j]=MAXX;
		}
				
	for (int i=1;i<=M;i++)
	{
		cin>>now>>nexts>>weight;
		
		dist[now][nexts]=min(weight, dist[now][nexts]);
		dist[nexts][now]=min(weight, dist[nexts][now]);
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>N>>M>>Q;
	read();
	
	for (int k=1;k<=N;k++)
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
	
	now=1;			
	res=0;
	for (int i=1;i<=Q;i++)
	{
		cin>>nexts;	
		
		if (i==1)
			now=nexts;
			
		res+=dist[now][nexts];
		now=nexts;
	}
	
	cout<<res<<"\n";
	
return 0;
}
