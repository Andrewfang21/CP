#include<bits/stdc++.h>
using namespace std;

const int N = 2000;

int n;
int dp[2][N];

vector<tuple<int,int>> v;
priority_queue<int,vector<int>,greater<int>> q[N];

void read() {
	string str;
	cin >> str;
	cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;

		q[y].push(x);
		if (q[y].size() > 1800 / y)
			q[y].pop();
	}

	for (int i = 1; i <= 1800; i ++) {
		while (!q[i].empty()) {
			v.emplace_back(q[i].top(), i);
			q[i].pop();
		}
	}
	v.emplace_back(-1, -1);
}

double toRadian(double x) {
	return x * acos(-1) / 180.0;
}

void solve() {
	sort(v.begin(), v.end(), [&](tuple<int,int> &l, tuple<int,int> &r) {
		if (get<0>(l) == get<0>(r))
			return get<1>(l) > get<1>(r);
		return get<0>(l) < get<0>(r);
	});

	memset(dp, -1, sizeof(dp));
	dp[0][0] = dp[1][0] = 0;

	for (int i = 1; i < v.size(); i ++) {
		for (int j = 1; j <= 1800; j ++) {
			dp[i & 1][j] = dp[(i + 1) & 1][j];

			int l, r;
			tie(l, r) = v[i];
			int rem = j - r;

			if (rem >= 0 && dp[(i + 1) & 1][rem] != -1) {
				dp[i & 1][j] = max(dp[i & 1][j], max(
					dp[(i + 1) & 1][rem], l));
			}
		}
	}

	double res = .0;
	for (int i = 1; i <= 1800; i ++) {
		int speed = dp[(v.size() + 1) & 1][i];
		if (speed == -1)
			continue;

		double curr = abs(2 * speed * speed * sin(toRadian(i / 10.0)) * cos(toRadian(i / 10.0)) * 9.80);
		res = max(res, curr);
	}

	cout << setprecision(8) << fixed << res << "\n";
}

int main() {
	read();
	solve();

	return 0;
}