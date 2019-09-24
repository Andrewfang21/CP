#include<bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5, k = 1e6 + 5;

int N, G;
int cost[n], profit[n], dp[2][k];

void read ()
{
	cin >> G >> N;

	for (int i = 1; i <= N; i ++)
		cin >> cost[i];

	for (int i = 1; i <= N; i ++)
		cin >> profit[i];
}

void work ()
{
	memset(dp, -1, sizeof(dp));

	for (int rem = 1; rem <= G; rem ++)
		dp[0][rem] = 0;

	dp[0][0] = dp[1][0] = 0;

	for (int pos = 1; pos <= N; pos ++)
	{
		for (int rem = 1; rem <= G; rem ++)
		{
			dp[pos & 1][rem] = dp[(pos + 1) & 1][rem];

			if (rem >= cost[pos])
			{
				dp[pos & 1][rem] = max(dp[pos & 1][rem],
									   dp[(pos + 1) & 1][rem - cost[pos]] + profit[pos]);

				if (dp[pos & 1][rem - cost[pos]] != -1)
					dp[pos & 1][rem] = max(dp[pos & 1][rem],
										   dp[pos & 1][rem - cost[pos]] + profit[pos]);
			}
		}
	}

	int res = -1;
	for (int rem = 1; rem <= G; rem ++)
		res = max(res, dp[N & 1][rem]);

	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC --)
	{
		read ();
		work ();
	}

return 0;
}