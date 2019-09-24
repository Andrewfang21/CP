#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

const int n = 305;
typedef pair<pair<int, int>, pair<int, int> > ii;

int N, M;

int dist[n][n];
char maze[n][n];

int movex[4] = {0, 0, -1, 1};
int movey[4] = {1, -1, 0, 0};

pair<int, int> start;

void read () {
	cin >> N >> M;
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= M; j ++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'Y')
				start = mp(i, j);

			dist[i][j] = INT_MAX;
		}
}

bool inside (int x, int y) {
	return (x > 0 && x <= N && y > 0 && y <= M);
}

bool isWall (int x, int y) {
	return maze[x][y] == '#';
}

void solve (int tc) {
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(mp(mp(0, 0), 
			  mp(start.first, start.second)));

	int res = -1;
	while (!Q.empty()) {
		ii u = Q.top();			Q.pop();

		int posX, posY, enemy, step;
		posX = u.second.first, posY = u.second.second;
		enemy = u.first.first, step = u.first.second;

		if (!inside(posX, posY) || isWall(posX, posY))
			continue;

		if (dist[posX][posY] != INT_MAX)
			continue;

		dist[posX][posY] = step;
		if (maze[posX][posY] == 'T') {
			res = enemy;
			break;
		}

		for (int i = 0; i < 4; i ++) {
			pair<int, int> nexts = mp(posX + movex[i], posY + movey[i]);

			if (inside(nexts.first, nexts.second) && !isWall(nexts.first, nexts.second)) {
				int nextCount = enemy;

				if (maze[nexts.first][nexts.second] == '*')
					nextCount ++;

				Q.push(mp(mp(nextCount, step + 1), 
						  mp(nexts.first, nexts.second)));
			}
		}
	}

	cout << "Kasus #" << tc << ": " << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	int tc;		cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}