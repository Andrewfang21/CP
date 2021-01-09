#include<bits/stdc++.h>
using namespace std;

const int N = 25;
const int MOD = 1e9 + 7;

int n, m, zero_cnt;
long long A[N][N];
vector<tuple<int,int,int>> v;

void read () {
	string sub;
	getline(cin, sub);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> A[i][j];
			if (A[i][j] == 0)
				zero_cnt ++;
		}
}

long long power(long long b, long long p) {
	if (p == 0) {
		return 1;
	} else if (p == 1) {
		return b;
	}

	long long tmp = power(b, p / 2) % MOD;
	if (p % 2 == 0)
		return (tmp % MOD * tmp % MOD) % MOD;

	return ((b % MOD * tmp % MOD) % MOD * tmp % MOD) % MOD;
}

long long get(long long num, long long piv) {
	int l = 0;
	int r = 30;

	int up = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long curr = num * power(2, mid);
		if (curr < piv) {
			up = mid;
			l = mid + 1;
		} else if (curr > piv) {
			r = mid - 1;
		} else return mid;
	}

	return up;
}

bool all_same (int pos) {
	for (int i = 2; i <= n; i ++) {
		if (A[i][pos] != A[i - 1][pos])
			return false;
	}

	return true;
}

void multiply(int pos, int k) {
	for (int i = 1; i <= m; i ++)
		A[pos][i] = (A[pos][i] % MOD * power(2, k) % MOD) % MOD;
}

int search() {
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++)
			if (A[i][j] == 0)
				res ++;
	}
	return res;
}

void solve() {
	int tot = n * m;
	int pos = 1;
	while (zero_cnt < tot) {
		int res = 0;
		for (int i = 1; i <= n; i ++) {
			if (A[i][pos] == 0)
				res ++;
		}
		if (res == n) {
			pos ++;
			continue;
		}
		if (res < n && res != 0) {
			v.emplace_back(1, pos, 1);
			for (int i = 1; i <= n; i ++)
				A[i][pos] ++;
		}

		long long maks = -1;
		for (int i = 1; i <= n; i ++)
			maks = max(A[i][pos], maks);

		for (int i = 1; i <= n; i ++) {
			if (A[i][pos] < maks) {
				long long k = get(A[i][pos], maks);
				if (k == 0)
					continue;

				v.emplace_back(3, i, k);
				multiply(i, k);
			}
		}

		if (all_same(pos)) {
			v.emplace_back(2, pos, A[1][pos]);
			for (int i = 1; i <= n; i ++) {
				A[i][pos] = 0;
			}
			pos ++;
		} else {
			long long mins = INT_MAX;
			for (int i = 1; i <= n; i ++)
				mins = min(mins, A[i][pos]);

			mins --;
			v.emplace_back(2, pos, mins);

			for (int i = 1; i <= n; i ++)
				A[i][pos] -= mins;
		}

		zero_cnt = search();
	}
}

void print() {
	cout << v.size() << "\n";
	for (tuple<int,int,int> t : v) {
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read();
	solve();
	print();
	
	
return 0;
}
