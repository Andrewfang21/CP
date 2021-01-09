#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;

		if ((a - x) + (b - y) <= n) {
			cout << x * y << "\n"; 
			continue;
		}

		ll tot = min(a - x, n);
		ll rem = n - tot;
		ll res1 = (a - tot) * (b - rem);

		tot = min(b - y, n);
		rem = n - tot;
		ll res2 = (b - tot) * (a - rem);

		cout << min(res1, res2) << "\n";
	}
}