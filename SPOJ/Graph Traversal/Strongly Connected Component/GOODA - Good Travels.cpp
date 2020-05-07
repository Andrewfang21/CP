#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
const ll INF = 1e13 + 5;

int n, m, s, e;
int val[N], rep[N], sizes[N];
ll dist[N];
bool vis[N];

vector<int> adj[N], revAdj[N], condAdj[N];
vector<pair<int, int> > edge;

typedef pair<ll, int> pii;

void read() {
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &val[i]);
	for (int i = 0; i < m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		revAdj[v].push_back(u);
		edge.push_back(make_pair(u, v));
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

void getSCC(int pos, int &groupId) {
	if (vis[pos])
		return;

	vis[pos] = true;
	rep[pos] = groupId;

	for (int next : revAdj[pos]) {
		if (!vis[next])
			getSCC(next, groupId);
	}
}

ll getCost(int init) {
	priority_queue<pii, vector<pii> > q;
	q.push(make_pair(sizes[init], init));

	while (!q.empty()) {
		pii curr = q.top();
		q.pop();

		ll cost =  curr.first;
		int pos = curr.second;

		dist[pos] = cost;

		for (int next : condAdj[pos]) {
			if (dist[next] < dist[pos] + sizes[next])
				q.push(make_pair(dist[pos] + sizes[next], next));
		}
	}

return dist[rep[e]];
}

void solve() {
	stack<int> st;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i])
			dfs(i, st);
	}

	memset(vis, false, sizeof(vis));
	int SCCtot = 0;
	while (!st.empty()) {
		int pos = st.top();
		st.pop();

		if (!vis[pos]) {
			getSCC(pos, SCCtot);
			dist[SCCtot] = -INF;
			SCCtot ++;
		}
	}

	for (int i = 1; i <= n; i ++)
		sizes[rep[i]] += val[i];

	for (int i = 0; i < m; i ++) {
		int u, v;
		u = edge[i].first, v = edge[i].second;

		if (rep[u] == rep[v])
			continue;

		condAdj[rep[u]].push_back(rep[v]);
	}

	ll res = getCost(rep[s]);
	printf("%lld\n", res);
}

int main() {
	
	read();
	solve();

return 0;
}