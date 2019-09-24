#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[1000005],i,N,TC;
	
int main()
{
	ios_base::sync_with_stdio(false);
	memset(dp,0,sizeof(dp));
	dp[2]=dp[3]=1;
	
	for (i=4;i<=1000000;i++)
		dp[i]=((dp[i-2]%mod)+(dp[i-3]%mod))%mod;
	
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		cout<<dp[N]<<"\n";
	}
return 0;
}
