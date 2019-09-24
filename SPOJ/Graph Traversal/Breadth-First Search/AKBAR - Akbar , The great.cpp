#include<bits/stdc++.h>
using namespace std;

const int n = 1000005;

int N, M, K;
int power[n], vis[n];

vector<int> adj[n];

struct state
{
	int node, stamina, person;
};

void reset ()
{
	for (int i = 1; i <= n; i ++)
		adj[i].clear();

	memset(vis, -1, sizeof(vis));
	memset(power, -1, sizeof(power));
}

void read ()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= M; i ++)
	{
		int u, v;

		cin >> u >> v;
		adj[u].push_back(v);			adj[v].push_back(u);
	}

	for (int i = 1; i <= K; i ++)
	{
		int A, B;

		cin >> A >> B;
		power[A] = B;
	}
}

void work ()
{
	queue<state> q;

	for (int i = 1; i <= N; i ++)
		if (power[i] != -1)
			q.push({i, power[i], i});

	bool ans = true;
	while (!q.empty())
	{
		state u = q.front();				q.pop();

		if (vis[u.node] != -1 && vis[u.node] != u.person)
		{
			ans = false;
			break;
		}
		vis[u.node] = u.person;

		for (int i = 0; i < adj[u.node].size(); i ++)
		{
			int nexts = adj[u.node][i];

			if (u.stamina > 0)
				q.push({nexts, u.stamina - 1, u.person});
		}
	}

	for (int i = 1; i <= N; i ++)
		if (vis[i] == -1)
			ans = false;

	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC --)
	{
		reset();
		read ();
		work ();
	}
return 0;
}