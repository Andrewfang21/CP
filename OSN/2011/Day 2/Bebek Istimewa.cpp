#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int A[N], V[N];
bool vis[2 * N][N], found = false;

bool inside(int pos) {
	return (pos >= 1 && pos <= n);
}

void dfs(int pos, int time, int mode) {
	if (!inside(pos) || found)
		return;

	if (mode == 0 && pos != A[time]) {
		V[time] = pos;
		if (time == m) {
			found = true;
			for (int i = 1; i <= time; i ++)
				printf("%d\n", V[i]);
		
			return;
		}

		dfs(pos + 1, time + 1, 0);
		dfs(pos - 1, time + 1, 0);

	} else if (mode == 1 && !vis[pos][time] && A[time] != pos) {
		vis[pos][time] = true;
		V[time] = pos;

		if (time == m && A[time] != pos) {
			found = true;
			for (int i = 1; i <= m; i ++)
				printf("%d\n", V[i]);
		}

		dfs(pos + 1, time + 1, 1);
		dfs(pos - 1, time + 1, 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &A[i]);

	if (n > 2000) {
		for (int i = n / 2; i <= n; i ++) {
			if (found)
				break;

			dfs(i, 0, 0);
		}
	} else {
		for (int i = 1; i <= n; i ++) {
			if (vis[i][1] || A[1] == i)
				continue;

			dfs(i, 1, 1);
		}
	}

	if (!found)
		puts("menyerah");

	return 0;
}