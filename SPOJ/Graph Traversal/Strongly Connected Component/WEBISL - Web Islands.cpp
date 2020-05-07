#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int ID[N];
bool vis[N];
vector<int> adj[N], revAdj[N], ANS[N];

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		revAdj[v].push_back(u);
	}
}

void dfs(int pos, stack<int> &st) {
	if (vis[pos])	return;

	vis[pos] = true;
	for (int next : adj[pos]) {
		if (!vis[next])
			dfs(next, st);
	}
	st.push(pos);
}

void getSCC(int pos, int &SCCtot) {
	if (vis[pos])	return;

	vis[pos] = true;
	ANS[SCCtot].push_back(pos);

	for (int next : revAdj[pos]) {
		if (!vis[next])
			getSCC(next, SCCtot);
	}
}

void solve() {
	memset(vis, false, sizeof(vis));
	stack<int> st;

	for (int i = 0; i < n; i ++) {
		if (!vis[i])
			dfs(i, st);
	}

	memset(vis, false, sizeof(vis));

	int SCCtot = 0;
	while (!st.empty()) {
		int pos = st.top();
		st.pop();

		if (!vis[pos]) {
			getSCC(pos, SCCtot);
			SCCtot ++;
		}
	}

	for (int i = 0; i < SCCtot; i ++) {
		sort(ANS[i].begin(), ANS[i].end());
		for (int pos : ANS[i]) {
			ID[pos] = ANS[i][0];
		}
	}

	for (int i = 0; i < n; i ++)
		printf("%d\n", ID[i]);
}

int main() {

	read();
	solve();

return 0;
}