#include<bits/stdc++.h>
#pragma GCC Optimize ("O3")
#define val first
#define frek second
using namespace std;

const int n = 1e5 + 5;

int N, Q;
int A[n];

struct state
{
	int cnt;
	pair<int, int> pref, suff;

}seg[5 * n], MINS;

void build_seg (int pos, int L, int R)
{
	if (L == R)
	{
		seg[pos].pref.val = seg[pos].suff.val = A[L];
		seg[pos].cnt = seg[pos].pref.frek = seg[pos].suff.frek = 1;

		return; 
	}

	int mid = (L + R) / 2;
	build_seg (2 * pos, L, mid);
	build_seg (2 * pos + 1, mid + 1, R);

	state Left, Right;
	Left = seg[2 * pos];				Right = seg[2 * pos + 1];

	int temp = 0;
	if (Left.suff.val == Right.pref.val)
		temp = Left.suff.frek + Right.pref.frek;

	if (Left.pref.val == Right.pref.val)
		seg[pos].pref = make_pair(Left.pref.val, Left.pref.frek + Right.pref.frek);
	else
		seg[pos].pref = make_pair(Left.pref.val, Left.pref.frek);

	if (Left.suff.val == Right.suff.val)
		seg[pos].suff = make_pair(Right.suff.val, Right.suff.frek + Left.suff.frek);
	else
		seg[pos].suff = make_pair(Right.suff.val, Right.suff.frek);

	seg[pos].cnt = max(temp,
				   max(seg[pos].suff.frek,
				   max(seg[pos].pref.frek,
				   max(seg[2 * pos].cnt, seg[2 * pos + 1].cnt))));
}

state GET (int pos, int L, int R, int QL, int QR)
{
	if (L > QR || R < QL)
		return MINS;
	if (QL <= L && QR >= R)
		return seg[pos];

	int mid = (L + R) / 2;

	if (mid >= QR)
		return GET (2 * pos, L, mid, QL, QR);

	if (mid < QL)
		return GET (2 * pos + 1, mid + 1, R, QL, QR);
 
	state Left, Right, res;
	Left = GET (2 * pos, L, mid, QL, QR);			Right = GET (2 * pos + 1, mid + 1, R, QL, QR);

	int temp = 0;
	if (Left.suff.val == Right.pref.val)
		temp = Left.suff.frek + Right.pref.frek;

	if (Left.pref.val == Right.pref.val)
		res.pref = make_pair(Left.pref.val, Left.pref.frek + Right.pref.frek);
	else
		res.pref = make_pair(Left.pref.val, Left.pref.frek);

	if (Left.suff.val == Right.suff.val)
		res.suff = make_pair(Right.suff.val, Right.suff.frek + Left.suff.frek);
	else
		res.suff = make_pair(Right.suff.val, Right.suff.frek);

	res.cnt = max(temp,
			  max(res.suff.frek, 
			  max(res.pref.frek,
			  max(Left.cnt, Right.cnt))));

return res;
}


void read ()
{
	cin >> Q;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

void work ()
{
	build_seg (1, 1, N);
	MINS.cnt = MINS.pref.val = MINS.pref.frek = MINS.suff.val = MINS.suff.frek = -1;

	while (Q --)
	{
		int L, R;
		cin >> L >> R;

		state val = GET (1, 1, N, L, R);
		cout << val.cnt << "\n";
	}
	memset(seg, 0, sizeof(seg));
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0);

	while (cin >> N)
	{
		if (N == 0)
			return 0;

		read ();
		work ();
	}

return 0;
}