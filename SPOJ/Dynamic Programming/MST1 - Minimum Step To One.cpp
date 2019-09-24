#include<bits/stdc++.h>
using namespace std;
long long dp[20000005],i,TC;

int main()
{
	memset(dp,-1,sizeof(dp));
	for (i=1;i<=2*pow(10,7);i++)
	{
		if (i%2==0)
		{
			if (i%3==0)
			{
				dp[i]=min(dp[i-1],min(dp[i/2],dp[i/3]))+1;
			}
			else
				dp[i]=min(dp[i-1],dp[i/2])+1;
		}
		else
		if (i%3==0)
			dp[i]=min(dp[i-1],dp[i/3])+1;
		else
			dp[i]=dp[i-1]+1;
	}
	cin>>TC;
	
	for (i=1;i<=TC;i++)
	{
		int num;
		cin>>num;
		
		printf("Case %d: %lld\n",i,dp[num]);
	}
return 0;
}
