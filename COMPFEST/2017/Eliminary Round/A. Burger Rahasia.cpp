#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int TC;		cin >> TC;
	
	while (TC--) {
		ll A, B, C, sum;
		cin >> A >> B >> C;


		sum = (((A % MOD) * (B % MOD)) % MOD * (C % MOD)) % MOD;
		sum --;

		cout << sum << "\n";
	}
return 0;
}