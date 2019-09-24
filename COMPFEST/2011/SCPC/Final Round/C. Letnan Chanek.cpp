#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int n = 1e3 + 5;

int N, M;
bool vis[n];

vector<int> adj[n];

void dfs(int pos, int ancestor) {

	if (!vis[pos] && pos != ancestor) {
		vis[pos] = true;

		for (int i = 0; i < adj[pos].size(); i ++) {
			int nexts = adj[pos][i];

			if (!vis[nexts] && nexts != ancestor)
				dfs(nexts, ancestor);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int TC;		cin >> TC;
	
	while (TC --) {
		cin >> N >> M;

		for (int i = 1; i <= M; i ++) {
			int u, v;		cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int res, idx;
		res = idx = INT_MIN;

		for (int i = 1; i <= N; i ++) {
			int cnt = 0;
			memset(vis, false, sizeof(vis));

			for (int j = 1; j <= N; j ++) {
				if (i != j && !vis[j]) {
					cnt ++;
					dfs(j, i);
				}
			}

			if (res < cnt) {
				res = cnt, idx = i;
			} else
			if (res == cnt)
				idx = min(idx, i);
		}

		cout << idx << " " << res << "\n";

		for (int i = 1; i <= N; i ++)
			adj[i].clear();
	}
	
return 0;
}