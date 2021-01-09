#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int K = 1e6 + 5;
const long long MOD = 1e9 + 7;

long long n, m, k;
long long C[N][N];
char s[K], shop[K];

void read() {
	scanf("%s", s);
	scanf("%lld %lld %lld", &n, &m, &k);
	scanf("%s", shop);
}

long long power(long long b, long long p) {
	if (p == 0)
		return 1;
	else if (p == 1)
		return b % MOD;

	long long tmp = power(b, p / 2);
	if (p % 2)
		return (b % MOD * (tmp % MOD * tmp % MOD) % MOD) % MOD;

	return (tmp % MOD * tmp % MOD) % MOD;
}

void precompute() {
	for (int i = 0; i <= m; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (j == 0 || i == 0)
				C[i][j] = 1;
			else 
				C[i][j] = (C[i-1][j-1] % MOD + C[i-1][j] % MOD) % MOD;
		}
	}
}

void solve() {
	if (s[8] == '8' || s[9] == '9') {
		long long res = power(power(2, m), n - 1) % MOD;
		long long x, y;
		x = y = 1;
		for (int i = m; i > m - k; i --)
			x = (x % MOD * i % MOD) % MOD;

		for (int i = 1; i <= k; i ++)
			y = (y % MOD) * (i % MOD) % MOD;

		long long tmp = (x % MOD * power(y, MOD - 2) % MOD) % MOD;
		res = (res % MOD * (tmp % MOD)) % MOD;
		printf("%lld\n", res);

		return;
	}

	precompute();
	long long res = (power(power(2, m), n - 1) % MOD * C[m][k] % MOD) % MOD;
	printf("%lld\n", res);	
}

int main() {
	read();
	solve();

	return 0;	
}