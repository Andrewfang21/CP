#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,K,i,j,INF=2*pow(10,7);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		int apple[105],dp[105];
		memset(dp,-1,sizeof(dp));
		memset(apple,0,sizeof(apple));
		
		for (i=1;i<=K;i++)
			cin>>apple[i];
		
		for (i=1;i<=100;i++)
			dp[i]=INF;
		dp[0]=0;
		
		for (i=1;i<=K;i++)
		{
			for (j=1;j<=i;j++)
			{
				if (apple[j]!=-1)
				{
					if (dp[i-j]!=INF)
					{
						dp[i]=min(dp[i],dp[i-j]+apple[j]);
					}
				}
			}
		}
		/*for (i=1;i<=K;i++)
			cout<<dp[i]<<" ";
		cout<<"\n";*/
		
		if (dp[K]==INF)
			cout<<"-1\n";
		else
			cout<<dp[K]<<"\n";
	}
return 0;
}
