#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
long long pref[N];
map<long long, long long> exist;

void read() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		long long x;
		cin >> x;

		pref[i] = pref[i - 1] + x;
		exist[pref[i]] ++;
	}
}

void solve() {
	long long res = 0;
	for (auto &it : exist) {
		res += (it.second * (it.second - 1)) / 2;
		if (it.first == 0)
			res += it.second;
	}

	cout << res << "\n";
	exist.clear();
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		read();
		solve();
	}

return 0;
}