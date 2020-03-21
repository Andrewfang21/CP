#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5, K = 20;

int n;
ll sparse[N][K], sizes[N], depth[N], w[N];

vector<int> adj[N];

void read () {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> w[i];

	memset(sparse, -1, sizeof(sparse));

	for (int i = 2; i <= n; i ++) {
		cin >> sparse[i][0];
		adj[sparse[i][0]].push_back(i);
	}
}

void dfs (int pos, int dist) {
	depth[pos] = dist;
	sizes[pos] = w[pos];

	for (int next : adj[pos]) {
		sparse[next][0] = pos;
		dfs(next, dist + 1);

		sizes[pos] += sizes[next];
	}
}

void buildLCA () {
	for (int j = 1; j < K; j ++) {
		for (int i = 1; i <= n; i ++) {
			if (sparse[i][j - 1] == -1)
				sparse[i][j] = -1;
			else
				sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
		}
	}
}

int getLCA (int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);

	for (int i = K - 1; i >= 0; i --) {
		if (sparse[u][i] != -1 && depth[sparse[u][i]] >= depth[v])
			u = sparse[u][i];
	}

	if (u == v)
		return u;

	for (int i = K - 1; i >= 0; i --) {
		if (sparse[u][i] != sparse[v][i])
			u = sparse[u][i], v = sparse[v][i];
	}

return sparse[u][0];
}

void solve () {
	dfs (1, 0);
	buildLCA ();

	int Q;
	cin >> Q;

	int root = 1;
	while (Q --) {
		char tipe;
		ll x, resp;

		cin >> tipe >> x;

		if (tipe == 'R') {
			root = x;
		} else {
			if (root == x) {
				cout << sizes[1] << "\n";
				continue;
			}

			int lca = getLCA(root, x);	
			if (lca == x) {
				int dist = depth[root] - depth[x] - 1;
				x = root;

				for (int i = K - 1; i >= 0; i --) {
					if (dist >= (1 << i)) {
						x = sparse[x][i];
						dist -= (1 << i);
					}
				} 
				resp = sizes[1] - sizes[x];
			} else resp = sizes[x];

			cout << resp << "\n";
		}
	}
}

int main () {
	read ();
	solve ();

return 0;
}