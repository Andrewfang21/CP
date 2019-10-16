#include<bits/stdc++.h>
using namespace std;

const int N = 65, K = 10;

long long dp[N][K];

int main() {
	for (int i = 0; i < K; i ++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i ++) {
		for (int j = 0; j < K; j ++)
			for (int k = 0; k <= j; k ++)
				dp[i][j] += dp[i - 1][k];
	}

	int Q;
	cin >> Q;

	while (Q --) {
		int tc, idx;
		cin >> tc >> idx;

		long long res = 0;
		for (int i = 0; i < K; i ++)
			res += dp[idx][i];

		cout << tc << " " << res << "\n";
	}

return 0;
}