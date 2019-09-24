#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define ll long long
#define MOD 1000000007
using namespace std;

const int n = 1e5 + 5, k = 5000005;

ll N, M;

ll fakt[k], height[n], sizes[n], parent[n];
bool visited[n];

int findset (int pos) {
	if (pos == parent[pos])
		return pos;
	else {
		int x = findset(parent[pos]);
		parent[pos] = x;

		return x;
	}
}

bool sameSet (int A, int B) {
return findset(A) == findset(B);
}

void mergeSet (int A, int B) {
	int x, y;
	x = findset(A);			y = findset(B);

	if (height[x] >= height[y]) {
		parent[y] = x;

		sizes[x] += sizes[y];		sizes[y] = 0;
	}
	else {
		parent[x] = y;

		sizes[y] += sizes[x];		sizes[x] = 0;
	}

	if (height[x] == height[y])		height[x] ++;
}

void work (int tc) {

	memset(visited, false, sizeof(visited));

	ll validIsland, res;

	validIsland = 0;			res = 1;
	for (int i = 1; i <= N; i ++) {

		int currIsland = findset(i);
		if (visited[currIsland])		continue;

		visited[currIsland] = true;
		if (sizes[currIsland] > 1)
			validIsland ++;

		int provincesCount = sizes[currIsland];
		if (provincesCount % 2 == 0)
			res = ((res % MOD) * (fakt[provincesCount / 2 * (provincesCount - 1)] % MOD) ) % MOD;
		else
			res = ((res % MOD) * (fakt[(provincesCount - 1) / 2 * provincesCount] % MOD)) % MOD;
	}

	res = ((res % MOD) * (fakt[validIsland] % MOD)) % MOD;
	cout << "Kasus #" << tc << ": " << res << "\n";
}

void precompute () {

	fakt[0] = 1;
	for (int i = 1; i <= 3000000; i ++) {
		fakt[i] = ((fakt[i - 1] % MOD) * (i % MOD)) % MOD;
	}
}

void read () {
	cin >> N >> M;
	for (int i = 1; i <= M; i ++) {
		int A, B;
		cin >> A >> B;

		if (!sameSet(A, B))
			mergeSet(A, B);
	}
}

void reset () {
	for (int i = 1; i < n; i ++) {
		parent[i] = i;
		sizes[i] = 1;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	precompute ();

	int TC;		cin >> TC;
	for (int i = 1; i <= TC; i ++) {

		reset ();
		read ();
		work (i);

	}

return 0;
}