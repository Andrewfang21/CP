#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int G[N][N], revG[N][N];
bool vis[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		char s[N];
		scanf("%s", s);

		for (int j = 0; j < n; j ++) {
			G[i][j] = (s[j] == 'Y' ? 1 : 0);
			revG[j][i] = G[i][j];
		}
	}
}

void dfs(int pos, stack<int> &st) {
	if (vis[pos])
		return;

	vis[pos] = true;
	for (int next = 0; next < n; next ++) {
		if (next == pos || G[pos][next] == 0 || vis[next])
			continue;

		dfs(next, st);
	}
	st.push(pos);
}

void getSCC(int pos) {
	if (vis[pos])
		return;

	vis[pos] = true;
	for (int next = 0; next < n; next ++) {
		if (next == pos || revG[pos][next] == 0 || vis[next])
			continue;

		getSCC(next);
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
			getSCC(pos);
			SCCtot ++;
		}
	}

	printf("%d\n", SCCtot);
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read();
		solve();
	}

return 0;
}