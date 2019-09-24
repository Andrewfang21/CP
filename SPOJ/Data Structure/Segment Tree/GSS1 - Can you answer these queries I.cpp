#include<bits/stdc++.h>
using namespace std;

const int n = 5e4 + 5, INF = INT_MAX;

int N, Q;
int A[n];

struct state
{
	int Lsum, Rsum, Msum, Tsum;
}seg[5 * n], MIN;

void read ()
{
	cin >> N;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

void build_seg (int pos, int L, int R)
{
	if (L == R)
	{
		seg[pos].Lsum = seg[pos].Rsum = seg[pos].Msum = seg[pos].Tsum = A[L];
		return;
	}

	int mid = (L + R) / 2;

	build_seg (2 * pos, L, mid);
	build_seg (2 * pos + 1, mid + 1, R);

	seg[pos].Lsum = max(seg[2 * pos].Lsum, seg[2 * pos].Tsum + seg[2 * pos + 1].Lsum);
	seg[pos].Rsum = max(seg[2 * pos + 1].Rsum, seg[2 * pos].Rsum + seg[2 * pos + 1].Tsum);
	seg[pos].Msum = max(seg[pos].Lsum, 
					max(seg[pos].Rsum, 
					max(seg[2 * pos].Msum,
					max(seg[2 * pos + 1].Msum, seg[2 * pos].Rsum + seg[2 * pos + 1].Lsum))));
	seg[pos].Tsum = seg[2 * pos].Tsum + seg[2 * pos + 1].Tsum;
}

state GET (int pos, int L, int R, int QL, int QR)
{
	if (L > QR || R < QL)
		return MIN;
	if (QL <= L && QR >= R)
		return seg[pos];

	int mid = (L + R) / 2;
	if (QL > mid)
		return GET (2 * pos + 1, mid + 1, R, QL, QR);
	if (QR <= mid)
		return GET (2 * pos, L, mid, QL, QR);

	state Left, Right, res;
	Left = GET (2 * pos, L, mid, QL, QR);
	Right = GET (2 * pos + 1, mid + 1, R, QL, QR);

	res.Lsum = max(Left.Lsum, Left.Tsum + Right.Lsum);
	res.Rsum = max(Right.Rsum, Left.Rsum + Right.Tsum);
	res.Msum = max(res.Lsum,
			   max(res.Rsum,
			   max(Left.Msum,
			   max(Right.Msum, Left.Rsum + Right.Lsum))));
	res.Tsum = Left.Tsum + Right.Tsum;

return res;
}

void work ()
{
	MIN.Lsum = MIN.Rsum = MIN.Tsum = MIN.Msum = -INT_MIN;
	build_seg(1, 1, N);

	// for (int pos = 1; pos < 10; pos ++)
	// 	cout << pos << " :  L = " << seg[pos].Lsum << "    R = " << seg[pos].Rsum << "   M = " << seg[pos].Msum << "   Total = " << seg[pos].Tsum << "\n";

	cin >> Q;
	while (Q --)
	{
		int L, R;
		cin >> L >> R;

		state res = GET (1, 1, N, L, R);
		cout << res.Msum << "\n";
	}
}


int main ()
{
	ios_base::sync_with_stdio(false);
//	cin.tie(0);			cout.tie(0);

	read ();
	work ();

return 0;
}