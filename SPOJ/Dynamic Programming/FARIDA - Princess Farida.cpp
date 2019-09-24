#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,tc,N,i,ans;
	cin>>TC;
	
	for (tc=1;tc<=TC;tc++)
	{
		cin>>N;
		long long arr[N+5],dp[N+5];
		
		if (N==0)
			cout<<"Case "<<tc<<": "<<"0\n";
		else
		{
			for (i=1;i<=N;i++)
				cin>>arr[i];
			
			memset(dp,0,sizeof(dp));
			dp[0]=0;
			ans=dp[1]=arr[1];
			
			for (i=2;i<=N;i++)
			{
				dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
				if (ans<dp[i])
					ans=dp[i];
			}
			cout<<"Case "<<tc<<": "<<ans<<"\n";
		}
	}
return 0;
}
