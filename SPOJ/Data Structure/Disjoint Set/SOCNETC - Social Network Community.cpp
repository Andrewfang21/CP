#include <bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int parent[n], sizes[n], height[n];

bool sameSet(int A, int B);

int findset (int pos) {
	if (pos == parent[pos])
		return pos;
	else {
		int x = findset(parent[pos]);
		parent[pos] = x;

		return x;
	}
}

void merge (int A, int B) {
	int x, y;
	x = findset(A);			y = findset(B);

	if (x != y) {
		if (height[x] >= height[y]) {
			parent[y] = x;
			sizes[x] += sizes[y];		sizes[y] = 0;
		}
		else {
			parent[x] = y;
			sizes[y] += sizes[x];		sizes[x] = 0;
		}
	}

	if (height[x] == height[y])		height[x] ++;
}

bool exceedSize(int A, int B, int limit) {
	if (!sameSet(A, B)) {
		return sizes[findset(A)] + sizes[findset(B)] > limit;
	}
}

bool sameSet(int A, int B) {
	return findset(A) == findset(B);
}

void init (int N) {
	for (int i = 1; i <= N; i ++) {
		parent[i] = i;
		height[i] = 1;
		sizes[i] = 1;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	int N, M, Q;

	cin >> N >> M >> Q;

	init (N);
	while (Q --) {
		char query;
		cin >> query;

		if (query == 'A') {
			int x, y;		cin >> x >> y;

			if (!exceedSize(x, y, M) && !sameSet(x, y))
				merge(x, y);
		}
		else
		if (query == 'S') {
			int x;		cin >> x;
			cout << sizes[findset(x)] << "\n";
		}
		else {
			int x, y;		cin >> x >> y;

			sameSet(x, y) ? cout << "Yes\n" : cout << "No\n";
		}
	}
return 0;
}