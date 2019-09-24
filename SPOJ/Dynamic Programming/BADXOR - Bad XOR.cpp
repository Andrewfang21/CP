#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 2500, MOD = 1e8 + 7;

int N, M;
int dp[n][n], A[n];

bool exist[n];

void read () {
	cin >> N >> M;
	memset(exist, false, sizeof(exist));
	for (int i = 1; i <= N; i ++) 
		cin >> A[i];

	for (int i = 1; i <= M; i ++) {
		int num;		cin >> num;
		exist[num] = true;
	}
}

void work (int tc) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for (int i = 1; i <= N; i ++)
		for (int val = 0; val < 1024; val ++) {
			dp[i][val] = (dp[i - 1][val] + dp[i - 1][val ^ A[i]]) % MOD; 
		}

	LL res = 0;
	for (int i = 0; i < 1024; i ++) {
		if (!exist[i])		res = (res + dp[N][i]) % MOD;
	}

	cout << "Case " << tc << ": ";
	if (N == 0) {
		exist[0] == true ? cout << "0\n" : cout << "1\n"; 
	}
	else
		cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	for (int i = 1; i <= TC; i ++) {
		read ();
		work (i);
	}
return 0;
}