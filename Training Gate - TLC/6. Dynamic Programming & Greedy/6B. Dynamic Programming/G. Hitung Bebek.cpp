#include<bits/stdc++.h>
#define mod 1000000
using namespace std;
long long dp[1000005],i,N;

int main()
{
	dp[0]=dp[1]=1;
	
	for (i=2;i<=1000000;i++)
	{
		if ((dp[i-1]+dp[i-2])>999999)
			dp[i]=((dp[i-1]%mod)+(dp[i-2]%mod))%mod;
		else
			dp[i]=dp[i-1]+dp[i-2];
	}
	cin>>N;
	
	cout<<dp[N]<<"\n";
return 0;
}