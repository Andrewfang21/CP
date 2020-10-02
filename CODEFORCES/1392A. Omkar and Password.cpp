#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector<int> V(n, 0);
	int maks = -1;
	for (int i = 0; i < n; i ++) {
		scanf("%d", &V[i]);
		maks = max(maks, V[i]);
	}

	int cnt = 0;
	for (int v : V)
		if (v == maks)	cnt ++;

	printf("%d\n", cnt == n ? cnt : 1);
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		solve();
	}

return 0;
}