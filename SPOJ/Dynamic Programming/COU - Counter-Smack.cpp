#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i;
	string str;
	cin>>TC;
	
	while (TC--)
	{
		cin>>str;
		int dp[str.length()+5];
		memset(dp,0,sizeof(dp));
		for (i=0;i<str.length();i++)
		{
			if (i>=2)
			{
				if (str[i-2]=='N')
				{
					if (str[i]=='P')
						dp[i+1]=1+max(dp[i],dp[i-1]);
					if (str[i]=='N')
						dp[i+1]=-1+max(dp[i],dp[i-1]);
				}
				else
				{
					if (str[i]=='P')
						dp[i+1]=max(dp[i+1],dp[i]+1);
					if (str[i]=='N')
						dp[i+1]=max(dp[i+1],-1+dp[i]);
				}
			}
			else
			{
				if (str[i]=='P')
					dp[i+1]=max(dp[i+1],dp[i]+1);
				if (str[i]=='N')
					dp[i+1]=-1+dp[i];
			}
		}
		for (i=1;i<=str.length();i++)
			cout<<dp[i]<<" ";
		cout<<"\n";
		cout<<dp[str.length()]<<"\n";
	}
return 0;
}
