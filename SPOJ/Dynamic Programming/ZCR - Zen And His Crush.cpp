#include<bits/stdc++.h>
using namespace std;
double dp[1005][1005],arr[1005];
int N,TC,K;
bool memo[1005][1005];

double solve(int i, int remaining)
{
	if (i>N && remaining!=0)
		return 0.0;
	if (i<=N && remaining<0)
		return 0.0;
	if (i>N && remaining==0)
		return 1.0;
	if (memo[i][remaining])
		return dp[i][remaining];
		
//	cout<<i<<" "<<remaining<<"\n";
	double	ans=solve(i+1,remaining-1)*arr[i]+
				solve(i+1,remaining)*(1-arr[i]);
	
	memo[i][remaining]=true;
return dp[i][remaining]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		int i;
		for (i=1;i<=N;i++)
			cin>>arr[i];
		
		memset(memo,false,sizeof(memo));	
		double ans=solve(1,K);
		cout<<setprecision(10)<<fixed<<ans<<"\n";
	}
return 0;
}
