#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL MOD = 1e9 + 7;

int N, M;

void solve() {
	cin >> N >> M;
	
	LL Un, Sn, res = 0;
	for (int i = 1; i <= N; i ++) {
		Un = i + (i - 1) * M;
		Sn = (i * (i + Un)) / 2;

		res = (res + Sn % MOD) % MOD;
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();

return 0;
}