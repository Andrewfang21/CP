#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define LL long long
using namespace std;

const int n = 2505, k = 95, MOD = 10243;

int N, K;
int child[n], sibling[n], dp[n][k][2];
bool vis[n];

vector<int> adj[n];

void read () {
	cin >> N >> K;

	for (int i = 1; i < N; i ++) {
		int u, v;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void print () {
	for (int i = 1; i <= N; i ++) {
		cout << i << "    Child : " << child[i] << "    Sibling : " << sibling[i] << "\n";
	}
}

void init (int now, int parent) {
	if (vis[now])		return;

	vis[now] = true;
	child[now] = sibling[now] = -1;

	int last = -1;
	for (int i = 0; i < adj[now].size(); i ++) {
		int nexts = adj[now][i];

		if (nexts == parent)	continue;
		
		if (child[now] == -1)
			child[now] = nexts;

		if (last != -1)
			sibling[last] = nexts;

		init(nexts, now);
		last = nexts;
	}
}

LL solve (int now, int rem, int parent) {
	if (dp[now][rem][parent] != -1)		return dp[now][rem][parent];

	LL res = 0;
	if (sibling[now] != -1 && child[now] != -1) {
		for (int i = 0; i <= rem; i ++)
			res = (res + solve(child[now], i, 0) * solve(sibling[now], rem - i, parent)) % MOD;

		if (parent == 1 || rem == K) {	// Ambil curr node
			for (int i = 0; i < rem; i ++)
				res = (res + solve(child[now], i, 1) * solve(sibling[now], rem - i - 1, parent)) % MOD;
		}
	}
	else
	if (sibling[now] != -1) {
		res = (res + solve(sibling[now], rem, parent)) % MOD;

		if (parent == 1 || rem == K)
			if (rem >= 1)
				res = (res + solve(sibling[now], rem - 1, parent)) % MOD; 
	}
	else
	if (child[now] != -1) {
		res = (res + solve(child[now], rem, 0)) % MOD;

		if (parent == 1 || rem == K)
			if (rem >= 1)
				res = (res + solve(child[now], rem - 1, 1)) % MOD;
	}
	else {
		if (rem == 0 || rem == 1 && parent == 1)	res = 1;
	}

return dp[now][rem][parent] = res;
}

void work () {
	memset(vis, false, sizeof(vis));
	memset(child, -1, sizeof(child));
	memset(sibling, -1, sizeof(sibling));

	init(1, -1);

//	print ();
	memset(dp, -1, sizeof(dp));
	LL res = solve(1, K, 0);

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}