#include<bits/stdc++.h>
using namespace std;

const int N = 605, INF = 1e9;

int p, t, s, c;
int cap[N][N], match[N], dist[N];

vector<int> adj[N];

struct state {
	int x, y;
}person[N], taxi[N];

void read () {
	scanf("%d %d %d %d", &p, &t, &s, &c);
	for (int i = 1; i <= p; i ++) {
		scanf("%d %d", &person[t + i].x, &person[t + i].y);
	}

	for (int i = 1; i <= t; i ++) {
		scanf("%d %d", &taxi[i].x, &taxi[i].y);
	}
}

bool reachable (int i, int j) {
	int distBef = abs(taxi[i].x - person[j].x) + abs(taxi[i].y - person[j].y);
	int distAft = distBef * 200;

return (distAft <= (s * c));
}

void buildEdge () {
	for (int i = 1; i <= t; i ++) {
		for (int j = 1; j <= p; j ++) {
			if (reachable(i, t + j)) {
				adj[i].push_back(t + j);
				adj[t + j].push_back(i);
			}
		}
	}
}

bool bfs () {
	queue<int> Q;
	for (int i = 1; i <= t; i ++) {
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
			return true;

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

		if (dist[matched] == dist[pos] + 1 && dfs(matched)) {
			match[next] = pos;
			match[pos] = next;

			return true;
		}
	}

	dist[pos] = INF;

return false;
} 

void solve () {
	memset(match, 0, sizeof(match));
	for (int i = 0; i < N; i ++) {
		adj[i].clear();
	}

	buildEdge ();

	int res = 0;
	while (bfs()) {
		for (int i = 1; i <= t; i ++) {
			if (match[i] == 0 && dfs(i))
				res ++;
		}
	}
				
	printf("%d\n", res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read ();
		solve ();
	}

return 0;
}
