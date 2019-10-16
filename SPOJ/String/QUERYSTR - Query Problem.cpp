#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int Z[N];

void ZAlgorithm(char s[N]) {
	memset(Z, 0, sizeof(Z));

	int left = 0;
	int right = 0;

	int n = strlen(s);

	Z[0] = n;
	for (int k = 1; k < n; k ++) {
		if (k > right) {
			left = right = k;

			while (right < n && s[right] == s[right - left])
				right ++;

			Z[k] = right - left;
			right --;
		}
		else {
			int k1 = k - left;

			if (Z[k1] < right - k + 1)
				Z[k] = Z[k1];
			else {
				left = k;
				while (right < n && s[right] == s[right - left])
					right ++;

				Z[k] = right - left;
				right --;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		char s[N];
		scanf("%s", s);

		int n = strlen(s);
		reverse(s, s + n);

		ZAlgorithm(s);

		int Q;
		scanf("%d", &Q);

		while (Q --) {
			int query;
			scanf("%d", &query);

			printf("%d\n", Z[n - query]);
		}
	}

return 0;
}