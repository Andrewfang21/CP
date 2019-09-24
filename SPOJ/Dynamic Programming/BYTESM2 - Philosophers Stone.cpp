#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,M,i,j,maks;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		long long batu[N+5][M+5],dp[N+5][M+5];
		maks=-1;
		
		memset(batu,0,sizeof(batu));
		memset(dp,0,sizeof(dp));
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>batu[i][j];
				
		for (i=1;i<=M;i++)
		{
			dp[0][i]=0;
			dp[1][i]=batu[1][i];
		}
		
		for (i=1;i<=N;i++)
			dp[i][0]=0;
		
		for (i=2;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				dp[i][j]=batu[i][j]+max(max(dp[i-1][j],dp[i-1][j+1]),dp[i-1][j-1]);
				if (maks<dp[i][j])
					maks=dp[i][j];
			}
		cout<<maks<<"\n";
		/*for (i=1;i<=N;i++)
		{
			for (j=1;j<=M;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}*/
	}
return 0;
}
