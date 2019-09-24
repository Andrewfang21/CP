#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC;
	cin>>TC;
	
	while (TC--)
	{
		int N,i;
		cin>>N;
		long long dp[N+10],toy[N+10];
		memset(dp,0,sizeof(dp));
		memset(toy,0,sizeof(toy));
		for (i=0;i<N;i++)
			cin>>toy[i];
		
		for (i=N-1;i>=0;i--)
		{
			long long temp1,temp2,temp3;
			temp1=toy[i]+dp[i+2];
			temp2=toy[i]+toy[i+1]+dp[i+4];
			temp3=toy[i]+toy[i+1]+toy[i+2]+dp[i+6];
			
			dp[i]=max(temp1,max(temp2,temp3));
			
			//cout<<temp1<<" "<<temp2<<" "<<temp3<<"\n";
		}
		cout<<dp[0]<<"\n";
	}
return 0;
}
