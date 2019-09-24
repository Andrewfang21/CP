#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 505;

LL N, K;
LL A[n], MIN;

void read () {
	cin >> N >> K;

	MIN = -1;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i];
		MIN = max(MIN, A[i]);
	}
}

LL proses (LL len) {
	LL curr_len, blocks;

	curr_len = len;		blocks = 1;
	for (int i = 1; i <= N; i ++) {
		if (curr_len < A[i]) {
			curr_len = len;
			blocks ++;
		}
		curr_len -= A[i];
	}
return blocks;
}

void print (int len) {
	//cout << len << "\n";
	int curr_len, blocks_rem;

	bool slash[n];
	memset(slash, false, sizeof(slash));

	curr_len = len;		blocks_rem = K - 1;
	for (int i = N; i >= 1; i --) {
		if (i == blocks_rem)
		{
			slash[i] = true;	
			blocks_rem --;
		}
		else {
			if (curr_len < A[i]) {
				curr_len = len;
				slash[i] = true;
				blocks_rem --;
			}
			curr_len -= A[i];
		}
	}

	// for (int i = 1; i <= N; i ++)
	// 	cout << i << "  " << slash[i] << "\n";

	for (int i = 1; i <= N; i ++) {
		if (slash[i]) {
			cout << A[i] << " / ";
		}
		else {
			if (i == N)	cout << A[i] << "\n"; else cout << A[i] << " ";
		} 
	}
}

void work () {
	LL L, R, res = -1, temp;

	L = MIN;		R = 1e10;
	while (L <= R) {
		LL mid = (L + R) / 2;

		LL num_blocks = proses(mid);

//		cout << L << " " << R << " " << mid << "   " << num_blocks << "\n";
		if (num_blocks < K) {
			temp = mid;
			R = mid - 1;
		}
		else
		if (num_blocks > K)
			L = mid + 1;
		else {
			res = mid;
			R = mid - 1;
		}
	}
	if (res == -1)	res = temp;
	// cout << res << "  " << temp << "\n";
	print(res);
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;

	while (TC --) {
		read ();
		work ();
	}

return 0;
}