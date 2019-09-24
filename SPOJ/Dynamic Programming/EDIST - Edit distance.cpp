#include<bits/stdc++.h>
using namespace std;
long long dp[2005][2005];

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,i,j;
	cin>>TC;
	
	while (TC--)
	{
		string a,b;
		cin>>a>>b;
		memset(dp,0,sizeof(dp));
		
		for (i=0;i<=a.length();i++)
			for (j=0;j<=b.length();j++)
			{
				if (i==0)
					dp[i][j]=j;
				else
				if (j==0)
					dp[i][j]=i;
				else
				if (a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
		cout<<dp[a.length()][b.length()]<<"\n";
	}
return 0;
}
