#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,i,j,k,L,N,pref[205],S[205][205],dp[205][205];
	char arr[205];
	cin>>TC;
	
	while (TC--)
	{
		memset(pref,0,sizeof(pref));
		memset(dp,0,sizeof(dp));
		cin>>N;
		for (i=1;i<=N;i++)
		{
			cin>>arr[i];
			if (arr[i]=='1')
				pref[i]=pref[i-1]+1;
			else
				pref[i]=pref[i-1];
		}
		for (i=1;i<N;i++)
			for (j=i+1;j<=N;j++)
				S[i][j]=pref[j]-pref[i-1];
		
		for (i=1;i<=N;i++)
			if (arr[i]=='1')
				dp[i][i]=1;
			else
				dp[i][i]=0;
				
		for (L=2;L<=N;L++)
		{
			for (i=1;i<=(N-L+1);i++)
			{
				j=i+L-1;
				for (k=i;k<j;k++)
				{
					if ((j-i+1)-S[i][j]<S[i][j])
						dp[i][j]=j-i+1;
					else
						dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
						
					//cout<<i<<" "<<k<<" "<<j<<" "<<dp[i][j]<<"\n";
				}
			}
		}
		/*for (i=1;i<=N;i++)
		{
			for (j=1;j<=N;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}*/
		cout<<dp[1][N]<<"\n";
	}
return 0;
}
