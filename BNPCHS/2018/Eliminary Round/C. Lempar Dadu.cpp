#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

bool canWin (ll val) {
	ll nom, denom;

	nom = val * val;
	denom = N * N;

	if (nom > denom - nom)
		return true;

return false;
}

void solve (int tc) {
	scanf("%lld", &N);

	ll l, r, res = -1;
	l = 1, r = N - 1;

	while (l <= r) {
		ll mid = (l + r) / 2;
		if (canWin(mid)) {
			r = mid - 1;
			res = mid;
		} else l = mid + 1;
	}

	printf("Kasus #%d: %lld\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve (i);
	}

return 0;
}