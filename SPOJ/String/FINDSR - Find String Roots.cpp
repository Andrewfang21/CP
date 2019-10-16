#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int lps[N];

char text[N];

void solve() {
	memset(lps, 0, sizeof(lps));
	for (int i = 1, k = 0; i < n; i ++) {
		while (k > 0 && text[i] != text[k])
			k = lps[k - 1];

		if (text[i] == text[k])
			k ++;

		lps[i] = k;
	}
	
	if (n % (n - lps[n - 1]) == 0)
		printf("%d\n", n / (n - lps[n - 1]));
	else
		printf("1\n");
}

int main () {
	while (scanf("%s", text) != EOF) {
		if (text[0] == '*')
			break;

		n = strlen(text);
		solve();
	}

return 0;
}