#include<bits/stdc++.h>
using namespace std;
int dist[105][105],N,M,Q,dp[105][105][1<<9],query[10],INF=2*pow(10,8);

void reset()
{
	int i,j;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
		{
			if (i==j)
				dist[i][j]=0;
			else
				dist[i][j]=INF;
		}
}

void Floyd_Warshall()
{
	int i,j,k;
	for (k=0;k<N;k++)
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
			{
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
}

bool full(int mask)
{
	if (mask==(1<<Q)-1)
		return true;	
return false;
}

int solve(int i, int j, int mask)
{
	if (full(mask))
		return 0;
	if (dp[i][j][mask]!=-1)
		return dp[i][j][mask];
		
	int ans=INF;
	for (int it=0;it<Q;it++)
	{
		int temp=1<<it;
		int temp1=mask&temp, temp2=mask|temp;
		
		if (temp1==0)	//query belum dikerjakan
		{
			ans=min(ans,
				min(solve(query[it], j, temp2)+dist[i][query[it]],
					solve(i, query[it], temp2)+dist[j][query[it]]));
		}
	}	
return dp[i][j][mask]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	
	reset();
	int i,a,b,c;
	
	for (i=1;i<=M;i++)
	{
		cin>>a>>b>>c;
		dist[a][b]=dist[b][a]=c;
	}
	Floyd_Warshall();
	cin>>Q;
	for (i=0;i<Q;i++)
		cin>>query[i];
	
	int start_first,start_second,ans;
	cin>>start_first>>start_second;
	
	memset(dp,-1,sizeof(dp));
	ans=solve(start_first,start_second,0);
	cout<<ans<<"\n";
return 0;
}
