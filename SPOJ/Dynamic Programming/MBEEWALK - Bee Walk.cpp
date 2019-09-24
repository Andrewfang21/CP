#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<int,int> dp[65][65];
	int time,x,y,TC,i,j,a;	//dp[x][y][time]
	dp[30][30][0]=1;
	
	for (time=1;time<=15;time++)
	{
		for (x=1;x<=58;x++)
		{
			for (y=1;y<=58;y++)
			{
				dp[x][y][time]=dp[x][y+1][time-1]+dp[x][y-1][time-1]+dp[x+1][y][time-1]+dp[x-1][y][time-1]+dp[x+1][y-1][time-1]+dp[x-1][y+1][time-1];
			}
		}
	}
	/*for (time=1;time<=2;time++)
		for (i=1;i<=60;i++)
			for (j=1;j<=60;j++)	
				if (dp[i][j][time]>=1)
					cout<<i<<" "<<j<<" "<<time<<" "<<dp[i][j][time]<<"\n";*/
				
	cin>>TC;
	for (i=1;i<=TC;i++)
	{
		cin>>a;
		cout<<dp[30][30][a]<<"\n";
	}
return 0;
}
