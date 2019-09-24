#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define LL long long
using namespace std;

const int n = 1e5 + 5;

LL N, TC, maks, curr_node;
LL root[2], dist[n], relation[n];

bool vis[n], path[n], found;

vector< pair<LL, LL> > adj[n]; 
stack<int> st;

void read ()
{
	cin >> N;

	for (int i = 1; i < N; i ++)
	{
		LL u, v, d;
		cin >> u >> v >> d;

		adj[u].push_back(make_pair(v, d));			adj[v].push_back(make_pair(u, d));
	}
}

void reset ()
{
	memset(vis, false, sizeof(vis));
	memset(relation, false, sizeof(relation));
	maks = -1;
	found = false;
}

void DFS (int now, LL step, int tipe)
{
	if (vis[now])	return;

	vis[now] = true;
	if (step > maks)
	{
		maks = step;
		root[tipe] = now;
	}

	for (int i = 0; i < adj[now].size(); i ++)
	{
		pair<int, int> nexts = adj[now][i];

		if (!vis[nexts.first])
			DFS (nexts.first, step + nexts.second, tipe);
	}
}

void jelajah (int now, LL step)
{
	vis[now] = true;

	if (!path[now])	
		dist[now] = step;

	for (int i = 0; i < adj[now].size(); i ++)
	{
		pair<int, int> nexts = adj[now][i];

		if (vis[nexts.first])		continue;
		if (path[nexts.first])		continue;

		relation[nexts.first] = curr_node; 
		jelajah (nexts.first, step + nexts.second);
	}
}

void cek (int now, LL step)
{
	if (vis[now])		return;
	if (found)			return;

	st.push(now);
	dist[now] = step;
	vis[now] = true;

	if (now == root[1])
	{
		found = true;
		return;
	}

	for (int i = 0; i < adj[now].size(); i ++)
	{
		pair<int, int> nexts = adj[now][i];

		if (!vis[nexts.first])
		{
			cek (nexts.first, step + nexts.second);
			if (!found)
				st.pop();
		}
	}
}

void work ()
{
	reset ();			DFS (1, 0, 0);
	reset ();			DFS (root[0], 0, 1);		

	reset ();			cek(root[0], 0);

	memset(path, false, sizeof(path));
	while (!st.empty())
	{
		int now = st.top();			st.pop();
		path[now] = true;
	}

	reset ();
	for (int i = 1; i <= N; i ++)
		if (path[i])
		{
			curr_node = i;
			jelajah(i, 0);
		}

	for (int i = 1; i <= N; i ++)
	{
		LL res;

		if (path[i])
			res = max(dist[i], abs(dist[root[1]] - dist[i]));
		else
		{
			int temp = relation[i];

			res = dist[i] + max(dist[temp], abs(dist[root[1]] - dist[temp]));
		}
		
		if (i == N)
			cout << res << "\n";
		else
			cout << res << " ";
	}

	for (int i = 1; i <= N; i ++)
		adj[i].clear();
}

int main ()
{
	ios_base::sync_with_stdio(false);

	cin >> TC;

	while (TC --)
	{
		read ();
		work ();
	}
return 0;
}