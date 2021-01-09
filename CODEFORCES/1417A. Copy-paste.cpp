#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int n, k;
		cin >> n >> k;

		vector<int> V(n, 0);
		for (int i = 0; i < n; i ++) {
			cin >> V[i];
		}
		sort(V.begin(), V.end());

		int mins = V[0];
		int res = 0;
		for (int i = 1; i < n; i ++) {
			res += (k - V[i]) / mins;
		}

		cout << res << "\n";
	}
}