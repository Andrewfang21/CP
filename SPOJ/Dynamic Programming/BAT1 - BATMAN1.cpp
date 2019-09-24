#include<bits/stdc++.h>
using namespace std;
int N,M,dp[21][21][1005][2],INF=2*pow(10,7),locks[21],cost[21][21],power[21][21];

int solve(int i, int j, int money_left, int opened)
{
	if (j==(M+1))
		return -INF;
	if (money_left<0)
		return -INF;
	if (i==(N+1))
		return 0;
	if (dp[i][j][money_left][opened]!=-1)
		return dp[i][j][money_left][opened];
		
	int ans;
	if (opened==0)	//batch ke-i belum dibuka
		ans=max(solve(i,j,money_left-locks[i],1),	//buka batch ke-i
				solve(i+1,j,money_left,0));	//biarkan dan lanjut ke batch selanjutnya
	else
	if (opened==1)	//batch ke-i sudah terbuka
		ans=max(solve(i,j,money_left-cost[i][j],1)+power[i][j],	//beli weapon[i][j]
			max(solve(i,j+1,money_left,1),	//pindah ke weapon selanjutnya
				solve(i+1,1,money_left,0)));	//pindah ke batch selanjutnya

return dp[i][j][money_left][opened]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,j,K,ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M>>K;
		for (i=1;i<=N;i++)
			cin>>locks[i];
		
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>cost[i][j];
		
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>power[i][j];
				
		memset(dp,-1,sizeof(dp));
		ans=solve(1,1,K,0);
		
		if (ans<=0)
			cout<<"0\n";
		else
			cout<<ans<<"\n";
	}
return 0;
}
