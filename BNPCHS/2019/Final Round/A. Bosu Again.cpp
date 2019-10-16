#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve (int tc) {
	ll n, res = 0;
	scanf("%lld", &n);

	if (n % 2 == 0) {
		res = n / 2;
		res *= (n + 1);
	} else {
		res = (n + 1) / 2;
		res *= n;
	}

	printf("Case #%d: %lld\n", tc, res);
}

int main () {
	ios_base::sync_with_stdio(false);
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}
