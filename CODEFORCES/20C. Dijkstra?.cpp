#include<bits/stdc++.h>
using namespace std;
 
const int n = 2e5 + 5;
 
int N, M;
int par[n], dist[n];
 
vector<pair<int, int> > adj[n];
 
typedef pair<int, pair<int, int > > ii;
 
void read () {
	cin >> N >> M;
	for (int i = 1; i <= M; i ++) {
		int u, v, c;
		cin >> u >> v >> c;
 
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
}
 
void backtrack (deque<int> &V, int pos) {
	if (pos == 0)	return;
 
	V.push_front(pos);
	backtrack(V, par[pos]);
}
 
void solve () {
	memset(dist, -1, sizeof(dist));
	memset(par, -1, sizeof(par));
	par[1] = 0;
 
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(make_pair(0, make_pair(1, 0)));
 
	int res = -1;
	while (!Q.empty()) {
		ii u = Q.top();		Q.pop();
 
		int pos, parent, step;
		pos = u.second.first, parent = u.second.second, step = u.first;
 
		if (dist[pos] != -1)	continue;
		dist[pos] = step;
		par[pos] = parent;
 
		if (pos == N) {
			res = step;
			break;
		}
 
		for (int i = 0; i < adj[pos].size(); i ++) {
			pair<int, int> next = make_pair(adj[pos][i].first, step + adj[pos][i].second);
 
			if (dist[next.first] != -1)	continue;
			Q.push(make_pair(next.second, make_pair(next.first, pos)));
		}
	}
 
	if (res == -1)
		cout << "-1\n";
	else {
		deque<int> V;
		backtrack(V, N);
 
		for (int i = 0; i < V.size(); i ++)
			i == V.size() - 1 ? cout << V[i] << "\n" : cout << V[i] << " ";
	}
}
 
int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();
 
return 0;
}