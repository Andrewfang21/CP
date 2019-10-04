#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int N = 2e6 + 5, inf = INT_MAX;

int n, m;
int level[N], last[N];
char col[N];

vector<pair<int, int> > adj[N];

void read () {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i ++) {
		scanf("%s", col);

		for (int j = 0; j < m; j ++) {
			int idIN, idOUT;
			idIN = 2 * i * m + 2 * j + 1;
			idOUT = idIN + 1;

			// Kanan, Bawah
			int next[2] = {idOUT + 1, idOUT + 2 * m - 1};

			if (col[j] == '#')
				continue;

			if (i == 0 && j == 0 || i == n - 1 && j == m - 1) {
				adj[idIN].push_back(make_pair(idOUT, inf));
				adj[idOUT].push_back(make_pair(idIN, 0));
			}
			else  {
				adj[idIN].push_back(make_pair(idOUT, 1));
				adj[idOUT].push_back(make_pair(idIN, 0));
			}

			if (j + 1 < m) {
				adj[idOUT].push_back(make_pair(next[0], inf));
				adj[next[0]].push_back(make_pair(idOUT, 0));
			}

			if (i + 1 < n) {
				adj[idOUT].push_back(make_pair(next[1], inf));
				adj[next[1]].push_back(make_pair(idOUT, 0));
			}
		}
	}
}

bool bfs () {
	memset(level, -1, sizeof(level));
	level[1] = 1;

	queue<int> Q;
	Q.push(1);

	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();

		for (pair<int, int> next : adj[pos]) {
			if (level[next.first] == -1 && next.second > 0) {
				level[next.first] = level[pos] + 1;
				Q.push(next.first);
			}
		}
	}

return (level[2 * n * m] != -1);
}

int dfs (int pos, int currFlow) {
	if (pos == 2 * n * m)
		return currFlow;

	while (last[pos] < adj[pos].size()) {
		pair<int, int> next = adj[pos][last[pos]];

		if (level[next.first] == level[pos] + 1 && next.second > 0) {
			int nextFlow = min(currFlow, next.second);
			int res = dfs(next.first, nextFlow);

			if (res > 0) {
				adj[pos][last[pos]].second -= res;

				for (int i = 0; i < adj[next.first].size(); i ++) {
					if (adj[next.first][i].first == pos) {
						adj[next.first][i].second += res;
						break;
					}
				}

				return res;
			}
		}

		last[pos] ++;
	}

return 0;
}


void solve () {
	int res = 0;
	while (bfs()) {
		memset(last, 0, sizeof(last));

		while (true) {
			int flow = dfs(1, inf);
			if (flow == 0)
				break;

			res += flow;
		}
	}

	printf("%d\n", res);
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}