#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 1e5 + 5;

LL N, res;
LL parent[n], height[n], sizes[n];

map<string, LL> V;

int findset (int pos) {
	if (parent[pos] == pos)
		return pos;
	else {
		int X = findset(parent[pos]);
		parent[pos] = X;

		return X;
	}
}

void merge (int A, int B) {
	int X, Y;
	X = findset(A);		Y = findset(B);

	if (height[X] >= height[Y]) {
		parent[Y] = X;
		sizes[X] += sizes[Y];		sizes[Y] = 0;

		res = sizes[X];
	}
	else {
		parent[X] = Y;
		sizes[Y] += sizes[X];		sizes[X] = 0;

		res = sizes[Y];
	}

	if (height[X] == height[Y])		height[X] ++;
}

bool same_set (int A, int B) {
	int X, Y;
	X = findset(A);		Y = findset(B);

return X == Y;
}

int main () {
	ios_base::sync_with_stdio(false);
//	cin.tie(0);		cout.tie(0);

	int TC;		cin >> TC;
	while (TC --) {
		V.clear();
		cin >> N;

		int num = 0;
		for (int i = 1; i <= N; i ++) {
			string A, B;
			cin >> A >> B;

			if (!V[A]) {
				V[A] = ++ num;
				parent[V[A]] = num;		sizes[V[A]] = 1;
			}
			if (!V[B]) {
				V[B] = ++ num;
				parent[V[B]] = num;		sizes[V[B]] = 1;
			}

			if (!same_set(V[A], V[B]))
				merge(V[A], V[B]);
			else
				res = max(sizes[parent[V[A]]], sizes[parent[V[B]]]);

			cout << res << "\n";
		}
	}
return 0;
}