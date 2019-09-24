#include<bits/stdc++.h>
using namespace std;
long long bull[5005],cow[5005],dp[5005][5005],N,M,INF=100000000000;

long long solve(long long i, long long j)
{
	if (i>N && j>M)
		return 0;
	if (i<=N && j>M)
		return INF;
	if (dp[i][j]!=-1)
		return dp[i][j];
		
	long long ans=min(solve(i+1,j+1)+abs(bull[i]-cow[j]),
				solve(i,j+1));
				
//	cout<<i<<" "<<j<<"  "<<ans<<"\n";
return dp[i][j]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	long long i;
	for (i=1;i<=N;i++)
		cin>>bull[i];
	for (i=1;i<=M;i++)
		cin>>cow[i];
		
	sort(bull+1,bull+N+1);		sort(cow+1,cow+M+1);
	memset(dp,-1,sizeof(dp));
	long long ans=solve(1,1);
	cout<<ans<<"\n";
return 0;	
}
