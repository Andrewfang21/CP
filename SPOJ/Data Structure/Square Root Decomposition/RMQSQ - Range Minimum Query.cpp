#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 5;

int N, blockCount, blockSize;
LL segment[n], A[n];

void build_segment () {
	int currPos = -1;

	blockSize = sqrt(N);

	int currMax;
	for (int i = 0; i < N; i ++) {
		if (i % blockSize == 0) {
  			currPos ++;
  			segment[currPos] = A[i];
		}

		segment[currPos] = min(segment[currPos], A[i]);
	}
}

int query (int L, int R) {
	LL res = LLONG_MAX;

	while (L <= R && L % blockSize != 0)
		res = min(res, A[L ++]);
	
	while (L + blockSize <= R) {
		res = min(res, segment[L / blockSize]);
		L += blockSize;
	}

	while (L <= R)
		res = min(res, A[L ++]);

return res;
}

int main () {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> A[i];

	build_segment();

	// for (int i = 0; i < blockCount; i ++)
	// 	cout << i << "  " << segment[i] << "\n";

	int Q;		cin >> Q;
	while (Q --) {
		int L, R;
		cin >> L >> R;

		cout << query(L, R) << "\n";
	}

return 0;
}