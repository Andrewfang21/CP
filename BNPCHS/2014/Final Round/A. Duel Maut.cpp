#include<bits/stdc++.h>
using namespace std;

const int n = 105;

int A[n], B[n];

int main() {
	ios_base::sync_with_stdio(false);
	int TC;		scanf("%d", &TC);

	for (int tc = 1; tc <= TC; tc ++) {
		int N, M;
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i ++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= M; i ++)
			scanf("%d", &B[i]);
			
		int res = INT_MAX;
		for (int i = 1; i <= N; i ++) 
			for (int j = 1; j <= M; j ++) {
				int currVal = abs(A[i] - B[j]);
				res = min(res, currVal);
			}

		printf("Kasus #%d: %d\n", tc, res);
	}

return 0;
}
