#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[]={1,2,3},N,dp[35][5][5];

bool check(ll prevs, ll now, ll nexts)
{
	if (prevs!=now && prevs!=nexts && now!=nexts)
		return false;
	
//	cout<<prevs<<" "<<now<<" "<<nexts<<"\n";	
return true;		
}

ll solve(ll i, ll prevs, ll curr)
{
	if (i>N)
		return 1;
	if (dp[i][prevs][curr]!=-1)
		return dp[i][prevs][curr];
		
	ll ans=0;
	for (ll it=0;it<3;it++)
		if (check(prevs,curr,arr[it]))
			ans+=solve(i+1,curr,arr[it]);
					
return dp[i][prevs][curr]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	memset(dp,-1,sizeof(dp));
	
	if (N==1)
	{
		cout<<"3\n";
		return 0;
	}
	
	ll ans=0;
	for (ll i=0;i<3;i++)
		for (ll j=0;j<3;j++)
			ans+=solve(3,arr[i],arr[j]);
	
	cout<<ans<<"\n";
return 0;
}