#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M,i,j,INF=2*pow(10,8);
	cin>>N>>M;
	
	int dp[N+10][M+10],ans=INF,maze[N+5][M+5];
	
	for (i=0;i<=N+5;i++)
		for (j=0;j<=M+5;j++)
			dp[i][j]=INF;
			
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
		{
			cin>>maze[i][j];
			if (i==1)
				dp[i][j]=maze[i][j];
		}
			
			
	for (i=2;i<=N;i++)
	{
		for (j=1;j<=N;j++)
		{
			dp[i][j]=maze[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
			
			if (i==N)
				ans=min(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
return 0;
}
