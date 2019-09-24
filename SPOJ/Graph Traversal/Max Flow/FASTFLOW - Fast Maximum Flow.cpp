#include<bits/stdc++.h>
#pragma GCC Optimize("03")
#define ll long long
using namespace std;

const ll N = 5e3 + 5, INF = 1e15 + 5;

int n, m;
ll capacity[N][N], flow[N][N], level[N], last[N];

vector<int> adj[N];

void read () {
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v, cost;
		cin >> u >> v >> cost;

		if (u == v) continue;

		adj[u].push_back(v);		adj[v].push_back(u);

		if (capacity[u][v]) {
			capacity[u][v] += cost;		capacity[v][u] += cost;
		} else
			capacity[u][v] = capacity[v][u] = cost;
	}
}

bool bfs () {
	memset(level, -1, sizeof(level));

	queue<int> Q;
	Q.push(1);

	level[1] = 1;
	while (!Q.empty()) {
		int currNode = Q.front();	
		Q.pop();

		for (int next : adj[currNode]) {
			if (level[next] == -1 && capacity[currNode][next] - flow[currNode][next] > 0) {
				level[next] = level[currNode] + 1;
				Q.push(next);
			}
		}
	}

return level[n] != -1;
}

ll dfs (int now, ll currFlow) {
	if (now == n)		return currFlow;

	while (last[now] < adj[now].size()) {
		int next = adj[now][last[now]];

		if (level[next] == level[now] + 1 && capacity[now][next] - flow[now][next] > 0) {
			ll nextFlow = min(currFlow, capacity[now][next] - flow[now][next]);
			ll res = dfs (next, nextFlow);

			if (res > 0) {
				flow[now][next] += res;
				flow[next][now] -= res;

				return res;
			}
		}

		last[now] ++;
	}

return 0;
}


void solve () {
	ll res = 0;
	while (bfs()) {
		memset(last, 0, sizeof(last));
		
		while (true) {
			ll currFlow = dfs (1, INF);

			if (currFlow == 0)		break;
			res += currFlow;
		}
	}
	cout << res << "\n";
}

int main () {
	read ();
	solve ();

return 0;
}