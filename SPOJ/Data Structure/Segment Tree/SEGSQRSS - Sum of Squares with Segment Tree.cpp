#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize ("O3")
using namespace std;

const int n = 1e5 + 5;

int N, Q;
int A[n];

pair<int, int> lazy[5 * n];

struct state
{
	LL sum, square;
}seg[5 * n];

void print ()
{
	cout << "Sum :  ";
	for (int i = 1; i <= 7; i ++)
		cout << seg[i].sum << " ";
	cout << "\n";

	cout << "Square Sum :  ";
	for (int i = 1; i <= 7; i ++)
		cout << seg[i].square << " ";
	cout << "\n";
}

void read ()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

void build_seg (int pos, int L, int R)
{
	if (L == R)
	{
		seg[pos].sum = A[L];
		seg[pos].square = A[L] * A[L];

		return;
	}

	int mid = (L + R) / 2;
	build_seg (2 * pos, L, mid);
	build_seg (2 * pos + 1, mid + 1, R);

	seg[pos].sum = seg[2 * pos].sum + seg[2 * pos + 1].sum;
	seg[pos].square = seg[2 * pos].square + seg[2 * pos + 1].square;
}

state GET (int pos, int L, int R, int QL, int QR)
{
	LL X;
	if (lazy[pos].first != -1)
	{
		X = lazy[pos].second;
		if (lazy[pos].first == 0)
		{
			seg[pos].sum = (R - L + 1) * X;
			seg[pos].square = (R - L + 1) * X * X;
		}
		else
		{
			seg[pos].square += 2 * X * seg[pos].sum + (R - L + 1) * X * X;
			seg[pos].sum += (R - L + 1) * X;
		}

		if (L != R)
			lazy[2 * pos] = lazy[2 * pos + 1] = lazy[pos]; 
		
		lazy[pos].first = -1;
	}

	if (L > QR || R < QL)
		return {0, 0};

	if (QL <= L && QR >= R)
		return seg[pos];

	int mid = (L + R) / 2;

	if (mid >= QR)
		return GET (2 * pos, L, mid, QL, QR);

	if (mid < QL)
		return GET (2 * pos + 1, mid + 1, R, QL, QR);

	state Left, Right, res;
	Left = GET (2 * pos, L, mid, QL, QR);			Right = GET (2 * pos + 1, mid + 1, R, QL, QR);

	res.sum = Left.sum + Right.sum;
	res.square = Left.square + Right.square;

return res;
}

void update (int pos, int L, int R, int QL, int QR, int query, int S)
{
	LL X;
	if (lazy[pos].first != -1)
	{
		X = lazy[pos].second;
		if (lazy[pos].first == 0)
		{
			seg[pos].sum = (R - L + 1) * X;
			seg[pos].square = (R - L + 1) * X * X;
		}
		else
		{
			seg[pos].square += 2 * X * seg[pos].sum + (R - L + 1) * X * X;
			seg[pos].sum += (R - L + 1) * X;
		}

		if (L != R)
			lazy[2 * pos] = lazy[2 * pos + 1] = lazy[pos]; 
		
		lazy[pos].first = -1;
	}

	if (L > QR || R < QL)
		return;

	if (QL <= L && QR >= R)
	{
		if (query == 0)
		{
			seg[pos].sum = (R - L + 1) * S;
			seg[pos].square = (R - L + 1) * S * S;
		}
		else
		{
			seg[pos].square += 2 * S * seg[pos].sum + (R - L + 1) * S * S;
			seg[pos].sum += (R - L + 1) * S;
		}
		
		if (L != R)
			lazy[2 * pos] = lazy[2 * pos + 1] = {query, S}; 
		return;
	}

	int mid = (L + R) / 2;

	if (mid >= QR)
	{
		update (2 * pos, L, mid, QL, QR, query, S);
		seg[pos].sum = seg[2 * pos].sum + seg[2 * pos + 1].sum;
		seg[pos].square = seg[2 * pos].square + seg[2 * pos + 1].square;
		
		return;
	}

	if (mid < QL)
	{
		update (2 * pos + 1, mid + 1, R, QL, QR, query, S);
		seg[pos].square = seg[2 * pos].square + seg[2 * pos + 1].square;

		return;
	}
	update (2 * pos, L, mid, QL, QR, query, S);			
	update (2 * pos + 1, mid + 1, R, QL, QR, query, S);

	seg[pos].sum = seg[2 * pos].sum + seg[2 * pos + 1].sum;
	seg[pos].square = seg[2 * pos].square + seg[2 * pos + 1].square;
}

void work (int tc)
{
	memset(seg, 0, sizeof(seg));
	memset(lazy, -1, sizeof(lazy));
	build_seg (1, 1, N);

//	print ();

	cout << "Case " << tc << ":\n";
	while (Q --)
	{
		int query, L, R, X;
		cin >> query;

		if (query != 2)
		{
			cin >> L >> R >> X;

			update (1, 1, N, L, R, query, X );
//			print ();
		}
		else
		{
			cin >> L >> R;

			state res = GET (1, 1, N, L, R);
			cout << res.square << "\n";
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc ++)
	{
		read ();
		work (tc);
	}

return 0;
}