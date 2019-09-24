#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

struct state {
	int height, width, depth;
};

bool cmp (state lhs, state rhs) {
	if (lhs.width == rhs.width)
		return lhs.depth < rhs.depth;
return lhs.width < rhs.width;
}

int main () {
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N) {

		if (N == 0)		return 0;

		state A[4 * N];
		LL dp[4 * N];

		for (int i = 1; i <= N; i ++) {
			int w, d, h;
			cin >> h >> w >> d;

			A[i].height = h;
			A[i].width = max(w, d);		A[i].depth = min(w, d);
		}

		int M = N;
		for (int i = 1; i <= M; i ++) {
			A[++ N].height = A[i].width;
			A[N].width = max(A[i].height, A[i].depth);		A[N].depth = min(A[i].height, A[i].depth);

			A[++ N].height = A[i].depth;
			A[N].width = max(A[i].height, A[i].width);		A[N].depth = min(A[i].height, A[i].width);
		}

		sort(A + 1, A + N + 1, cmp);

		for (int i = 1; i <= N; i ++)		dp[i] = A[i].height;

		LL res = -1;
		for (int i = 1; i <= N; i ++) 
			for (int j = 1; j < i; j ++) {
				if (A[i].width > A[j].width && A[i].depth > A[j].depth)
					dp[i] = max(dp[i], dp[j] + A[i].height);	

					res = max(res, dp[i]);
			}
		cout << res << "\n";
	}
return 0;
}