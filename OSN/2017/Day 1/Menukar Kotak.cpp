#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int MAXX, dp[2][205][1805], N, permen[205];
long long K;
vector< int > orang;

void read()
{
	string subs;
	cin>>subs;
	
	cin>>N>>K;
	
	char a;
	for (int i = 1; i <= N; i++)
	{
		cin>>a;
		permen[i] = a-'0';
	}
	
	for (int i = 1; i <= N; i++)
	{
		cin>>a;
		if (a == '1')
			orang.pb(i);
	}
	MAXX = 9*N;
}

int dist (int a, int b)
{
	return abs(a - b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	read();
	
	memset(dp,-1,sizeof(dp));
	for (int pos_permen = 0; pos_permen <= N; pos_permen++)
	{
		dp[0][pos_permen][0] = 0;
		dp[1][pos_permen][0] = 0;
	}
	
	for (int pos_orang = 0; pos_orang < orang.size(); pos_orang++)
		for (int pos_permen = 1; pos_permen <= N; pos_permen++)
			for (int profit = 0; profit <= MAXX; profit++)
			{					
				dp[pos_orang & 1][pos_permen][profit] = dp[pos_orang & 1][pos_permen - 1][profit];
	
				if (profit - permen[pos_permen] >= 0)
				{
					if (dp[(pos_orang +1) & 1][pos_permen - 1][profit - permen[pos_permen]] != -1)
					{
						if (dp[pos_orang & 1][pos_permen][profit] != -1)		//udah pernah diisi
							dp[pos_orang & 1][pos_permen][profit] = min(dp[(pos_orang + 1) & 1][pos_permen - 1][profit - permen[pos_permen]] + dist(pos_permen, orang[pos_orang]),
																		dp[pos_orang & 1][pos_permen][profit]);
						else
							dp[pos_orang & 1][pos_permen][profit] = dp[(pos_orang + 1) & 1][pos_permen - 1][profit - permen[pos_permen]] + dist(pos_permen, orang[pos_orang]);
					}
				}
			}
	
	int res = 0;
	for (int profit = 0; profit <= MAXX; profit++)
		if (dp[(orang.size() + 1) & 1][N][profit] <= K && dp[(orang.size() + 1) & 1][N][profit] != -1)
		{
//			cout<<profit<<"  "<<dp[(orang.size() + 1) & 1][N][profit]<<"\n";
			res = profit;
		}
	
	cout<<res<<"\n";
return 0;		
}
