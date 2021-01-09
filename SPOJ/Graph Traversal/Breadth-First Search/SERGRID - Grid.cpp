#include<bits/stdc++.h>
using namespace std;

const int N = 500;

int n, m;
int A[N][N], vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			char c;
			cin >> c;
			A[i][j] = c - '0';
		}
}

bool inside(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void solve() {
	queue<tuple<int,int,int>> q;
	q.emplace(0,0,0);
	memset(vis, -1, sizeof(vis));

	while (!q.empty()) {
		int x, y, step;
		tie(x,y,step) = q.front();
		q.pop();

		if (vis[x][y] != -1)
			continue;

		vis[x][y] = step;
		if (x == n - 1 && y == m - 1) {
			printf("%d\n", step);
			return;
		}

		for (int i = 0; i < 4; i ++) {
			pair<int,int> nxt = make_pair(x + dx[i] * A[x][y], y + dy[i] * A[x][y]);
			if (!inside(nxt.first, nxt.second) || vis[nxt.first][nxt.second] != -1)
				continue;

			q.emplace(nxt.first,nxt.second,step + 1);
		}
	}

	printf("%d\n", -1);
}

int main() {
	read();
	solve();

	return 0;
}