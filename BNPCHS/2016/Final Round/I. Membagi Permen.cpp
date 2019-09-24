#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i ++) {
		int N, M;
		scanf("%d %d", &N, &M);

		int res = 0;
		for (int j = 1; j <= N; j ++) {
			if (N % j == M)
				res ++;
		}
		printf("Kasus #%d: %d\n", i, res);
	}

return 0;
}
