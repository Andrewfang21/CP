#include<bits/stdc++.h>
using namespace std;
int dp[35][35][3],arr[35],INF=100000000;

int solve(int left, int right, int turn)
{
	if (left>right)
		return 0;
	if (dp[left][right][turn]!=-1)
		return dp[left][right][turn];
		
	int ans;
	if (turn==1)	//giliran player 1
	{
		ans=max(arr[left]+solve(left+1,right,2),
				arr[right]+solve(left,right-1,2));
	}
	else
	{
		ans=max(solve(left+1,right,1),
				solve(left,right-1,1));
	}
//	cout<<left<<" "<<right<<"  "<<turn<<"   "<<ans<<"\n";
return dp[left][right][turn]=ans;
}

int solve2(int left, int right, int turn)
{
	if (left>right)
		return 0;
	if (dp[left][right][turn]!=-1)
		return dp[left][right][turn];
		
	int ans;
	if (turn==1)	//giliran player 1
	{
		ans=max(arr[left]+solve(left+1,right,2),
				arr[right]+solve(left,right-1,2));
	}
	else
	{
		ans=max(-arr[left]+solve(left+1,right,1),
				-arr[right]+solve(left,right-1,1));
	}
//	cout<<left<<" "<<right<<"  "<<turn<<"   "<<ans<<"\n";
return dp[left][right][turn]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,N,ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		for (i=1;i<=N;i++)
			cin>>arr[i];
			
		memset(dp,-1,sizeof(dp));
		ans=solve(1,N,1);
		memset(dp,-1,sizeof(dp));
		
		cout<<ans<<" "<<solve2(1,N,1)<<"\n";
	}
return 0;
}
