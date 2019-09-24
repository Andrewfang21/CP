#include<bits/stdc++.h>
using namespace std;
string str;
int dp[6005][6005],TC;

int solve(int i, int j)
{
	if (i==j)
		return 0;
	else
	if (i>j)
		return 0;
	else
	if (i==j-1)
	{
		if (str[i]==str[j])
			return 0;
		else
			return 1;
	}
	else
	if (dp[i][j]!=-1)
		return dp[i][j];
	else
	if (str[i]!=str[j])
	{
		dp[i][j]=min(solve(i+1,j),solve(i,j-1))+1;
		return dp[i][j];
	}
	else
	if (str[i]==str[j])
	{
		dp[i][j]=solve(i+1,j-1);
		return dp[i][j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>str;
		memset(dp,-1,sizeof(dp));
		cout<<solve(0,str.length()-1)<<"\n";
	}
return 0;
}
