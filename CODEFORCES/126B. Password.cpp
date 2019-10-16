#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
int lps[N];
string s;

void fail() {
	cout << "Just a legend\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;

	int n = s.length();
	for (int i = 1, k = 0; i < n; i ++) {
		while (k > 0 && s[i] != s[k])
			k = lps[k - 1];

		if (s[i] == s[k])
			k ++;

		lps[i] = k;
	}

	if (lps[n - 1] == 0)
		fail();

	for (int i = 0; i < n; i ++) {
		if (lps[i] == lps[n - 1] && i != n - 1) {
			for (int i = 0; i < lps[n - 1]; i ++)
				cout << s[i];
			cout << "\n";

			return 0;
		}
	}

	if (lps[lps[n - 1] - 1] == 0) {
		cout << "Just a legend\n";
		return 0;
	}

	int target = lps[lps[n - 1] - 1];
	for (int i = 0; i < target; i ++)
		cout << s[i];
	cout << "\n";

return 0;
}