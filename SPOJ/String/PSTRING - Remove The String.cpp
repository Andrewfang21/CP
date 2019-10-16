#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5, MAXM = 1e3 + 5, K = 30, inf = INT_MAX;

int n, m;
int suff[MAXN][K], lps[MAXN], dp[MAXN][MAXM];

char text[MAXN], pattern[MAXM];

void generateLPS() {
	for (int i = 1, k = 0; i < m; i ++) {
		while (k > 0 && pattern[i] != pattern[k])
			k = lps[k - 1];

		if (pattern[i] == pattern[k])
			k ++;

		lps[i] = k;		
	}
}

int solve(int pos, int matchedLen) {
	if (pos == n)
		return 0;
	if (dp[pos][matchedLen] != -1)
		return dp[pos][matchedLen];

	int currMatched = suff[matchedLen][text[pos] - 'a'];
	int res = inf;

	if (currMatched == m)
		res = solve(pos + 1, matchedLen) + 1;
	else {
		res = min(solve(pos + 1, currMatched),
				  solve(pos + 1, matchedLen) + 1);
	}

return dp[pos][matchedLen] = res;
}

void work() {
	generateLPS();

	memset(suff, 0, sizeof(suff));
	for (int i = 0; i < m; i ++) {
		for (char c = 'a'; c <= 'z'; c ++) {
			int k = i;
			while (k > 0 && pattern[k] != c)
				k = lps[k - 1];

			if (pattern[k] == c)
				k ++;

			suff[i][c - 'a'] = k;
		}
	}

	memset(dp, -1, sizeof(dp));
	int res = solve(0, 0);

	printf("%d\n", res);
}

int main() {
	while (scanf("%s %s", text, pattern) != EOF) {
		n = strlen(text);
		m = strlen(pattern);

		work();
	}

return 0;
}