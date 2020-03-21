#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair

using namespace std;

const int N = 1e4 + 5, K = 20;

typedef pair<int, int> PAIR;

int n, edgeCount;
int par[N], depth[N], head[N], subtree[N], seg[5 * N], loc[N], A[N], sparse[N][K];

vector<PAIR> adj[N];


void read() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].PB( MP(v, w) );
		adj[v].PB( MP(u, w) );
	}
}

void reset() {
	memset(subtree, 0, sizeof(subtree));
	memset(loc, 0, sizeof(loc));
	memset(depth, 0, sizeof(depth));
	memset(head, 0, sizeof(head));
	memset(A, 0, sizeof(A));

	edgeCount = 0;
	head[1] = -1;
	sparse[1][0] = 1;

	for (int i = 0; i < N; i ++)
		adj[i].clear();
}

void dfs(int pos, int prev) {
	par[pos] = prev;
	depth[pos] = depth[prev] + 1;
	subtree[pos] = 1;

	for (PAIR next : adj[pos]) {
		if (next.first == prev)
			continue;

		sparse[next.first][0] = pos;

		dfs(next.first, pos);
		subtree[pos] += subtree[next.first];
	}
}

void hld(int pos, int prev, int weight) {
	head[pos] = (head[pos] == -1 ? pos : head[prev]);

	int maxSubtree = 0;
	int cost = -1;
	int special = -1;

	loc[pos] = ++ edgeCount;
	A[edgeCount] = weight;

	for (PAIR next : adj[pos]) {
		if (next.first == prev)
			continue;

		if (subtree[next.first] > maxSubtree) {
			maxSubtree = subtree[next.first];
			cost = next.second;
			special = next.first;
		}
	}

	if (special != -1) {
		hld(special, pos, cost);

		for (PAIR next : adj[pos]) {
			if (next.first == prev || next.first == special)
				continue;

			head[next.first] = -1;
			hld(next.first, pos, next.second);
		}
	}
}

void build(int pos, int l, int r) {
	if (l == r) {
		seg[pos] = A[l];
		return;
	}

	int mid = (l + r) / 2;
	build(2 * pos, l, mid);
	build(2 * pos + 1, mid + 1, r);

	seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

int query(int pos, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)
		return 0;
	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;

return query(2 * pos, l, mid, ql , qr) + query(2 * pos + 1, mid + 1, r, ql, qr);
}

int crawl(int pos, int target) {
	int sum = 0;

	while (true) {
		if (pos == target)	break;

		if (head[pos] == head[target]) {
			sum += query(1, 1, n, loc[target] + 1, loc[pos]);
			break;
		}

		sum += query(1, 1, n, loc[ head[pos] ], loc[pos]);
		pos = par[head[pos]];
	}

return sum;
}

void buildLCA() {
	for (int j = 1; j < K; j ++) {
		for (int i = 0; i < n; i ++) {
			if (sparse[i][j - 1] == -1)
				sparse[i][j] = -1;
			else
				sparse[i][j] = sparse[ sparse[i][j - 1] ][j - 1];
		}
	}
}

int getLCA(int l, int r) {
	if (depth[l] < depth[r])
		swap(l, r);

	for (int i = K - 1; i >= 0; i --) {
		if (sparse[l][i] != -1 && depth[ sparse[l][i] ] >= depth[r])
			l = sparse[l][i];
	}

	if (l == r)
		return l;

	for (int i = K - 1; i >= 0; i --) {
		if (sparse[l][i] != sparse[r][i])
			l = sparse[l][i], r = sparse[r][i];
	}

return sparse[l][0];
}

int getKth(int pos, int k) {
	for (int i = K - 1; i >= 0; i --) {
		if (sparse[pos][i] != -1 && k >= (1 << i)) {
			pos = sparse[pos][i];
			k -= (1 << i);
		}
	}

return pos;
}

void solve() {
	dfs(1, 0);
	hld(1, 0, 0);
	buildLCA();
	build(1, 1, n);

	while (true) {
		char type[K];
		scanf("%s", type);

		if (type[1] == 'O')		break;

		int u, v;
		scanf("%d %d", &u, &v);

		int lca = getLCA(u, v);
		if (type[0] == 'D') {
			printf("%d\n", crawl(u, lca) + crawl(v, lca));
		}
		else {
			int k, res;
			scanf("%d", &k);

			int leftLength = depth[u] - depth[lca], rightLength = depth[v] - depth[lca];

			if (leftLength + 1 >= k)
				res = getKth(u, k - 1);
			else
				res = getKth(v, leftLength + rightLength - k + 1);
			
			printf("%d\n", res);
		}
	}
}


int main() {

	int tc;
	scanf("%d", &tc);

	while (tc --) {
		reset();
		read();
		solve();
	}

return 0;
}