#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const LL n = 3005, MOD = 1e9 + 7;

int N;

int cnt[n][16], dp[2][1 << 16], string_bit[n];
string S[n];

void read ()
{
	cin >> N;

	for (int i = 1; i <= N; i ++)
	{
		cin >> S[i];

		for (int j = 0; j < S[i].length(); j ++)
			cnt[i][S[i][j] - 'a'] ++;

		for (int j = 0; j < 15; j ++)
			if (cnt[i][j] % 2 == 1)
				string_bit[i] = string_bit[i] | (1 << j);
	}
}

int cek (LL mask)
{
	int sum = 0;

	for (int i = 0; i < 15; i ++)
	{
		int temp = mask & (1 << i);

		if (temp != 0)
			sum ++;
	}
return sum;
}

void work ()
{
	memset(dp, -1, sizeof(dp));
	
	for (int mask = 0; mask < (1 << 15); mask ++)
	{
		int bit_on = cek(mask);

		if (bit_on <= 1)		dp[(N + 1) & 1][mask] = 1;
		else					dp[(N + 1) & 1][mask] = 0;
	}


	for (int i = N; i >= 1; i --)
	{
		for (int curr_mask = 0; curr_mask < (1 << 15); curr_mask ++)
		{
			int prevs_mask = curr_mask ^ string_bit[i];

			if (dp[(i + 1) & 1][curr_mask] != -1 || dp[(i + 1) & 1][curr_mask] != -1)
			{
				dp[i & 1][curr_mask] = 0;
				if (dp[(i + 1) & 1][curr_mask] != -1)		dp[i & 1][curr_mask] += dp[(i + 1) & 1][curr_mask];
				if (dp[i & 1][curr_mask] >= MOD)			dp[i & 1][curr_mask] %= MOD;

				if (dp[(i + 1) & 1][prevs_mask] != -1)		dp[i & 1][curr_mask] += dp[(i + 1) & 1][prevs_mask];
				if (dp[i & 1][curr_mask] >= MOD)			dp[i & 1][curr_mask] %= MOD;
			}
		}
	}

	int res = (dp[1][0] - 1) % MOD;
	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}