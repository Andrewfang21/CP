#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int N, M;
bool vis[n];

vector<int> adj[n], revAdj[n], ANS[n];

void read () {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		revAdj[v].push_back(u);
	}
}

void dfs (int pos, stack<int> &st) {
	if (vis[pos])
		return;

	vis[pos] = true;

	for (int next : adj[pos]) {
		if (!vis[next])
			dfs(next, st);
	}
	st.push(pos);
}

void getSCC (int pos, int &SCCtot) {
	if (vis[pos])
		return;

	vis[pos] = true;
	ANS[SCCtot].push_back(pos);

	for (int next : revAdj[pos]) {
		if (!vis[next])
			getSCC(next, SCCtot);
	}
}

void solve () {
	memset(vis, false, sizeof(vis));
	stack<int> st;

	for (int i = 1; i <= N; i ++) {
		if (!vis[i])
			dfs(i, st);
	}

	memset(vis, false, sizeof(vis));
	
	int SCCtot = 0;
	while (!st.empty()) {
		int pos = st.top();		st.pop();
		
		if (!vis[pos]) {
			SCCtot ++;
			getSCC(pos, SCCtot);
		}
	}

	sort(ANS[SCCtot].begin(), ANS[SCCtot].end());
	
	printf("%d\n", ANS[SCCtot].size());
	for (int i = 0; i < ANS[SCCtot].size(); i ++) {
		printf("%d%c", ANS[SCCtot][i], i == ANS[SCCtot].size() - 1 ? '\n' : ' ');
	}
}

int main () {
	read ();
	solve ();

return 0;
}