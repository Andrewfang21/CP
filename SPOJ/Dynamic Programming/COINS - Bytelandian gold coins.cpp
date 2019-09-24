#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define LL long long
using namespace std;

LL N;
map<LL, LL> dp;

LL solve (LL pos) {
	if (pos == 0)		return 0;
	if (dp[pos] != 0)	return dp[pos];

	LL res = max(pos, solve(pos / 2) + solve(pos / 3) + solve(pos / 4));
return dp[pos] = res;
}

int main () {

	while (cin >> N) {
		LL res = solve(N);
		cout << res << "\n";

		dp.clear();
	}
return 0;
}
