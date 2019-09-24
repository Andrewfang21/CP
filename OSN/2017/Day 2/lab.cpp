#include<bits/stdc++.h>
using namespace std;

const int N = 205, MAX_LENGTH = 405;

int n, m, res;
int dist[N][N][MAX_LENGTH], bfsDist[N][N];

char maze[N][N];
string s, t, st;

bool done, can;
bool vis[N][N][MAX_LENGTH][2], endpoint[N][N];

int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

vector<pair<int, int> > start, finish;

struct state {
	int x, y, step;
};

void read () {
	string sub;
	cin >> sub;

	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> maze[i][j];

	cin >> s >> t;
}

bool inside (int i, int j) {return (i >= 0 && i < n && j >= 0 && j < m);}

void bfs () {
	queue<state> Q;
	for (pair<int, int> pos : start) {
		Q.push({pos.first, pos.second, 0});
	}

	memset(bfsDist, -1, sizeof(bfsDist));

	while (!Q.empty()) {
		state curr = Q.front();
		Q.pop();

		int x = curr.x, y = curr.y, step = curr.step;

		if (!inside(x, y))		continue;
		if (bfsDist[x][y] != -1)	continue;

		bfsDist[x][y] = step;

		if (endpoint[x][y]) {
			int currRes = s.length() + t.length() + step - 1;
			res = min(res, currRes);

			return;
		}

		for (int i = 0; i < 4; i ++) {
			pair<int, int> next = make_pair(x + movex[i], y + movey[i]);

			if (!inside(next.first, next.second))
				continue;
			if (bfsDist[next.first][next.second] != -1)
				continue;

			Q.push({next.first, next.second, step + 1});
		}
	}
}

void dfs (int i, int j, int len, int tipe) {
	if (!inside(i, j) || vis[i][j][len][tipe])
		return;

	vis[i][j][len][tipe] = true;

	if (tipe == 0 && len == s.length() - 1) {
		start.push_back(make_pair(i, j));
		return;
	}
	else if (tipe == 1 && len == 0) {
		finish.push_back(make_pair(i, j));
		endpoint[i][j] = true;

		return;
	}

	for (int it = 0; it < 4; it ++) {
		pair<int, int> next = make_pair(i + movex[it], j + movey[it]);
		
		if (!inside(next.first, next.second))
				continue;

		int nextLen = (tipe == 0 ? len + 1 : len - 1);
		if (vis[next.first][next.second][nextLen][tipe])
				continue;

		if (tipe == 0) {
			if (maze[next.first][next.second] == s[nextLen]) {
				dfs(next.first, next.second, nextLen, tipe);
			}
		} else {
			if (maze[next.first][next.second] == t[nextLen])
				dfs(next.first, next.second, nextLen, tipe);
		}
	}
}

void getStartingPoint() {
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			if (maze[i][j] == s[0])
				dfs(i, j, 0, 0);

			if (maze[i][j] == t[t.length() - 1])
				dfs(i, j, t.length() - 1, 1);
		}

	if (!start.empty() && !finish.empty())
		bfs();
}

int overlapString () {
	queue<state> Q;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			if (vis[i][j][s.length() - 1][0])
				Q.push({i, j, 0});
		}

	memset(dist, -1, sizeof(dist));

	while (!Q.empty()) {
		state pos = Q.front();
		Q.pop();

		int x = pos.x, y = pos.y, step = pos.step;
		if (!inside(x, y) || dist[x][y][step] != -1)
			continue;

		dist[x][y][step] = step;

		if (vis[x][y][0][1] == true) {
			cout << x << " " << y << " " << step << "\n";

			int jarak = s.length() + t.length() - (step + 1);
			return jarak;
		}		

		for (int i = 0; i < 4; i ++) {
			pair<int, int> next = make_pair(x + movex[i], y + movey[i]);
			int nextLen = step + 1;

			if (!inside(next.first, next.second) || s.length() - nextLen - 1 < 0)
				continue;

			if (vis[next.first][next.second][s.length() - nextLen - 1][0])
				Q.push({next.first, next.second, nextLen});
		}
	}	

return INT_MAX;
}

void solve () {
	res = INT_MAX;
	getStartingPoint();

	if (start.empty() || finish.empty()) {
		cout << "-1\n";
		return;
	}

	// cout << res << "\n";

	// Case when string s and t overlap
	res = min(res, overlapString());

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}