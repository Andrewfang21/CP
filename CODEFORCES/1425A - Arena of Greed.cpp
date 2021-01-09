#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll n) {
	if (n < 5)
		return max(1ll, n - 1);
	else if (n % 2 == 1 || n % 4 == 0)
		return n - solve(n - 1);

return n - solve(n / 2);
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		ll n;
		cin >> n;
		cout << solve(n) << "\n";
	}
}