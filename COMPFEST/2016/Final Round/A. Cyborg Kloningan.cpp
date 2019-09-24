#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 2e5 + 5;

ll N, K, A[n];

void read () {
	cin >> N >> K;
	for (int i = 1; i <= K; i ++)
		cin >> A[i];		
}

void solve () {
	ll totJurus = A[K], maks = LLONG_MAX;
	for (int i = 1; i <= K; i ++)
		maks > A[i] ? maks = A[i] : maks = maks;

	for (int i = 1; i <= K; i ++) {
		if (i != K)
			totJurus += (A[i] - N);
		if (totJurus < 0)
			break;
	}

	ll mins;
	if (totJurus < 0)
		mins = 0;
	else mins = totJurus;

	cout << mins << " " << maks << "\n";
}

int main () {
	read();
	solve();

return 0;
}