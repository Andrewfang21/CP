#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int par[N];
bool vis[N];

vector<int> adj[N];

void read () {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i ++) {
		int m;
		scanf("%d", &m);

		for (int j = 1; j <= m; j ++) {
			int next;
			scanf("%d", &next);

			adj[next].push_back(i);
		}
	}
}

void dfs (int pos, queue<int> &Q) {
	if (vis[pos])	return;
	vis[pos] = true;

	for (int next : adj[pos]) {
		if (!vis[next])
			dfs(next, Q);
	}

	Q.push(pos);
}

void solve () {
	memset(vis, false, sizeof(vis));

	queue<int> Q;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			dfs(i, Q);
		}
	}

	int prev = 0;
	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();

		par[pos] = prev;
		prev = pos;
	}

	for (int i = 1; i <= n; i ++) {
		printf("%d\n", par[i]);
	}
}

int main () {
	read ();
	solve ();

return 0;
}