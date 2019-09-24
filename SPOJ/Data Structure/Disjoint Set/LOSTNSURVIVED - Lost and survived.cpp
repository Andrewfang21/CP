#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 5, INF = 1e8;

int N, M, ans;
int parent[n], sizes[n], height[n], seg[5 * n];

pair<int, int> res;

void update (int pos, int L, int R, int X, int val) {
	if (L > X || R < X)		return;
	
	if (X <= L && X >= R) {
		seg[pos] = val;
		return;
	}
	int mid = (L + R) / 2;
	update(2 * pos, L, mid, X, val);		update(2 * pos + 1, mid + 1, R, X, val);

	seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}

void build_seg (int pos, int L, int R) {
	if (L == R) {
		seg[pos] = 1;
		return;
	}
	int mid = (L + R) / 2;
	build_seg(2 * pos, L, mid);		build_seg(2 * pos + 1, mid + 1, R);

seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}


int findset (int pos) {
	if (parent[pos] == pos)
		return pos;
	else {
		int x = findset(parent[pos]);
		parent[pos] = x;

		return x;
	}
}

bool same_set (int A, int B) {
	int X, Y;
	X = findset(A);		Y = findset(B);

return X == Y;
}

void merge (int A, int B) {
	int X, Y;
	X = findset(A);		Y = findset(B);

	if (height[X] >= height[Y]) {
		parent[Y] = X;
		sizes[X] += sizes[Y];		sizes[Y] = 0;

		update(1, 1, N, X, sizes[X]);		update(1, 1, N, Y, INF);
	} else {
		parent[X] = Y;
		sizes[Y] += sizes[X];		sizes[X] = 0;

		update(1, 1, N, X, INF);			update(1, 1, N, Y, sizes[Y]);
	}

	if (height[X] == height[Y])		height[X] ++;
	res.first = max(res.first, abs(sizes[X] - sizes[Y]));
	res.second = seg[1];
}

void reset () {
	memset(height, 0, sizeof(height));
	for (int i = 1; i <= N; i ++) {
		sizes[i] = 1;
		parent[i] = i;
	}
	res = make_pair(1, 1);
}

int main () {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	reset ();
	build_seg(1, 1, N);
	for (int i = 1; i <= M; i ++) {
		int u, v;
		cin >> u >> v;

		if (!same_set(u, v)) {
			merge(u, v);
		}

		ans = abs(res.first - res.second);
		cout << ans << "\n";
	}
return 0;
}