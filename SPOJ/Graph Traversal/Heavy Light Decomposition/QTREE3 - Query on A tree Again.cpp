#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9 + 5;

int n, q, nodeCount;
int subtree[N], depth[N], par[N], head[N], seg[5 * N], loc[N], ID[N];

vector<int> adj[N];

void read() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs(int pos, int prev) {
	par[pos] = prev;
	depth[pos] = depth[prev] + 1;
	subtree[pos] = 1;

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		dfs(next, pos);
		subtree[pos] += subtree[next];
	}
}

void hld(int pos, int prev) {
	head[pos] = (head[pos] == -1 ? pos : head[prev]);

	loc[pos] = ++ nodeCount;
	ID[ loc[pos] ] = pos;

	int maxSubtree = 0;
	int special = -1;

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		if (subtree[next] > maxSubtree) {
			maxSubtree = subtree[next];
			special = next;
		}
	}

	if (special != -1) {
		hld(special, pos);

		for (int next : adj[pos]) {
			if (next == prev || next == special)
				continue;

			head[next] = -1;
			hld(next, pos);
		}
	}
}

void build(int pos, int l, int r) {
	if (l == r) {
		seg[pos] = INF;
		return;
	}

	int mid = (l + r) / 2;

	build(2 * pos, l, mid);
	build(2 * pos + 1, mid + 1, r);

	seg[pos] = INF;
}

void update(int pos, int l, int r, int target) {
	if (target < l || target > r)
		return;
	if (target == l && target == r) {
		seg[pos] = (seg[pos] == INF ? l : INF);
		return;
	}

	int mid = (l + r) / 2;

	update(2 * pos, l, mid, target);
	update(2 * pos + 1, mid + 1, r, target);

	seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}

int query(int pos, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
		return INF;
	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;

return min(
		query(2 * pos, l, mid, ql, qr),
		query(2 * pos + 1, mid + 1, r, ql, qr)
	);
}

int crawl(int pos) {
	int res = query(1, 1, n, loc[1], loc[1]);

	while (true) {
		if (pos == 1)
			break;

		if (head[pos] == 1) {
			res = min(res, query(1, 1, n, loc[1], loc[pos]));
			break;
		}

		res = min(res, query(1, 1, n, loc[ head[pos] ], loc[pos]));
		pos = par[ head[pos] ];
	}

return res;
}

void solve() {
	head[1] = -1;

	dfs(1, 0);
	hld(1, 0);
	build(1, 1, n);

	while (q --) {
		int type, pos;
		scanf("%d %d", &type, &pos);

		if (type == 0)
			update(1, 1, n, loc[pos]);
		
		else {
			int res = crawl(pos);
			printf("%d\n", res == INF ? -1 : ID[res]);
		}
	}
}

int main() {
	
	read();
	solve();

return 0;
}