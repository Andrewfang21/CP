#include<bits/stdc++.h>
using namespace std;

void solve(int curr, int rem, vector<int> &v, map<int, bool> &has) {
	if (rem == 0)
		return;
	if (rem < curr) {
		if (has[rem]) {
			v[v.size() - 1] += rem;
		} else {
			v.push_back(rem);
		}
		return;
	}

	v.push_back(curr);
	has[curr] = true;
	solve(curr + 1, rem - curr, v, has);
}

int main() {
	int n;
	cin >> n;

	vector<int> v;
	map<int, bool> has;
	solve(1, n, v, has);

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i ++) {
		if (i == v.size() - 1)
			cout << v[i] << "\n";
		else
			cout << v[i] << " ";
	}

	return 0;
}
