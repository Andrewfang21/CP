#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e3 + 5;

LL N, K;
LL pref[n][n], petak[n][n];

void read ()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
		{
			cin >> petak[i][j];

			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + petak[i][j];
		}
}

LL get (int i, int j, int len)
{
	int AL, AR, BL, BR;
	AL = i;		AR = j;		BL = i + len - 1;		BR = j + len - 1;

	if (BL > N || BR > N)		return LLONG_MAX;

	LL res = pref[BL][BR] - pref[BL][AR - 1] - pref[AL - 1][BR] + pref[AL - 1][AR - 1];

	// cout << i << " " << j << "  " << len << "\n";
	// cout << AL << " " << AR << "  " << BL << " " << BR << "   " << res << "\n\n";

return res;
}

void work ()
{
	LL res = -1;

	for (int i = 1; i <= N; i ++)
	{
		int len, ujung;

		len = ujung = 1;

		while (ujung + len - 1 <= N)
		{
			LL curr_val = get(i, ujung, len);

			if (curr_val <= K)
			{
				res = max(res, curr_val);
				len ++;
			}
			else
			{
				if (len > 1)
					len --;
				ujung ++;
			} 
		}
	}

	res = max(res, 0LL);
	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}