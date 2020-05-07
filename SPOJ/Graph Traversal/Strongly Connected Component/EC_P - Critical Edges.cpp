#include<bits/stdc++.h>
using namespace std;

const int N = 705;

int n, m;
int low[N], disc[N], par[N];
bool vis[N];

vector<int> adj[N];
vector<pair<int, int> > bridges;

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs(int pos) {
	static int time = 0;
	disc[pos] = low[pos] = ++ time;
	vis[pos] = true;

	for (int next : adj[pos]) {
		if (!vis[next]) {
			par[next] = pos;
			dfs(next);

			low[pos] = min(low[pos], low[next]);
			if (low[next] > disc[pos]) {
				pos > next
					? bridges.push_back(make_pair(next, pos))
					: bridges.push_back(make_pair(pos, next));
			}
		}
		else if (next != par[pos])
			low[pos] = min(low[pos], disc[next]);
	}
}

void solve(int tc) {
	memset(low, -1, sizeof(low));
	memset(disc, -1, sizeof(disc));
	memset(vis, false, sizeof(vis));
	memset(par, -1, sizeof(par));

	for (int i = 1; i <= n; i ++) {
		if (disc[i] == -1)
			dfs(i);
	}

	int res = bridges.size();
	if (res > 0)
		printf("Caso #%d\n%d\n", tc, res);
	else
		printf("Caso #%d\nSin bloqueos\n", tc);

	sort(bridges.begin(), bridges.end());
	for (pair<int, int> bridge : bridges)
		printf("%d %d\n", bridge.first, bridge.second);

	for (int i = 1; i <= n; i ++)
		adj[i].clear();
	bridges.clear();
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