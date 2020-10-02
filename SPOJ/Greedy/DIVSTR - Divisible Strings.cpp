#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	cin.ignore();
	while (tc --) {
		string s, t;
		getline(cin, s);
		getline(cin, t);

		int pos = 0;
		int rep = 0;
		for (char c : s) {
			if (c == t[pos]) {
				pos ++;
				if (pos == t.length()) {
					rep ++;
					pos = 0;
				}
			}
		}

		int res = s.length() - t.length() * rep;
		cout << res << "\n";
	}
}