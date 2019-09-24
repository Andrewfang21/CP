#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1005;

int N;
int dp[2][n], A[n];

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i];
		dp[0][i] = dp[1][i] = 1;
	}
}

void work () {
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j < i; j ++)
			if (A[i] > A[j])
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);

	for (int i = N; i >= 1; i --)
		for (int j = N; j > i; j --)
			if (A[i] > A[j])
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);

	int res = -1;
	for (int i = 1; i <= N; i ++)
		res = max(res, dp[0][i] + dp[1][i] - 1);
	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;

	while (TC --) {
		read ();
		work ();
	}

return 0;
}