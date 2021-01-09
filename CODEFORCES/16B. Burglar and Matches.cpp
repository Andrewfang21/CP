#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v;
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		v.emplace_back(y, x);
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());

	long long res = 0;
	for (pair<int, int> p : v) {
		if (n >= p.second) {
			res += p.second * p.first;
			n -= p.second;
		} else {
			res += n * p.first;
			break;
		}
	}

	cout << res << "\n";

	return 0;
}