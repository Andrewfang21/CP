#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5, K = 26;

int n, m;
int cost[K], dp[N][N];
string A, B;

void read() {
	cin >> n >> m;
	for (int i = 0; i < K; i ++)
		cin >> cost[i];

	cin >> A >> B;
}

int solve(int i, int j) {
	if (i >= n || j >= m)
		return 0;
	int &ret = dp[i][j];
	if (ret != -1)
		return ret;

	int res = 0;
	if (A[i] == B[j]) {
		res = solve(i + 1, j + 1) + cost[A[i] - 'a'];
	}
	else {
		res = max(solve(i + 1, j + 1),
			  max(solve(i, j + 1), solve(i + 1, j)));
	}

	ret = res;
return ret;
}

void work() {
	memset(dp, -1, sizeof(dp));

	int res = solve(0, 0);
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	work();

return 0;
}