#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int lps[2 * N];

string text;
deque<char> s;

void solve(int tc) {
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

	cout << "Kasus #" << tc << ": " << text;
	for (int i = lps[s.size() - 1]; i < n; i ++)
		cout << s[i];
	cout << "\n";

	s.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		cin >> text;
		n = text.length();

		solve(i);
	}

return 0;
}