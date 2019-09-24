#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 1e3 + 5;

ll N;
ll X[n], Y[n];

int main() {
	ios_base::sync_with_stdio(false);
	int TC;		cin >> TC;

	while (TC --) {
		cin >> N;
		for (int i = 1; i <= N; i ++)
			cin >> X[i] >> Y[i];

		ll res = LLONG_MAX;
		for (int i = 1; i <= N; i ++) {
			ll maksX, maksY, minX, minY;

			maksX = maksY = LLONG_MIN;
			minX = minY = LLONG_MAX;

			for (int j = 1; j <= N; j ++) {
				if (i != j) {
					maksX = max(maksX, X[j]);
					minX = min(minX, X[j]);

					maksY = max(maksY, Y[j]);
					minY = min(minY, Y[j]);
				}
			}

			ll localRes = (maksX - minX) * (maksY - minY);
			res = min(res, localRes);
		}
		cout << res << "\n";
	}

return 0;
}