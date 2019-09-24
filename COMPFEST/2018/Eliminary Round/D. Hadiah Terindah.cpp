#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 5;

int N, Q, res;

int A[n], dp[n], seg[5 * n];
bool prime[n];

void read () {
	cin >> N >> Q;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

void precompute () {
	memset(prime, true, sizeof(prime));
	prime[1] = true;
	
	vector<int> V;
	V.push_back(1);

	int base = 2;
	while (base * base <= 1e5) {
		prime[base] = true;
		V.push_back(base);

		int p = 2;
		while (base * p <= 1e5) {
			prime[base * p] = false;
			p ++;
		}

		base ++;
		while (!prime[base])		base ++;
	}

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;			dp[1] = 1;
	for (int i = 2; i <= N; i ++)
		for (int j = 0; j < V.size(); j ++) {
			if (V[j] > i)		break;

			if (prime[i]) {
				dp[i] = 1;
				continue;
			}
			dp[i] == -1 ? dp[i] = dp[i - V[j]] + 1 : dp[i] = min(dp[i], dp[i - V[j]] + 1);
		}
}

void build_segtree (int pos, int L, int R) {
	if (L == R) {
		seg[pos] = A[L];
		return;
	}

	int mid = (L + R) / 2;
	build_segtree(2 * pos, L, mid);			build_segtree(2 * pos + 1, mid + 1, R);

seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

void update (int pos, int L, int R, int Q, int val) {
	if (L > Q || R < Q)
		return ;

	if (Q <= L && Q >= R) {
		seg[pos] = val;
		return;
	}

	int mid = (L + R) / 2;
	update (2 * pos, L, mid, Q, val);			update (2 * pos + 1, mid + 1, R, Q, val);

seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

int GET (int pos, int L, int R, int QL, int QR) {
	if (L > QR || R < QL)
		return 0;

	if (QL <= L && QR >= R)
		return seg[pos];

	int mid = (L + R) / 2;

return GET (2 * pos, L, mid, QL, QR) + GET (2 * pos + 1, mid + 1, R, QL, QR);
}

void solve (int pos) {
	int L, R, up, low;

	up = low = 0;
	if (A[pos + 1] == 1) {
		L = pos + 1;			R = N;

		while (L <= R) {
			int mid = (L + R) / 2;

			int curr_ones = GET (1, 1, N, pos + 1, mid);
			if (curr_ones == mid - pos) {				// semua A[] di range itu '1'
				up = mid;
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
	}

	if (A[pos - 1] == 1) {
		L = 1;					R = pos - 1;

		while (L <= R) {
			int mid = (L + R) / 2;

			int curr_ones = GET (1, 1, N, mid, pos - 1);
//			cout << "left : " << L << "    right : " << R << "    " << curr_ones << "\n";

			if (curr_ones == pos - mid) {
				low = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}	
	}
	
	int left_seg, right_seg;
	left_seg = right_seg = 0;
	
	if (A[pos - 1] == 1)
		left_seg = pos - low;

	if (A[pos + 1] == 1)
		right_seg = up - pos;

	// cout << "\n";
	// cout << pos <<" :    Left " << left_seg << "     Right " << right_seg << "\n";
	// cout << "dp[left] = " << dp[left_seg] << "     dp[right] = " << dp[right_seg] << "\n\n";

	if (A[pos] == 1) 		// gabung segment
		res = res - (dp[left_seg] + dp[right_seg]) + dp[left_seg + right_seg + 1];
	else 					// pisahin segment
		res = res - (dp[left_seg + right_seg + 1]) + dp[left_seg] + dp[right_seg];
}

void work () {
	precompute ();
	build_segtree(1, 1, N);

	int cnt = 0;
	for (int i = 1; i <= N; i ++) {
		if (A[i] == 1)
			cnt ++;
		else {
			res += dp[cnt];
			cnt = 0;
		}
	}
	if (cnt != 0)
		res += dp[cnt];

	cout << res << "\n";
	while (Q --) {
		int X;
		cin >> X;

		if (A[X] == 0) {		// merge segment
			A[X] = 1;
			update(1, 1, N, X, 1);

			solve (X);
		}
		else {		// split segment
			A[X] = 0;
			update (1, 1, N, X, -1);

			solve (X);
		}
		cout << res << "\n";
	}
}


int main () {
	ios_base::sync_with_stdio(false);

	read (); 
	work ();

return 0;
}