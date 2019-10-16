#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int lps[2 * N];

string text;
deque<char> s;

void solve() {
	memset(lps, 0, sizeof(lps));

	int c = 0;
	for (int i = 0; i < n; i ++)
		s.push_front(text[n - i - 1]);

	for (int i = 0; i < n; i ++)
		s.push_front(text[i]);

	for (int i = 1, k = 0; i < s.size(); i ++) {
		while (k > 0 && s[i] != s[k])
			k = lps[k - 1];

		if (s[i] == s[k])
			k ++;

		lps[i] = k;
	}

	cout << text;
	for (int i = lps[s.size() - 1]; i < n; i ++)
		cout << s[i];
	cout << "\n";

	s.clear();
}

int main() {

	while (cin >> text) {
		n = text.length();
		solve();
	}

return 0;
}