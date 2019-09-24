#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 1e5 + 5;

int N;
ll cnt[n];

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	ll sum = 0;
	for (int i = 1; i <= N; i ++) {
		int X;		cin >> X;

		for (int j = 1; j <= sqrt(X); j ++) {
			ll temp = X / j;
			
			if (X % j == 0) {
				if (temp != j)
					sum += (cnt[j] + cnt[temp]);
				else
					sum += cnt[j];
			}
		}
		cnt[X] ++;
	}
	cout << sum << "\n";

return 0;
}