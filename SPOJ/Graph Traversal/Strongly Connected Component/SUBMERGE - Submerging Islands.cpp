#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m;
int low[N], disc[N], par[N];

bool isAP[N], vis[N];

vector<int> adj[N];

void reset () {
	memset(disc, -1, sizeof(disc));
	memset(low, -1, sizeof(low));
	memset(par, -1, sizeof(par));
	memset(isAP, false, sizeof(isAP));
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < N; i ++)
		adj[i].clear();
}

void dfs (int pos) {
	static int time = 0;
	disc[pos] = low[pos] = ++time;
	vis[pos] = true;

	int children = 0;
	for (int next : adj[pos]) {
		if (disc[next] == -1) {
			par[next] = pos;
			children ++;
	
			dfs (next);
			low[pos] = min(low[pos], low[next]);
			
			if ((par[pos] == -1 && children >= 2) || (par[pos] != -1 && low[next] >= disc[pos]))
				isAP[pos] = true;
		} else 
		if (vis[next])
			low[pos] = min(low[pos], disc[next]);
	}
}

void solve () {
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			return;
		reset ();

		for (int i = 1; i <= m; i ++) {
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i ++) {
			if (disc[i] == -1)
				dfs(i);
		}

		int res = 0;
		for (int i = 1; i <= n; i ++) {
			if (isAP[i])
				res ++;
		}

		cout << res << "\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	solve ();

return 0;
}