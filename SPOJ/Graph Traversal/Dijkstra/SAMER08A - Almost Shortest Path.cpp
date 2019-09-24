#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize ("O3")
using namespace std;

const LL n = 505, INF = 1e18;

typedef pair<LL, pair<LL, LL> > ii;
typedef pair<LL, LL> vii;

LL N, M, S, T, res;
LL dist[n];

bool path[n][n];
	
vector<LL> par[n];
vector<vii> adj[n];

void read ()
{
	cin >> S >> T;

	for (int i = 1; i <= M; i ++)
	{
		int u, v, d;

		cin >> u >> v >> d;
		adj[u].push_back(make_pair(v, d));

		path[u][v] = true;
	}
}

void rec (int now, int prevs)
{
	if (!path[prevs][now])
		return;
	if (prevs == -1)
		return;

	path[prevs][now] = false;
//	cout << prevs << " " << now << "\n";

	for (int i = 0; i < par[prevs].size(); i ++)
		rec (prevs, par[prevs][i]);
}

void BFS ()
{
	priority_queue<ii, vector<ii>, greater<ii> > q;

	q.push(make_pair(0, make_pair(S, -1)));

	res = INF;
	while (!q.empty())
	{
		ii u = q.top();				q.pop();

		if (dist[u.second.first] == u.first)
		{
			if (u.second.second != -1)			
				par[u.second.first].push_back(u.second.second);
		}

		if (dist[u.second.first] == INF)
		{
			par[u.second.first].push_back(u.second.second);
			dist[u.second.first] = u.first;
		}

		for (int i = 0; i < adj[u.second.first].size(); i ++)
		{
			vii nexts = adj[u.second.first][i];

			if (path[u.second.first][nexts.first] == false)
				continue;

			if (dist[nexts.first] == INF || dist[nexts.first] == dist[u.second.first] + nexts.second)
				q.push(make_pair(dist[u.second.first] + nexts.second, make_pair(nexts.first, u.second.first)));
		}
	}
	res = dist[T];
}

void work ()
{
	for (int i = 0; i < N; i ++)
		dist[i] = INF;
	BFS ();

	// for (int i = 0; i < N; i ++)
	// 	cout << i << "   " << dist[i] << "\n";

	for (int i = 0; i < par[T].size(); i ++)
		rec(T, par[T][i]);

	for (int i = 0; i < N; i ++)
		dist[i] = INF;

	BFS ();

	if (res == INF)
		cout << "-1\n";
	else
		cout << res << "\n";
}

void reset ()
{
	for (int i = 0; i < N; i ++)
		adj[i].clear();
	for (int i = 0; i < N; i ++)
		par[i].clear();

	memset(path, false, sizeof(path));
}

int main ()
{
	ios_base::sync_with_stdio(false);

	while (cin >> N >> M)
	{
		if (N == 0)			return 0;

		read ();
		work ();
		reset ();
	}

return 0;
}