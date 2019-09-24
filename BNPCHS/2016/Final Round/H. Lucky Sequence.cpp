#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 1e5 + 5;

int N, pref[n];

void read () {
	scanf("%d", &N);

	pref[0] = 0;
	for (int i = 1; i <= N; i ++) {
		int X;
		scanf("%d", &X);

		pref[i] = pref[i - 1] + X;
	}
}

void solve (int tc) {
	ll sum = 0, totProb = (N * (N + 1)) / 2;
	for (int i = 1; i <= N; i ++) {
		sum += (i * pref[i]);
		sum -= (N * pref[i]);
		sum += (i * pref[i]);
	}
	
	double res = (double) sum / (double) totProb;
	printf("Kasus #%d: %.3lf\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}