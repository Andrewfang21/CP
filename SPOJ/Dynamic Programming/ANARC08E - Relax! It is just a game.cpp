#include<bits/stdc++.h>
using namespace std;

int N,M,dp[20][20];

int solve(int i, int j)
{
	if (i<0 || j<0)
		return 0;
	if (i==0 && j==0)
		return 1;
	if (dp[i][j]!=-1)
		return dp[i][j];
		
	int ans;
	ans=solve(i-1,j)+solve(i,j-1);
	
return dp[i][j]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N>>M)
	{
		if (N==-1 && M==-1)
			return 0;
		
		memset(dp,-1,sizeof(dp));
		
		int ans=solve(N,M);
		
		if (ans==(N+M))
			cout<<N<<"+"<<M<<"="<<ans<<"\n";
		else
			cout<<N<<"+"<<M<<"!="<<N+M<<"\n";
	}
return 0;
}
