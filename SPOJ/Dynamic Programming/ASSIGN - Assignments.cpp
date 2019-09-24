#include<bits/stdc++.h>
using namespace std;
long long N;

long long cnt_bits(long long mask)
{
	long long cnt=0;
	//cout<<mask<<":\n";
	for (long long i=0;i<N;i++)
	{
		long long temp=mask&(1<<i);
		if (temp!=0)
			cnt++;
		//cout<<mask<<" "<<i<<" "<<temp<<"\n";
	}
	/*cout<<cnt<<"\n";
	cout<<"\n";*/
return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,i,j;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		long long task[N+5][N+5],dp[(1<<N)];
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				cin>>task[i][j];
				
		memset(dp,0,sizeof(dp));
		dp[(1<<N)-1]=1;
		
		for (i=(1<<N)-1;i>=0;i--)
		{
			long long cnt=cnt_bits(i);
			for (j=0;j<N;j++)
			{
				long long temp=(1<<j);
				if ((task[cnt][j]==1)&&((i&temp)==0))
					dp[i]+=dp[i|temp];
			}
			//cout<<cnt<<" "<<i<<" "<<dp[i]<<"\n";
		}
		cout<<dp[0]<<"\n";
		/*for (i=0;i<(1<<N);i++)
			cout<<i<<" "<<dp[i]<<"\n";*/
	}
}
