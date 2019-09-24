#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, K = 25;

int n, m;
int sparse[N][K], depth[N];

vector<int> adj[N];

void read () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &m);

		for (int j = 1; j <= m; j ++) {
			int node;
			scanf("%d", &node);

			sparse[node][0] = i;
			adj[i].push_back(node);
		}
	}
}

void dfs (int pos, int dist) {
	depth[pos] = dist;

	for (int next : adj[pos]) {
		sparse[next][0] = pos;
		dfs(next, dist + 1);
	}
}

void buildLCA () {
	for (int j = 1; j <= 20; j ++) {
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

	for (int i = 20; i >= 0; i --) {
		if (sparse[u][i] != -1 && depth[sparse[u][i]] >= depth[v])
			u = sparse[u][i];
	}

	if (u == v)
		return u;

	for (int i = 20; i >= 0; i --) {
		if (sparse[u][i] != sparse[v][i])
			u = sparse[u][i], v = sparse[v][i];
	}

return sparse[u][0];
}

void solve (int tc) {
	dfs(1, 0);
	buildLCA ();

	int Q;
	scanf("%d", &Q);
	printf("Case %d:\n", tc);

	while (Q --) {
		int u, v;
		scanf("%d %d", &u, &v);

		int resp = getLCA(u, v);
		printf("%d\n", resp);
	}
}

void reset () {
	memset(sparse, -1, sizeof(sparse));
	memset(depth, 0, sizeof(depth));

	for (int i = 1; i <= n; i ++)
		adj[i].clear();
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		reset ();
		read ();
		solve (i);
	}

return 0;
}