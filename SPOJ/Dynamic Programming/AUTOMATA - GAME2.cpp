#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int dp[N][N];
string A, B;

bool solve(int i, int j) {
	if (i >= n && j < m - 1 || i < n - 1 && j >= m)
		return false;
	if (i == n - 1 && j == m - 1) {
		if (A[i] == B[j] || A[i] == '?' || A[i] == '*')
			return true;
		return false;
	}
	int &ret = dp[i][j];
	if (ret != -1)
		return ret;

	bool res = false;
	if (A[i] == '?')
		res = solve(i + 1, j + 1) || solve(i + 1, j);
	else if (A[i] == '*')
		res = solve(i, j + 1) || solve(i + 1, j + 1) || solve(i + 1, j);
	else if (A[i] == B[j])
		res = solve(i + 1, j + 1);

	ret = res;
return ret;
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		cin >> A >> B;

		memset(dp, -1, sizeof(dp));
		n = A.length(), m = B.length();

		bool res = solve(0, 0);
		res ? cout << "Yes\n" : cout << "No\n";
	}

return 0;
}