#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

typedef pair<long long, int> pii;

int n, m, k;
long long vis[N];

vector<pair<int, int>> adj[N];

void read() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	for (int i = 1; i <= n; i ++) {
		int t;
		scanf("%d", &t);

		while (t --) {
			int node;
			scanf("%d", &node);
			adj[node + n].emplace_back(i, 0);
		}
	}

	for (int i = 1; i <= k; i ++) {
		int p;
		scanf("%d", &p);
		for (const auto &it : adj[i + n]) {
			int u = it.first;
			adj[u].emplace_back(i + n, p);
		}
	}
}

void solve() {
	for (int i = 1; i <= n + k; i ++)
		vis[i] = LLONG_MAX;

	priority_queue<pii, vector<pii>, greater<pii>> q;

	vis[1] = 0;
	q.emplace(0, 1);

	while (!q.empty()) {
		int pos = q.top().second;
		long long w = q.top().first;

		q.pop();

		if (vis[pos] != w)
			continue;

		for (const auto &it : adj[pos]) {
			pii next = make_pair(w + it.second, it.first);

			if (vis[next.second] > next.first) {
				vis[next.second] = next.first;
				q.emplace(next);
			}
		}
	}

	printf("%lld\n", vis[n]);

	return;
}

int main() {
	read();
	solve();

return 0;
}