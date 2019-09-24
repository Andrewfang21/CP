#include<bits/stdc++.h>
using namespace std;

int A[5];

void read () {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i ++) {
		int X;
		scanf("%d", &X);

		A[X] ++;
	}
}

void solve (int tc) {
	printf("Kasus #%d: %d\n", tc, min(A[3], min(A[1], A[2])));
	memset(A, 0, sizeof(A));
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}