#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int vis[N];

vector<int> adj[N];

void read() {
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve(int tc) {
	queue<pair<int, int> > Q;
	for (int i = 1; i <= n; i ++) {
		if (adj[i].size() == 1)
			Q.push(make_pair(i, 0));
	}

	memset(vis, -1, sizeof(vis));
	while (!Q.empty()) {
		pair<int, int> curr = Q.front();
		Q.pop();

		int pos = curr.first, step = curr.second;
		if (vis[pos] != -1)
			continue;

		vis[pos] = step;

		for (int next : adj[pos]) {
			pair<int, int> nexts = make_pair(next, step + 1);

			if (vis[next] != -1)
				continue;
			Q.push(nexts);
		}
	}

	printf("Kasus #%d:\n", tc);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", vis[i] == -1 ? 0 : vis[i], i == n ? '\n' : ' ');

	for (int i = 1; i <= n; i ++)
		adj[i].clear();
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read();
		solve(i);
	}

return 0;
}