#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

void solve(int tc) {
	char s[N];
	scanf("%s", s);

	int n = strlen(s);
	int Z[N];

	int l, r;
	l = r = 0;
	for (int k = 1; k < n; k ++) {
		if (k > r) {
			l = r = k;
			while (r < n && s[r] == s[r - l])
				r ++;
			Z[k] = r - l;
			r --;
		} else {
			int k1 = k - l;
			if (Z[k1] < r - k + 1)
				Z[k] = Z[k1];
			else {
				l = k;
				while (r < n && s[r] == s[r - l])
					r ++;
				Z[k] = r - l;
				r --;
			}
		}
	}

	int res = 0;
	for (int i = 1; i < n; i ++) {
		if (Z[i] == n - i)	res ++;
	}
	printf("Case %d: %d\n", tc, res);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

	return 0;
}