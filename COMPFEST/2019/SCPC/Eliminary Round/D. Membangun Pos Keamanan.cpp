#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, m;
bool vis[N];

vector<int> adj[N];

void read() {
	scanf("%d %d", &n, &m);
	for (int i= 0; i < m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

ll dfs(int pos) {
	if (vis[pos])
		return 0;

	vis[pos] = true;

	ll res = 1;
	for (int next : adj[pos]) {
		if (vis[next])
			continue;

		res += dfs(next);
	}

return res;
}

void solve() {
	memset(vis, false, sizeof(vis));
	
	ll res = 0;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			res += (dfs(i) / 2);
		}
	}

	printf("%lld\n", res);
}

int main() {
	read();
	solve();

return 0;
}