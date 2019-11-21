#include<bits/stdc++.h>
using namespace std;

int cube(int X) {
	return X * X * X;
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int X;
		cin >> X;

		int res = cube(X) - cube(X - 2);
		cout << res << "\n"; 
	}

return 0;
}