#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int pref[N];
char str[N];
vector<char> v;

void read() {
	string s;
	cin >> s;
	cin >> n >> q;

	v.push_back(' ');
	for (int i = 1; i <= n; i ++) {
		cin >> str[i];
		if (str[i] == str[i - 1])
			pref[i] = pref[i - 1];
		else {
			pref[i] = pref[i - 1] + 1;
			v.push_back(str[i]);
		}
	}
}

void solve() {
	while (q --) {
		int l, r;
		cin >> l >> r;

		if (pref[r] - pref[l] + 1 >= 10)
			cout << pref[r] - pref[l] + 1 << "\n";
		else {
			int res = pref[r] - pref[l] + 1;
			cout << res << " ";
			for (int i = pref[l]; i <= pref[r]; i ++)
				cout << v[i];
			puts("");
		}
	}
}

int main() {
	read();
	solve();

	return 0;
}