#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int N = 305;

int n, m;
int cap[N][N], par[N];

vector<int> adj[N];

void read () {
	if (n == 0 && m == 0)
		exit(0);

	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;

		if (x == 1) {
			adj[0].push_back(i);
			adj[i].push_back(0);

			cap[0][i] = cap[i][0] = 1;
		} else {
			adj[n + 1].push_back(i);
			adj[i].push_back(n + 1);

			cap[n + 1][i] = cap[i][n + 1] = 1;
		}
	}

	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		cap[u][v] = cap[v][u] = 1;
	}
}

bool bfs () {
	memset(par, -1, sizeof(par));

	queue<int> Q;
	Q.push(0);

	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();

		for (int next : adj[pos]) {
			if (par[next] == -1 && cap[pos][next] > 0) {
				par[next] = pos;

				if (next == n + 1)
					return true;

				Q.push(next);
			}
		}
	}
return false;
}

void reset () {
	memset(cap, 0, sizeof(cap));
	for (int i = 0; i < N; i ++)
		adj[i].clear();
}

void solve () {
	while (cin >> n >> m) {
		reset ();
		read ();

		int res = 0;
		while (bfs()) {
			res ++;

			int pos = n + 1;
			while (pos != 0) {
				int prev = par[pos];

				cap[prev][pos] --;
				cap[pos][prev] ++;

				pos = prev;
			}
		}

		cout << res << "\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	solve ();

return 0;
}