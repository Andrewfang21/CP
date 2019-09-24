#include<bits/stdc++.h>
#define ll long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 5, MAXX = 1e7 + 5;

ll N, K, BIT[MAXX];
bool used[n];

void update (int idx, int val) {
	while (idx < MAXX) {
		BIT[idx] = max(BIT[idx] + val, 0LL);
		idx += (idx & -idx);
	}
}

ll query (int idx) {
	ll res = 0;
	while (idx > 0) {
		res += BIT[idx];
		idx -= (idx & -idx);
	}
return res;
}

ll getMaxInv (ll val) {
	ll res = val * (val - 1) / 2;
return res;
}

void solve () {
	scanf("%lld %lld", &N, &K);
	ll maxPoss = N * (N - 1) / 2;

	if (maxPoss < K) 
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i ++) 
			update(i, 1);

		vector<int> V;
		for (int i = 1; i <= N; i ++) {
			ll check = getMaxInv(N - V.size() - 1) + query(i);
			if (check >= K) {
				used[i] = true;
				V.push_back(i);

				update(i + 1, -1);

				if (check == K)
					break;
			}			
		}

		for (int i = N; i >= 1; i --) {
			if (!used[i])
				V.push_back(i);
		}

		for (int i = 0; i < V.size(); i ++) {
			i == V.size() - 1 ? printf("%d\n", V[i]) : printf("%d ", V[i]);
		}
	}
}

int main () {
	solve();

return 0;
}