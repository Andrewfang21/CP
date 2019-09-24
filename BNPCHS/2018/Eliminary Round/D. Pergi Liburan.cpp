#include<bits/stdc++.h>
using namespace std;

const int n = 1005;

int N, M, K;
bool vis[n];

vector<pair<int, int> > adj[n];

bool checkBit (int weight) {
	for (int i = 0; i <= 20; i ++) {
		int mask[2];
		mask[0] = K & (1 << i);
		mask[1] = weight & (1 << i);

		if (mask[0] == 0 && mask[1] != 0)
			return false;
	}

return true;
}

void displayBit (int weight) {
	cout << weight << "\n";
	for (int i = 0; i <= 20; i ++) {
		int mask = weight & (1 << i);
		if (mask)
			cout << "1";
		else
			cout << "0";
	}
	cout << "\n";

	cout << K << "\n";
	for (int i = 0; i <= 20; i ++) {
		int mask = K & (1 << i);
		if (mask)
			cout << "1";
		else
			cout << "0";
	}
	cout << "\n";
}

void read () {
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i ++) {
		int u, v, w;
		cin >> u >> v >> w;

		bool valid = checkBit(w);
		if (valid) {
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
	}
}

void dfs (int pos) {
	if (vis[pos])
		return;
	vis[pos] = true;

	for (pair<int, int> next : adj[pos]) {
		if (vis[next.first])	continue;
		dfs(next.first);
	}
}

void getCost (int &step) {
	for (int i = 1; i <= N; i ++) {
		for (pair<int, int> pos : adj[i]) {
			step |= pos.second;
		}
	}
}

void solve (int tc) {
	memset(vis, false, sizeof(vis));
	dfs(1);

	int step = 0;
	getCost(step);

	if (vis[N] && step == K)
		cout << "Kasus #" << tc << ": Bisa\n";
	else
		cout << "Kasus #" << tc << ": Tidak\n";

	for (int i = 1; i <= N; i ++)
		adj[i].clear();
}

int main () {
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}