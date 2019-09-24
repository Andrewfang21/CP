#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define ll long long
#define MOD 1000000007
using namespace std;

const int n = 2e6 + 5;

ll fakt[n];

void precompute () {
	fakt[0] = 1;
	for (int i = 1; i < n; i ++)
		fakt[i] = (fakt[i - 1] * i) % MOD;
}

ll pangkat (int base, int power) {
	if (power == 0)		return 1;
	if (power == 1)		return base;

	ll temp = pangkat(base, power / 2);	
	if (power % 2 == 1) {
		return((base * temp) % MOD * temp) % MOD;
	} else {
		return (temp * temp) % MOD;
	}
}

ll C (int n, int k) {
	ll res = (fakt[n] * ((pangkat(fakt[n - k], MOD - 2) * pangkat(fakt[k], MOD - 2)) % MOD)) % MOD;
return res;
}

void solve (int tc) {
	int N;
	scanf("%d", &N);

	ll res = C(2 * N, N + 1) % MOD;

	printf("Kasus #%d: %d\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	precompute();

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}