#include<bits/stdc++.h>
using namespace std;

int main() {
	string x, z;
	cin >> x >> z;

	string y = "";
	for (int i = 0; i < x.length(); i ++) {
		if (z[i] > x[i]) {
			cout << "-1\n";
			return 0;
		}
		y += min(z[i], x[i]);
	}

	cout << y << "\n";

	return 0;
}