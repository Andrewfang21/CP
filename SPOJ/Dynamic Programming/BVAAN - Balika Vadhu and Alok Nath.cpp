#include<bits/stdc++.h>
using namespace std;

int dp[105][105][105],INF=pow(10,6),N,M,K;
string a,b;

int solve(int i, int j, int remaining)
{
	if ((i==N || (j==M)))
	{
		if (remaining!=0)
			return -INF;
		else
			return 0;
	}
	if ((i<N || j<M))
		if (remaining<0)
			return -INF;
	if (dp[i][j][remaining]!=-1)
		return dp[i][j][remaining];
	
	int ans;
	
	if (a[i]==b[j])
		ans=max(solve(i+1,j+1,remaining-1)+a[i],
			max(solve(i+1,j,remaining),
				solve(i,j+1,remaining)));
	else
		ans=max(solve(i+1,j,remaining),
				solve(i,j+1,remaining));
			
return dp[i][j][remaining]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC;
	cin>>TC;
	
	while (TC--)
	{
		cin>>a>>b;
		cin>>K;
		N=a.length();		M=b.length();
		
		memset(dp,-1,sizeof(dp));
		int ans=0;
		
		ans=max(ans,solve(0,0,K));
		cout<<ans<<"\n";
	}
return 0;
}
