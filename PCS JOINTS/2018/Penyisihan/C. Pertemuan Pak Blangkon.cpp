#include<bits/stdc++.h>
using namespace std;

int N,M,dp[105][105][105],INF=pow(10,8);

struct lol
{
	int start,finish,profit;
}v[105];

bool cmp(lol lhs, lol rhs)
{
	return lhs.finish<rhs.finish;
}

int solve(int now, int last, int money)
{
	if (money<0)
		return -INF;
	if (now>N)
		return 0;	
	if (dp[now][last][money]!=-1)
		return dp[now][last][money];
		
	int ans;
	
	if (v[now].start>v[last].finish)
	{
		ans=max(solve(now+1,now,money-v[now].profit)+1,
				solve(now+1,last,money));
	}
	else
		ans=solve(now+1,last,money);
			
return dp[now][last][money]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	
	for (int tc=1;tc<=TC;tc++)
	{
		cin>>N>>M;
		for (int i=1;i<=N;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			v[i].start=a;		v[i].finish=b;		v[i].profit=c;
		}
		
		sort(v+1, v+N+1, cmp);
		
		memset(dp,-1,sizeof(dp));
		int res=solve(1,0,M);
		
		cout<<"Kasus #"<<tc<<": "<<res<<"\n";
	}
return 0;
}
