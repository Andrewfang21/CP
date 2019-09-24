#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,j;
	cin>>N;
	int dp[N+5][N+5];
	char maze[N+5][N+5];
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin>>maze[i][j];
				
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
		{
			if ((i!=1)&&(j!=1))
			{
				if (maze[i][j]!='#')
					dp[i][j]=dp[i][j-1]+dp[i-1][j];
			}
		}
	}
	
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	if (dp[N][N]==0)
	{
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				dp[i][i]=dp[i-1][j]+dp[i][j-1]+dp[i][j+1]+dp[i+1][j];
	
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=N;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
			
		if (dp[N][N]==0)
			cout<<"INCONCEIVABLE\n";
		else
			cout<<"THE GAME IS A LIE\n";
	}
	else
		cout<<dp[N][N]<<"\n";
return 0;
}
