#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 55, INF = 1e8;

int N, K;
double vis[n][n];
double petak[n][n];

struct state {
	int node;	double dist;	int rem;

	bool operator<(const state& lhs) const {
		if (dist == lhs.dist)
			return rem > lhs.rem;
		return dist > lhs.dist;
	}
};

void reset () {
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			vis[i][j] = INF;
}

void read () {
	cin >> N;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			cin >> petak[i][j];
	cin >> K;
	reset ();
}

void work () {
	priority_queue<state> Q;
	Q.push({0, 0, K});

	while (!Q.empty()) {
		state pos = Q.top();		Q.pop();

		if (vis[pos.node][pos.rem] != INF || pos.rem < 0)		continue;
		vis[pos.node][pos.rem] = pos.dist;

		if (pos.node == 1) {
			cout << setprecision(1) << fixed << pos.dist << "\n";
			return;
		}

		for (int i = 0; i < N; i ++) {
			int nexts = petak[pos.node][i];

			Q.push({i, pos.dist + nexts, pos.rem});
			Q.push({i, pos.dist + (nexts / 2.0), pos.rem - 1});
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	while (TC --) {
		read ();
		work ();
	}
return 0;
}