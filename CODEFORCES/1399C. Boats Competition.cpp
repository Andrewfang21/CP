#include<bits/stdc++.h>
using namespace std;

int n;
map<int, int> cnt;

int solve(int s) {
	int res = 0;
	for (int i = 1; i <= s / 2; i ++) {
		if (i == s - i)
			res += cnt[i] / 2;
		else
			res += min(cnt[i], cnt[s - i]);
	}

	return res;
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			cnt[x] ++;
		}

		int res = 0;
		for (int i = 2; i <= 100; i ++) {
			res = max(res, solve(i));
		}

		cout << res << "\n";
		cnt.clear();
	}
}