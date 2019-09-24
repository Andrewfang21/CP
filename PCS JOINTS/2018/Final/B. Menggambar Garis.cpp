#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 105;

int n, m, currSize;
int maze[N][N];
bool vis[N][N];

vector<int> bangun[N];

int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

bool inside (int i, int j) {return (i >= 1 && i <= n && j >= 1 && j <= m);}

int check (int i, int j) {
	return maze[i][j + 1] + maze[i][j - 1] + maze[i - 1][j] + maze[i + 1][j];
}


int dirx[] = {-1, 1, -1, 1};
int diry[] = {1, 1, -1, -1};

bool corner (int i, int j) {
	int res = 0;

	for (int it = 0; it < 4; it ++) {
		if (maze[i][j + diry[it]] + maze[i + dirx[it]][j] == 2)
			res ++;
	}

return res == true;
}

void dfs (int i, int j) {
	if (vis[i][j] || !inside(i, j) || maze[i][j] == 0)
		return;

	vis[i][j] = true;

	if (corner(i, j))
		bangun[currSize].push_back(2);

	int cnt = check(i, j);

	if (cnt != 2) {
		bangun[currSize].push_back(cnt);
	}

	for (int it = 0; it < 4; it ++) {
		dfs(i + movex[it], j + movey[it]);
	}
}

void read () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			char x;
			cin >> x;

			if (x == 'o')
				maze[i][j] = 1;
		}
}

void solve () {
	memset(vis, false, sizeof(vis));

	currSize = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (!vis[i][j] && maze[i][j] == 1) {
				dfs (i, j);
				currSize ++;
			}
		}

	if (currSize > 2) {
		cout << "Tidak bisa :(\n";
		return;
	}

	bool res;
	for (int i = 1; i < currSize; i ++) {
		res = false;
		int oddDeg = 0;

		for (int nodeDeg : bangun[i]) {
			if (nodeDeg % 2 == 1)
				oddDeg ++;
		}

		if (oddDeg == 0 || oddDeg == 2) {
			res = true;
		} else break;
	}

	if (res) {
		cout << "Yeayy bisa!! :D\n";
	} else {
		cout << "Tidak bisa :(\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}