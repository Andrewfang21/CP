#include<bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int,int,int>> A;
vector<int> V, res;

void read() {
	string str;
	getline(cin, str);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x, y, z;
		cin >> x >> y >> z;
		A.emplace_back(x, y, z);
		V.emplace_back(x);
	}
}

void solve() {
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); i ++) {
		int tmp = i;
		if (i >= get<1>(A[i]) && i <= get<2>(A[i]))
			continue;

		int curr = i - get<1>(A[i]);
		for (int j = 0; j < curr; j ++) {
			swap(A[tmp], A[tmp - 1]);
			tmp --;
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (get<0>(A[i]) == V[j]) {
				res.push_back(j + 1);
				break;
			}
		}
	}
	for (int i = 0; i < res.size(); i ++) {
		if (i == res.size() - 1)
			cout << res[i] << "\n";
		else
			cout << res[i] << " ";
	}
}

int main() {
	read();
	solve();

	return 0;
}