#include<bits/stdc++.h>
using namespace std;

void solve (int tc) {
	int N, M;
	scanf("%d %d", &N, &M);

	int res = 1;
	for (int i = 1; i <= N; i ++)
		res = (res * 10) % M;

	printf("Kasus #%d: %d\n", tc, res % M);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve (i);
	} 

return 0;
}