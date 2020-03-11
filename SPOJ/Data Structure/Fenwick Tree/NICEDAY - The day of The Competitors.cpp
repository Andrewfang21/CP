#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
int BIT[N];

struct state {
	int c1, c2, c3;
}A[N];

bool compare(state lhs, state rhs) {
	return lhs.c1 < rhs.c1;
}

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d %d %d", &A[i].c1, &A[i].c2, &A[i].c3);
}

void update(int idx, int value) {
	while (idx < N) {
		BIT[idx] = min(BIT[idx], value);
		idx += (idx & -idx);
	}
}

int get(int idx) {
	int res = INT_MAX;
	while (idx > 0) {
		res = min(res, BIT[idx]);
		idx -= (idx & -idx);
	}

return res;
}

void solve() {
	sort(A, A + n, compare);

	for (int i = 0; i < N; i ++)	BIT[i] = INT_MAX;

	int res = 0;
	for (int i = 0; i < n; i ++) {
		int currRank = get(A[i].c2);

		if (currRank > A[i].c3)
			res ++;

		update(A[i].c2, A[i].c3);
	}

	printf("%d\n", res);
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read();
		solve();
	}

return 0;
}