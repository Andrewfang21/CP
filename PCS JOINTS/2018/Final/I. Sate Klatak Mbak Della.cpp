#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5 + 5, MAXX = 1e13 + 5;

ll n, dp[N];

map<ll, ll> BIT;

struct state {
	int start,finish,profit;

}v[N];

bool cmp (state lhs, state rhs) {
	if (lhs.finish == rhs.finish)
		return lhs.start < rhs.start;
		
return lhs.finish < rhs.finish;
}

void update (ll idx, ll val) {
	while (idx < MAXX) {
		BIT[idx] = max(BIT[idx], val);
		idx += (idx & -idx);
	}
}

ll sum (ll idx) {
	ll res = 0;

	if (idx == 0)
		return idx;

	while (idx > 0) {
		res = max(res, BIT[idx]);
		idx -= (idx & -idx);
	}

return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		ll a, b, c;
		cin >> a >> b >> c;

		v[i].start = a;
		v[i].finish = a + c;
		v[i].profit = b;
	}

	sort (v + 1, v + n + 1, cmp);
	ll res = v[1].profit;
	
	for (int i = 1; i <= n; i ++) {
		ll prevs = sum(v[i].start);
		dp[i] = prevs + v[i].profit;

		update(v[i].finish, dp[i]);
		res = max(res, dp[i]);
	}

	cout << res << "\n";
	
return 0;
}
