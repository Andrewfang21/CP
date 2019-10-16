#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int lps[N];
char s[N];

void solve(int tc) {
	int n;
	scanf("%d", &n);
	scanf("%s", s);

	for (int i = 1, k = 0; i < n; i ++) {
		while (k > 0 && s[i] != s[k])
			k = lps[k - 1];

		if (s[i] == s[k])
			k ++;

		lps[i] = k;
	}

	printf("Test case #%d\n", tc);
	for (int i = 1; i <= n; i ++) {
		if (i % (i - lps[i - 1]) == 0 && lps[i - 1] > 0) {
			printf("%d %d\n", i, i / (i - lps[i - 1]));
		}
	}
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}