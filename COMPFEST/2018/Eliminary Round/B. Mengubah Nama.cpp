#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e2 + 5, k = 1e4 + 5;

int N, K;

int P[n], W[n], dp[n][k];
string A[n], B[n];

void read () {
	cin >> K >> N;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i] >> B[i] >> P[i];

		if (A[i].length() > B[i].length())
			swap (A[i], B[i]);
	}
}

int solve (int pos, int rem) {	
	if (pos > N)
		return 0;
	if (dp[pos][rem] != -1)
		return dp[pos][rem];

	int res;
	if (rem >= W[pos]) {
		res = max(solve(pos + 1, rem - W[pos]) + P[pos],
				  solve(pos + 1, rem));
	}
	else
		res = solve(pos + 1, rem);

return dp[pos][rem] = res;
}

void work () {
	for (int i = 1; i <= N; i ++) {
		int cnt = 0;
		for (int pos = 0; pos < A[i].length(); pos ++) {
			if (A[i][pos] != B[i][pos])
				cnt ++;
		}
		cnt += (B[i].length() - A[i].length());
		W[i] = cnt;
	}

	memset(dp, -1, sizeof(dp));
	int res = solve(1, K);

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}