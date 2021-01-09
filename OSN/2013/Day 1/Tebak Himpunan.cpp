#include<bits/stdc++.h>
using namespace std;

int n, k, q;

void solve_linear() {
	vector<int> v;
	for (int i = 1; i <= n; i ++) {
		cout << "1 " << i << endl;
		string resp;
		cin >> resp;
		if (resp[0] == 'y')
			return;
		else if (resp[0] == 'b')
			v.push_back(i);
	}

	cout << v.size();
	for (int x : v)
		cout << " " << x;
	cout << endl;
}

void solve_binser() {
	int l, r, up;
	l = 1, r = n, up = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		cout << "1 " << mid << endl;
		string resp;
		cin >> resp;
		if (resp[0] == 'b') {
			up = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << up;
	for (int i = 1; i <= up; i ++)
		cout << " " << i;
	cout << endl;
}

void solve_general() {
	set<int> s;
	bool cant[n + 5];
	memset(cant, false, sizeof(cant));

	for (int i = 1; i < n; i ++) {
		bool can = true;
		for (int j = i + 1; j <= n; j ++) {
			if (cant[i] && cant[j])
				continue;

			cout << "2 " << i << " " << j << endl;
			string resp;
			cin >> resp;
			if (resp[0] == 'b' && s.find(j) == s.end() && !cant[j]) {
				s.insert(j);
			} else if (resp[0] == 't') {
				cant[i] = cant[j] = true;
				s.erase(i);
				s.erase(j);
				can = false;
			} else if (resp[0] == 'y') {
				return;
			}
		}

		if (can && s.find(i) == s.end() && !cant[i])
			s.insert(i);
	}

	cout << s.size();
	for (const auto &k : s)
		cout << " " << k;
	cout << endl;

	string resp;
	cin >> resp;
	if (resp[0] == 'y')
		return;
	else if (resp[0] == 'b') {
		for (const auto &k : s) {
			s.erase(k);
			cout << s.size();
			for (const auto &kk : s) {
				cout << " " << kk;
			}
			cout << endl;
			string resp;
			cin >> resp;
			if (resp[0] == 'y')
				return;

			s.insert(k);
		}
	}
}

int main() {
	string x, y;
	cin >> x >> y;
	cin >> n >> k >> q;

	if (y[0] == '3' || y[0] == '4') {
		solve_linear();
	} else if (y[0] == '5') {
		solve_binser();
	} else solve_general();

	return 0;
}