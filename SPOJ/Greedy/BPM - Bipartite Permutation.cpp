#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		int n;
		scanf("%d", &n);

		int res[4] = {0, 1, 1, 0};
		printf("Case %d: %d\n", i, res[n % 4]);
	}

	return 0;
}