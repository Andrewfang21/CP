#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int N,INF=2*pow(10,8),cost[15][15],dp[11][1<<11];

int solve(int curr_city, int mask)
{
	if (mask==(1<<N+1)-1)
		return cost[curr_city][0];	
	if (dp[curr_city][mask]!=-1)
		return dp[curr_city][mask];
		
	int min_cost=INF;
	for (int i=0;i<=N;i++)
	{
		int temp=mask&(1<<i);
		if (temp==0)
		{
			int temp1=mask|(1<<i);
			min_cost=min(min_cost,solve(i,temp1)+cost[curr_city][i]);
		}
	}
return dp[curr_city][mask]=min_cost;	
}

int main(void)
{
	int TC,i,j;
	scanf("%d",&TC);
	
	while (TC--)
	{
		scanf("%d",&N);
		for (i=0;i<=N;i++)
			for (j=0;j<=N;j++)
			{
				if (i==j)
					cost[i][j]=0;
				else
					scanf("%d",&cost[i][j]);
			}
		memset(dp,-1,sizeof(dp));
		
		printf("%d\n",solve(0,0));
	}
return 0;
}
