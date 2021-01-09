#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i ++)	cin >> a[i];
		for (int i = 0; i < n; i ++)	cin >> b[i];

		sort(b.begin(), b.end(), greater<int>());
		bool flag = true;
		for (int i = 0; i < n; i ++) {
			if (a[i] + b[i] > k) {
				flag = false;
				cout << "No\n";
				break;
			}
		}

		if (flag)
			cout << "Yes\n";
	}

	return 0;
}