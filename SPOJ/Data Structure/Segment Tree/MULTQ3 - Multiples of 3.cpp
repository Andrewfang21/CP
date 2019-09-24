#include<bits/stdc++.h>
#pragma GCC Optimize ("O3")
using namespace std;

const int n = 1e5 + 5;

int N, Q;
int seg[3][5 * n], lazy[5 * n];

void build_seg (int pos, int L, int R)
{
	if (L == R)
	{
		seg[0][pos] = 1;
		return;		
	}

	int mid = (L + R) / 2;

	build_seg (2 * pos, L, mid);
	build_seg (2 * pos + 1, mid + 1, R);

seg[0][pos] = seg[0][2 * pos] + seg[0][2 * pos + 1];
}

void update (int pos, int L, int R, int QL, int QR)
{
	if (lazy[pos] != 0)
	{
		if (lazy[pos] == 1)
		{
			int temp = seg[0][pos];
			seg[0][pos] = seg[2][pos];		seg[2][pos] = seg[1][pos];		seg[1][pos] = temp;
		}
		else
		{
			int temp = seg[0][pos];
			seg[0][pos] = seg[1][pos];		seg[1][pos] = seg[2][pos];		seg[2][pos] = temp;
		}

		if (L != R)
		{
			lazy[2 * pos] = (lazy[2 * pos] + lazy[pos]) % 3;
			lazy[2 * pos + 1] = (lazy[2 * pos + 1] + lazy[pos]) % 3;
		}
		lazy[pos] = 0;
	}

	if (L > QR || R < QL)
		return;

	if (QL <= L && QR >= R)
	{
		int temp = seg[0][pos];
		seg[0][pos] = seg[2][pos];		seg[2][pos] = seg[1][pos];		seg[1][pos] = temp;

		if (L != R)
		{
			lazy[2 * pos] = (lazy[2 * pos] + 1) % 3;
			lazy[2 * pos + 1] = (lazy[2 * pos + 1	] + 1) % 3;
		}
		return;
	}

	int mid = (L + R) / 2;

	update (2 * pos, L, mid, QL, QR);
	update (2 * pos + 1, mid + 1, R, QL, QR);

	for (int i = 0; i < 3; i ++)
		seg[i][pos] = seg[i][2 * pos] + seg[i][2 * pos + 1];
}

int GET (int pos, int L, int R, int QL, int QR)
{
	if (lazy[pos] != 0)
	{
		if (lazy[pos] == 1)
		{
			int temp = seg[0][pos];
			seg[0][pos] = seg[2][pos];		seg[2][pos] = seg[1][pos];		seg[1][pos] = temp;
		}
		else
		{
			int temp = seg[0][pos];
			seg[0][pos] = seg[1][pos];		seg[1][pos] = seg[2][pos];		seg[2][pos] = temp;
		}

		if (L != R)
		{
			lazy[2 * pos] = (lazy[2 * pos] + lazy[pos]) % 3;
			lazy[2 * pos + 1] = (lazy[2 * pos + 1] + lazy[pos]) % 3;
		}
		lazy[pos] = 0;
	}

	if (L > QR || R < QL)
		return 0;

	if (QL <= L && QR >= R)
		return seg[0][pos];

	int mid = (L + R) / 2;

return GET (2 * pos, L, mid, QL, QR) + GET (2 * pos + 1, mid + 1, R, QL, QR);
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0);
	cin >> N >> Q;

	N ++;
	build_seg (1, 1, N);

	while (Q --)
	{
		int tipe, L, R;
		cin >> tipe >> L >> R;

		L ++;			R ++;
		if (tipe == 0)
			update (1, 1, N, L, R);
		else
		{
			int res = GET (1, 1, N, L, R);
			cout << res << "\n";
		}
	}
return 0;
}