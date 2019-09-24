#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define LL long long
using namespace std;

LL N, M;

map<LL, LL> height, parent;

LL findset (LL pos) {
	if (parent[pos] == pos)
		return pos;
	else {
		LL x = findset(parent[pos]);
		parent[pos] = x;

		return x;
	}
}

bool same_set (LL A, LL B) {
	LL X, Y;
	X = findset(A);		Y = findset(B);

return X == Y;
}

void merge (LL A, LL B) {
	LL X, Y;
	X = findset(A);		Y = findset(B);

	height[X] > height[Y] ? parent[Y] = X : parent[X] = Y;
	if (height[X] == height[Y])		height[Y] ++;
}

int main () {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	LL res = N;
	for (LL i = 1; i <= M; i ++) {
		LL u, v;

		cin >> u >> v;

		if (parent[u] == 0)		parent[u] = u;
		if (parent[v] == 0)		parent[v] = v;
 
		if (!same_set(u, v)) {
			merge(u, v);
			res --;
		}
	}
	cout << res << "\n";

return 0;
}