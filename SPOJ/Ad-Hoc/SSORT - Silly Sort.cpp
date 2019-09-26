#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, currSize;
ll A[N], copyA[N], pos[N], sum[N];

bool vis[N];

map<ll, ll> idx;
vector<ll> V[N];

void read () {
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &A[i]);
		copyA[i] = A[i];
	}
}

void reset () {
	for (int i = 1; i <= currSize; i ++)
		V[i].clear();
	
	idx.clear();

	memset(sum, 0, sizeof(sum));
	memset(vis, false, sizeof(vis));
	memset(A, 0, sizeof(A));
	memset(copyA, 0, sizeof(copyA));

	currSize = 0;
}

void dfs (int pos, int currSize) {
	if (vis[pos])
		return;
	vis[pos] = true;

	int oriPos = idx[A[pos]];
	V[currSize].push_back(A[pos]);
	sum[currSize] += A[pos];

	dfs(oriPos, currSize);
}

void solve (int tc) {
	sort(copyA + 1, copyA + n + 1);
	for (int i = 1; i <= n; i ++) {
		idx[copyA[i]] = i;
		pos[i] = copyA[i];
	}

	currSize = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			currSize ++;
			dfs(i, currSize);
		}
	}

	for (int i = 1; i <= currSize; i ++)
		sort(V[i].begin(), V[i].end());

	ll mins = copyA[1], res = 0;

	for (int i = 1; i <= currSize; i ++) {
		ll cost = (sum[i] - V[i][0]) + (V[i][0] * (V[i].size() - 1));

		if (V[i][0] == mins) {
			res += cost;

			continue;
		}

		ll otherCost = 2 * (mins + V[i][0]);
		otherCost += (sum[i] - V[i][0]) + (mins * (V[i].size() - 1));

		res += min(cost, otherCost);
	}

	printf("Case %d: %lld\n", tc, res);
}

int main () {
	int tc, caseNum = 0;

	while (scanf("%d", &n) && n != 0) {
		read ();
		solve (++ caseNum);
		reset ();
	}

return 0;
}