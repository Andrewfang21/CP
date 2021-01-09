#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, l;
	cin >> k >> l;

	int res = 0;
	while (true) {
		if (l == 1)
			break;

		if (l % k == 0) {
			l /= k;
			res ++;
		} else {
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	cout << res - 1 << "\n";

	return 0;
}