#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 1e5 + 5, MOD = 1e9 + 7;

int N, M, currSize;
int low[n], disc[n], cost[n];

bool stMember[n];

vector<pair<int, int> > Q[n];
vector<int> adj[n];

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++)
		cin >> cost[i];

	cin >> M;
	for (int i = 1; i <= M; i ++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}
}

void dfs (int pos, stack<int> &st) {
	static int time = 0;

	disc[pos] = low[pos] = ++ time;
	st.push(pos);
	stMember[pos] = true;

	for (int next : adj[pos]) {
		if (disc[next] == -1) {
			dfs(next, st);
			low[pos] = min(low[pos], low[next]);
		} 
		else if (stMember[next]) {
			low[pos] = min(low[pos], disc[next]);
		}
	}

	if (disc[pos] == low[pos]) {
		while (st.top() != pos) {
			int u = st.top();		st.pop();
			Q[currSize].push_back(make_pair(cost[u], u));
			stMember[u] = false;
		}

		int u = st.top();		st.pop();
		Q[currSize ++].push_back(make_pair(cost[u], u));
		stMember[u] = false;
	}
}

void solve () {
	memset(disc, -1, sizeof(disc));
	memset(low, -1, sizeof(low));

	stack<int> st;


	for (int i = 1; i <= N; i ++) {
		if (disc[i] == -1)
			dfs(i, st);
	}

	for (int i = 0; i < currSize; i ++)
		sort(Q[i].begin(), Q[i].end());

	pair<ll, ll> res = make_pair(0, 1);
	for (int i = 0; i < currSize; i ++) {
		int mins = Q[i][0].first;
		int count = 1;

		for (int j = 1; j < Q[i].size(); j ++) {
			pair<int, int> pos = Q[i][j];
			if (pos.first == mins)		count ++;
			if (pos.first != mins)		break;
		}

		res.first += Q[i][0].first;
		res.second = (res.second * count) % MOD;
	}

	cout << res.first << " " << res.second << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}