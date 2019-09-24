#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[10][100005],i,TC,num,res;

int main()
{
	memset(dp,0,sizeof(dp));
	for (i=0;i<=9;i++)
		dp[i][1]=1;
	
	for (i=2;i<=100002;i++)
	{
		dp[0][i]=dp[7][i-1]%mod;
		dp[1][i]=((dp[2][i-1]%mod)+(dp[4][i-1]%mod))%mod;
		dp[2][i]=((dp[1][i-1]%mod)+(dp[3][i-1]%mod)+(dp[5][i-1]%mod))%mod;
		dp[3][i]=((dp[2][i-1]%mod)+(dp[6][i-1]%mod))%mod;
		dp[4][i]=((dp[1][i-1]%mod)+(dp[5][i-1]%mod)+(dp[7][i-1]%mod))%mod;
		dp[5][i]=((dp[2][i-1]%mod)+(dp[4][i-1]%mod)+(dp[6][i-1]%mod)+(dp[8][i-1]%mod))%mod;
		dp[6][i]=((dp[3][i-1]%mod)+(dp[5][i-1]%mod)+(dp[9][i-1]%mod))%mod;
		dp[7][i]=((dp[0][i-1]%mod)+(dp[4][i-1]%mod)+(dp[8][i-1]%mod))%mod;
		dp[8][i]=((dp[5][i-1]%mod)+(dp[7][i-1]%mod)+(dp[9][i-1]%mod))%mod;
		dp[9][i]=((dp[6][i-1]%mod)+(dp[8][i-1]%mod))%mod;
	}
	cin>>TC;
	while (TC--)
	{
		cin>>num;
		res=0;
		for (i=0;i<=9;i++)
		{
			res+=dp[i][num];
			res%=mod;
		}
		cout<<res<<"\n";
	}
return 0;
}
