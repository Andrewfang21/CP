#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 2e5 + 5;

int N, M, S;
LL dp[n], A[n], B[n], P[n];

vector<LL> valid[n], temp[n];
priority_queue<LL, vector<LL>, greater<LL> > store, notUsed;

void read() {
	cin >> N >> M >> S; 
	for (int i = 1; i <= M; i ++) {
		cin >> A[i] >> B[i] >> P[i];
		valid[A[i]].push_back(i);
	}
}

void solve() {

	for (int i = 1; i <= N; i ++)	dp[i] = LLONG_MAX;

	for (int i = 1; i <= N; i ++) {
		dp[i] = dp[i - 1] + S;		// Buy separately

		for (int j = 0; j < valid[i].size(); j ++) {
			int idx = valid[i][j];

			LL currRes = dp[i - 1] + P[idx];
			store.push(currRes);
			temp[B[idx] + 1].push_back(currRes);
		}

		// List of unused packages
		for (int j = 0; j < temp[i].size(); j ++)
			notUsed.push(temp[i][j]);

		while (!store.empty() && !notUsed.empty()) {
			LL x, y;
			x = store.top();		y = notUsed.top();

			if (x == y)
				store.pop(), notUsed.pop();
			else
				break;
		}

		if (!store.empty()) {
			LL x = store.top();
			dp[i] = min(dp[i], x);
		}
	}
	cout << dp[N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	solve();

return 0;
}
