#include<bits/stdc++.h>
using namespace std;

const int n = 45, k = 25;

int N, M, K;
bool vis[n][n][k][2];
char petak[n][n];

pair<int, int> start;

int movex[] = {1, -1, 0, 0};
int movey[] = {0, 0, 1, -1};

struct state {
	int x, y, rem, spike;
};

void read () {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i ++) 
		for (int j = 1; j <= M; j ++) {
			cin >> petak[i][j];

			if (petak[i][j] == '@')		start = make_pair(i, j);
		}
}

bool valid (int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M)	return false;
	if (petak[x][y] == '#')					return false;
return true;
}

bool BFS () {
	queue<state> Q;
	memset(vis, false, sizeof(vis));

	Q.push({start.first, start.second, K, 0});

	while (!Q.empty()) {
		state u = Q.front();			Q.pop();

		if (vis[u.x][u.y][u.rem][u.spike] || !valid(u.x, u.y))		continue;
		vis[u.x][u.y][u.rem][u.spike] = true;

		if (u.x == start.first && u.y == start.second && u.spike == 1)
			return true;

		for (int i = 0; i < 4; i ++) {
			state nexts = {u.x + movex[i], u.y + movey[i], u.rem, u.spike};

			if (petak[nexts.x][nexts.y] == 's')		nexts.rem --;
			if (petak[nexts.x][nexts.y] == 'x')		nexts.spike = 1;

			if (nexts.rem < 0)		continue;
			Q.push({nexts.x, nexts.y, nexts.rem, nexts.spike});
		}
	}
return false;
}

void work () {
	bool res = BFS();
	res == false ? cout << "IMPOSSIBLE\n" : cout << "SUCCESS\n";
}
 
int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}