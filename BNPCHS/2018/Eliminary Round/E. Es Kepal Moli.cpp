#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 3e5 + 5;

int N;
ll A[n], pref[n], suff[n];

void read () {
	scanf("%d", &N);
	for (int i = 1; i <= 3 * N; i ++) {
		scanf("%lld", &A[i]);
	}
}

void solve (int tc) {
	priority_queue<int, vector<int>, greater<int> > QMax;
	priority_queue<int, vector<int> > QMin;

	memset(pref, 0, sizeof(pref));
	memset(suff, 0, sizeof(suff));

	for (int i = 1; i <= N; i ++) {
		pref[i] = pref[i - 1] + A[i];
		QMax.push(A[i]);
	}

	for (int i = N + 1; i <= 2 * N; i ++) {
		pref[i] = pref[i - 1] - QMax.top() + A[i];

		QMax.pop();
		QMax.push(A[i]);
	}

	for (int i = 3 * N; i > 2 * N; i --) {
		suff[i] = suff[i + 1] + A[i];
		QMin.push(A[i]);
	}

	for (int i = 2 * N; i > N; i --) {
		suff[i] = suff[i + 1] - QMin.top() + A[i];

		QMin.pop();
		QMin.push(A[i]);
	}

	ll res = LLONG_MIN;
	for (int i = N; i <= 2 * N; i ++) {
		res = max(res, pref[i] - suff[i + 1]);
	}

	printf("Kasus #%d: %lld\n", tc, res);
}

int main () {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {
		read ();
		solve (i);
	}

return 0;
}