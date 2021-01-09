#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int vis[N][N];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool inside(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void precompute() {
	memset(vis, -1, sizeof(vis));

	queue<tuple<int,int,int>> q;
	q.emplace(0, 0, 0);
	while (!q.empty()) {
		int x, y, step;
		tie(x, y, step) = q.front();
		q.pop();

		if (vis[x][y] != -1)
			continue;

		vis[x][y] = step;

		for (int i = 0; i < 8; i ++) {
			pair<int,int> nxt = make_pair(x + dx[i], y + dy[i]);
			if (!inside(nxt.first, nxt.second) || vis[nxt.first][nxt.second] != -1)
				continue;

			q.emplace(nxt.first, nxt.second, step + 1);
		}
	}
}

void solve() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		int x, y;
		scanf("%d %d", &x, &y);
		x --, y --;

		printf("%d\n", vis[x][y]);
	}
}

int main() {
	precompute();
	solve();

	return 0;
}