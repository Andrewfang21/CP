#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int N, M;
int par[n], disc[n], low[n];
bool vis[n];

vector<int> adj[n];

void read () {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs (int pos) {
	static int time = 0;
	vis[pos] = true;
	disc[pos] = low[pos] = ++ time;

	for (int next : adj[pos]) {
		if (!vis[next]) {
			par[next] = pos;
			dfs(next);

			low[pos] = min(low[pos], low[next]);

			if (low[next] > disc[pos])
				printf("%d <--> %d is a bridge\n", next, pos);
		}
		else if (next != par[pos])
			low[pos] = min(low[pos], disc[next]);
	}
}

void solve () {
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= N; i ++) {
		if (!vis[i])
			dfs(i);
	}
}

int main () {
	read ();
	solve ();

return 0;
}