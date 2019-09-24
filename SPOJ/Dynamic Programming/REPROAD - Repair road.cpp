#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,K,TC;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		int dp[K+5][N+5],road[N+5],i,j,maks=-1;
		
		memset(dp,0,sizeof(dp));
		for (i=1;i<=N;i++)
		{
			cin>>road[i];
			if (road[i]==1)
				dp[0][i]=dp[0][i-1]+road[i];
			//dp[repair][index]
		}
		for (i=1;i<=K;i++)
		{
			for (j=1;j<=N;j++)
			{
				if (road[j]==0)
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=dp[i][j-1]+1;
					
				if (maks<dp[i][j])
					maks=dp[i][j];
			}
		}
		cout<<maks<<"\n";
	}
}
