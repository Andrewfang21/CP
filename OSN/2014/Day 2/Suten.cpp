#include<bits/stdc++.h>
using namespace std;

const int N = 105;

bool vis[N];
vector<pair<int,int>> adj[N];

int dfs(int u, int v, int len) {
	if (u == v) {
		if (len < 0) {
			int cycle = (abs(len) + 2) / 3;
			return (3 * cycle - abs(len)) % 3;
		}
		return len % 3;
	}

	if (adj[u].empty() || vis[u])
		return INT_MAX;

	vis[u] = true;
	for (pair<int, int> next : adj[u]) {
		if (vis[next.first])
			continue;

		int res = dfs(next.first, v, len + next.second);
		if (res != INT_MAX) {
			vis[u] = false;
			return res;
		}
	}
	vis[u] = false;

	return INT_MAX;
}

int main() {
	char str[25];
	scanf("%s", str);

	int n;
	scanf("%d", &n);

	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n * (n - 1) / 2; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		int res = dfs(u, v, 0);
		if (res == 0) {
			printf("SERI\n");
			fflush(stdout);
		}
		else  if (res == 1) {
			printf("%d MENANG\n", u);
			fflush(stdout);
		}
		else if (res == 2) {
			printf("%d MENANG\n", v);
			fflush(stdout);
		}
		else {
			printf("PASS\n");
			fflush(stdout);
			
			scanf("%s", str);
			if (str[0] == 'S') {
				adj[u].emplace_back(v, 0);
				adj[v].emplace_back(u, 0);
			} else {
				int winner = stoi(str);
				scanf("%s", str);

				if (winner == u) {
					adj[u].emplace_back(v, 1);
					adj[v].emplace_back(u, -1);
				} else {
					adj[u].emplace_back(v, -1);
					adj[v].emplace_back(u, 1);
				}
			}
		}
	}

	return 0;
}