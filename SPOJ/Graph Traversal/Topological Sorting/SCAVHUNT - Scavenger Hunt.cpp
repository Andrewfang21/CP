#include<bits/stdc++.h>
using namespace std;

const int N = 405;

int n;
bool vis[N];

vector<int> adj[N];
map<int, string> mapping;
map<string, int> node;

void read() {
	cin >> n;

	int curr = 1;
	for (int i = 1; i < n; i ++) {
		string u, v;
		cin >> u >> v;

		if (node[u] == 0) {
			node[u] = curr;
			mapping[curr ++] = u;
		}

		if (node[v] == 0) {
			node[v] = curr;
			mapping[curr ++] = v;
		}

		adj[node[u]].push_back(node[v]);
	}
}

void dfs(int pos, stack<int> &st) {
	if (vis[pos])
		return;

	vis[pos] = true;
	for (int next : adj[pos]) {
		if (!vis[next])
			dfs(next, st);
	}

	st.push(pos);
}

void solve(int tc) {
	memset(vis, false, sizeof(vis));

	stack<int> st;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i])
			dfs(i, st);
	}

	cout << "Scenario #" << tc << ":\n";

	while (!st.empty()) {
		int pos = st.top();
		st.pop();

		cout << mapping[pos] << "\n";
	}

	node.clear();
	mapping.clear();

	for (int i = 1; i <= n; i ++)
		adj[i].clear();
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		read();
		solve(i);
	}

return 0;
}