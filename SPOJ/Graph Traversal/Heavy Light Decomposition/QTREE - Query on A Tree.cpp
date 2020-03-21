#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define PB push_back
#define MP make_pair
using namespace std;

const int N = 1e4 + 5;

typedef pair<int, int> PAIR;

int n, edgeCount;
int subtree[N], loc[N], A[N], par[N], depth[N], head[N], seg[5 * N];

vector<int> edge[N];
vector<pair<int, int> > adj[N];

void reset() {
	memset(subtree, 0, sizeof(subtree));
	memset(loc, 0, sizeof(loc));
	memset(depth, 0, sizeof(depth));
	memset(head, 0, sizeof(head));
	memset(A, 0, sizeof(A));

	edgeCount = 0;
	head[1] = -1;

	for (int i = 0; i < N; i ++) {
		adj[i].clear();
		edge[i].clear();
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].PB(MP(v, w));
		adj[v].PB(MP(u, w));

		edge[i].PB(u);
		edge[i].PB(v);
	}
}

void dfs(int pos, int prev) {
	par[pos] = prev;
	depth[pos] = depth[prev] + 1;
	subtree[pos] = 1;

	for (PAIR next : adj[pos]) {
		if (next.first == prev)
			continue;

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
			if (next.first == special || next.first == prev)
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

	seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
} 

int query(int pos, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
		return -1;
	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;

return max(query(2 * pos, l, mid, ql, qr), query(2 * pos + 1, mid + 1, r, ql, qr));
}

void update(int pos, int l, int r, int target, int value) {
	if (target < l || target > r)
		return;
	if (l == r) {
		seg[pos] = value;
		return;
	}

	int mid = (l + r) / 2;
	update(2 * pos, l, mid, target, value);
	update(2 * pos + 1, mid + 1, r, target, value);

	seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
}

int crawl(int pos, int target) {
	int maks = 0;

	while (true) {
		if (pos == target)		break;

		if (head[pos] == head[target]) {
			maks = max(maks, query(1, 1, n, loc[target] + 1, loc[pos]));
			break;
		}

		maks = max(maks, query(1, 1, n, loc[head[pos]], loc[pos]));
		pos = par[head[pos]];
	}

return maks;
}

int getLCA(int l, int r) {
	while (head[l] != head[r]) {
		if (depth[head[r]] > depth[head[l]])
			r = par[head[r]];
		else
			l = par[head[l]];
	}

	if (depth[r] > depth[l])
		return l;

return r;
}

void solve() {
	dfs(1, 0);
	hld(1, 0, 0);
	build(1, 1, n);

	while (true) {
		string type;
		cin >> type;

		if (type[0] == 'D')		break;

		int u, v;
		cin >> u >> v;

		if (type[0] == 'Q') {
			int lca = getLCA(u, v);
			int l = crawl(u, lca), r = crawl(v, lca);

			cout << max(l, r) << "\n";	
		}
		else {
			int pos = 0;
			if (depth[ edge[u - 1][0] ] > depth[ edge[u - 1][1] ])
				pos = edge[u - 1][0];
			else
				pos = edge[u - 1][1];

			update(1, 1, n, loc[pos], v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc --) {
		reset();
		read();
		solve();
	}	

return 0;
}
