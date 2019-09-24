#include<bits/stdc++.h>
using namespace std;

void solve (int tc) {
	long long x, y;
	cin >> x >> y;

	string res = "";
	if (-x == y)
		res = "Nol";
	else if (-x < y)
		res = "Positif";
	else res = "Negatif";

	cout << "Kasus #" << tc << ": " << res << "\n";
}

int main () {
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		solve (i);
	}

return 0;
}