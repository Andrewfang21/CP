#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int n;
		cin >> n;

		map<char, int> m;
		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;
			for (char c : s)
				m[c] ++;
		}

		bool can = true;
		for (char c = 'a'; c <= 'z'; c ++)
			if (m[c] % n != 0) {
				can = false;
				break;
			}

		puts(can ? "YES" : "NO");
	}
}