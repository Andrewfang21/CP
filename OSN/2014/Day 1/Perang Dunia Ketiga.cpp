#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n; 
long long A[N], cnt[N], pref[N][2];

void read() {
	char s[20];
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%lld", &A[i]);
		cnt[A[i]] ++;
		if (A[i] == 0)
			pref[0][0] ++;
	}
}

void solve() {
	sort(A, A + n);
	for (int i = 1; i < 2000000; i ++) {
		pref[i][0] = pref[i - 1][0] + cnt[i];
		pref[i][1] = pref[i - 1][1] + i * cnt[i];
	}

	if (A[n - 1] == 0) {
		printf("%d\n", n);
		return;
	}

	long long res = LLONG_MAX;
	for (int i = 1; i <= A[n - 1]; i += 2) {
		long long sum, tmp;
		sum = tmp = 0;

		for (int j = i; j < 2000000; j *= 2) {
			if (tmp == 0 && pref[0][0] != 0)
				sum += j * pref[j][0] - pref[j][1];
			else
				sum += j * (pref[j][0] - pref[tmp][0]) - (pref[j][1] - pref[tmp][1]);

			tmp = j;
		}
		res = min(res, sum);
	}

	printf("%lld\n", res);
}

int main() {
	read();
	solve();

	return 0;
}