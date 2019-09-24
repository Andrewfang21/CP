#include<bits/stdc++.h>
using namespace std;

const int n = 105;

int N;
int pref[n];

void solve (int tc) {
	scanf("%d", &N);
	
	pref[0] = 1;
	for (int i = 1; i <= N; i ++) {
		int X;
		scanf("%d", &X);

		pref[i] = pref[i - 1] * X;
	}


	int res = 0;
	for (int i = 1; i <= N; i ++) {
		int X;
		scanf("%d", &X);

		res += (pref[i] * X);
	}
	printf("Kasus #%d: %d\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve (i);
	}

return 0;
}