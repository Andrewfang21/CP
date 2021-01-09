#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const long long MAKS = 3000000000;

int n, k;
long long curr_pos, curr_res, curr_sz;
long long par[N], chld[N][5], C[N][N], dp[N], sz[N];
bool printed[N];
vector<int> res;

void precompute() {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = min(C[i - 1][j - 1] + C[i - 1][j], MAKS);
		}
	}

	memset(par, -1, sizeof(par));
	memset(chld, 0, sizeof(chld));
	memset(printed, false, sizeof(printed));
	memset(sz, 0, sizeof(sz));
}

void read() {
	ios_base::sync_with_stdio(false);
	string subs;
	cin >> subs;
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v, t;
		cin >> u >> v >> t;
		par[v] = u;
		chld[u][t] = v;
	}
}

void dfs(int node) {
	if (node == 0)
		return;
	if (chld[node][0] == 0 && chld[node][1] == 0) {
		sz[node] = dp[node] = 1;
		return;
	}

	int left_chld, right_chld, curr_sz = 0;
	left_chld = chld[node][0];
	right_chld = chld[node][1];

	dfs(left_chld);
	dfs(right_chld);

	if (left_chld != 0)
		curr_sz += sz[left_chld];
	if (right_chld != 0)
		curr_sz += sz[right_chld];

	dp[node] = 1;
	for (int i = 0; i < 2; i ++) {
		if (chld[node][i] != 0)
			dp[node] = min(dp[node] * dp[chld[node][i]], MAKS);
	}

	dp[node] = min(dp[node] * C[curr_sz][sz[left_chld]], MAKS);
	sz[node] = curr_sz + 1;
}

void search(int now) {
	if (now == 0 || now == curr_pos)
		return;
	if (!printed[now]) {
		curr_res = min(curr_res * dp[now], MAKS);
		curr_res = min(curr_res * C[curr_sz + sz[now]][sz[now]], MAKS);
		curr_sz += sz[now];
	} else {
		search(chld[now][0]);
		search(chld[now][1]);
	}
}

void solve() {
	int root;
	for (int i = 1; i <= n; i ++) {
		if (par[i] == -1)
			root = i;
	}

	dfs(root);

	res.push_back(root);
	printed[root] = true;
	while (res.size() != n) {
		for (int i = 0; i <= n; i ++) {
			if (printed[i])
				continue;
			if (!printed[par[i]])
				continue;

			curr_pos = i;
			curr_res = dp[i];
			curr_sz = sz[i] - 1;
			search(root);

			if (k > curr_res)
				k -= curr_res;
			else {
				res.push_back(i);
				printed[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < res.size(); i ++) {
		if (i == res.size() - 1)
			cout << res[i] << "\n";
		else
			cout << res[i] << " ";
	}
}

int main() {
	precompute();
	read();
	solve();

	return 0;
}