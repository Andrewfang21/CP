#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define sec second
#pragma GCC Optimize("O3")
using namespace std;

const int n = 105;

typedef pair<double, int> ii;

int N, M;
double dist[n];
bool vis[n];

vector<ii> adj[n];

bool read () {
	cin >> N;
	if (N == 0)		return false;

	cin >> M;
	for (int i = 1; i <= M; i ++) {
		int u, v;		double p;

		cin >> u >> v >> p;
		adj[u].push_back(mp(p, v));			adj[v].push_back(mp(p, u));
	}

	for (int i = 1; i <= N; i ++)
		dist[i] = 100.00;

return true;
}

void work () {
	memset(vis, false, sizeof(vis));
	priority_queue<ii, vector<ii> > q;

	q.push(mp(1.00, 1));
	while (!q.empty()) {
		ii u = q.top();		q.pop();

		if (not vis[u.sec]) {
			vis[u.sec] = true;
			dist[u.sec] = u.fi;

			if (u.sec == N) {
				double res = dist[u.sec] * 100.000;
				cout << setprecision(6) << fixed << res << " percent\n";
				break;
			}

			for (int i = 0; i < adj[u.sec].size(); i ++) {
				ii nexts = mp((adj[u.sec][i].fi * u.fi) / 100.0, adj[u.sec][i].sec);

				q.push(mp(nexts.fi, nexts.sec));
			}			
		}
 	}

 	for (int i = 1; i <= N; i ++)
 		adj[i].clear();
}

int main () {
	ios_base::sync_with_stdio(false);

	while (read ()) {
		work ();
	}
return 0;
}