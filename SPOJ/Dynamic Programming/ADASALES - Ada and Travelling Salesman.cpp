#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, q;
ll cost[N], up[N], down[N];

vector<int> adj[N];

void read() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i ++)
		scanf("%lld", &cost[i]);

	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void down_dfs(int pos, int prev) {
	down[pos] = 0;

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		down_dfs(next, pos);

		down[pos] = max(down[pos],
						down[next] + max(0ll, cost[next] - cost[pos]));
	}
}

void up_dfs(int pos, int prev) {
	ll dirProfit[2] = {-1, -1};

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		ll adjIncome = max(0ll, cost[next] - cost[pos]);

		if (down[next] + adjIncome >= dirProfit[0]) {
			dirProfit[1] = dirProfit[0];
			dirProfit[0] = down[next] + adjIncome; 
		} 
		else if (down[next] + adjIncome > dirProfit[1])
			dirProfit[1] = down[next] + adjIncome;
	}

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		ll altMove = dirProfit[0],
		   adjIncome = max(0ll, cost[next] - cost[pos]);
		
		if (down[next] + adjIncome == dirProfit[0])
			altMove = dirProfit[1];

		adjIncome = max(0ll, cost[pos] - cost[next]);
		up[next] = max(up[pos] + adjIncome,
					   altMove + adjIncome);

		up_dfs(next, pos);
	}
}

void solve() {
	down_dfs(0, -1);
	up_dfs(0, -1);

	while (q --) {
		int src;
		scanf("%d" , &src);

		printf("%lld\n", max(up[src], down[src]));
	}
}

int main() {

	read();
	solve();

return 0;	
}