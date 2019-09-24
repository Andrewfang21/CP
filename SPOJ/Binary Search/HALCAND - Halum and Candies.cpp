#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;

int n, k;
ll A[N];

void read () {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i]);
}

bool canAssign (ll tot, ll bound) {
	for (int i = 0; i < k; i ++) {
		if (A[i] >= bound)
			continue;

		if (tot < (bound - A[i]))
			return false;

		tot -= (bound - A[i]);
	}

return true;
}

void solve (int tc) {
	sort (A, A + n, greater<ll>() );

	ll res = A[k - 1];
	for (int i = 0; i < k; i ++)
		A[i] -= res;

	ll sum = 0;
	for (int i = k; i < n; i ++)
		sum += A[i];

	ll l = 0, r = sum, up = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;

		bool cek;
		if (cek = canAssign(sum, mid)) {
			up = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	res += up;
	printf("Case %d: %lld\n", tc, res);
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