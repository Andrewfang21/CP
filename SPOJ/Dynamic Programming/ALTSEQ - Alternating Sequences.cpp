#include<bits/stdc++.h>
using namespace std;

int N,a[5005],dp[5005][5005],INF=pow(10,5);

int solve(int now, int last)
{
	if (now>N)
		return 0;
	if (dp[now][last]!=-1)
		return dp[now][last];
		
	int ans;
	if (last==0)
	{
		ans=max(solve(now+1,now)+1,
				solve(now+1,last));
	}
	else
	{
		if (abs(a[now]) > abs(a[last]))
		{
			if ((a[now]>0 && a[last]<0) || (a[now]<0 && a[last]>0))
				ans=max(solve(now+1,now)+1,
						solve(now+1,last));
			else
				ans=solve(now+1,last);
		}
		else
			ans=solve(now+1,last);
	}
//	cout<<now<<" "<<last<<"   "<<ans<<"\n";
return dp[now][last]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	for (int i=1;i<=N;i++)
		cin>>a[i];
		
	memset(dp,-1,sizeof(dp));
	int ans;
	
	ans=solve(1,0);
	cout<<ans<<"\n";
return 0;
}
