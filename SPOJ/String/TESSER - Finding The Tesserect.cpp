#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int A[N], lps[N];
char text[N];

string pattern;

void read() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> A[i];

	cin >> pattern;
}

void KMP() {
	memset(lps, 0, sizeof(lps));
	memset(text, 0, sizeof(text));

	for (int i = 1; i < n; i ++) {
		if (A[i] > A[i - 1])
			text[i - 1] = 'G';
		else if (A[i] == A[i - 1])
			text[i - 1] = 'E';
		else
			text[i - 1] = 'L';
	}

	int k = 0;
	for (int i = 1; i < pattern.length(); i ++) {
		while (k > 0 && pattern[i] != pattern[k])
			k = lps[k - 1];

		if (pattern[i] == pattern[k])
			k ++;

		lps[i] = k;
	}
}

void solve() {
	KMP();

	bool res = false;
	for (int i = 0, k = 0; i < n; i ++) {
		while (k > 0 && text[i] != pattern[k])
			k = lps[k - 1];

		if (text[i] == pattern[k])
			k ++;

		if (k == pattern.length()) {
			res = true;
			break;
		}
	}

	res ? cout << "YES\n" : cout << "NO\n";
}

int main () {
	int tc;
	cin >> tc;

	while (tc --) {
		read();
		solve();
	}

return 0;
}