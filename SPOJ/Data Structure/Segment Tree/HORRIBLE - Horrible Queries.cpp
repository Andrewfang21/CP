#include<bits/stdc++.h>
#pragma GCC Optimize ("O3")
#define LL long long
using namespace std;

const int n = 100005;

LL N, Q;
LL seg[100 * n], lazy[100 * n];

void update (int pos, int L, int R, int QL, int QR, LL val)
{
	if (lazy[pos] != 0)
	{
		seg[pos] += (R - L + 1) * lazy[pos];

		if (L != R)
		{
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (L > QR || R < QL)
		return;
	if (QL <= L && QR >= R)
	{
		seg[pos] += (R - L + 1) * val;

		if (L != R)
		{
			lazy[2 * pos] += val;
			lazy[2 * pos + 1] += val;
		}
		return;
	}

	int mid = (L + R) / 2;

	update(2 * pos, L, mid, QL, QR, val);
	update(2 * pos + 1, mid + 1, R, QL, QR, val);

	seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

LL GET (int pos, int L, int R, int QL, int QR)
{
	if (lazy[pos] != 0)
	{
		seg[pos] += (R - L + 1) * lazy[pos];

		if (L != R)
		{
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (L > QR || R < QL)
		return 0;

	if (QL <= L && QR >= R)
		return seg[pos];

	int mid = (L + R) / 2;

return GET(2 * pos, L, mid, QL, QR) + GET(2 * pos + 1, mid + 1, R, QL, QR);
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;

	cin >> TC;
	while (TC --)
	{
		cin >> N >> Q;
	
		memset(seg, 0, sizeof(seg));
		memset(lazy, 0, sizeof(lazy));
		while (Q --)
		{
			LL tipe, L, R, val;
			cin >> tipe;

			if (tipe == 0)
			{
				cin >> L >> R >> val;
				update(1, 1, N, L, R, val);

//				cout << GET(1, 1, N, L, R) << "\n";
			}
			else
			{
				cin >> L >> R;
				LL res = GET(1, 1, N, L, R);

				cout << res << "\n";
			}
		}
	}

return 0;
}