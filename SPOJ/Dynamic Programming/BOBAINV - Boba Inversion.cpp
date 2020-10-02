#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n;
int A[N], dp[N][N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i]);
}

void precompute() {
	for (int i = 0; i < n - 1; i ++)
		for (int j = i + 1; j < n; j ++)
			dp[i][j] = A[i] > A[j] ? 1 : 0;

	for (int i = 0; i < n - 1; i ++)
		for (int j = i + 1; j < n; j ++)
			dp[i][j] += dp[i][j - 1];

	for (int j = n - 1; j >= 1; j --)
		for (int i = j - 1; i >= 0; i --)
			dp[i][j] += dp[i + 1][j];
}

void solve() {
	precompute();

	int k;
	scanf("%d", &k);
	while (k --) {
		int l, r;
		scanf("%d %d", &l, &r);

		printf("%d\n", dp[l - 1][r - 1]);
	}
}

int main() {
	read();
	solve();

return 0;
}