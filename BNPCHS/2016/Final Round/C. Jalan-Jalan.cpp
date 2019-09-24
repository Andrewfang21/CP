#include<bits/stdc++.h>
using namespace std;

const int n = 1e4 + 5;

int N, K;
int A[n];

void read () {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= K; i ++) {
		scanf("%d", &A[i]);
	}
}

void solve (int tc) {
	sort(A + 1, A + K + 1);

	int currSum, res, pos;
	res = 0, currSum = pos = 1;

	while (currSum <= N) {
		if (pos > K)
			break;

		if (currSum < A[pos]) {
			currSum += currSum;
			res ++;
		} else {
			currSum += A[pos];
			pos ++;
		}
	}
	printf("Kasus #%d: %d\n", tc, res);
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