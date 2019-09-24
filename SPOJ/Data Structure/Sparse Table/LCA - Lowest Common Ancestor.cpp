#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, times;
int occur[N], depth[N], euler[N], seg[N];

vector<int> adj[N];

void read () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &m);

		for (int j = 1; j <= m; j ++) {
			int next;
			scanf("%d", &next);

			adj[i].push_back(next);
		}
	}
}

void reset () {
	times = 0;

	for (int i = 1; i <= n; i ++)
		adj[i].clear();

	memset(depth, 0, sizeof(depth));
	memset(euler, 0, sizeof(euler));
	memset(occur, -1, sizeof(occur));
}

void dfs (int pos, int height) {
	times ++;
	depth[pos] = height;
	euler[times] = pos;

	if (occur[pos] == -1)
		occur[pos] = times;

	for (int next : adj[pos]) {
		dfs(next, height + 1);
		times ++;

		euler[times] = pos;
	}
}

void buildSeg (int pos, int l, int r) {
	if (l == r) {
		seg[pos] = euler[l];
		return;
	}

	int mid = (l + r) / 2;
	buildSeg(2 * pos, l, mid);
	buildSeg(2 * pos + 1, mid + 1, r);

	seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}

int query(int pos, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)
		return INT_MAX;

	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;

return min(
	query(2 * pos, l, mid, ql, qr),
	query(2 * pos + 1, mid + 1, r, ql, qr));
}

void solve (int tc) {
	memset(occur, -1, sizeof(occur));
	dfs(1, 0);

	buildSeg(1, 1, times);

	int Q;
	scanf("%d", &Q);
	printf("Case %d:\n", tc);

	while (Q --) {
		int u, v;
		scanf("%d %d", &u, &v);

		pair<int, int> req = make_pair(occur[u], occur[v]);
		if (req.first > req.second)
			swap(req.first, req.second);

		int resp = query(1, 1, times, req.first, req.second);
		printf("%d\n", resp);
	}
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
		reset ();
	}

return 0;
}