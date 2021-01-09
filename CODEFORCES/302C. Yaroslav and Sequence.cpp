#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> pos, neg;

	for (int i = 0; i < 2 * n - 1; i ++) {
		int x;
		cin >> x;
		if (x >= 0)	pos.push_back(x);
		else neg.push_back(-x);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int poss = 0, negg = 0;
	for (int x : pos)	poss += x;
	for (int x : neg)	negg += x;

	int res = 0;
	if (neg.empty()) {
		for (int x : pos)	res += x;
		cout << res << "\n";
		return 0;
	}

	for (int x : pos)	res += x;
	for (int x : neg)	res += x;

	if (n % 2 == 0 && neg.size() % 2) {
		if (pos.empty())
			res -= 2 * neg[0];
		else
			res -= 2 * min(neg[0], pos[0]);
	}

	cout << res << "\n";

	return 0;
}