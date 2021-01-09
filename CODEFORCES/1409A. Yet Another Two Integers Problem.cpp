#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int a, b;
		cin >> a >> b;

		int maks = max(a, b), mins = min(a, b);
		if (maks == mins) {
			puts("0");
			continue;
		}
		else if (maks - mins <= 10) {
			puts("1");
			continue;
		}

		int tot = (maks - mins) / 10;
		int rem = (maks - mins) % 10;
		cout << tot + (rem != 0) << "\n";
	}
}