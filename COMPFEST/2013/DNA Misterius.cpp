#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int N;
int A[n], sign[n], seg[5 * n], lazy[5 * n];
string S;

void read () {
	cin >> S;
	for (int i = 0; i < S.length(); i ++) {
		S[i] == '(' ? A[i + 1] = 1 : A[i + 1] = -1;
		sign[i + 1] = A[i + 1];

		A[i + 1] += A[i];
	}
}

void build_seg (int pos, int L, int R) {
	if (L == R) {
		seg[pos] = A[L];
		return;
	}

	int mid = (L + R) / 2;
	build_seg(2 * pos, L, mid);
	build_seg(2 * pos + 1, mid + 1, R);

	seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}

int query (int pos, int L, int R, int qL, int qR) {
	if (lazy[pos] != 0) {
		seg[pos] += lazy[pos];

		if (L != R) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (L > qR || R < qL)
		return INT_MAX;

	if (qL <= L && qR >= R) {
		return seg[pos];
	}

	int mid = (L + R) / 2;

return min(
	query(2 * pos, L, mid, qL, qR),
	query(2 * pos + 1, mid + 1, R, qL, qR));
}

void update (int pos, int L, int R, int qL, int qR, int val) {
	if (lazy[pos] != 0) {
		seg[pos] += lazy[pos];

		if (L != R) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (L > qR || R < qL)
		return;

	if (qL <= L && qR >= R) {
		seg[pos] += val;

		if (L != R) {
			lazy[2 * pos] += val;
			lazy[2 * pos + 1] += val;
		}

		// printf("seg[%d] = %d  L = %d  R = %d  qL = %d  qR = %d  val = %d\n", pos, seg[pos], L, R, qL, qR, val);
		return;
	}

	int mid = (L + R) / 2;
	update(2 * pos, L, mid, qL, qR, val);
	update(2 * pos + 1, mid + 1, R, qL, qR, val);

	seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}

void solve () {
	N = S.length();
	build_seg(1, 1, N);
	memset(lazy, 0, sizeof(lazy));

	int tipe;
	while (cin >> tipe) {
		if (tipe == -1)
			break;

		if (tipe == 0) {	
			if (query(1, 1, N, N, N) == 0 && query(1, 1, N, 1, N) >= 0)
				cout << "Y";
			else
				cout << "T";
		} else {
			int pos;
			cin >> pos;
			sign[++ pos] *= -1;

			// printf("sign[%d] = %d\n", pos, sign[pos]);	
			update(1, 1, N, pos, N, sign[pos] * 2);

			// for (int i = 1; i <= N; i ++)
			// 	cout << i << ": " << query(1, 1, N, i, i) << "\n";
		}
	}

	cout << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;

	while (tc --) {
		read ();
		solve ();
	}

return 0;
}