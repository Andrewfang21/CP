#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 5e6 + 5;

int N, M, K, H;
int movex[2][2] = {{0, -1}, {0, 1}}, movey[2][2] = {{1, 0}, {-1, 0}};

bool vis[n], used[n];

vector<int> V[2];
vector<vector<int> > A;

pair<int, int> pos[n];

void printMaze () {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			int totDigit = to_string(A[i][j]).length();
			for (int k = 1; k <= 7 - totDigit; k ++)
				printf("0");
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	// A.clear();
}

int getLength (int num) {
	int len, bound = 1;
	for (int i = 1; i <= 7; i ++) {
		bound *= 10;

		if (num < bound) {
			len = i;
			break;
		}
	}
return len;
}

void printFormattedID(int ID) {
	int totDigit = getLength(ID);
	for (int i = 1; i <= 7 - totDigit; i ++)
		printf("0");
	printf("%d\n", ID);
}

void printAns(vector<int> V[2], int totID) {
	if (totID > 200) {
		reverse(V[1].begin(), V[1].end());

		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < V[i].size(); j ++)
				printFormattedID(V[i][j]);
		}
	} else {
		for (int i = 0; i < V[0].size(); i ++)
			printFormattedID(V[0][i]);
	}
}

bool inside (int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void dfs (int x, int y, int dir) {
	if (!inside(x, y))
		return;

	ll ID = A[x][y];
	if (vis[ID])
		return;

	vis[ID] = true;

	for (int i = 0; i < 2; i ++) {
		pair<int, int> nexts = make_pair(x + movex[dir][i], y + movey[dir][i]);

		if (inside(nexts.first, nexts.second)) {
			ID = A[nexts.first][nexts.second];

			if (!vis[ID])
				dfs(nexts.first, nexts.second, dir);
		}
	}
}

void checkPath (int x, int y, int dir) {
	if (!inside(x, y))
		return;

	ll ID = A[x][y];
	if (vis[ID] || !used[ID])
		return;

	if (dir != -1) {
		if (V[dir].size() > 100)
			return;
	}

	vis[ID] = true;
	if (used[ID]) {
		if (dir != -1)
			V[dir].push_back(ID);
		else 
			V[0].push_back(ID);
	}

	if (dir != -1) {
		if (V[dir].size() == 100)
			return;
	}

	vector<pair<int, int> > nextMove;
	if (dir != 1) {
		nextMove.push_back(make_pair(1, 0));
		nextMove.push_back(make_pair(0, 1));
	} else {
		nextMove.push_back(make_pair(-1, 0));
		nextMove.push_back(make_pair(0, -1));
	}

	for (int i = 0; i < 2; i ++) {
		pair<int, int> nexts = make_pair(x + nextMove[i].first, y + nextMove[i].second);

		if (inside(nexts.first, nexts.second)) {
			ID = A[nexts.first][nexts.second];

			if (used[ID] && !vis[ID]) 
				checkPath(nexts.first, nexts.second, dir);
		}
	}
}

void solve () {
	scanf("%d %d %d %d", &N, &M, &K, &H);

	deque<int> Q;
	ll MOD = N * M;

	memset(vis, false, sizeof(vis));
	memset(used, false, sizeof(used));

	ll firstID, secondID;
	firstID = (K + H) % MOD + 1;
	secondID = (((((N - 1) * M) + M) % MOD) * (K % MOD) + H) % MOD + 1;

	vis[firstID] = vis[secondID] = true;
	used[firstID] = used[secondID] = true;

	for (int i = 1; i <= N; i ++) {
		vector<int> row;
		for (int j = 1; j <= M; j ++) {
			ll ID = (((((i - 1) * M) + j) % MOD) * (K % MOD) + H) % MOD + 1;
			pos[ID] = make_pair(i - 1, j - 1);

			row.push_back(ID);

			if (ID != firstID && ID != secondID)
				Q.push_back(ID);
		}

		A.push_back(row);
	}

	// printMaze();
	int totID = 0;

	sort(Q.begin(), Q.end());
	while (!Q.empty()) {
		ll ID = Q.front();		Q.pop_front();

		if (!vis[ID]) {
			pair<int, int> coor = pos[ID];

			vis[ID] = true;
			dfs(coor.first - 1, coor.second + 1, 0);
			dfs(coor.first + 1, coor.second - 1, 1);

			used[ID] = true;
			totID ++;
		}
	}

	memset(vis, false, sizeof(vis));

	if (totID > 200) {
		checkPath(0, 0, 0);
		checkPath(N - 1, M - 1, 1);
	} else {
		checkPath(0, 0, -1);
	}

	printAns(V, totID);
}

int main () {
	solve();
	
return 0;
}