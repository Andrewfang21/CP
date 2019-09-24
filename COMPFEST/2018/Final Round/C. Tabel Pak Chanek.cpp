#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int N, Q;
int pref[n];

void read ()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; i ++)
	{
		int X;
		cin >> X;

		pref[i] = pref[i - 1] ^ X;
	}
}

void work ()
{
	while (Q --)
	{
		int L1, R1, L2, R2;
		cin >> L1 >> R1 >> L2 >> R2;

		int L, R, res;
		L = max (L1, R1);			R = min (L2, R2);

		if (L > R)
			res = 0;
		else
			res = pref[R] ^ pref[L - 1];

		cout << res << "\n";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}