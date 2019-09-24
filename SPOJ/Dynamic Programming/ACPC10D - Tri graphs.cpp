#include<bits/stdc++.h>
using namespace std;
long long dp[100005][6],N,i,j,INF=2*pow(10,8);
int maze[100005][6];

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N)
	{
		if (N==0)
			return 0;
				
		for (i=1;i<=N;i++)
			for (j=1;j<=3;j++)
				cin>>maze[i][j];
				
		for (i=0;i<=N+5;i++)
			for (j=0;j<=5;j++)
				dp[i][j]=INF;
				
		dp[1][2]=0;
		
		for (i=2;i<=N;i++)
			for (j=1;j<=3;j++)
				dp[i][j]=maze[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
		
		cout<<dp[N][2]<<"\n\n";
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=3;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
	}
return 0;
}
