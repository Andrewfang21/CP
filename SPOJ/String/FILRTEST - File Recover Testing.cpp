#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int lps[N];
char s[N];

int main() {
	ios_base::sync_with_stdio(false);

	long long totalLen;
	while (scanf("%lld %s", &totalLen, s) != EOF) {
		if (totalLen == -1 && s[0] == '*')
			break;

		int n = strlen(s);

		if (totalLen < n) {
			printf("0\n");
			continue;
		}

		for (int i = 1, k = 0; i < n; i ++) {
			while (k > 0 && s[i] != s[k])
				k = lps[k - 1];

			if (s[i] == s[k])
				k ++;

			lps[i] = k;
		}

		int len = lps[n - 1];
		long long res = 1 + (totalLen - n) / (n - len);

		printf("%lld\n", res);
	}

return 0;
}