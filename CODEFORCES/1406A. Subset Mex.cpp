#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int n;
		cin >> n;

		vector<int> v(n, 0);
		for (int i = 0; i < n; i ++)
			cin >> v[i];

		sort(v.begin(), v.end());

		bool used[n + 5];
		memset(used, false, sizeof(used));
		int curr1 = -1, curr2 = -1;
		for (int i = 0; i < n; i ++) {
			if (v[i] == curr1 + 1 && !used[i]) {
				used[i] = true;
				curr1 = v[i];
			} else if (v[i] == curr2 + 1 && !used[i]) {
				used[i] = true;
				curr2 = v[i];
			}
		}

		cout << curr1 + curr2 + 2 << "\n";
	}
}