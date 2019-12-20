#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, q;
ll cost[N], in[N], out[N];

vector<int> adj[N];

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; i ++)
		cin >> cost[i];

	for (int i = 0 ; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void inDfs(int pos, int prev) {

	in[pos] = 0;

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		inDfs(next, pos);

		ll possIncome = 0;
		if (cost[next] - cost[pos] > 0)
			possIncome = cost[next] - cost[pos];

		in[pos] = max(in[pos], in[next] + possIncome);
	}
}

void outDfs(int pos, int prev) {

	pair<ll, ll> maks = make_pair(-1, -1);

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		ll possIncome = 0;
		if (cost[next] - cost[pos] > 0)
			possIncome = cost[next] - cost[pos];
		
		if (in[next] + possIncome >= maks.first)
			maks = make_pair(in[next] + possIncome, maks.first);
		else
		if (in[next] + possIncome > maks.second)
			maks.second = in[next] + possIncome;
	}

	for (int next : adj[pos]) {
		if (next == prev)
			continue;

		ll pick = maks.first, possIncome = 0;
	
		if (cost[next] - cost[pos] > 0)
			possIncome = cost[next] - cost[pos];

		if (in[next] + possIncome == maks.first)
			pick = maks.second;

		possIncome = 0;
		if (cost[pos] - cost[next] > 0)
			possIncome = cost[pos] - cost[next];

		out[next] = max(possIncome + out[pos], pick + possIncome);
		outDfs(next, pos);
	}
}

void solve() {
	inDfs(0, -1);
	outDfs(0, -1);

	while (q --) {
		int x;
		cin >> x;

		cout << max(in[x], out[x]) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	solve();

return 0;
}
