#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005, MAXM = 3e4 + 5;

int N, M, s, t;
int cost[MAXM], low[MAXN], disc[MAXN];
bool vis[MAXN];

vector<int> edges, bridge, ANS;
vector<pair<int, int> > adj[MAXN];

void read () {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &s, &t);

	for (int i = 1; i <= M; i ++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);

		adj[u].push_back(make_pair(v, i));
		adj[v].push_back(make_pair(u, i));
		cost[i] = c;
	}
}

bool dfs (int pos) {
	if (pos == t)
		return true;

	vis[pos] = true;

	for (pair<int, int> next : adj[pos]) {
		if (!vis[next.first] && dfs(next.first)) {
			edges.push_back(next.second);
			// printf("%d --> %d\n", pos, next.first);
			return true;
		}
	}

return false;
}

bool canReach (int pos, int posID, int forbidEdge) {
	static int time = 0;
	vis[pos] = true;
	low[pos] = disc[pos] = ++time;

	bool res = false;
	if (pos == t)
		res = true;

	for (pair<int, int> next : adj[pos]) {
		if (next.second == forbidEdge || next.second == posID)
			continue;

		if (disc[next.first] == -1) {
			bool flag = canReach(next.first, next.second, forbidEdge);
			if (flag)
				res = true;

			low[pos] = min(low[pos], low[next.first]);
			if (low[next.first] > disc[pos] && flag)
				bridge.push_back(next.second);
		} else if (vis[next.first])
			low[pos] = min(low[pos], disc[next.first]);
	}
return res;
} 

void solve () {
	memset(vis, false, sizeof(vis));
	if (!dfs(s)) {
		printf("0\n0\n");
		return;
	}

	int res = INT_MAX;
	for (int forbidEdge : edges) {
		bridge.clear();
		memset(vis, false, sizeof(vis));
		memset(disc, -1, sizeof(disc));
		memset(low, -1, sizeof(low));

		if (!canReach(s, -1, forbidEdge)) {
			if (cost[forbidEdge] < res) {
				res = cost[forbidEdge];
				ANS = {forbidEdge};
			}
		}

		for (int edge : bridge) {
			if (cost[forbidEdge] + cost[edge] < res) {
				res = cost[forbidEdge] + cost[edge];
				ANS = {forbidEdge, edge};
			}
		}

		// printf("current edge = %d\n", forbidEdge);
		// for (int edge : bridge) {
		// 	printf("%d ", edge);
		// }
		// printf("\n");
	}
 
	if (res == INT_MAX) {
		printf("-1\n");
		return;
	}
	printf("%d\n%d\n", res, ANS.size());
	for (int i = 0; i < ANS.size(); i ++) {
		printf("%d%c", ANS[i], i == ANS.size() - 1 ? '\n' : ' ');
	}
}

int main () {
	read ();
	solve ();

return 0;
}