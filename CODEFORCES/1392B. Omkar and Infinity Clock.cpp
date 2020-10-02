#include<bits/stdc++.h>
using namespace std;

void print(int A[], int n) {
	for (int i = 0; i < n; i ++)
		printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		long long n, k;
		scanf("%lld %lld", &n, &k);

		int A[n + 5];
		long long maks = LLONG_MIN;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &A[i]);
			maks = max(maks, (long long)A[i]);
		}

		if (k > 1)
			k = k % 2 + 2;
	
		while (k --) {
			maks = LLONG_MIN;
			for (int i = 0; i < n; i ++)
				maks = max(maks, (long long) A[i]);

			for (int i = 0; i < n; i ++)
				A[i] = maks - A[i];
		}
		print(A, n);
	}
}