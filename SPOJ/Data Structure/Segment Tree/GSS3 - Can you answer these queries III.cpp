#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e4 + 5;

int n;
int A[N];

struct state {
	ll lsum, rsum, maxSum, totSum;
}seg[5 * N], MIN;

void read () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &A[i]);
	}
}

void buildSeg (int pos, int l, int r) {
	if (l == r) {
		seg[pos].lsum = seg[pos].rsum = seg[pos].maxSum = seg[pos].totSum = A[l];
		return;
	}

	int mid = (l + r) / 2;
	buildSeg (2 * pos, l, mid);
	buildSeg (2 * pos + 1, mid + 1, r);

	seg[pos].lsum = max(seg[2 * pos].lsum,
						seg[2 * pos].totSum + seg[2 * pos + 1].lsum);

	seg[pos].rsum = max(seg[2 * pos + 1].rsum,
						seg[2 * pos + 1].totSum + seg[2 * pos].rsum);

	seg[pos].maxSum = max(seg[pos].lsum,
					  max(seg[pos].rsum,
					  max(seg[2 * pos].maxSum,
					  max(seg[2 * pos + 1].maxSum,
					  	  seg[2 * pos].rsum + seg[2 * pos + 1].lsum))));

	seg[pos].totSum = seg[2 * pos].totSum + seg[2 * pos + 1].totSum;
}

state query (int pos, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)
		return MIN;
	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;
	if (ql > mid)
		return query (2 * pos + 1, mid + 1, r, ql, qr);
	if (qr <= mid)
		return query (2 * pos, l, mid, ql, qr);

	state lnode, rnode, res;
	lnode = query (2 * pos, l, mid, ql, qr);
	rnode = query (2 * pos + 1, mid + 1, r, ql, qr);

	res.lsum = max(lnode.lsum, lnode.totSum + rnode.lsum);
	res.rsum = max(rnode.rsum, rnode.totSum + lnode.rsum);
	res.maxSum = max(res.lsum,
				 max(res.rsum,
				 max(lnode.maxSum,
				 max(rnode.maxSum,
				 	 lnode.rsum + rnode.lsum))));
	res.totSum = lnode.totSum + rnode.totSum;

return res;
}

void update (int pos, int l, int r, int idx, int val) {
	if (l > idx || r < idx)
		return;

	if (l == idx && r == idx) {
		A[l] = val;
		seg[pos].lsum = seg[pos].rsum = seg[pos].maxSum = seg[pos].totSum = A[l];
		return;
	}

	int mid = (l + r) / 2;
	update (2 * pos, l, mid, idx, val);
	update (2 * pos + 1, mid + 1, r, idx, val);

	seg[pos].lsum = max(seg[2 * pos].lsum,
						seg[2 * pos].totSum + seg[2 * pos + 1].lsum);

	seg[pos].rsum = max(seg[2 * pos + 1].rsum,
						seg[2 * pos + 1].totSum + seg[2 * pos].rsum);

	seg[pos].maxSum = max(seg[pos].lsum,
					  max(seg[pos].rsum,
					  max(seg[2 * pos].maxSum,
					  max(seg[2 * pos + 1].maxSum,
					  	  seg[2 * pos].rsum + seg[2 * pos + 1].lsum))));

	seg[pos].totSum = seg[2 * pos].totSum + seg[2 * pos + 1].totSum;
}

void solve () {
	MIN.lsum = MIN.rsum = MIN.totSum = MIN.maxSum = LLONG_MIN;
	buildSeg(1, 1, n);

	int Q;
	scanf("%d", &Q);

	while (Q --) {
		int tipe;
		scanf("%d", &tipe);

		if (tipe == 1) {
			int l, r;
			scanf("%d %d", &l, &r);

			state res = query(1, 1, n, l, r);
			printf("%lld\n", res.maxSum);
		} else {
			int idx, val;
			scanf("%d %d", &idx, &val);

			update(1, 1, n, idx, val);
		}
	}
}

int main () {
	read ();
	solve ();

return 0;
}