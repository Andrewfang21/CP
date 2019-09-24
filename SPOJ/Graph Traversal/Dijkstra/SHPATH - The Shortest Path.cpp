#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3		")
using namespace std;

const int n = 1e4 + 5;
typedef pair<LL, LL> state;

int N, M;
bool vis[n];

vector<state> adj[n];

map<string, int> A;

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++) {
		string S;		cin >> S;
		A[S] = i;

		cin >> M;
		for (int j = 1; j <= M; j ++) {
			LL v, d;
			cin >> v >> d;

			adj[i].push_back(make_pair(v, d));
		}
	}
}

LL BFS (int src, int to) {

	memset(vis, false, sizeof(vis));
	priority_queue<state, vector<state>, greater<state> > Q;
	Q.push(make_pair(0, src));

	while (!Q.empty()) {
		state u = Q.top();		Q.pop();
		
		if (vis[u.second])		continue;
		vis[u.second] = true;

		// cout << src << " " << u.second << "   " << u.first << '\n';

		if (u.second == to)
			return u.first;

		for (int i = 0; i < adj[u.second].size(); i ++) {
			pair<int, int> nexts = adj[u.second][i];

			Q.push(make_pair(u.first + nexts.second, nexts.first));
		}
	}
}

void work () {
	int Q;
	cin >> Q;

	while (Q --) {
		string U, V;
		cin >> U >> V;

		LL res = BFS(A[U], A[V]);
		cout << res << "\n";
	}
}

void reset () {
	for (int i = 1; i <= N; i ++)	adj[i].clear();
	A.clear();		
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	while (TC --) {
		read ();
		work ();
		reset ();
	}
return 0;
}