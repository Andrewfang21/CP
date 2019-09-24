#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9;

int n, m, p;
int dist[N], match[N];

bool used[N], vis[N];

vector<int> adj[N];

void read () {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= p; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		v += n;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool bfs () {
	queue<int> Q;

	for (int i = 1; i <= n; i ++) {
		if (match[i] == 0) {
			dist[i] = 0;
			Q.push(i);
		} else dist[i] = INF;
	}

	dist[0] = INF;
	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();

		if (pos == 0)
			continue;

		for (int next : adj[pos]) {
			int matched = match[next];

			if (dist[matched] == INF) {
				dist[matched] = dist[pos] + 1;
				Q.push(matched);
			}
		}
	}

return (dist[0] != INF);
}

bool dfs (int pos) {
	if (pos == 0)
		return true;

	for (int next : adj[pos]) {
		int matched = match[next];

		if (dist[matched] == dist[pos] + 1) {
			if (dfs(matched)) {
				match[next] = pos;
				match[pos] = next;

				return true;
			}
		} 
	}	

	dist[pos] = INF;

return false; 	
}

void solve () {
	int res = 0;
	memset(match, 0, sizeof(match));

	while (bfs()) {
		for (int i = 1; i <= n; i ++) {
			if (match[i] == 0 && dfs(i))
				res ++;
		}
	}

	printf("%d\n", res);
}

int main () {
	read ();
	solve ();

return 0;
}
