#include<bits/stdc++.h>
#pragma GCC Optimize ("O3")
using namespace std;

const int n = 30005, INF = INT_MAX;

int N;
int A[n], pref[n], seg[2][100 * n], lazy[2][100 * n];

void read ()
{
	cin >> N;

	pref[0] = 0;
	for (int i = 1; i <= N; i ++)
	{
		char C;
		cin >> C;

		if (C == '(')
			A[i] = 1;
		else
			A[i] = -1;

		pref[i] = pref[i - 1] + A[i];
	}
}

void build_seg (int pos, int L, int R, int tipe)
{
	lazy[0][pos] = lazy[1][pos] = 0;

	if (L == R)
	{
		if (tipe == 0)		// Range Sum
			seg[tipe][pos] = A[L];
		else
			seg[tipe][pos] = pref[L];
		return; 
	}
	int mid = (L + R) / 2;

	build_seg(2 * pos, L, mid, tipe);
	build_seg(2 * pos + 1, mid + 1, R, tipe);

	if (tipe == 0)
		seg[tipe][pos] = seg[tipe][2 * pos] + seg[tipe][2 * pos + 1];
	else
		seg[tipe][pos] = min(seg[tipe][2 * pos], seg[tipe][2 * pos + 1]);
}

void update (int pos, int L, int R, int QL, int QR, int tipe, int val)
{
	if (lazy[pos] != 0)
	{
		if (tipe == 0)
			seg[tipe][pos] += (R - L + 1) * lazy[tipe][pos];
		else
			seg[tipe][pos] += lazy[tipe][pos];

		if (L != R) 
		{
			lazy[tipe][2 * pos] += lazy[tipe][pos];			lazy[tipe][2 * pos + 1] += lazy[tipe][pos];
		}
		lazy[tipe][pos] = 0;
	}

	if (L > QR || R < QL)
		return;

	if (QL <= L && QR >= R)
	{
		if (tipe == 0)
			seg[tipe][pos] += (R - L + 1) * val;
		else
			seg[tipe][pos] += val;

		if (L != R)
		{
			lazy[tipe][2 * pos] += val;
			lazy[tipe][2 * pos + 1] += val; 
		}
		return;
	}

	if (L == R)		return;

	int mid = (L + R) / 2;

	update(2 * pos, L, mid, QL, QR, tipe, val);
	update(2 * pos + 1, mid + 1, R, QL, QR, tipe, val);

	if (tipe == 0)
		seg[tipe][pos] = seg[tipe][2 * pos] + seg[tipe][2 * pos + 1];
	else
		seg[tipe][pos] = min(seg[tipe][2 * pos], seg[tipe][2 * pos + 1]);
}

int GET (int pos, int L, int R, int QL, int QR, int tipe)
{
	if (lazy[pos] != 0)
	{
		if (tipe == 0)
			seg[tipe][pos] += (R - L + 1) * lazy[tipe][pos];
		else
			seg[tipe][pos] += lazy[tipe][pos];

		if (L != R) 
		{
			lazy[tipe][2 * pos] += lazy[tipe][pos];			lazy[tipe][2 * pos + 1] += lazy[tipe][pos];
		}
		lazy[tipe][pos] = 0;
	}

	if (L > QR || R < QL)
	{
		if (tipe == 0)		return 0;
		return INF;
	}

	if (QL <= L && QR >= R)
		return seg[tipe][pos];

	int mid = (L + R) / 2;

	if (tipe == 0)
		return GET(2 * pos, L, mid, QL, QR, tipe) + GET(2 * pos + 1, mid + 1, R, QL, QR, tipe);
	else
		return min(GET(2 * pos, L, mid, QL, QR, tipe), GET(2 * pos + 1, mid + 1, R, QL, QR, tipe));
}

void work (int tc)
{
	for (int i = 0; i < 2; i ++)
		build_seg(1, 1, N, i);

	int Q;
	cin >> Q;

	cout << "Test " << tc << ":\n";
	while (Q --)
	{
		int idx;
		cin >> idx;

		if (idx == 0)
		{
			int mins, sum;
			sum = GET(1, 1, N, 1, N, 0);
			mins = GET(1, 1, N, 1, N, 1);

			if (sum == 0 && mins >= 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			if (A[idx] == 1)
			{
				A[idx] = -1;
				update(1, 1, N, idx, idx, 0, -2);
				update(1, 1, N, idx, N, 1, -2);
			}
			else
			{
				A[idx] = 1;
				update(1, 1, N, idx, idx, 0, 2);
				update(1, 1, N, idx, N, 1, 2);
			}
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);

	for (int tc = 1; tc <= 10; tc ++)
	{
		read ();
		work (tc);
	}

return 0;
}