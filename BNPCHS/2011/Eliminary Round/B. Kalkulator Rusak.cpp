#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll pangkat (int base, int power) {
	if (power == 0)
		return 1;
	if (power == 1)
		return base;
		
	ll temp = pangkat (base, power / 2) % MOD;
	
	if (power % 2 == 1)
		return ((temp * temp) % MOD * base) % MOD;

return (temp * temp) % MOD;
}

int main () {
	ios_base::sync_with_stdio(false);
	int TC;		cin >> TC;
	
	while (TC --) {
		ll N, M;
		cin >> N >> M;
		
		bool exist = false;
		ll res = 0;
		
		for (int i = 1; i <= N; i ++) {
			ll num;			cin >> num;
			
			if (num == 0)
				exist = true;
		}
		
		for (int i = 1; i <= M; i ++) {
			if (!exist)
				res = (res % MOD + pangkat(N, i) % MOD) % MOD;
			else {
				if (i == 1)
					res = (res + N) % MOD;
				else
					res = (res + ((N - 1) % MOD * pangkat(N, i - 1) % MOD)) % MOD;
			}
		}
		
		cout << res << "\n";
	}
return 0;
}