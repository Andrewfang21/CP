#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005, INF = 1e9, MOD = 1e9 + 7;

int n, p;
int x[N], y[N], dist[N], cost[N][N];

bool vis[N];

void read () {
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &x[i], &y[i]);	
	}
}

int sqr (int A) {return A * A;}

void setCost () {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) 
			cost[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);

		dist[i] = INF;
	}
}

void solve (int tc) {
	setCost();
	memset(vis, false, sizeof(vis));

	ll res = 0;
	dist[1] = 0;

	for (int i = 1; i <= n; i ++) {
		int currMin = INF;
		int idx = -1;

		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dist[j] <= currMin) {
				currMin = dist[j];
				idx = j;
			}
		}

		if (currMin == INF)
			currMin = 0;

		res += (ll) ceil(sqrt(currMin) * p);
		if (res >= MOD)
			res %= MOD;

		vis[idx] = true;

		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], cost[idx][j]);
	}

	printf("Scenario #%d: %lld\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}