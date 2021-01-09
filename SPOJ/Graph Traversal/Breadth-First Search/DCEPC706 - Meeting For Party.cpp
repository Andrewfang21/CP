#include<bits/stdc++.h>
using namespace std;

const int N = 205;

int n, m;
int vis[N][N][3];
char A[N][N];

pair<int,int> ankur, anuja, jyoti;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + 2; i ++) {
		for (int j = 0; j < m + 2; j ++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
				A[i][j] = '.';
				continue;
			}
			cin >> A[i][j];
			if (A[i][j] == '1')
				ankur = make_pair(i, j);
			else if (A[i][j] == '2')
				anuja = make_pair(i, j);
			else if (A[i][j] == '3')
				jyoti = make_pair(i, j);
		}
	}
}

bool inside(int x, int y) {
	return (x >= 0 && x < n + 2 && y >= 0 && y < m + 2);
}

void solve() {
	queue<tuple<int,int,int,int>> q;
	q.emplace(ankur.first,ankur.second,0,0);
	q.emplace(anuja.first,anuja.second,1,0);
	q.emplace(jyoti.first,jyoti.second,2,0);

	memset(vis, -1, sizeof(vis));
	while (!q.empty()) {
		int x, y, player, step;
		tie(x,y,player,step) = q.front();
		q.pop();

		if (vis[x][y][player] != -1)
			continue;
		vis[x][y][player] = step;

		for (int i = 0; i < 4; i ++) {
			pair<int,int> nxt = make_pair(x + dx[i], y + dy[i]);
			if (!inside(nxt.first,nxt.second) || A[nxt.first][nxt.second] == '#' || vis[nxt.first][nxt.second][player] != -1)
				continue;

			q.emplace(nxt.first, nxt.second, player, step + 1);
		}
	}

	int res = INT_MAX;
	for (int i = 0; i < n + 2; i ++) {
		for (int j = 0; j < m + 2; j ++) {
			if (A[i][j] == '#' || vis[i][j][0] == -1 || vis[i][j][1] == -1 || vis[i][j][2] == -1)
				continue;

			int curr = max(vis[i][j][0], max(vis[i][j][1], vis[i][j][2]));
			res = min(res, curr);
		}
	}

	printf("%d\n", res);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		read();
		solve();
	}

	return 0;
}