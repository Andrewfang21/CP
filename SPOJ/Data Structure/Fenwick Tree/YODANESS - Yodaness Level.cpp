#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
const int K = 25;
const int LIMIT = 35000;

int n;
int BIT[LIMIT];
string start_mapper[N], finish_mapper[N];

map<string, int> string_mapper;

void read() {
	memset(BIT, 0, sizeof(BIT));
	string_mapper.clear();

	cin >> n;

	string s;
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		start_mapper[i] = s;
		string_mapper[s] = i;
	}

	for (int i = 1; i <= n; i ++) {
		cin >> s;
		finish_mapper[i] = s;
	}
}

void update(int idx) {
	while (idx > 0) {
		BIT[idx] ++;
		idx -= (idx & -idx);
	}
}

int query(int idx) {
	int res = 0;
	while (idx < LIMIT) {
		res += BIT[idx];
		idx += (idx & -idx);
	}

	return res;
}

void solve() {
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		string s = finish_mapper[i];
		int pos = string_mapper[s];

		int cost = query(pos);

		res += abs(pos + cost - i);
		update(pos);
	}

	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	string s;
	while (tc --) {
		read();
		solve();
	}

	return 0;
}