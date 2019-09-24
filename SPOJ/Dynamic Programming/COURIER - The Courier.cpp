#include<bits/stdc++.h>
using namespace std;
long long N,M,INF=2*pow(10,18),dp[105][1<<13],sizes,start[60],finish[60],source,dist[105][105];

void print()
{
	for (long long i=0;i<N;i++)
	{
		for (long long j=0;j<N;j++)
			cout<<dist[i][j]<<" ";
		cout<<"\n";
	}
}

void reset()
{
	memset(dp,-1,sizeof(dp));
	long long i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (i==j)
				dist[i][j]=0;
			else
				dist[i][j]=INF;
		}
	}	
}

void Floyd_Warshall()
{
	long long i,j,k;
	for (k=0;k<N;k++)
	{
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
}

long long solve(long long curr_city, long long mask)
{
	if (mask==(1<<sizes)-1)
		return dist[curr_city][source-1];
	if (dp[curr_city][mask]!=-1)
		return dp[curr_city][mask];
		
	long long min_cost=INF;
	for (long long i=0;i<sizes;i++)
	{
		long long temp=mask&(1<<i);
		if (temp==0)
		{
			temp=mask|(1<<i);
			long long lol=dist[curr_city][start[i]]+dist[start[i]][finish[i]];
			min_cost=min(min_cost,(lol+solve(finish[i],temp)));
			//cout<<curr_city<<" "<<solve(finish[i],temp)<<"\n";
		}
	}
return dp[curr_city][mask]=min_cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	long long TC,i,j,a,b,c;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M>>source;
		reset();
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			dist[a-1][b-1]=min(dist[a-1][b-1],c);
			dist[b-1][a-1]=min(dist[b-1][a-1],c);
		}
		Floyd_Warshall();
		//print();
		
		long long Q,temp=0;
		cin>>Q;
		sizes=0;
		for (i=0;i<Q;i++)
		{
			cin>>a>>b>>c;
			sizes+=c;
			while (c--)
			{
				start[temp]=a-1;	finish[temp]=b-1;
				temp++;
			}	
		}
		cout<<solve(source-1,0)<<"\n";
	}
return 0;
}
