#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int vis[N][N];
char A[N][N];

pair<int, int> s, f;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};
queue<tuple<int,int,int>> q;

void read() {
	string str;
	cin >> str;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			char c;
			cin >> c;
			if (c == 'S')
				s = make_pair(i, j);
			else if (c == 'T')
				f = make_pair(i, j);

			A[i][j] = c;
			vis[i][j] = INT_MAX;
		}
	}
}

bool inside(int x, int y) {
	return (x > 0 && x <= n && y > 0 && y <= m);
}

void jump(int u, int v, int w, int it) {
	while (inside(u, v)) {
		if (A[u][v] != '.') {
			q.emplace(u, v, w + 1);
			break;
		}
		u += dr[it];
		v += dc[it];
	}
}

void solve() {
	q.emplace(s.first, s.second, 0);
	while (!q.empty()) {
		int u, v, w;
		tie(u, v, w) = q.front();
		q.pop();

		if (vis[u][v] <= w)
			continue;

		vis[u][v] = w;
		for (int i = 0; i < 4; i ++) {
			pair<int, int> next = make_pair(u + dr[i], v + dc[i]);
			bool canJump = A[next.first][next.second] == '.';
			if (canJump)
				jump(next.first, next.second, w, i);
			else {
				if (!inside(next.first, next.second))
					continue;

				q.emplace(next.first, next.second, w);
			}
		}
	}

	int res = vis[f.first][f.second];
	if (res != INT_MAX)
		cout << res << "\n";
	else
		cout << "-1\n";
}

int main() {
	read();
	solve();

	return 0;
}