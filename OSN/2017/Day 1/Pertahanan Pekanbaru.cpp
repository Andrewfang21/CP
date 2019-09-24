#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 5;

ll n, Sd, Sm;
ll P[N], L[N], K[N];

void read () {
	string subs;
	cin >> subs;

	cin >> n >> Sd >> Sm;
	for (int i = 1; i < n; i ++) {
		cin >> P[i] >> K[i] >> L[i];
	}
}

void solve () {
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	ll res = 0;

	for (int i = 1; i < n; i ++) {
		if (Sd < P[i]) {
			while (!Q.empty() && Sd < P[i]) {
				ll time = Q.top();
				Q.pop();

				Sd ++;
				res += time;
			}

			if (Q.empty() && Sd < P[i]) {
				cout << "-1\n";
				return;
			}

			if (L[i] <= K[i]) {
				Sd ++;
				res += L[i];
			} else {
				Q.push(L[i] - K[i]);
				res += K[i];
			}
		} else {
			if (L[i] <= K[i]) {
				Sd ++;
				res += L[i];
			} else {
				Q.push(L[i] - K[i]);
				res += K[i];
			}
		}
	}

	if (Sd < Sm) {
		while (!Q.empty() && Sd < Sm) {
			ll time = Q.top();
			Q.pop();

			Sd ++;
			res += time;
		}

		if (Q.empty() && Sd < Sm) {
			cout << "-1\n";
			return;
		}
	}

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}
