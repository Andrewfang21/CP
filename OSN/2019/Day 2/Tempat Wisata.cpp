#include<bits/stdc++.h>
using namespace std;

const int n = 2e5 + 5;

int N, M;
int seg[5 * n], lazy[5 * n], ans[n];

struct state {
	int left, right, idx;
}person[n];

bool cmp (state LHS, state RHS) {
	if (LHS.left == RHS.left)
		return LHS.right < RHS.right;
return LHS.left < RHS.left;
}

void read() {
	cin >> N >> M;
	for (int i = 1; i <= N; i ++) {
		cin >> person[i].left >> person[i].right;
		person[i].idx = i;
	}
}

void update(int pos, int L, int R, int QL, int QR) {
	if (lazy[pos] != 0) {
		seg[pos] += (R - L + 1) * lazy[pos];

		if (L != R)
			lazy[2 * pos] += lazy[pos], lazy[2 * pos + 1] += lazy[pos];

		lazy[pos] = 0;
	}

	if (QL <= L && QR >= R) {
		seg[pos] += (R - L + 1);

		if (L != R) 
			lazy[2 * pos] += 1, lazy[2 * pos + 1] += 1;
		return;
	}

	if (QL > R || QR < L)	return;

	int mid = (L + R) / 2;

	update(2 * pos, L, mid, QL, QR);
	update(2 * pos + 1, mid + 1, R, QL, QR);

	seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

int query (int pos, int L, int R, int X) {
	if (lazy[pos] != 0) {
		seg[pos] += (R - L + 1) * lazy[pos];

		if (L != R)
			lazy[2 * pos] += lazy[pos], lazy[2 * pos + 1] += lazy[pos];

		lazy[pos] = 0;
	}

	if (X <= L && X >= R)
		return seg[pos];

	if (X > R || X < L)	return 0;

	int mid = (L + R) / 2;
	
return query(2 * pos, L, mid, X) + query(2 * pos + 1, mid + 1, R, X);
}

int binser(int idx, int left, int border) {
	int start = left - 1;
	int right = N, pos = -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (person[mid].left > border)
			right = mid - 1;
		else {
			pos = mid;
			left = mid + 1;
		}
	}

	if (pos != -1)
		update(1, 1, N, start + 1, pos);

	if (pos == -1)
		return 0;
return pos - start;
}

void solve() {
	sort(person + 1, person + N + 1, cmp);

	for (int i = 1; i < N; i ++) {
		int currBorder = person[i].right;
		ans[person[i].idx] = binser(i, i + 1, currBorder);
	}

	for (int i = 1; i <= N; i ++)
		ans[person[i].idx] += query(1, 1, N, i);

	for (int i = 1; i <= N; i ++)
		cout << ans[i] << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}
