#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, m;
ll A[N], pref[N];

void read () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> A[i];
	}
}

void solve () {
	pref[0] = 0;
	for (int i = 1; i <= n; i ++)
		pref[i] = pref[i - 1] + A[i];

	ll res = 0;
	for (int i = 1; i <= n; i ++) {
		if (i + m > n)
			break;

		ll curr = pref[i + m] - pref[i - 1];
		res = max(res, curr);
	}

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}