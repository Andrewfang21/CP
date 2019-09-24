#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, A[N], pref[N];

void read () {
	scanf("%d", &n);

	pref[0] = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &A[i]);
		pref[i] = pref[i - 1] + A[i];
	}
}

void solve () {
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		int currRes = -1;

		for (int j = i; j <= n; j ++) {
			int bef = pref[i - 1];
			int aft = pref[n] - pref[j];

			int len = j - i + 1;
			int ones = pref[j] - pref[i - 1];
			int zeros = len - ones;

			currRes = max(currRes, bef + aft + zeros);
		}

		res = max(res, currRes);
	}

	printf("%d\n", res);
}

int main () {
	read ();
	solve ();

return 0;
}