#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e6 + 5, MAXX = 1e7 + 5;

int N, L;
int A[n], dp[n], BIT[MAXX];

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i];
		A[i] ++;
	}
	cin >> L;
}

void update (int idx, int val) {
	while (idx < MAXX) {
		BIT[idx] = max(BIT[idx], val);
		idx += (idx & -idx);
	}
}

int GET (int idx) {
	int res = 0;
	while (idx > 0) {
		res = max(res, BIT[idx]);
		idx -= (idx & -idx);
	}
return res;
}

void work () {
	memset(BIT, 0, sizeof(BIT));
	for (int i = 1; i <= N; i ++)		dp[i] = 1;

	for (int i = 1; i <= N; i ++) {
		if (A[i] == 1) {
			update(1, dp[i]);
			continue;
		}

		int curr_val = GET(A[i] - 1);
		dp[i] += curr_val;

		update(A[i], dp[i]);
	}

	// for (int i = 1; i <= N; i ++)
	// 	cout << i << " " << dp[i] << "    " << A[i] << "\n";

	int res = INT_MAX;
	for (int i = 1; i <= N; i ++)
		if (dp[i] >= L)		res = min(res, A[i] - 1); 

	res != INT_MAX ? cout << res << "\n" : cout << "-1\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);

	int TC;		cin >> TC;
	while (TC -- ) {
		read ();
		work ();
	}
return 0;
}