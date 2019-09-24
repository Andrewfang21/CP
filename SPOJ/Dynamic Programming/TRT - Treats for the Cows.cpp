#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 2005;

LL N;
LL A[n], dp[n][n];

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

LL solve (int curr_pos, int day) {
	int L, R;
	L = curr_pos;		R = N - day + L;

	if (L > R)
		return 0;
	if (dp[curr_pos][day] != -1)
		return dp[curr_pos][day];

	LL res;
	res = max(solve(curr_pos + 1, day + 1) + A[L] * day,
			  solve(curr_pos, day + 1) + A[R] * day);

return dp[curr_pos][day] = res;
}

void work () {
	memset (dp, -1, sizeof(dp));

	LL res = solve(1, 1);
	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}