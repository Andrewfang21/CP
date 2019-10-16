#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 105, inf = 1e12;

ll n, m, k;
ll dp[N][N][N], tree[N], paint[N][N];

void read() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		cin >> tree[i];

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> paint[i][j];
}

ll solve(int pos, int group, int prev) {
	if (pos == 0) 
		return (group != k ? inf : 0);
	
	if (group > k)
		return inf;

	if (dp[pos][group][prev] != -1)
		return dp[pos][group][prev];

	ll res = inf;

	if (tree[pos] == 0) {
		for (int next = 1; next <= m; next ++) {
			if (next != prev)
				res = min(res, solve(pos - 1, group + 1, next) + paint[pos][next]);
			else
				res = min(res, solve(pos - 1, group, next) + paint[pos][next]);

		}
	}
	else {
		if (tree[pos] != prev)
			res = solve(pos - 1, group + 1, tree[pos]);
		else
			res = solve(pos - 1, group, tree[pos]);
	}

return dp[pos][group][prev] = res;
}

void work() {
	memset(dp, -1, sizeof(dp));

	ll res = solve(n, 0, m + 1);
	res == inf ? cout << "-1\n" : cout << res << "\n";
}

int main() {
	read();
	work();

return 0;
}