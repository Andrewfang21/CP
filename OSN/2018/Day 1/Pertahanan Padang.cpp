#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int K = 15, N = 100;

ll odd, even, Q;
ll pref[N];

vector<pair<int, ll> > A;

void impossible () {
	puts("TIDAK MUNGKIN");
	exit(0);
}

void init () {
	while (odd != 0 || even != 0) {
		if (even >= odd) {
			if (odd == 0) 
				impossible();
			
			ll repeat = even / odd;
			even -= repeat * odd;

			A.push_back(make_pair(0, repeat));
		}
		else {
			ll repeat = odd / (even + 1);
			odd -= repeat * (even + 1);

			A.push_back(make_pair(1, repeat));
		}
	} 
}

int main () {
	string subs;
	cin >> subs;	
	cin >> odd >> even >> Q;

	init();
	reverse(A.begin(), A.end());
	
	int idx = 0;
	for (pair<int, ll> pos : A) {
		idx == 0 ? pref[idx] = pos.second : pref[idx] = pref[idx - 1] + pos.second;
		idx ++;
	}
	
	puts("MUNGKIN");
	while (Q --) {
		ll ql, qr;
		cin >> ql >> qr;

		if (qr >= pref[idx - 1]) {
			puts("DI LUAR BATAS");
			continue;
		}

		bool finish = false;
		for (int i = 0; i < A.size(); i ++) {
			if (finish)
				break;

			// Start printing on this segment
			if (i == 0 && pref[i] > ql || i > 0 && pref[i - 1] <= ql && pref[i] > ql) {
				while (ql < pref[i]) {
					cout << A[i].first;
					ql ++;

					if (ql > qr) {
						puts("");
						finish = true;

						break;
					}
				}
			}
		}
	}

return 0;
}