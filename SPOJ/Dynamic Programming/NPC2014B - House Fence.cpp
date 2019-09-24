#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const LL n = 5005, INF = LLONG_MAX;

LL N, A[n];

void read ()
{
	cin >> N;
	for (int i = 1; i <= N ; i ++)
		cin >> A[i];
}

LL solve (int L, int R, int H)
{
	LL res, mins;
	res = 0;		mins = INF;

	for (int i = L; i <= R; i ++)
		mins = min(mins, A[i]);

	for (int i = L; i <= R; i ++)
	{
		if (A[i] == mins)		continue;

		int L1, R1;
		L1 = R1 = i;

		while (R1 < R && A[R1 + 1] != mins)
			R1 ++;

		res += solve(L1, R1, mins);
		i = R1 + 1;
	}
return min(res + mins - H, R - L + 1LL);
}

void work ()
{
	LL res = solve(1, N, 0);
	cout << res << "\n";	
}

int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}