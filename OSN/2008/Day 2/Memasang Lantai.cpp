#include<bits/stdc++.h>
using namespace std;

const int N = 1005, MOD = 1000000;

int dp[N];

int solve(int pos) {
	if (pos < 0)
		return 0;
	if (pos == 0)
		return 1;
	if (dp[pos] != -1)
		return dp[pos];

	int res = (solve(pos - 3) + solve(pos - 1)) % MOD;

return dp[pos] = res;
}

int main() {
	int x;
	scanf("%d", &x);

	memset(dp, -1, sizeof(dp));
	int res = solve(x);
	printf("%d\n", res);

return 0;
}