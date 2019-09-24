#include<bits/stdc++.h>
using namespace std;
int maze[20],sol[20],N,dp[17][1<<17],INF=100000000,temp;

int solve(int i, int mask)
{
	if (mask==(1<<N)-1)
		return 0;
	if (dp[i][mask]!=-1)
		return dp[i][mask];
		
	int ans=INF;
	for (int it=0;it<N;it++)
	{
		int temp1=mask&(1<<it);
		
		if (temp1==0)	//masih belum dipindahkan
		{
			int temp2=mask|(1<<it);
			ans=min(ans,solve(i+1,temp2)+abs(i-it)+abs(maze[i]-sol[it]));
		}
	}
return dp[i][mask]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N)
	{
		if (N==0)
			return 0;
		
		int i;
		for (i=0;i<N;i++)
			cin>>maze[i];
		for (i=0;i<N;i++)
			cin>>sol[i];
			
		memset(dp,-1,sizeof(dp));
		int	ans=solve(0,0);
		
		cout<<ans<<"\n";
	}
return 0;
}
