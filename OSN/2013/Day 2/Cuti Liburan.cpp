#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int K = 505;
const int INF = 3e4 + 5;

short n, p, q;
short dp[N][K][N][2];

vector<tuple<short,short,short>> v;

void read() {
	string str;
	getline(cin, str);

	cin >> n >> p >> q;
	for (int i = 0; i < n; i ++) {
		int b, d, w;
		cin >> b >> d >> w;
		v.emplace_back(b, d, w);
	}
}

short maks(short x, short y) {
	return (x > y ? x : y);
}

short work(short i, short j, short k, short flag) {
	if (j < 0)
		return -INF;
	else if (j >= 0 && i < 0) {
		if (k < q)
			return -INF;
		return 0;
	}
	if (dp[i][j][k][flag] != -1)
		return dp[i][j][k][flag];

	short res = -1;
	if (get<2>(v[i]) != get<2>(v[i - 1])) {
		res = maks(work(i - 1, j, k, 0), work(i - 1, j - get<0>(v[i]), k + 1 - flag, 0) + get<1>(v[i]));
	} else {
		if (flag == 0)
			res = maks(work(i - 1, j, k, 0), work(i - 1, j - get<0>(v[i]), k + 1, 1) + get<1>(v[i]));
		else
			res = maks(work(i - 1, j, k, 1), work(i - 1, j - get<0>(v[i]), k, 1) + get<1>(v[i]));
	}

	return dp[i][j][k][flag] = res;
}

void solve() {
	sort(v.begin(), v.end(), [&](tuple<short,short,short> &l, tuple<short,short,short> &r) {
		return get<2>(l) < get<2>(r);
	});
	memset(dp, -1, sizeof(dp));

	short res = work(n - 1, p, 0, 0);
	if (res > 0)
		cout << res << "\n";
	else
		puts("-1");
}

int main() {
	read();
	solve();

	return 0;
}