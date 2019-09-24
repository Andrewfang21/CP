#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	int i,j;
	while (cin>>a>>b)
	{
		deque<char> res;
		int dp[a.length()+5][b.length()+5];
		memset(dp,0,sizeof(dp));
		int ans=-1;
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
					dp[i][j]=1+dp[i-1][j-1];
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					
				if (ans<dp[i][j])
					ans=dp[i][j];
			}
		//cout<<ans<<"\n";
		
		for (i=0;i<=a.length();i++)
		{
			for (j=0;j<=b.length();j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
		i=a.length();	j=b.length();
		int temp,index;
		temp=index=ans;
		
		while ((i>=0)&&(j>=0))
		{
			if (a[i-1]==b[j-1])
			{
				res.push_front(a[i-1]);
				cout<<i<<" "<<j<<" "<<a[i-1]<<"\n";
				i--;	j--;
			}
			else
			if (dp[i-1][j]>=dp[i][j-1])
			{
				res.push_front(b[j-1]);
				cout<<i<<" "<<j<<" "<<b[j-1]<<"\n";
				i--;
			}
			else
			{
				res.push_front(a[i-1]);
				cout<<i<<" "<<j<<" "<<a[i-1]<<"\n";
				j--;
			}
		}
		for (temp=1;temp<res.size();temp++)
			cout<<res[temp];
		cout<<"\n";
		res.clear();
	}
}
