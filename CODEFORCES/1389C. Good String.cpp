#include<bits/stdc++.h>
using namespace std;

int solve(string s, int x, int y) {
	int res = 0;
	for (char c : s) {
		if (c - '0' == x)
			res ++, swap(x, y);
	}

	if (res % 2 && x != y)
		res --;

	return res;
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		string s;
		cin >> s;

		int res = 0;
		for (int i = 0; i <= 9; i ++)
			for (int j = 0; j <= 9; j ++)
				res = max(res, solve(s, i, j));

		cout << s.length() - res << "\n";
	}
}