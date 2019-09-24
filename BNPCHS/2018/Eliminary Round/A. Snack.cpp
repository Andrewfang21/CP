#include<bits/stdc++.h>
using namespace std;

void solve (int tc) {
	int N, K;
	scanf("%d %d", &N, &K);

	printf("Kasus #%d: %s\n", tc, N % (K + 1) == 0 ? "ya" : "tidak");	
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}