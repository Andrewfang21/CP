#include<bits/stdc++.h>
using namespace std;

const int N = 40;

int n, m;
long long A[N][N];
bool vis[N][N];

vector<long long> V;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void read() {
	char s[N];
	scanf("%s", s);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%lld", &A[i][j]);
}

bool inside(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, long long sum) {
	if (!inside(x, y) || vis[x][y])
		return;

	vis[x][y] = true;
	if (x == n - 1 && y == m - 1) {
		V.push_back(sum);
		vis[x][y] = false;
		return;
	}

	for (int i = 0; i < 4; i ++) {
		pair<int,int> nxt = make_pair(x + dx[i], y + dy[i]);
		if (!inside(nxt.first, nxt.second) || vis[nxt.first][nxt.second])
			continue;

		dfs(nxt.first, nxt.second, sum + A[nxt.first][nxt.second]);
	}
	vis[x][y] = false;
}

long long get(long long x, long long y) {
	long long l = 0;
	long long r = V.size() - 1;

	long long up, low;
	up = low = -1;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (V[mid] >= x) {
			low = mid;
			r = mid - 1;
		} else l = mid + 1;
	}

	l = 0, r = V.size() - 1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (V[mid] <= y) {
			up = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	if (up >= 0 && low >= 0 && up - low + 1 > 0)
		return up - low + 1;
	return 0;
}

void solve() {
	memset(vis, false, sizeof(vis));
	dfs(0, 0, A[0][0]);

	sort(V.begin(), V.end());
	int q;
	scanf("%d", &q);
	while (q --) {
		long long l, r;
		scanf("%lld %lld", &l, &r);
		long long res = get(l, r);
		printf("%lld\n", res);
	}
}

int main() {
	read();
	solve();

	return 0;
}